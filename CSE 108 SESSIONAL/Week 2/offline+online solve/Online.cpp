#include<iostream>
#include "Array.cpp"
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;
class Util{
   public:
       Stack Clone(Queue q)
       {
           Stack t(q.getLength());
           while(!q.isEmpty())
           {
               t.push(q.dequeue());
           }
           return t;
       }
       Queue Clone(Stack s)
       {
           Queue r(s.getLength());
           while(!s.isEmpty())
           {
               r.enqueue(s.pop());
           }
           return r;
       }
};
int main()
{
    Stack s(10);
    for(int i=0;i<5;i++)
    {
        s.push(i+1);
    }
    Queue q(10);
    for(int i=0;i<5;i++)
    {
        q.enqueue(i+1);
    }
    cout << "Elements of Stack s(original): " << endl;
    while(!s.isEmpty())
    {
        cout << s.pop() << " " ;
    }
    cout << endl;

    cout << "Elements of queue q(original): " << endl;
    while(!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    Util u;
    Stack m;
    Queue n;
    m=u.Clone(q);
    n=u.Clone(s);
    cout<<"STACK FROM QUEUE:"<<endl;
    while(!m.isEmpty())
    {
        cout<<m.pop()<<" ";
    }
    cout<<"\n";
    cout<<"QUEUE FROM STACK:"<<endl;
    while(!n.isEmpty())
    {
        cout<<n.dequeue()<<" ";
    }
    cout<<"\n";
}

