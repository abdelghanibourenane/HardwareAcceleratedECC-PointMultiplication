/******************************************************************************

  File: module.cpp
  Author: Abdelghani Bourenane
  Date: April 22, 2023

  Description: This file contains the HLS code for the Bonary field Operaitons.


******************************************************************************/
#include"gf2_arithmetic.hpp"

/*----------------------------------------------------------------------
 * binary field arithmetic operations
 -------------------------------------------------------------------------*/
void vec_swap(vec &x, vec &y){
	x ^= y;
	y ^= x;
	x ^= y;
}

uint16_t vec_degree(const vec &x){
	uint16_t i;
	i=VECTOR_NBITS-1;
	while(x[i]==0){
		i-=1;
	}
	return i+1;
}

void bf_add(vec &z, const vec &x, const vec &y){
	int i;
	for (i = 0; i < VECTOR_NBITS; ++i) {
		z[i] = (x[i] ^ y[i]);
	}
	/*
	void bf_add(vec &z, const vec &x, const vec &y) {
    #pragma HLS pipeline II=1
   		 z = x ^ y;
	}

	*/
}


void bf_mult(vec &z, const vec &x, const vec &y) {
	//    #pragma HLS PIPELINE II=1
    short i;
    vec tmp = x;
    if (y[0] != 0) {
        z = x;
    } else {
        z = 0x0;
    }

    for (i = 1; i < l; ++i) {
        tmp <<= 1;
        if (tmp[l]) {
            bf_add(tmp, tmp, polynomial);
        }
        if (y[i]) {
            bf_add(z, z, tmp);
        }

    }
}
//#pragma HLS inline auto
void bf_inv(vec &z,const vec &x){
	vec u,v,g,h;
	u=x;
	v=polynomial;
	z=0x01;
	g=0x00;
	int j;
	while(u!=(0x01)){
		j=vec_degree(u)-vec_degree(v);
		if(j<0){
			vec_swap(u,v);
			vec_swap(g,z);
			j=(-j);
		}
		h=v<<j;
		bf_add(u,u,h);  //u ← u + z^j * v
		h=g<<j;
		bf_add(z,z,h); //Z ← Z + z^j * g
	}

}

void point_double(vec &x, vec &y){
	if(x==0){
		y=0x0;
	}else{
		//calculate lambda  λ = x1 + y1 / x1
		vec lambda;
		bf_inv(lambda,x);
		bf_mult(lambda,lambda,y);
		bf_add(lambda,lambda,x);
		//calculate x and y of the doubled point x3 = λ^2 + λ + a , y3 = x1^2 + (λ + 1) * x3
		bf_mult(y,x,x);
		bf_mult(x,lambda,lambda);
		lambda^=(vec)coeff_a;
		bf_add(x,x,lambda);
		bf_mult(lambda,lambda,x);
		bf_add(y,y,lambda);
	}
}

void point_add(vec &x1, vec &y1, const vec &x2, const vec &y2){
	if((x2!=0x0)&(y2!=0x0)){
		if((x1==0x0)&(y1==0x0)){
			//(x, y) + O = O + (x, y) = (x, y) for all (x, y) ∈ E(Fp)
			x1=x2;
			y1=y2;
		}
		else{
			if(x1==x2){
				if(y1==y2){
					point_double(x1,y1);
				}else{
					x1=0x0;
					y1=0x0;
				}
			}else{
				vec a,b,c,d;
				//calculating lambda: λ=(y1+y2)/(x1+x2)
				bf_add(a,x1,x2);
				bf_add(b,y1,y2);
				bf_inv(c,a);
				bf_mult(c,c,b);
				// calculating: x3 = λ2 + λ + x1 + x2 + a
				bf_mult(d,c,c);
				bf_add(d,d,c);
				bf_add(d,d,a);
				d^=(vec)coeff_a;
				//d=x3, calculating: y3 = λ(x1 + x3) + x3 + y1
				bf_add(x1,x1,d);
				bf_mult(a,x1,c);
				bf_add(a,a,d);
				bf_add(y1,y1,a);
				x1=d;
			}
		}
	}
}

