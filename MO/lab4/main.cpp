/*!
    Optimization Methods.
    lab 4
    8BM71
    Ibetullov Yuriy
    3 var
*/

#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

static int  funcCounter = 0,
            derivative1Counter = 0,
            derivative2Counter = 0;

void print(const char* method, double xmin, double ymin, int i)
{
    cout.width(20); cout << method;
    cout.width(20); cout.precision(12); cout << xmin;
    cout.width(20); cout.precision(12); cout << ymin;
    cout.width(15); cout << i;
    cout.width(10); cout << funcCounter;
    cout.width(10); cout << derivative1Counter;
    cout.width(10); cout << derivative2Counter;
    cout << endl;
}

double sourceFunc(double x1, double x2)
{
    funcCounter++;
    return pow(x1,4) +2* pow(x2,4) + pow(x1,2) * pow(x2,2) + 2*x1 + x2;
}

double derivative1(double x1, double x2)
{
    derivative1Counter++;
    return 2 * x1 * (2*x1*x1 + x2) + 2;
}

double derivative2(double x1, double x2)
{
    derivative2Counter++;
    return 2 * (6 * x1 * x1 + x2 * x2);
}

int main()
{
    double  e = 0.00001,
            a = 0,
            b = 1,
            h = 0.1,
            xk = (a + b) / 2;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "e = " << e << endl;
    cout << "h = " << h << endl;
    cout << "xk = " << xk << endl;
    cout << endl;

    cout.width(16); cout << "Method";
    cout.width(20); cout << "min X";
    cout.width(20); cout << "min Y";
    cout.width(23); cout << "Iterations";
    cout.width(7); cout << "f(x)";
    cout.width(10); cout << "f'(x)";
    cout.width(10); cout << "f''(x)" << endl;

    return 0;
}
