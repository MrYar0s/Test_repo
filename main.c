#include "main.h"
//! Print roots of equation
//! @param [in]  Num_Roots
//! @param [in]  x1 The first root
//! @param [in]  x2 The second root
//!
//!
//! in case of infinite number of roots,
//! returns INF_ROOTS.

int main() {
	int num_of_roots = 0;

	unit_test();

	double a, b, c, x1, x2;
	a = b = c = 0;
	x1 = x2 = 0;

	printf("Enter equation coefficients\n");
	int check = scanf("%lg %lg %lg", &a, &b, &c);
	while (check != 3) {
		check = scanf("%lg %lg %lg", &a, &b, &c);
		printf("ERROR: You entered wrong coefficients\n");
        	fflush(stdin);
	}

	if (Compare(a))
	{
		num_of_roots = SolveLineEquation(b, c, &x1);
	}
	else
	{
		num_of_roots = SolveSquareEquation(a, b, c, &x1, &x2);
	}
	assert(isfinite(x1));
	assert(isfinite(x2));


	switch (num_of_roots)
	{
	case 0: printf("No roots\n");
		break;
	case 1: printf("x1=%.3lg\n", x1);
		break;
	case 2: printf("x1=%.3lg ", x1);
		printf("x2=%.3lg\n", x2);
		break;
	case INF_ROOTS: printf("Any number");
		break;
	default: printf("ERROR: number of roots = %d", num_of_roots);
		return 1;
	}
	return 0;
}

int SolveLineEquation(double b, double c, double* x1)
{
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);
	
	if (Compare(b))
	{
		return (Compare(c)) ? INF_ROOTS : 0;
	}
	else
	{
		if (Compare(c))
		{
			*x1 = 0;
			return 1;
		}
		else {
			*x1 = -c / b;
			return 1;
		}
	}
}

int SolveSquareEquation(double a, double b, double c, double* x1, double* x2)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	if (Compare(b))
	{

		if (Compare(c))
		{
			*x1 = 0;
			return 1;
		}
		else
		{
			double u = -c / a;
			if (u > BORDER)
			{
				*x1 = sqrt(u);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		double d = b * b - 4 * a * c;
		double sqrt_d = sqrt(d);
		if (Compare(d))
		{
			*x1 = *x2 = -b / (2 * a);
			return 1;
		}
		else if (d < BORDER)
		{
			return 0;
		}
		else
		{
			*x1 = (-b - sqrt_d) / (2 * a);
			*x2 = (-b + sqrt_d) / (2 * a);
			if (*x1 == -0)
			{
				*x1 = 0;
			}
			if (*x2 == -0)
			{
				*x2 = 0;
			}
			return 2;
		}
	}
}

void unit_test()
{
	FILE* input;
	FILE* res;
	input = fopen("in.TXT", "r");
	res = fopen("res.TXT", "w");

	double a, b, c, x1, x2;

	a = b = c = 0;
	x1 = x2 = 0;
	int num_of_roots = 0;
	while (fscanf(input, "%lg %lg %lg", &a, &b, &c) > 0)
	{
		if (Compare(a))
		{
			num_of_roots = SolveLineEquation(b, c, &x1);
		}
		else
		{
			num_of_roots = SolveSquareEquation(a, b, c, &x1, &x2);
		}

		assert(isfinite(x1));
		assert(isfinite(x2));

		switch (num_of_roots)
		{
		case 0: fprintf(res, "No roots\n");
			break;
		case 1: fprintf(res, "x1=%.3lg\n", x1);
			break;
		case 2: fprintf(res, "x1=%.3lg ", x1);
			fprintf(res, "x2=%.3lg\n", x2);
			break;
		case INF_ROOTS: fprintf(res, "Any number\n");
			break;
		default: fprintf(res, "ERROR: number of roots = %d", num_of_roots);
			break;
		}
	}
	fclose(res);
	fclose(input);
}
int Compare(double p)
{
	if (p >= -BORDER && p <= BORDER)
	{
		return 1;
	}
	return 0;
}
