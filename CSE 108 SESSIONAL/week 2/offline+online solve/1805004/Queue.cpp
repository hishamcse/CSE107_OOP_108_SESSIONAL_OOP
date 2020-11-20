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
    Queue(){front=0;rear=0;size=0;}
    Queue(int y)
    {
        front=0;rear=0;
        s.setLength(y);
        size=s.getLength();
    }
    void clone(Queue l)
    {
        size=l.s.getLength();
        s.clone(l.s);
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
        int k;
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        k=s.getElementAt(front++);
        front=(front+1)%(size+1);
        return k;
    }
    int isEmpty()
    {
	return (front>=size);
    }

    int isFull()
    {
	return (rear==size);
    }

};


