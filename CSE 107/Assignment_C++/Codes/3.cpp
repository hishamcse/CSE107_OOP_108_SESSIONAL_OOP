#include <iostream>
#include <cmath>
using namespace std;

double areaTri(double a, double b = 1, double c = 1)
{
    double p, s;
    if ((a+b)<c || (b+c)<a || (a+c)<b)
        return 0;
    p = (a + b + c)/2.0;
    s = sqrt(p * (p-a) * (p-b) * (p-c));
    return s;
}

int main()
{
    cout<<areaTri(1.5)<<endl;
    cout<<areaTri(1.5, 1.5)<<endl;
    cout<<areaTri(2, 2, 2)<<endl;
}
