/*!
    Optimization Methods.
    lab 3
    8BM71
    Ibetullov Yuriy
    3 var
*/

#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

static int  funcCounter = 0,
            firstDerivativeCounter = 0,
            secondDerivativeCounter = 0;

void print(const char* method, double xmin, double ymin, int i)
{
    cout.width(20); cout << method;
    cout.width(20); cout.precision(12); cout << xmin;
    cout.width(20); cout.precision(12); cout << ymin;
    cout.width(15); cout << i;
    cout.width(10); cout << funcCounter;
    cout.width(10); cout << firstDerivativeCounter;
    cout.width(10); cout << secondDerivativeCounter;
    cout << endl;
}

double getF(double x)
{
    funcCounter++;
    return sqrt(1 + x*x) + exp(-2*x);
}

double firstDerivative(double x)
{
    firstDerivativeCounter++;
    return (x / sqrt(1+ x*x)) - 2 * exp(-2 * x);
}

double secondDerivative(double x)
{
    secondDerivativeCounter++;
    return (1 / pow(sqrt(1 + x*x),3)) + 4 * exp(-2 * x);
}

double newtonNextStep(double xk)
{
    return xk - firstDerivative(xk) / secondDerivative(xk);
}

void newtonRaphson(double xk, double e)
{
    funcCounter = 0;
    firstDerivativeCounter = 0;
    secondDerivativeCounter = 0;
    double yk, derYk;
    double xkNext, ykNext, derYkNext;
    double xMin, yMin;
    int iteration = 0;

    do
    {
        xkNext = newtonNextStep(xk);
        ykNext = getF(xkNext);
        yk = getF(xk);
        derYk = firstDerivative(xk);

        if (ykNext > yk && derYk * (xkNext - xk) < 0){
            xkNext = (xkNext + xk) / 2;
            ykNext = getF(xkNext);
        }

        derYkNext = firstDerivative(xkNext);
        iteration++;
        xk = xkNext;
        xMin = xkNext;
        yMin = ykNext;
    } while (abs(derYkNext / ykNext) >= e);

    print("Newton-Raphson", xkNext, ykNext, iteration);
}

double firstDerivativeApprox(double x, double h)
{
    firstDerivativeCounter++;
    return (getF(x + h) - getF(x - h)) / (2 * h);
}

double secondDerivativeApprox(double x, double h)
{
    secondDerivativeCounter++;
    return (getF(x + h) - 2 * getF(x) + getF(x - h)) / (2 * h * h);
}

double quasiNextStep(double xk, double h)
{
    return xk - firstDerivativeApprox(xk, h) / secondDerivativeApprox(xk, h);
}

void quasiNewtonian(double xk, double e, double h)
{
    funcCounter = 0;
    firstDerivativeCounter = 0;
    secondDerivativeCounter = 0;
    double yk, derYk;
    double xkNext, ykNext, derYkNext;
    double xMin, yMin;
    int iteration = 0;

    do
    {
        xkNext = quasiNextStep(xk, h);
        ykNext = getF(xkNext);
        yk = getF(xk);
        derYk = firstDerivativeApprox(xk, h);

        if (ykNext > yk && derYk * (xkNext - xk) < 0){
            xkNext = (xkNext + xk) / 2;
            ykNext = getF(xkNext);
        }

        derYkNext = firstDerivativeApprox(xkNext, h);
        iteration++;
        xk = xkNext;
        xMin = xkNext;
        yMin = ykNext;
    } while (abs(derYkNext / ykNext) >= e);

    print("Quasi-Newtonian", xkNext, ykNext, iteration);
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

    newtonRaphson(xk, e);
    quasiNewtonian(xk, e, h);

    return 0;
}
