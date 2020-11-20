#include<iostream>
#define UNDEFINED 0
#define LINE 1
#define RECTANGLE 2
#define CUBE 3

using namespace std;

class Shape
{
    int type;
public:
    Shape()
    {
        type = UNDEFINED;
        cout<<"In Shape with Type "<<type<<endl;
    }

    Shape(int type)
    {
        this->type = type;
        cout<<"In Shape with Type "<<type<<endl;
    }

    virtual int area()
    {
        cout<<"Overload this function in derived class"<<endl;
        return -1;
    }

    virtual int volume()
    {
        cout<<"Overload this function in derived class"<<endl;
        return -1;
    }

    virtual int get_type(){ return type; }

    virtual void set_type(int type){ this->type = type; }

    ~Shape(){
        cout<<"destructing shape"<<endl;
    }
};


class Line: public Shape
{
public:
    int length;
    Line()
    {
        Shape(1);
        length = 0;
        cout<<"In Line with length "<<length<<endl;
    }
    Line(int type, int length):Shape(type)
    {
        this->length = length;
        cout<<"In Line with length "<<length<<endl;
    }

    ///override area() and volume()
    int area()
    {
        return 0;
    }

    int volume()
    {
        return 0;
    }

    ///setter getter if required
//    int get_type(){ return get_type(); }
//    void set_type(){ Shape::set_type(LINE); }

    ~Line(){
        cout<<"destructing line"<<endl;
    }

};

class Rectangle: public Line
{
    int width;
public:
    Rectangle()
    {
        Shape(2);
        width = 0;
        length = 0;
        cout<<"In Rectangle with width "<<width<<endl;
    }

    Rectangle(int type, int length, int width):Line(type,length)
    {
        this->width = width;
        cout<<"In Rectangle with width "<<width<<endl;
    }

    ///override area() and volume()
    int area()
    {
        return width*length;
    }

    int volume()
    {
        return Line::volume();
    }

    ///setter getter if required
    int get_type(){ return get_type(); }
    void set_type(int type){ Shape::set_type(RECTANGLE); }

    void set_width(int width){
        this->width=width;
    }

    int get_width(){
        return width;
    }

    void set_length(int length){
        this->length=length;
    }

    int get_length(){
        return length;
    }

    ~Rectangle(){
        cout<<"destructing Rectangle"<<endl;
    }

};

class Cube: public Rectangle
{
    int height;
public:
    Cube()
    {
        /// set length and width
        set_type(CUBE);
        height = 0;
        length=0;
        set_width(0);
        cout<<"In Cube with height "<<height<<endl;
    }

    Cube(int type, int length, int width, int height): Rectangle(type, length, width)
    {
        this->height = height;
        cout<<"In Cube with height "<< this->height<<endl;
    }

    ///override area() and volume()
    int area()
    {
        return 2*Rectangle::area()+2*Rectangle::get_length()*height+2*Rectangle::get_width()*height;
    }

    int volume()
    {
        return Rectangle::area()*height;
    }

    ///setter getter if required
    int get_type(){ return get_type(); }
    void set_type(int type){ Shape::set_type(RECTANGLE); }

    void set_width(int width){
        set_width(width);
    }

    int get_width(){
        return get_width();
    }

    void set_length(int length){
        set_length(length);
    }

    int get_length(){
        return get_length();
    }

    void set_height(int height){
        this->height=height;
    }

    int get_height(){
        return height;
    }

    ~Cube(){
        cout<<"destructing cube"<<endl;
    }

};


int main()
{
    Shape s;
    s.area();
    ///Overload this function in derived class
    s.volume();
    ///Overload this function in derived class

    Line l(LINE, 5);
    ///Implement area and volume function
    cout<<"area of line "<<l.area()<<endl;
    ///Area is 0
    cout<<"volume of line "<<l.volume()<<endl;
    ///Volume is 0

    Rectangle r(RECTANGLE, 5, 2);
    ///Notice that access modifier is private
    cout<<"area of rect "<<r.area()<<endl;
    ///Area is 10
    cout<<"volume of rect "<<r.volume()<<endl;
    ///Volume is 0

    Cube c(CUBE, 5, 2, 4);
    ///You can not access length due to private modifier in rectangle
    ///write necessary methods in rectangle to access length
    cout<<"area of cube "<<c.area()<<endl;
    ///Area is 76
    cout<<"volume of area "<<c.volume()<<endl;
    ///Volume is 40

    ///Demonstration of Virtual Function in Shape
    Shape* s1;
    s1 = &l;
    cout<<"area of line "<<s1->area()<<endl;
    ///Area is 0
    cout<<"volume of line "<<s1->volume()<<endl;
    ///Volume is 0

    s1 = &r;
    cout<<"area of rect "<<s1->area()<<endl;
    cout<<"volume of rect "<<s1->volume()<<endl;

    s1 = &c;
    cout<<"area of cube "<<s1->area()<<endl;
    cout<<"volume of cube "<<s1->volume()<<endl;

    ///write destructor function and observe (by printing something) the order of constructor and destructor call

    return 0;
}

