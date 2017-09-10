/*!
	Optimization Methods.
	lab 1
	8BM71
	Ibetullov Yuriy
	3 var
*/

#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/*
	i [1, ...], 2

	    (i+1)     i    i
	(-1)      * 2   * x
	--------------------
			i!

*/

double getY(double x, double delta)
{
	double last = 2*x;
	double result = last;

	for (int i = 3; abs(last) > delta ; i+=2)
	{
		last = -1 * last * 2 * 2 * x * x / ((i - 1) * i);
		result += last;
	}

	return result;
}

void print(double x, double y, double z, double w)
{
	cout.width(15); cout.precision(9); cout << x;
	cout.width(15); cout.precision(9); cout << y;
	cout.width(15); cout.precision(9); cout << z;
	cout.width(20); cout.precision(9); cout << w << endl;
}

void calculation(double x0, double xk, double h, double delta)
{
	cout.width(10); cout << "x";
	cout.width(15); cout << "y";
	cout.width(15); cout << "z";
	cout.width(20); cout << "w" << endl;

	int i = 0;
	while (x0 <= xk)
	{
		double y = getY(x0, delta);
		double z = sin(2*x0);
		double w = y - z;

		print(x0, y, z, w);

		x0 += h;
	}
}

int main(int argc, char* argv[])
{
	double x0 = - M_PI / 4;
	double xk = (-1) * x0;
	double h = M_PI / 20;

	cout << "e = 0.001" << endl;
	calculation(x0, xk, h, 0.001);

	cout << endl  << endl << "e = 0.00001" << endl;
	calculation(x0, xk, h, 0.00001);
	
	cout << endl << endl << "e = 0.0000001" << endl;
	calculation(x0, xk, h, 0.0000001);

	system("pause");

	return 0;
}