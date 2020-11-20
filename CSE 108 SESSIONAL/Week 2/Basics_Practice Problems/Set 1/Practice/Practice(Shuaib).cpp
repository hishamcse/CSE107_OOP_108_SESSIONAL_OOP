#include<iostream>
using namespace std;
class Fraction
{
public:
    double numerator;
    double denominator;
    Fraction()
    {
        numerator=0;
        denominator=1;
    }
    Fraction(double x, double y)
    {
        numerator=x;
        denominator=y;
    }
    double getNumerator(){return numerator;}
    double getDenominator(){return denominator;}
    double getVal(){return numerator/denominator;}
    void setNumerator(double x){numerator=x;}
    void setDenominator(double y){denominator=y;}
    void printFraction()
    {
        cout<<numerator<<'/'<<denominator<<endl;
    }
    Fraction addFraction(Fraction a)
    {
        double num_result=numerator*a.denominator+denominator*a.numerator;
        double den_result=denominator*a.denominator;
        return Fraction(num_result, den_result);
    }
    Fraction subtractFraction(Fraction a)
    {
        double num_result=numerator*a.denominator-denominator*a.numerator;
        double den_result=denominator*a.denominator;
        return Fraction(num_result, den_result);
    }
    Fraction mulFraction(Fraction a)
    {
        double num_result=numerator*a.numerator;
        double den_result=denominator*a.denominator;
        return Fraction(num_result, den_result);
    }
    Fraction divFraction(Fraction a)
    {
        double num_result=numerator*a.denominator;
        double den_result=denominator*a.numerator;
        return Fraction(num_result, den_result);
    }
    Fraction divFraction(int n)
    {
        if(!n)
        {
            cout<<"Division by zero illegal"<<endl;
            return *this;
        }
        else return Fraction(numerator, denominator*n);
    }

};
class Point
{
    Fraction x;
    Fraction y;
public:
    Point(){}
    Point(Fraction x, Fraction y)
    {
        this->x=x;
        this->y=y;
    }
    Fraction &getx(){return x;}
    Fraction &gety() {return y;}
    Fraction setx(Fraction x) {this->x=x;}
    Fraction sety(Fraction y) {this->y=y;}

};
class Line
{
public:
    Point start;
    Point end;
    Line(Point start, Point end){this->start=start;this->end=end;}

    Point midPoint()
    {
        Point mid;
        mid.setx(start.getx().addFraction(end.getx()).divFraction(2));
        mid.sety(start.gety().addFraction(end.gety()).divFraction(2));
        return mid;
    }
    int contains(Point p)
    {
        double slope1_num=p.gety().getVal()-start.gety().getVal();
        double slope1_den=p.getx().getVal()-start.getx().getVal();
        double slope2_num=p.gety().getVal()-end.gety().getVal();
        double slope2_den=p.getx().getVal()-end.getx().getVal();
        double slope1=slope1_num/slope1_den;
        double slope2=slope2_num/slope2_den;
        return slope1==slope2;
    }
    Point intersection(Line l)
    {
        Fraction a=end.gety().subtractFraction(start.gety());
        Fraction b=start.getx().subtractFraction(end.getx());
        Fraction c1=start.gety().mulFraction(end.getx());
        Fraction c2=end.gety().mulFraction(start.getx());
        Fraction c=c1.subtractFraction(c2);

        Fraction d=l.end.gety().subtractFraction(l.start.gety());
        Fraction e=l.start.getx().subtractFraction(l.end.getx());
        Fraction f1=l.start.gety().mulFraction(l.end.getx());
        Fraction f2=l.end.gety().mulFraction(l.start.getx());
        Fraction f=f1.subtractFraction(f2);

        Fraction x_num=b.mulFraction(f).subtractFraction(e.mulFraction(c));
        Fraction x_den=a.mulFraction(e).subtractFraction(b.mulFraction(d));
        Fraction y_num=c.mulFraction(d).subtractFraction(a.mulFraction(f));
        Fraction y_den=a.mulFraction(e).subtractFraction(b.mulFraction(d));
        Fraction x=x_num.divFraction(x_den);
        Fraction y=y_num.divFraction(y_den);
        x_den.printFraction();
        return Point(x,y);
    }

};

int main()
{
    Fraction x1(3,2), y1(1,2);
    Fraction x2(15,2), y2(13,2);
    Fraction x3(11,2), y3(1,3);
    Fraction x4(1,2), y4(5,2);
    Point start1(x1,y1),end1(x2,y2);
    Point start2(x3,y3), end2(x4,y4);
    Line line1(start1,end1);
    Line line2(start2,end2);
    Point n=line1.intersection(line2);
    n.getx().printFraction();
    n.gety().printFraction();
}
