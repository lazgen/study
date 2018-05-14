#include <iostream>
#include <math.h>

using namespace std;

unsigned long long int yearsToMinutes(unsigned int years)
{
    return years * 365 * 24 * 60 * 60;
}

long double secondsToYears(unsigned long long int seconds)
{
    return seconds / (60 * 60 * 24 * 365);
}

void task1()
{
    unsigned int n = 52;
    unsigned int k = 6;
    unsigned int s = 30;
    unsigned int m = 5;
    unsigned int v = 10;

    cout << "Task 1" << endl;
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    cout << "s = " << s << endl;
    cout << "m = " << m << endl;
    cout << "v = " << v << endl << endl;

    unsigned long long int C = static_cast<unsigned long long int>(pow(n,k));
    cout << "Variants (C) = " << C << endl;

    unsigned long long int t = C / s;
    cout << "Bruteforce time (t) = " << t  << " s" << endl;

    unsigned long long int T = t * v / m;
    cout << "Bruteforce time (T) with timeout = " << T << " s" << endl;

    unsigned long long int Total = t + T;
    cout << "Total time = " << Total << " s = " << secondsToYears(Total) << " years" << endl;

}

void task2()
{
    unsigned int t = 60;
    unsigned int s = 30;
    unsigned int n = 52;

    cout << endl << "Task 2" << endl;
    cout << "n = " << n << endl;
    cout << "t = " << t << endl;
    cout << "s = " << s << endl << endl;

    unsigned long long int C = yearsToMinutes(t) * s;
    cout << "Variants (C) = " << C << endl;

    long double k = log(C)/log(n);
    cout << "Password length = " << k << endl;
}

void task3()
{
    unsigned int k = 10;
    unsigned int t = 60;
    unsigned int s = 30;

    cout << endl << "Task 3" << endl;
    cout << "k = " << k << endl;
    cout << "t = " << t << endl;
    cout << "s = " << s << endl << endl;

    unsigned long long int C = yearsToMinutes(t) * s;
    cout << "Variants (C) = " << C << endl;

    long double n = pow(C, 1.0/k);
    cout << "Password alphabet = " << n << endl;

}

int main()
{
    task1();
    task2();
    task3();
    return 0;
}
