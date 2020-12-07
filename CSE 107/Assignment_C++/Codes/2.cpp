#include<iostream>
using namespace std;

float area (float a)
{
    return 3.14*a*a;
}

float area (float a, float b)
{
    return a*b;
}

int main ()
{
     cout<< area (4) <<endl;
     cout<< area (3.2, 5.4) <<endl;
}

