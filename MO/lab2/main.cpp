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
typedef pair<double, double> POINT;

int fcounter = 0;

double getF(double x)
{
    fcounter++;
    return sqrt(1 + x*x) + pow(M_E,-2*x);
}

double myMin(double a, double b, double c)
{
    return a > b ? b > c ? c : b : a > c ? c : a;
}

void printResult(char* method, int N, int It, double xMin, double y)
{
    printf ("%-25s %-10i %-10i %-10f %-10f\n", method, N, It, xMin, y);
}

void generalSearch(double a, double b, double e)
{
    fcounter = 0;
    POINT min(-1.0,1000.0);
    for (double i = a; i < b + e / 2; i+= e)
    {
        double y = getF(i);

        if (y < min.second)
        {
            min.second = y;
            min.first = i;
        }
    }

    printResult(__FUNCTION__, fcounter-1, fcounter, min.first, min.second);
}

void bisectionSearch(double a, double b, double e)
{
    unsigned int counter = 0;
    fcounter = 0;

    POINT left(a, getF(a));
    POINT right(b, getF(b));

    double D = right.first - left.first;
    POINT central;
    central.first = (right.first + left.first) * 0.5;
    central.second = getF(central.first);

    while (abs(D) > e)
    {
        POINT leftIntervalCenter;
        POINT rightIntervalCenter;
        leftIntervalCenter.first = (central.first + left.first) * 0.5;
        rightIntervalCenter.first = (right.first + central.first) * 0.5;
        leftIntervalCenter.second = getF(leftIntervalCenter.first);
        rightIntervalCenter.second = getF(rightIntervalCenter.first);

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

    printResult(__FUNCTION__, counter, fcounter, central.first, central.second);
}

void goldenSectionSearch(double a, double b, double e)
{
    unsigned int counter = 0;
    fcounter = 0;
    double fi = 1 / ((sqrt(5) + 1) * 0.5);

    POINT left(a, getF(a));
    POINT right(b, getF(b));
    POINT p3, p4, min;

    p3.first = right.first - fi * (right.first - left.first);
    p3.second = getF(p3.first);
    p4.first = left.first + fi * (right.first - left.first);
    p4.second = getF(p4.first);

    while (abs(right.first - left.first) > e)
    {
        if(p3.second < p4.second)
        {
            right = p4;
            p4 = p3;
            p3.first = right.first - fi * (right.first - left.first);
            p3.second = getF(p3.first);
            min = p3;
        }
        else
        {
            left = p3;
            p3 = p4;
            p4.first = left.first + fi * (right.first - left.first);
            p4.second = getF(p4.first);
            min = p4;
        }
        counter++;
    }

    if(left.second < min.second)
        min = left;
    else if(right.second < min.second)
        min = right;

    printResult(__FUNCTION__, counter, fcounter, min.first, min.second);
}

int main()
{
    double a = 0.;
    double b = 1.;
    double e = .00001;

    printf ("%-25s %-10s %-10s %-10s %-10s\n\n", "Method", "It", "N", "xMin", "f(xMin)");

    generalSearch(a,b,e);
    bisectionSearch(a,b,e);
    goldenSectionSearch(a,b,e);

    return 0;
}
