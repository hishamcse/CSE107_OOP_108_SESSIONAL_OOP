#include <iostream>
#include <cstdlib>
using namespace std;

class Stack
{
    Array s;
    int size;
    int top;
public:
    Stack(){size=0;top=0;}
    Stack(int y){
    top=0;
    s.setLength(y);
    size=s.getLength();
    }
    void push(int x)
    {
        if(isFull())
        {
            cout << "Stack is full" << endl;
            exit(0);
        }
        s.setElementAt(top++,x);
    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            exit(0);
        }
        return s.getElementAt(--top);
    }
    void clone(Stack w)
    {
        w.s.setLength(5);
        top=0;
        s.setLength(w.s.getLength());
        for(int i=s.getLength()-1;i>=0;i--)
        {
            s.setElementAt(i,w.s.getElementAt(top++));
        }
    }
    int isFull()
    {
        return (top==size);
    }
    int isEmpty()
    {
        return (top==0);
    }
    int getLength()   //for online
    {
        return size;
    }
    ~Stack(){size=0;top=0;}
};

