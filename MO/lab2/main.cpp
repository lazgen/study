/*!
    Optimization Methods.
    lab 2
    8BM71
    Ibetullov Yuriy
    3 var
*/

#include <iostream>
#include <cmath>
using namespace std;

#define M_E 2.71828182845904523536

double getF(double x)
{
    return sqrt(1 + x*x) + pow(M_E,-2*x);
}

double myMin(double a, double b, double c)
{
    return a > b ? b > c ? c : b : a > c ? c : a;
}

void printResult(char* method, int N, int It, double xMin, double y)
{
    static bool f = false;

    if(!f)
    {
        printf ("%-25s %-10s %-10s %-10s %-10s\n\n", "Method", "N", "Iteration", "xMin", "f(xMin)");
        f = true;
    }

    printf ("%-25s %-10i %-10i %-10f %-10f\n", method, N, It, xMin, y);
}

void generalSearch(double a, double b, double e)
{
    int fcounter = 0;
    double min = 10000.0;
    double xMin;
    for (double i = a; i < b + e / 2; i+= e)
    {
        double y = getF(i);

        if (y < min)
        {
            min = y;
            xMin = i;
        }
        fcounter++;
    }

    printResult("General Search", fcounter-1, fcounter, xMin, min);
}

void bisectionSearch(double a, double b, double e)
{
    unsigned int counter = 0;
    unsigned int fcounter = 0;

    pair<double, double> left(a, getF(a)); fcounter++;
    pair<double, double> right(b, getF(b)); fcounter++;

    double D = right.first - left.first;
    pair<double, double> central((right.first + left.first)*0.5,
                                 getF((right.first + left.second)*0.5)); fcounter++;

    while (abs(D) > e)
    {
        pair<double, double> leftIntervalCenter((central.first + left.first) * 0.5,
                                                getF((central.first + left.first) * 0.5)); fcounter++;

        pair<double, double> rightIntervalCenter((right.first + central.first) * 0.5,
                                                getF((right.first + central.first) * 0.5)); fcounter++;

        double m = myMin(leftIntervalCenter.second, central.second, rightIntervalCenter.second);
        if (m == leftIntervalCenter.second)
        {
            right = central;
            central = leftIntervalCenter;
            left = left;
        }
        else if (m == central.second)
        {
            central = central;
            left = leftIntervalCenter;
            right = rightIntervalCenter;
        }
        else if (m == rightIntervalCenter.second)
        {
            left = central;
            central = rightIntervalCenter;
            right = right;
        }

        D = right.first - left.first;
        counter++;
    }

    printResult("Bisection Search", counter, fcounter, central.first, central.second);
}

void goldenSectionSearch(double a, double b, double e)
{
    unsigned int counter = 0;
    unsigned int fcounter = 0;
    double xMin, min;

    printResult("Golden Section Search", counter, fcounter, xMin, min);
}

int main()
{
    double a = 0.;
    double b = 1.;
    double e = .00001;

    generalSearch(a,b,e);
    bisectionSearch(a,b,e);
    goldenSectionSearch(a,b,e);

    return 0;
}
