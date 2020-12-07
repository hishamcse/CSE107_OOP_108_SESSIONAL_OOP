#include <iostream>
using namespace std;

template <class T,int n=3>
T multiply (T a)
{
  return a*n;
}

int main () {
  int i=5, j=6;
  double f=2.3, g=0.5;
  cout << multiply<int>(i) << '\n';
  cout << multiply<double,4>(f) << '\n';
  return 0;
}

