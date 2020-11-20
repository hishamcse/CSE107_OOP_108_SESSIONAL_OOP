#include <iostream>
#include <cstdlib>
using namespace std;

class Stack
{
    Array s;
    int size;
    int top;
    // you are not allowed to add any field; you can only add methods
public:
    Stack()
    {
        size=0;
        top=0;
    }
    Stack(int k)
    {
        top=0;
        s.setLength(k);
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
    void clone(Stack t)
    {
        t.s.setLength(5);
        top=0;
        s.setLength(t.s.getLength());
        for(int i=s.getLength()-1;i>=0;i--)
        {
            s.setElementAt(i,t.s.getElementAt(top++));
        }
    }
    int isFull()
    {
        return (top>=size);
    }
    int isEmpty()
    {
        return top==0;
    }
    ~Stack(){size=0;top=0;}
};
