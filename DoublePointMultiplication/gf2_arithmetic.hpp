/******************************************************************************

  File: module.cpp
  Author: Abdelghani Bourenane
  Date: April 22, 2023

  Description: This file contains the HLS code for the binary field arithmetic.


******************************************************************************/

#ifndef GF2_ARITHMETIC_HPP
#define GF2_ARITHMETIC_HPP
#include <iostream>
#include <cmath>
#include <bitset>
#include "ap_int.h"

using namespace std;

#define coeff_a  1
#define cofactor 2

#define l 163
#define MARGIN 3
#define VECTOR_NBITS (l + MARGIN)


typedef ap_int<VECTOR_NBITS> vec;
const vec coeff_b = 0x1;
const vec polynomial = (vec)0x800000000 << 128 | (vec)0x0000000000000000 << 64 | (vec)0x00000000000000c9;
const vec base_x = [](){
    vec base_x_temp;
    base_x_temp.range(63,   0) = 0xDE4E6D5E5C94EEE8;  //289070FB05D38FF58321F2E800536D538CCDAA3D9
    base_x_temp.range(127, 64) = 0x7BBC11ACAA07D793;
    base_x_temp.range(VECTOR_NBITS-1, 128) = 0x2FE13C053;
    return base_x_temp;
}();

const vec base_y = [](){
    vec base_y_temp;
    base_y_temp.range(63,   0) = 0x0536d538ccdaa3d9;  //289070FB05D38FF58321F2E800536D538CCDAA3D9
    base_y_temp.range(127, 64) = 0x5d38ff58321f2e80;
    base_y_temp.range(VECTOR_NBITS-1, 128) = 0x289070fb0;
    return base_y_temp;
}();

const vec base_order = (vec)0x0400000000 << 128 | (vec)0x0000000000020108 << 64| (vec)0xa2e0cc0d99f8a5ef;

void vec_swap(vec &x, vec &y);
uint16_t vec_degree(const vec &x);
void bf_add(vec &z, const vec &x, const vec &y);
void bf_mult(vec &z, const vec &x, const vec &y);
void bf_inv(vec &z,const vec &x);
void point_double(vec &x, vec &y);
void point_add(vec &x1, vec &y1, const vec &x2, const vec &y2);
#endif
