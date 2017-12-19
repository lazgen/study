/*!
    Optimization Methods.
    lab 4
    8BM71
    Ibetullov Yuriy
    3 var

    min = -1.44283
    x = -0.759225
    y = -0.405325
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

static int  funcCounter = 0,
            derivative1Counter = 0;

void print(const char* method, double ymin, vector<double> x, int i)
{
    cout.width(20); cout << method;
    cout.width(20); cout.precision(12); cout << x[0];
    cout.width(20); cout.precision(12); cout << x[1];
    cout.width(20); cout.precision(12); cout << ymin;
    cout.width(15); cout << i;
    cout.width(10); cout << funcCounter;
    cout.width(10); cout << derivative1Counter ;
    cout << endl;
}

double sourceFunc(double x1, double x2)
{
    funcCounter++;
    return pow(x1, 4) + 2 * pow(x2, 4) + pow(x1, 2) * pow(x2, 2) + 2 * x1 + x2;
}

//double derivative1(double x1, double x2)
//{
//    derivative1Counter++;
//    return 2 * x1 * (2 * x1 * x1 + x2) + 2;
//}

//double derivative2(double x1, double x2)
//{
//    derivative2Counter++;
//    return 2 * (6 * x1 * x1 + x2 * x2);
//}

double derivative1X1(double x1, double x2)
{
    derivative1Counter++;
    return 2 * (2 * x1 * x1 * x1 + x2 * x2 * x1 + 1);
}

double derivative1X2(double x1, double x2)
{
    derivative1Counter++;
    return 2 * x1 * x1 * x2 + 8 * x2 * x2 * x2 + 1;
}

vector<double> grad(double x1, double x2)
{
    return vector<double> {
        derivative1X1(x1, x2),
                derivative1X2(x1, x2)
    };

}

double norma(vector<double> vector)
{
    double result = 0.0;
    for (double value : vector)
        result += value * value;

    return sqrt(result);
}

vector<double> nextXVector(const vector<double> current, double lambda)
{
    vector<double> gradient = grad(current[0], current[1]);
    vector<double> result {
        current[0] - lambda * gradient[0],
                current[1] - lambda * gradient[1],
    };

    return result;
}

void gradientDescentMethod(double x1, double x2, double lambda, double e)
{
    int it = 0;
    vector<double> next { x1, x2 };
    do {
        next = nextXVector(next, lambda);
        it++;
    } while (norma(grad(next[0],next[1])) + e * 0.5 >= e);

    print("Gradient Descent", sourceFunc(next[0],next[1]), next, it);
}

void marquardtMethod(double x1, double x2, double lambda, double e)
{

}

int main()
{
    double  e = 0.00001,
            x1 = -1,
            x2 = 1,
            lambda = 0.01;

    cout << "e = " << e << endl;
    cout << "lambda = " << lambda << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << endl;

    cout.width(16); cout << "Method";
    cout.width(20); cout << "min X1";
    cout.width(20); cout << "min X2";
    cout.width(20); cout << "min Y";
    cout.width(20); cout << "Iterations";
    cout.width(10); cout << "f(x) N";
    cout.width(10); cout << "f'(x) N" << endl;

    gradientDescentMethod(x1,x2,lambda,e);
    marquardtMethod(x1,x2,lambda,e);

    return 0;
}
