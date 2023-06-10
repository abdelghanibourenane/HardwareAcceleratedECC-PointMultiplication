#ifndef DPM_HPP
#define DPM_HPP
#include"gf2_arithmetic.hpp"
const int Nz = 2;
const int w = 2;
struct Point{
	vec x;
	vec y;
};
extern Point values[6];
void Radix2wDPM(vec &k1, vec &k2, Point &R, Point &S, Point &P);
void Qi_parameter(ap_int<w+1> &Qi, short &Q);
void generate_points(Point* values, Point &R, Point &S);
#endif
