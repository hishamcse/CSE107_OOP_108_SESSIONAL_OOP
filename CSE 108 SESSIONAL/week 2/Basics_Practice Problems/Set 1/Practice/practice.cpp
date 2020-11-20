//operator overloading needed for this problem
#include<iostream>
using namespace std;
class fraction
{
public:
    int numerator;
    int denumerator;
    void printfraction(int n,int d)
    {
        cout<<n<<"/"<<d<<endl;
    }
    fraction sum(fraction a)
    {
        fraction b;
        b.numerator=numerator*a.denumerator+a.numerator*denumerator;
        b.denumerator=denumerator*a.denumerator;
        return b;
    }
    fraction div(int a)
    {
        fraction c;
        c.numerator=numerator;
        c.denumerator=denumerator*a;
        return c;
    }
};
class point
{
public:
    fraction x;
    fraction y;

};
class line
{
    public:
    point start;
    point end;
    point midpoint()
    {
        point m;
        m.x=start.x.sum(end.x);
        m.x=m.x.div(2);
        m.y=start.y.sum(end.y);
        m.y=m.y.div(2);
        return m;
    }
    int contains(point p)
    {
        if((start.x*(p.y-end.y)+start.y*(end.x-p.x)+(p.x*end.y-end.x*p.y))==0)//seperate function needed for subtraction and multiplication.very much complicated
        {
            return 1;
        }
        else{return 0;}
    }

};
int main()
{
    line s;
    s.start.x.numerator=3;
    s.start.x.denumerator=5;
    s.start.y.numerator=5;
    s.start.y.denumerator=10;
    s.end.x.numerator=6;
    s.end.x.denumerator=4;
    s.end.y.numerator=1;
    s.end.y.denumerator=3;
    point t=s.midpoint();
    t.x.printfraction(t.x.numerator,t.x.denumerator);
    t.y.printfraction(t.y.numerator,t.y.denumerator);
    int k=s.contains(t);
    if(k==1){cout<<"this is on"<<endl;}
    else{cout<<"not on"<<endl;}
}
