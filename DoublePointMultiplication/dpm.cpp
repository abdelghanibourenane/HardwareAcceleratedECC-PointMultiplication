#include"dpm.hpp"
#include"gf2_arithmetic.hpp"
Point values[6];
void Radix2wDPM(vec &k1, vec &k2, Point &R, Point &S, Point &P){
	ap_uint<l+1+Nz> u = 0x0;
	u =k1.range(l+Nz,0);
	u<<=1;
	ap_uint<l+1+Nz> v = 0x0;
	v =k2.range(l+Nz,0);
	v<<=1;
	Point M;
	P.x = 0x0;
	P.y = 0x0;
    ap_int<w+1> di_u,di_v;
	short Qu,Qv;
	generate_points(values,R,S);
 	for (int i = ((l+Nz)/w)-1 ; i >= 0 ; i--){
		for(int j=0;j<w+1;j++){
			di_u[j]=u[(i*w)+j];
			di_v[j]=v[(i*w)+j];
		}
		Qi_parameter(di_u,Qu);
		Qi_parameter(di_u,Qv);
		if((Qu==1 &	Qv == 1) || (Qu == 2 &	Qv == 2)){
			if((v[2*w+2]-u[2*w+2])==1){
				M=values[3];
			}else{
				M=values[0];
			}
		}else if(Qu==1 & Qv == 2){
			if((v[2*w+2]-u[2*w+2])==1){
				M=values[4];
			}else{
				M=values[1];
			}
		}else if(Qu==2 & Qv == 1){
			if((v[2*w+2]-u[2*w+2])==1){
				M=values[5];
			}else{
				M=values[2];
			}
		}else{
			M.x=0x0;
			M.y=0x0;
		}
		point_double(P.x, P.y);
		vec tmp_y;
		if(Qu==0 &	Qv == 0){
			point_double(P.x, P.y);
			if(v[2*w+2]==1){
				bf_add(tmp_y, M.x, M.y);	
				point_add(P.x, P.y, M.x, tmp_y);
			}else{
				point_add(P.x, P.y, M.x, M.y);
			}
		}else if(Qu==0 & Qv == 1){
			point_double(P.x, P.y);
			if(v[2*w+2]==1){
				bf_add(tmp_y, S.x, S.y);	
				point_add(P.x, P.y, S.x, tmp_y);
			}else{
				point_add(P.x, P.y, S.x, S.y);
			}
		}else if(Qu==0 &	Qv == 2){
			if(v[2*w+2]==1){
				bf_add(tmp_y, S.x, S.y);	
				point_add(P.x, P.y, S.x, tmp_y);
			}else{
				point_add(P.x, P.y, S.x, S.y);
			}
			point_double(P.x, P.y);
		}else if(Qu==1 &	Qv == 0){
			point_double(P.x, P.y);
			if(u[2*w+2]==1){
				bf_add(tmp_y, R.x, R.y);	
				point_add(P.x, P.y, R.x, tmp_y);
			}else{
				point_add(P.x, P.y, R.x, R.y);
			}
		}else if((Qu==1 &	Qv == 1) || (Qu==1 &	Qv == 2)){
			point_double(P.x, P.y);
			if(u[2*w+2]==1){
				bf_add(tmp_y, M.x, M.y);	
				point_add(P.x, P.y, M.x, tmp_y);
			}else{
				point_add(P.x, P.y, M.x, M.y);
			}
		}else if(Qu==2 & Qv == 0){
			if(u[2*w+2]==1){
				bf_add(tmp_y, R.x, R.y);	
				point_add(P.x, P.y, R.x, tmp_y);
			}else{
				point_add(P.x, P.y, R.x, R.y);
			}
			point_double(P.x, P.y);
		}else if(Qu==2 & Qv == 1){
			point_double(P.x, P.y);
			if(u[2*w+2]==1){
				bf_add(tmp_y, M.x, M.y);	
				point_add(P.x, P.y, M.x, tmp_y);
			}else{
				point_add(P.x, P.y, M.x, M.y);
			}
		}else if(Qu==2 &	Qv == 2){
			if(u[2*w+2]==1){
				bf_add(tmp_y, M.x, M.y);	
				point_add(P.x, P.y, M.x, tmp_y);
			}else{
				point_add(P.x, P.y, M.x, M.y);
			}
			point_double(P.x, P.y);
		}
 	}
}

void Qi_parameter(ap_int<w+1> &Qi, short &Q){
    int n;
	Q=n=0;
    Q = Qi[0] + Qi[1] - (Qi[2] * (1 << 1));
    while ((Q % 2) == 0 & Q!=0) {
        Q /= 2;
        n++;
    }
	Q = Q*pow(2,n);
}


void generate_points(Point* values, Point &R, Point &S) {
	Point temp;
	// R+S
	temp = R;
	point_add(temp.x, temp.y, S.x, S.y);
    values[0] = temp;
    //R+2S
    temp=S;
    point_double(temp.x, temp.y);
    point_add(temp.x, temp.y, R.x, R.y);
    values[1]=temp;
	//2R+S
	temp=R;
	point_double(temp.x, temp.y);
	point_add(temp.x, temp.y, S.x, S.y);
	values[2]=temp;
	//R-S
	temp=S;
	bf_add(temp.y, temp.x, temp.y);
	point_add(temp.x, temp.y, R.x, R.y);
	values[3]=temp;
	//R-2S
	temp = S;
	point_double(temp.x, temp.y);
	bf_add(temp.y, temp.y, temp.x);
	point_add(temp.x, temp.y, R.x, R.y);
	values[4]=temp;
	//2R -S
	temp=R;
	point_double(temp.x, temp.y);
	vec temp_y = S.y;
	bf_add(temp_y, temp_y, S.x);
	point_add(temp.x, temp.y, S.x, temp_y);
	values[5]=temp;
}
