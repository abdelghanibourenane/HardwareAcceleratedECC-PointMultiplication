/******************************************************************************

  File: module.cpp
  Author: Abdelghani Bourenane
  Date: April 22, 2023

  Description: This file contains the HLS code for the Radix2wECC Scalar Multiplication  module.


******************************************************************************/
#ifndef MODULE_HPP
#define MODULE_HPP
#include <iostream>
#include <cmath>
#include "ap_int.h"
#include <bitset>
#include<string.h>
#include<stdio.h>
#include "gf2_arithmetic.hpp"
const int Nz = 2;
const int w = 5;

struct Point{
	vec x;
	vec y;
};
extern Point values[1 << (w - 2)];

void Radix2wECC(volatile unsigned int *k, volatile unsigned int *x_o, volatile unsigned int *y_o);
void m_n_parameters(ap_int<w+1> slice, int& m, int& n) ;
//ap_int<l+1+Nz> radix_format(ap_int<l> value);
void generate_points(Point* values, vec b, vec c);
#endif
