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

void vec_swap(vec &x, vec &y);
uint16_t vec_degree(const vec &x);
void bf_add(vec &z, const vec &x, const vec &y);
void bf_mult(vec &z, const vec &x, const vec &y);
void bf_inv(vec &z,const vec &x);
void point_double(vec &x, vec &y);
void point_add(vec &x1, vec &y1, const vec &x2, const vec &y2);
#endif
