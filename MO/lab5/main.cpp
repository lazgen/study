/*!
    Optimization Methods.
    lab 5
    8BM71
    Ibetullov Yuriy
    3 var
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

static int  funcCounter = 0,
            gradDesCounter = 0,
            derivative1Counter = 0;

void print(const char* method, double ymin, vector<double> x, int i)
{
    cout.width(18); cout << method;
    cout.width(15); cout.precision(12); cout << x[0];
    cout.width(15); cout.precision(12); cout << x[1];
    cout.width(20); cout.precision(12); cout << ymin;
    cout.width(10); cout << i;
    cout.width(10); cout << gradDesCounter;
    cout.width(10); cout << funcCounter;
    cout.width(10); cout << derivative1Counter ;
    cout << endl;
}

double norma(vector<double> vector)
{
    double result = 0.0;
    for (double value : vector)
        result += value * value;

    return sqrt(result);
}

// f(x1, x2)
double sourceFunc(double x1, double x2)
{
    funcCounter++;
    return x1 * x1 + 9 * x2 * x2 - 12 * x1 - 36 * x2;
}

// g(x1,x2)
vector<double> limitsFactor(double x1, double x2)
{
    return vector<double>
    {
        -(x1 + 1),
        (x1 - 4),
        -(x2 -1),
        (x2 - 2)
    };
}

///Метод штрафных функций
// G(x1, x2)
vector<double> penaltyFunction(double x1, double x2)
{
    vector<double> limits = limitsFactor(x1, x2);
    return vector<double> {
        1 / -limits[0],
        1 / -limits[1],
        1 / -limits[2],
        1 / -limits[3],
    };
}

double limitedPenaltyFunction(double x1, double x2, double r)
{
    vector<double> penalty = penaltyFunction(x1, x2);
    return sourceFunc(x1, x2) + r * (penalty[0] + penalty[1] + penalty[2] + penalty[3]);
}

// dQ/dx1
double limitedPenaltyFunctionDerivative1X1(double x1, double x2, double r)
{
    derivative1Counter++;
    return 2.0 * x1 - 12.0 + r * (-1.0/((x1 + 1.0)*(x1 + 1.0)) + 1.0/((x1 - 4.0)*(x1 - 4.0)));
}

// dQ/dx2
double limitedPenaltyFunctionDerivative1X2(double x1, double x2, double r)
{
    derivative1Counter++;
    return 18.0 * x2 - 36.0 + r * (-1.0/pow(x2-1.0,2) + 1.0/pow(x2 - 2.0,2));
}

vector<double> penaltyGradient(double x1, double x2, double r)
{
    return vector<double> {
        limitedPenaltyFunctionDerivative1X1(x1,x2,r),
        limitedPenaltyFunctionDerivative1X2(x1,x2,r)
    };
}


vector<double> penaltyNextXVector(const vector<double> &current, const vector<double> &gradient, double lambda)
{
    return vector<double> {
                current[0] - lambda * gradient[0],
                current[1] - lambda * gradient[1],
    };
}


vector<double> gradientDescentMethod(const vector<double> &xVector, double e, double r)
{
    double lambda = 0.001;
    vector<double> next = xVector;
    vector<double> gradient = penaltyGradient(next[0], next[1], r);
    do {
        gradDesCounter++;
        next = penaltyNextXVector(next, gradient, lambda);
        gradient = penaltyGradient(next[0], next[1], r);
    } while (norma(gradient) + e * 0.5 >= e);
    return next;
}

void barrierFunctions(double e)
{
    derivative1Counter = 0;
    funcCounter = 0;
    gradDesCounter = 0;

    int iteration = 0;
    double r = 1;

    vector<double> xVector {0, 0};
    vector<double> xMinVector;
    while(iteration <= 10000)
    {
        xMinVector = gradientDescentMethod(xVector, e, r);

        iteration++;
        vector<double> limits = limitsFactor(xMinVector[0], xMinVector[1]);

        if (limits[0] <= 0  &&  limits[1] <= 0 && limits[2] <= 0 && limits[3] <= 0)
            break;

        xVector = xMinVector;
        r /= 100;
    }

    double yMin = sourceFunc(xMinVector[0], xMinVector[1]);
    print("Barrier functions", yMin, xMinVector, iteration);

}


///Метод факторов

//срезка
double cutout(double value)
{
    return value >= 0 ? value : 0;
}

double limitedFunctionFactor(double x1, double x2, double r, const vector<double> &sigma)
{
    vector<double> limits = limitsFactor(x1,x2);
    return sourceFunc(x1, x2) + r * (cutout(limits[0] + sigma[0]) * (cutout(limits[0] + sigma[0])) - sigma[0] * sigma[0] +
                                    cutout(limits[1] + sigma[1]) * (cutout(limits[1] + sigma[1])) - sigma[1] * sigma[1] +
                                    cutout(limits[2] + sigma[2]) * (cutout(limits[2] + sigma[2])) - sigma[2] * sigma[2] +
                                    cutout(limits[3] + sigma[3]) * (cutout(limits[3] + sigma[3])) - sigma[3] * sigma[3]);
}

double limitedFunctionFactorderivativeX1(double x1, double x2, double r, const vector<double> &sigma)
{
    derivative1Counter++;
    vector<double> limits = limitsFactor(x1,x2);
    return 2 * x1 - 12 + r * ((-2) * (cutout(limits[0] + sigma[0])) + 2 * (cutout(limits[1] + sigma[1])));
}

double limitedFunctionFactorderivativeX2(double x1, double x2, double r, const vector<double> &sigma)
{
    derivative1Counter++;
    vector<double> limits = limitsFactor(x1,x2);
    return 18 * x2 - 36 + r * ((-2) * (cutout(limits[2] + sigma[2])) + 2 * (cutout(limits[3] + sigma[3])));
}

vector<double> grad(double x1, double x2, double r, const vector<double> &sigma)
{
    return vector<double> {
                limitedFunctionFactorderivativeX1(x1, x2, r, sigma),
                limitedFunctionFactorderivativeX2(x1, x2, r, sigma)
    };
}

vector<double> gradientDescentFactor(const vector<double> &xVector, double e, double r, const vector<double> &sigma)
{
    double lambda = 0.01;
    vector<double> result = xVector;
    vector<double> gradient;
    gradient = grad(result[0], result[1], r, sigma);
    while (norma(gradient) > e) {
        gradDesCounter++;
        result = penaltyNextXVector(result, gradient, lambda);
        gradient = grad(result[0], result[1], r, sigma);
    }

    return result;
}

void FactorsMethod(double e)
{
    derivative1Counter = 0;
    funcCounter = 0;
    gradDesCounter = 0;

    int it = 0;
    double r = 1;

    vector<double> xVector {1, 1};
    vector<double> xMinVector;
    vector<double> sigma {0, 0, 0, 0};
    vector<double> sigmaPrev;

    while(true)
    {
        xMinVector = gradientDescentFactor(xVector, e, r, sigma);
        it++;
        sigmaPrev = sigma;

        vector<double> limits = limitsFactor(xMinVector[0], xMinVector[1]);

        sigma[0] = cutout(limits[0] + sigma[0]);
        sigma[1] = cutout(limits[1] + sigma[1]);
        sigma[2] = cutout(limits[2] + sigma[2]);
        sigma[3] = cutout(limits[3] + sigma[3]);

        if (abs(sigmaPrev[0] - sigma[0]) < e ||
            abs(sigmaPrev[1] - sigma[1]) < e ||
            abs(sigmaPrev[2] - sigma[2]) < e ||
            abs(sigmaPrev[3] - sigma[3]) < e)
            break;

        xVector = xMinVector;
    }

    print("Factors Method", sourceFunc(xMinVector[0], xMinVector[1]), xMinVector, it);
}

int main()
{
    double  e = 0.0001;

    cout << endl;
    cout.width(18); cout << "Method";
    cout.width(15); cout << "min X1";
    cout.width(15); cout << "min X2";
    cout.width(20); cout << "min Y";
    cout.width(10); cout << "Iter";
    cout.width(10); cout << "Iter2";
    cout.width(10); cout << "f(x) N";
    cout.width(10); cout << "f'(x) N" << endl;

    barrierFunctions(e);
    FactorsMethod(e);

    return 0;
}
