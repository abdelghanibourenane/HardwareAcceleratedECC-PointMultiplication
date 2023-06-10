#include"dpm.hpp"
#include"gf2_arithmetic.hpp"
int main(){
	Point R,S,P;
	R.x=base_x;
	R.y= base_y;
	S.x= base_x;
	S.y = base_y;
	vec u =0x2;
	vec v = 0x2;
	Radix2wDPM(u,v,R,S,P);
	cout<<endl<<hex<<P.x<<endl<<P.y<<endl;


	return 0;
}
