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
#include <array>

using namespace std;


template <typename T, int N>
using matrix = std::array<std::array<T,N>,N>;

template <typename T, int N>
matrix<T, N> invert(matrix<T, N> source)
{
    matrix<T, N> unit;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            unit[i][j] = (i == j) ? 1 : 0;

    T temp;

    for (int k = 0; k < N; k++)
    {
        temp = source[k][k];
        for (int j = 0; j < N; j++)
        {
            source[k][j] /= temp;
            unit[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = source[i][k];
            for (int j = 0; j < N; j++)
            {
                source[i][j] -= source[k][j] * temp;
                unit[i][j] -= unit[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = source[i][k];

            for (int j = 0; j < N; j++)
            {
                source[i][j] -= source[k][j] * temp;
                unit[i][j] -= unit[k][j] * temp;
            }
        }
    }

    return unit;
}

static int  funcCounter = 0,
            derivative1Counter = 0,
            derivative2Counter = 0;

void print(const char* method, double ymin, vector<double> x, int i)
{
    cout.width(20); cout << method;
    cout.width(20); cout.precision(12); cout << x[0];
    cout.width(20); cout.precision(12); cout << x[1];
    cout.width(20); cout.precision(12); cout << ymin;
    cout.width(15); cout << i;
    cout.width(10); cout << funcCounter;
    cout.width(10); cout << derivative1Counter ;
    cout.width(10); cout << derivative2Counter ;
    cout << endl;
}

double sourceFunc(double x1, double x2)
{
    funcCounter++;
    return pow(x1, 4) + 2 * pow(x2, 4) + pow(x1, 2) * pow(x2, 2) + 2 * x1 + x2;
}

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

double derivative2X1(double x1, double x2)
{
    derivative2Counter++;
    return 2 * (6 * x1 * x1 + x2 * x2);
}

double derivative2X2(double x1, double x2)
{
    derivative2Counter++;
    return 2 * (x1 * x1 + 12 * x2 * x2);
}

double derivative2X1X2(double x1, double x2)
{
    derivative2Counter++;
    return 4 * x1 * x2;
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

vector<double> nextXVector(const vector<double> &current, double lambda)
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

vector<vector<double>> hesseMatrix(const vector<double> &source)
{
    return vector<vector<double>> {
                                  { derivative2X1(source[0], source[1]), derivative2X1X2(source[0], source[1]) },
                                  { derivative2X1X2(source[0], source[1]), derivative2X2(source[0], source[1]) }
                                  };
}

void marquardtMethod(double x1, double x2, double lambda, double e)
{
    vector<vector<double>> E
    {
        {1,0},
        {0,1},
    };

    matrix<double, 2> temp;
    vector<double> xVector {x1, x2};
    vector<double> sVector(2);
    vector<double> nextXVector(2);
    vector<vector<double>> gessian;
    vector<double> gradient = grad(x1, x2);
    double yMin = sourceFunc(xVector[0], xVector[1]);
    double yk;
    int iteration = 0;

    while (norma(gradient) > e)
    {
        gessian = hesseMatrix(xVector);

        for (unsigned int i = 0; i < gessian.size(); i++)
            for (unsigned int j = 0; j < gessian[i].size(); j++)
                temp[i][j] = gessian[i][j] + lambda * E[i][j];

        temp = invert<double, 2>(temp);

        for (unsigned int i = 0; i < temp.size(); i++)
        {
            sVector[i] = 0;
            for (unsigned int j = 0; j < temp[i].size(); j++)
                sVector[i] += temp[i][j] * -gradient[j];
        }

        for (unsigned int i = 0; i < xVector.size(); i++)
            nextXVector[i] = xVector[i] + sVector[i];

        yk = sourceFunc(nextXVector[0], nextXVector[1]);

        if (yk < yMin)
            lambda /= 2;
        else
            lambda *= 2;

        iteration++;
        xVector = nextXVector;
        yMin = yk;
        gradient = grad(xVector[0], xVector[1]);
    }

    print("Marquardt", yMin, xVector, iteration);
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
    cout.width(10); cout << "f'(x) N";
    cout.width(10); cout << "f''(x) N" << endl;

    gradientDescentMethod(x1,x2,lambda,e);

    funcCounter = 0;
    derivative1Counter = 0;
    derivative2Counter = 0;

    marquardtMethod(x1,x2,10000,e);

    return 0;
}
