#include<iostream>
using namespace std;

class Point2D
{
    int x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void print();
    ~Point2D()
    {
        x = 0;
        y = 0;
    }
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
    Circle()
    {
        center.setX(0);
        center.setY(0);
        radius=0;
    }
    Circle(Point2D c, double r);
    void setcircle(Point2D p,double x);
    Point2D getcenter();
    double getrad();
    double area();
    void print();
    int intersect(Circle rhs);
    int contains(Point2D p);
    double perimeter();
    ~ Circle()
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
void Circle::setcircle(Point2D p,double x)
{
    center.setX(p.getX());
    center.setY(p.getY());
    radius=x;
}
Point2D Circle::getcenter()
{
    return center;
}
double Circle::getrad()
{
    return radius;
}
double Circle::area()
{
    return 3.14*radius*radius;
}

int Circle::intersect(Circle rhs)
{
    double d,k;
    d=(center.getX()-rhs.getcenter().getX())*(center.getX()-rhs.getcenter().getX())+
      (center.getY()-rhs.getcenter().getY())*(center.getY()-rhs.getcenter().getY());
    k=radius+rhs.getrad();
    if(d<=k*k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Circle::contains(Point2D rhs)
{
    if((rhs.getX()>=center.getX())&&(rhs.getX()<=(center.getX()+radius))&&
            (rhs.getY()>=center.getY())&&(rhs.getY()<=(center.getY()+radius)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double Circle::perimeter()
{
    return 2*3.14*radius;
}
void Circle::print()
{
    cout << "Center: "<<center.getX()<<" "<<center.getY()<<endl;
    cout << "Radius: " << radius<<endl;
}

class Rectangle
{
    Point2D blp,trp;
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
        blp.setX(p.getX());
        blp.setY(p.getY());
        trp.setX(q.getX());
        trp.setY(q.getY());
    }
    void setrect(Point2D p,Point2D q);
    Point2D getbottom();
    Point2D gettop();
    double area();
    int intersect(Rectangle rhs);
    int contains(Point2D p);
    int inside(Circle c);
    double perimeter();
    ~Rectangle()
    {
        trp.setX(0);
        trp.setY(0);
        blp.setX(0);
        blp.setY(0);
    }
};
void Rectangle::setrect(Point2D p,Point2D q)
{
    blp.setX(p.getX());
    blp.setY(p.getY());
    trp.setX(q.getX());
    trp.setY(q.getY());
}
Point2D Rectangle::getbottom()
{
    return blp;
}
Point2D Rectangle::gettop()
{
    return trp;
}
double Rectangle::area()
{
    double a;
    a=(trp.getX()-blp.getX())*(trp.getY()-blp.getY());
    return a;
}
int Rectangle::intersect(Rectangle rhs)
{
    if((rhs.getbottom().getX()>=blp.getX())&&(rhs.getbottom().getY()>=blp.getY())
            ||(rhs.gettop().getX()<=trp.getX())&&(rhs.gettop().getY()<=trp.getY()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Rectangle::contains(Point2D p)
{
    if(p.getX()>=blp.getX()&&p.getY()>=blp.getY()&&p.getX()<=trp.getX()&&p.getY()<=trp.getY())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Rectangle::inside(Circle c)
{
    if(c.contains(blp)&&c.contains(trp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double Rectangle::perimeter()
{
    return 2*(trp.getX()-blp.getX())*(trp.getY()-blp.getY());
}
int main(void)
{
    Point2D p(2,3),q(5,6),t(1,2),l(3,4);
    Circle c(p,3);
    cout<<"circle area::"<<c.area()<<endl;
    Circle d(q,4);
    cout<<"intersect of circle:"<<c.intersect(d)<<endl;
    cout<<"contains the point:"<<c.contains(q)<<endl;


    Rectangle r(p,q),m(t,l);
    cout<<"area of rect:"<<r.area()<<endl;
    cout<<"intersect to rect::"<<r.intersect(m)<<endl;
    cout<<"contains the point:"<<r.contains(t)<<endl;
    cout<<"inside the circle:"<<r.inside(c)<<endl;

    return 0;
}

