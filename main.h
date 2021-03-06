#pragma once
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//! A constant denoting that the equation has an infinite number of roots
#define INF_ROOTS -1
//! A constant to help compare a number with zero
#define BORDER 1e-5

//! Solves a square equation ax2+bx+c = 0
//! @param [in]  a    a - coefficient
//! @param [in]  b    b - coefficient
//! @param [in]  c    c - coefficient
//! @param [out] x1   Pointer to the first root
//! @param [out] x2   Pointer to the second root
//!
//! return number of roots
//!
//! in case of infinite number of roots,
//! returns INF_ROOTS.
int SolveSquareEquation(double a, double b, double c, double* x1, double* x2);
//! Solves a line equation bx+c = 0
//! @param [in]  b    b - coefficient
//! @param [in]  c    c - coefficient
//! @param [out] x1   Pointer to the first root
//!
//! return number of roots
//!
//! in case of infinite number of roots,
//! returns INF_ROOTS.
int SolveLineEquation(double b, double c, double* x1);
//! This function checks correct of this program
//!	@param [in] input opens in.TXT
//! @param [out] res opens res.TXT
void unit_test();
//! A function to help compare a number with zero
int Compare(double p);

/*! \file in.TXT
	\brief Text document with a set of numbers to input.

	Example of numbers

	1 0 0					\n
	2.42 13.5 12.6				\n
	-4.12 13.5 -4.5				\n
	1 0 1					\n
	1 1 1					\n
	0 1 1					\n
	0 0 1					\n
	4 4 1					\n
	0 0 0					\n
	0 1 0					\n
	1 1 0					\n
	-19.78 42.15 -23.72			\n
	27.1 -34.01 72.21			\n
	-54.64 -43.32 1.59			\n
	4.01 -47.67 89.76			\n
	-42.09 -120.98 34.38			\n
	71.69 -56.45 88.58			\n
	-59.36 -45.34 4.24			\n
	24.76 73.90 20.87			\n
	-1 0 0					\n
	-1 -1 0					\n
	-1 -1 -1				\n
	0 -1 0					\n
	0 0 -1					\n
	0 -1 -1					\n
	-1 0 -1					\n
		
*/
/*! \file res.TXT
	\brief Text document with a result of program

	Example of numbers

	x1=0				\n
	x1=-4.39 x2=-1.19		\n
	x1=2.9 x2=0.377			\n
	No roots			\n
	No roots			\n
	x1=-1				\n
	No roots			\n
	x1=-0.5				\n
	Any number			\n
	x1=0				\n
	x1=-1 x2=0			\n
	No roots			\n
	No roots			\n
	x1=0.0351 x2=-0.828 		\n
	x1=2.35 x2=9.54			\n
	x1=0.261 x2=-3.13		\n
	No roots			\n
	x1=0.0842 x2=-0.848 		\n
	x1=-2.67 x2=-0.316		\n
	x1=0				\n
	x1=0 x2=-1			\n
	No roots			\n
	x1=0				\n
	No roots			\n
	x1=-1				\n
	No roots			\n
*/
/*! \file out.TXT
	\brief Text document with a correct output

	Example of number

	x1=0				\n
	x1=-4.39 x2=-1.19		\n
	x1=2.9 x2=0.377			\n
	No roots			\n
	No roots			\n
	x1=-1				\n
	No roots			\n
	x1=-0.5				\n
	Any number			\n
	x1=0				\n
	x1=-1 x2=0			\n
	No roots			\n
	No roots			\n
	x1=0.0351 x2=-0.828 		\n
	x1=2.35 x2=9.54			\n
	x1=0.261 x2=-3.13		\n
	No roots			\n
	x1=0.0842 x2=-0.848 		\n
	x1=-2.67 x2=-0.316		\n
	x1=0				\n
	x1=0 x2=-1			\n
	No roots			\n
	x1=0				\n
	No roots			\n
	x1=-1				\n
	No roots			\n
*/
/*! \file main.h
	\brief Description of files

	Include text with description of in.TXT, out.TXT, res.TXT
*/
