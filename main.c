﻿#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define INF_ROOTS -1
#define BORDER 1e-20

int SolveEquation(double a, double b, double c, double* x1, double* x2);
int Compare(double p);

/*----------------------------------------------------------------------*/
//! Print roots of equation
//! @param [in]  Num_Roots
//! @param [in]  x1
//! @param [in]  x2
//!
//!
//! in case of infinite number of roots,
//! returns INF_ROOTS.
/*----------------------------------------------------------------------*/

int main() 
{

	double a, b, c, x1, x2;

	a = b = c = 0;
	x1 = x2 = 0;

	printf("Enter equation coefficients\n");
	int check = scanf("%lg %lg %lg", &a, &b, &c);

	if (check != 3) 
	{
		printf("ERROR: You entered wrong coefficients");
		return 0;
	}

	int num_of_roots = SolveEquation(a, b, c, &x1, &x2);

	assert(isfinite(x1));
	assert(isfinite(x2));
	
	Compare(a);
	Compare(b);
	Compare(c);

	switch (num_of_roots)
	{
	case 0: printf("No roots\n");
		break;
	case 1: printf("x1=%lg\n", x1);
		break;
	case 2: printf("x1=%lg ", x1);
		    printf("x2=%lg\n", x2);
		break;
	case INF_ROOTS: printf("Any number");
		break;
	default: printf("ERROR: number of roots = %d", num_of_roots);
		return 1;
	}
	return 0;
}

/*----------------------------------------------------------------------*/
/*function to solve a square equation*/
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
/*----------------------------------------------------------------------*/

int SolveEquation(double a, double b, double c, double* x1, double* x2) 
{

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	if (a == 0) 
	{
		if (b == 0)
		{
			return (c == 0) ? INF_ROOTS : 0;
		}
		else
		{
			if (c != 0)
			{
				*x1 = -c / b;
				return 1;
			}
			else {
				*x1 = 0;
				return 1;
			}
		}
	}
	else
	{
		if (b == 0)
		{
			
			if (c == 0)
			{
				*x1 = 0;
				return 1;
			}
			else
			{
				if (c < 0)
				{
					*x1 = sqrt(-c / a);
					return 1;
				}
				else
				{
					*x1 = 0;
					return 1;
				}

			}

		}
		double d = b * b - 4 * a * c;
		double sqrt_d = sqrt(d);
		Compare(d);
		Compare(sqrt_d);
		if (d == 0) 
		{
			*x1 = *x2 = -b / (2 * a);
			return 1;
		}
		else if (d < 0)
		{
			return 0;
		}
		else
		{
			*x1 = (-b - sqrt_d) / (2 * a);
			*x2 = (-b + sqrt_d) / (2 * a);
			return 2;
		}
	}
}

int Compare(double p) 
{
	if (p >= -BORDER && p <= BORDER) 
	{
		p = 0;
	}
	return 0;
}