#include<iostream>
using namespace std;

class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void print();
	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(int argx,int argy)
{
	x = argx;
	y = argy;
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
	cout << "(" << x << "," << y << ")";
}

class Circle
{
	Point2D center;
	double radius;
public:
	Circle(){center.setX(0);center.setY(0);radius=0;}
	Circle(Point2D c, double r);
	void setcenter(Point2D c);
	Point2D getcenter();
	double area(); //returns area of the circle
	void print(); //prints the circle in the stdout
	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle
	~Circle(){center.setX(0);center.setY(0);radius=0;};
};

Circle::Circle(Point2D c, double r)
{
  radius=r;
  setcenter(c);
}
void Circle::setcenter(Point2D c)
{
  center.setX(c.getX());
  center.setY(c.getY());
}
Point2D Circle::getcenter()
{
   return center;
}
double Circle::area()
{
	return 3.14*radius*radius;
}

int Circle::intersect(Circle rhs)
{
	if((rhs.center.getX()-center.getX())*(rhs.center.getX()-center.getX())+
	((rhs.center.getY()-center.getY())*(rhs.center.getY()-center.getY()))<=((radius*radius)+(rhs.radius*rhs.radius)))
	{
	 return 1;
	}
	else {return 0;}
}

int Circle::contains(Point2D rhs)
{
	if((((rhs.getX()-center.getX())*(rhs.getX()-center.getX()))+
	((rhs.getY()-center.getY())*(rhs.getY()-center.getY())))<=(radius*radius))
	{return 1;}
	else {return 0;}
}
double Circle::perimeter()
{
   return 2*3.14*radius;
}
void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius;
}

class Rectangle
{
	Point2D t;
	Point2D l;
	//consider the rectangle is axes parallel
public:
	Rectangle(){t.setX(0);l.setY(0);}//write a default constructor that initializes all values to 0
	Rectangle(Point2D p,Point2D q);//write a constructor that accepts values of all member variables and set the members
	//variables accordingly
	void setpointt(Point2D p);
	void setpointl(Point2D q);
	Point2D getpointt();
	Point2D getpointl();
	double area(); //returns area of the rectangle
	int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
	int contains(Point2D p); //determine if this rectangle contains point p
	int inside(Circle c); //determine if this rectangle is completely inside the circle c
	double perimeter(); //returns perimeter of the circle
	//write a destructor that sets all values to 0
};
Rectangle::Rectangle(Point2D p,Point2D q)
{
   setpointt(p);
   setpointl(q);
   getpointt();
   getpointl();
}
void Rectangle::setpointt(Point2D p)
{
  t.setX(p.getX());
  t.setY(p.getY());
}
Point2D Rectangle::getpointt()
{
  return t;
}
void Rectangle::setpointl(Point2D q)
{
  l.setX(q.getX());
  l.setY(q.getY());
}
Point2D Rectangle::getpointl()
{
  return l;
}
double Rectangle::area()
{
  return abs(((t.getX()-l.getX())*(t.getY()-l.getY())));
}
int Rectangle::intersect(Rectangle rhs)
{
   if((rhs.l.getX()>=l.getX())&&(rhs.l.getX()<=t.getX())&&(rhs.t.getY()>=l.getY())&&(rhs.t.getY()<=t.getY()))
   {
    return 1;
   }
   else return 0;
}
int Rectangle::contains(Point2D p)
{
   return 1;
}
int Rectangle::inside(Circle c)
{
   return 1;
}
double Rectangle::perimeter()
{
 return 2*((t.getX()-l.getX())+(t.getY()+l.getY()));
}
int main(void)
{
    Point2D c(10,5);
    Point2D d(4,7);
    Point2D e(1,3);
    Point2D f(2,4);
	Circle c1(c,4);
	Circle c2(d,5);
	cout<<c1.area()<<endl;
	cout<<c1.intersect(c2)<<endl;
	cout<<c1.contains(d)<<endl;

	Rectangle r1(c,d);
	Rectangle r2(e,f);
	cout<<r1.area()<<endl;
	cout<<r1.intersect(r2)<<endl;
	cout<<r1.contains(e)<<endl;
	cout<<r1.inside(c2)<<endl;
	cout<<r1.perimeter()<<endl;


	return 0;
}
