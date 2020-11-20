#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 100
#define EMPTY -99

class Array
{
    int a[SIZE];
    int length;
public:
    Array()
    {
        length = 0;
    }
    Array(int size)
    {
        length = size;
        for (int i = 0; i < size; i++)
        {
            a[i] = EMPTY;
        }
    }
    Array(int l,int k)
    {
        setLength(l);
        for(int i=0;i<getLength();i++)
        {
            setElementAt(i,k);
        }
    }
    Array(int p,int n[])
    {
        setLength(p);
        for(int i=0;i<getLength();i++)
        {
            setElementAt(i,n[i]);
        }
    }
    void clone(Array m)
    {
        setLength(m.length);
        for(int i=0;i<getLength();i++)
        {
            setElementAt(i,m.a[i]);
        }
    }
    void setLength(int size)
    {
        length = size;
    }
    int getLength()
    {
        return length;
    }
    void setElementAt(int i, int e)
    {
        if(i >= length)
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
        a[i]=e;
    }
    int getElementAt(int i)
    {
        if(i >= length)
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
        return a[i];
    }
    void print()
    {
        for(int i =0; i < length; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

    }
    ~Array()
    {
        setLength(0);
    }
};

