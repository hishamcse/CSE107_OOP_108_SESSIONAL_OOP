#include<iostream>
#include<cmath>
using namespace std;

class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; }
	Point2D(int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void print();
	Point2D operator+(Point2D p);
	Point2D operator*(int n);
	bool operator==(Point2D p);
	bool operator!=(Point2D p);

	~Point2D(){ x = 0; y = 0; }
};

Point2D::Point2D(int argx,int argy)
{
	x=argx;
	y=argy;
}

void Point2D::setX(int argx)
{
	x=argx;
}

void Point2D::setY(int argy)
{
	y=argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")"<<endl;
}

Point2D Point2D::operator+(Point2D p)
{
    Point2D q;
    q.x=x+p.x;
    q.y=y+p.y;

    return q;
}
Point2D Point2D::operator*(int n)
{
    Point2D q;
    q.x=x*n;
    q.y=y*n;
    return q;
}
bool Point2D::operator==(Point2D p)
{
    if(this->x==p.getX()&&this->y==p.getY())
    {
        return true;
    }
    return false;
}
bool Point2D::operator!=(Point2D p)
{
    if(this->x!=p.getX()||this->y!=p.getY())
    {
        return true;
    }
    return false;
}
class Circle
{
	Point2D center;
	double radius;
public:
	Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0;
	}
	Circle(Point2D c, double r);
	Point2D getCenter();
	double getRadius();
	void setCenter(Point2D c);
	void setRadius(double radius);
	double area();
	void print();
	Circle operator+(Point2D p);
	Circle operator*(int n);
	Circle operator+(Circle c);;
	Circle operator-(Circle c);
	bool operator==(Circle c);
	bool operator>(Circle c);
	bool operator>=(Circle c);
	bool operator<(Circle c);
	bool operator<=(Circle c);
	Circle operator++();
	Circle operator++(int);
	~Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0;
	}

};

Circle::Circle(Point2D c, double r)
{
	center.setX(c.getX());
	center.setY(c.getY());
	radius=r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
	center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
	return center;
}

double Circle::getRadius()
{
	return radius;
}

double Circle::area()
{
	return 3.14*radius*radius;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius<<endl;;
}

Circle Circle::operator+(Point2D p)
{
    Circle c;
    c.center.setX(center.getX()+p.getX());
    c.center.setY(center.getY()+p.getY());
    c.radius=radius;
    return c;
}
Circle Circle::operator*(int n)
{
	Circle c;
    c.center.setX(center.getX()*n);
    c.center.setY(center.getY()*n);
    c.radius=radius*n;
    return c;

}
Circle Circle::operator+(Circle c)
{
    Circle d;
    int a=(radius)/(radius+c.radius);
    d.center.setX(center.getX()*a+c.center.getX()*(1-a));
    d.center.setY(center.getY()*a+c.center.getY()*(1-a));
    d.radius=radius+c.radius;
    return d;
}
Circle Circle::operator-(Circle c)
{
    Circle d;
    int a=(radius)/(radius+c.radius);
    d.center.setX(center.getX()*a-c.center.getX()*(1-a));
    d.center.setY(center.getY()*a-c.center.getY()*(1-a));
    d.radius=radius-c.radius;
    return d;
}
bool Circle::operator==(Circle c)
{
    if(area()==c.area()){return true;}
    return false;
}
bool Circle::operator>(Circle c)
{
    if(area()>c.area()){return true;}
    return false;
}
bool Circle::operator>=(Circle c)
{
    if(area()>=c.area()){return true;}
    return false;
}
bool Circle::operator<(Circle c)
{
    if(area()<c.area()){return true;}
    return false;
}
bool Circle::operator<=(Circle c)
{
    if(area()<=c.area()){return true;}
    return false;
}
Circle Circle::operator++()
{
	 ++radius;
     return *this;
}
Circle Circle::operator++(int)
{
    radius++;
    return *this;
}
class Rectangle
{
	Point2D trp;
	Point2D blp;
public:
	Rectangle()
	{
	    trp.setX(0);
	    trp.setY(0);
	    blp.setX(0);
	    blp.setY(0);
	}
	Rectangle(Point2D p,Point2D q)
	{
	    trp.setX(p.getX());
	    trp.setY(p.getY());
	    blp.setX(q.getX());
	    blp.setY(q.getY());
	}
	void settrp(Point2D p);
	void setblp(Point2D q);
	Point2D gettrp();
	Point2D getblp();
	Rectangle operator+(Point2D p);
	Rectangle operator*(int n);
	~Rectangle()
	{
	    trp.setX(0);
	    trp.setY(0);
	    blp.setX(0);
	    blp.setY(0);
	}
};
void Rectangle::settrp(Point2D p)
{
    trp.setX(p.getX());
    trp.setY(p.getY());
}
void Rectangle::setblp(Point2D q)
{
    blp.setX(q.getX());
    blp.setY(q.getY());
}
Point2D Rectangle::gettrp()
{
    return trp;
}
Point2D Rectangle::getblp()
{
    return blp;
}
Rectangle Rectangle::operator+(Point2D p)
{
    Rectangle r;
    r.trp.setX(trp.getX()+p.getX());
    r.trp.setY(trp.getY()+p.getY());
    r.blp.setX(blp.getX()+p.getX());
    r.blp.setY(blp.getY()+p.getY());
    return r;
}
Rectangle Rectangle::operator*(int n)
{
    Rectangle r;
    r.trp.setX(trp.getX()*n);
    r.trp.setY(trp.getY()*n);
    r.blp.setX(blp.getX()*n);
    r.blp.setY(blp.getY()*n);
    return r;

}
int main(void)
{
    Point2D p1(2,6),p2(1,7),p3(2,6),p4(1,2);
	Point2D p=p1+p2;
	p.print();
	Point2D m=p1*2;
	m.print();
    bool b=(p1==p3);
    if(b){cout<<"both point equal"<<endl;}
    else{cout<<"point unequal"<<endl;}
    bool c=(p1!=p2);
    if(c){cout<<"both point unequal"<<endl;}
    else{cout<<"both point unequal"<<endl;}


	Circle c1(p1,4.5),c2(p2,3.4);
	Circle k=c1+p3;
	k.print();
	Circle a=c1*2;
	a.print();
	Circle n=c1+c2;
	n.print();
	Circle d=c1-c2;
	d.print();
	if(c1==c2){cout<<"two circles are equal"<<endl;}
	else{cout<<"two circles are not equal"<<endl;}
	if(c1>c2){cout<<"c1 is greater"<<endl;}
	if(c1>=c2){cout<<"c1 is greater or equal"<<endl;}
	if(c1<c2){cout<<"c2 is greater"<<endl;}
	if(c1<=c2){cout<<"c2 is greater or equal"<<endl;}
	(c1++).print();
	(++c1).print();

	Rectangle r1(p1,p2);
	Rectangle f=r1+p3;
	f.gettrp().print();
	f.getblp().print();
	Rectangle z=r1*2;
	z.gettrp().print();
	z.getblp().print();

	return 0;
}
