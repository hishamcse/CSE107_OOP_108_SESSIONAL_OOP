#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    Array s;
    int size;
    int front;
    int rear;
public:
    Queue(){front=0;rear=0;size=0;}
    Queue(int y)
    {
        front=0;rear=0;
        size=y;
        s.setLength(size+1);
    }
    int getfront()
    {
        return front;
    }
    int getrear()
    {
        return rear;
    }
    void clone(Queue l)
    {
        size=l.getLength();
        //s.clone(l.s);
        front=l.getfront();
        rear=l.getrear();
        s.setLength(size+1);
        for(int i=front;i!=rear;i=i%(size+1))
        {
            s.setElementAt(i,l.s.getElementAt(i));
            i++;
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
        rear%=(size+1);
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
        front%=(size+1);
        return k;
    }
    int isEmpty()
    {
	return (rear==front);
    }

    int isFull()
    {
	return (rear+1)%(size+1)==front;
    }
    int getLength()   //for online
    {
        return size;
    }
};


