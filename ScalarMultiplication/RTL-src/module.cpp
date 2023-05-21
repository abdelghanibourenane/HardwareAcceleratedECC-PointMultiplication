/******************************************************************************

  File: module.cpp
  Author: Abdelghani Bourenane
  Date: April 22, 2023

  Description: This file contains the HLS code for the Radix2wECC Scalar Multiplication  module.


******************************************************************************/

#include"module.hpp"

using namespace std;
Point values[1 << (w - 2)];

void Radix2wECC(volatile unsigned int *k, volatile unsigned int *x_o, volatile unsigned int *y_o){
	#pragma HLS INTERFACE m_axi depth=6 port=k offset=slave
	#pragma HLS INTERFACE m_axi depth=6 port=x_o offset=slave
	#pragma HLS INTERFACE m_axi depth=6 port=y_o offset=slave
	#pragma HLS INTERFACE s_axilite port=return

	unsigned int buff1[6];
	unsigned int buff2[6];
	unsigned int buff3[6];

	memcpy(buff1, (const unsigned int*)k, 6*sizeof(int));
	memcpy(buff2, (const unsigned int*)x_o, 6*sizeof(int));
	memcpy(buff3, (const unsigned int*)y_o, 6*sizeof(int));

	ap_uint<192> a,b,c;
	a=0x0;b=0x0;c=0x0;
	for (int i = 0; i < 6; i++) {
		a |= (ap_uint<192>)buff1[i] << (i*32);
	}
	for (int i = 0; i < 6; i++) {
		b |= (ap_uint<192>)buff2[i] << (i*32);
	}
	for (int i = 0; i < 6; i++) {
		c |= (ap_uint<192>)buff3[i] << (i*32);
	}
	ap_uint<l+1+Nz> scalar = 0x0;
	scalar =a.range(l+Nz,0);
	cout<<"scalar is: "<<hex<<scalar<<endl;
	scalar<<=1;
	Point R;
	R.x = 0x0;
	R.y = 0x0;
    //radix_format(scalar);
    ap_int<w+1> slice;
    generate_points(values, b, c);
    int m,n;
    for (int i = ((l+Nz)/w)-1 ; i >= 0 ; i--){
		for(int k = w-1 ; k >= 0 ; k--){
			slice = 0;
			for(int j=0;j<w+1;j++){
				slice[j]=scalar[(i*w)+j];
			}
			//        #pragma HLS PIPELINE II=1
			m_n_parameters(slice, m,n);
			point_double(R.x,R.y);
			if (m != 0){
				if (k == n){
					if(slice[(w)]==1){
						vec y_tmp;
						bf_add(y_tmp,(values[((m-1)/2)]).x,(values[((m-1)/2)]).y);
						point_add(R.x, R.y, (values[((m-1)/2)]).x, y_tmp);
					}else{
						point_add(R.x, R.y, (values[((m-1)/2)]).x, (values[((m-1)/2)]).y);
					}
				}
			}
		}
    }
    b.range(162,0)=(R.x).range(162,0);
    c.range(162,0)=(R.y).range(162,0);
    for(int i=0;i<6;i++){
    	buff2[i]=(int)b.range((i+1)*32-1,i*32);
    	buff3[i]=(int)c.range((i+1)*32-1,i*32);
    }
    memcpy((int *)x_o,buff2,6*sizeof(int));
    memcpy((int *)y_o,buff3,6*sizeof(int));
}

void m_n_parameters(ap_int<w+1> slice, int& m, int& n) {
    int Q = slice[0] + (slice[1] * (1 << 0)) + (slice[2] * (1 << 1)) + (slice[3] * (1 << 2)) + (slice[4] * (1 << 3)) - (slice[5] * (1 << 4));
    if (Q == 0) {
        m = n = 0;
        return;
    }
    m=n=0;
    while ((Q % 2) == 0) {
        Q /= 2;
        n++;
    }
    m = std::abs(Q);
}
/*
ap_int<l+1+Nz> radix_format(ap_int<l> value) {
    ap_int<l+1+Nz> result = (ap_uint<Nz>(0), value(162, 0), ap_uint<1>(0)); // select the most significant 163 bits, shift them to the right by one bit, add Nz zeros to the left, and add a single zero bit to the right
    return result;
}
*/
void generate_points(Point* values, vec b, vec c) {
    values[0].x = b ;
    values[0].y = c ;
    Point tmp;
    tmp.x = (vec)b;
    tmp.y = (vec)c;
    point_double(tmp.x,tmp.y);
    Point tmp1;
    tmp1=tmp;
    //    #pragma HLS pipeline

    for (int i = 1; i < (1 << (w - 2)); i++) {
        point_add(tmp1.x, tmp1.y, values[i - 1].x, values[i - 1].y);
        values[i]=tmp1;
        tmp1=tmp;
    }
}

