#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    Array s;
    int size;
    int front;
    int rear;
    // you are not allowed to add any field; you can only add methods
public:
    Queue()
    {
        size=0;front=0;rear=0;
    }
    Queue(int y)
    {
        front=0;
        rear=0;
        s.setLength(y);
        size=s.getLength();

    }
    void clone(Queue q)
    {
        //size=q.s.getLength();
        //s.clone(q.s);
        q.s.setLength(10);
        //front=0;rear=0;
        s.setLength(q.s.getLength());
        for(int i=0;i<=s.getLength()-1;i++)
        {
            enqueue(q.dequeue());
        }
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            cout << "Queue is full" << endl;
            exit(0);
        }
        s.setElementAt(rear++,x);
        rear=(rear+1)%(size+1);
    }
    int dequeue()
    {
        int j;
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        j=s.getElementAt(front++);
        front=(front+1)%(size+1);
        return j;
    }

    int isFull()
    {
        return  (rear+1)%(size+1)==(front+1);
    }
    int isEmpty()
    {
        return (rear==front);
    }
};
