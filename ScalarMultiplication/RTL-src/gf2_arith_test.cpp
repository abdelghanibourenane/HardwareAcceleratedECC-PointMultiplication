#include"gf2_arithmetic.hpp"
#include"module.hpp"

int main()
{   cout<<"-------------------------------------------------------------"<<endl;
	cout<<endl;
	unsigned int a[6] = {0x0FFF8000, 0xF0003E00, 0xE0001FFF, 0xFFF00FFF, 0x0FFE0FFF, 0x00000002 };
	unsigned int k[6] = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	unsigned int c[6] = {0xCCDAA3D9, 0x0536D538, 0x321F2E80, 0x5D38FF58, 0x89070FB0, 0x00000002 };                        //2
	unsigned int b[6] = {0x5c94eee8, 0xde4e6d5e, 0xaa07d793, 0x7bbc11ac, 0xfe13c053, 0x00000002};
	Radix2wECC(a,b,c);
	cout<<hex<<b[5]<<b[4]<<b[3]<<b[2]<<b[1]<<b[0]<<endl;
	cout<<hex<<c[5]<<c[4]<<c[3]<<c[2]<<c[1]<<c[0]<<endl;
	/*vec a = base_x;
    vec b =base_y;
	vec x2= (vec)0x2ccdaa3d9<<128 | (vec)0x0536d538321f2e80<<64 | (vec)0x5d38ff5889070fb0;
	vec y2= (vec)0x25c94eee8<<128 | (vec)0xde4e6d5eaa07d793<<64 | (vec)0x7bbc11acfe13c053;
	vec c;
	for(int i=0;i<20;i++){
		c=i;
		Radix2wECC(c,a,b);
		cout<<endl<<"k = "<<dec<<c<<endl;
		cout<<"x = "<<hex<<a<<endl;
		cout<<"y = "<<hex<<b<<endl<<endl;
	}
	c= (vec)0x018EBBB95EED0E13;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	c= (vec)0x00159D893D4CDD74<<64 | (vec)0x7246CDCA43590E13;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	cout<<"------------------"<<endl;
	c= (vec)301430391<<128| (vec)93010823634716769740<<64 | (vec)8142323349532409856;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	cout<<"------------------"<<endl;
	c= (vec) 0x1C00004000000038<<64 | (vec)0x03FFFFFFCFFFFFE0;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	c= (vec) 0xFF<<128 | (vec)0xF030001F0000FFFF<<64 | (vec)0xF000003800000000;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	c = (vec) 0x7FFF04<<128 | (vec)0x00000FF8000FFFFF<<64 | (vec)0xFF80007FFFFFFFFF;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	c = (vec) 0x400000000<<128 | (vec)0x0000000000020108<<64 | (vec)0xA2E0CC0D99F8A5DB;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;

	c = (vec) 0x400000000<<128 | (vec)0x0000000000020108<<64 | (vec)0xA2E0CC0D99F8A5DC;
	Radix2wECC(c,a,b);
	cout<<endl<<"k = "<<dec<<c<<endl;
	cout<<"x = "<<hex<<a<<endl;
	cout<<"y = "<<hex<<b<<endl<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	*/
	return 0;
}
