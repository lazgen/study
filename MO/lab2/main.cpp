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
    return a > b ? (b > c ? c : b) : a > c ? c : a;
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

void bisectionSearch(double a, double b, double e) //DOTO
{
    unsigned int counter = 0;
    unsigned int fcounter = 0;

    std::pair left(a, getF(a)); fcounter++;
    std::pair right(b, getF(b)); fcounter++;

    double D = right.x - left.x;


//    double left = a;
//    double right = b;
//    double leftY = getF(left); fcounter++;
//    double rightY = getF(right); fcounter++;
//    double interval = right - left;

//    double xMin, min, x3, x4, x5, y3, y4, y5;

//    while(interval > e)
//    {
//        x3 = (left + right) * 0.5;

//        x4 = (left + x3) * 0.5;
//        x5 = right - x3 * 0.5;

//        y3 = getF(x3); fcounter++;
//        y4 = getF(x4); fcounter++;
//        y5 = getF(x5); fcounter++;

//        double m = myMin(y3,y4,y5);

//        if (m == y3) {
//            min = y3;
//            xMin = x3;
//            left = x4;
//            leftY = y4;
//            right = x5;
//            rightY = x5;
//        }
//        else if (m == y4) {
//            min = y4;
//            xMin = x4;
//            left = left;
//            right = x3;
//            rightY = y3;
//        }
//        else if (m == y5) {
//            min = y5;
//            xMin = x5;
//            left = x3;
//            leftY = y3;
//            right = right;
//        }

//        interval = right - left;
//        counter++;
//    }

    printResult("Bisection Search", counter, fcounter, xMin, min);
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
