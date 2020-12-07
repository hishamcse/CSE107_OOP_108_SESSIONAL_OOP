#include<iostream>
#include<string>
using namespace std;

long fact(int n,int c=10)
{
    if(c==0 || n==0) return 1;
    return n*fact(n-1,c-1);
}

//int fibonacci(int n) {
//    if (n == 1)
//        return 1;
//    else
//        return fibonacci(n, 2, 1, 2);
//}
//
//int fibonacci(int n, int f1, int f2, int c) {
//    if (c == n)
//        return f1;
//    else
//        return fibonacci(n, f1 + f2, f1, c + 1);
//}

//class Profile
//{
//public:
//    string name;
//    int id;
//
//    Profile(string name)
//    {
//       this->name=name;
//       this->id=-1;
//    }
//
//    Profile(const Profile &p,int id=-1){
//        this->name=p.name;
//        this->id=id;
//    }
//};

int main()
{
//    Profile q("Hisham");
//    Profile p=q;
//    cout<<p.name<<" "<<p.id<<endl;
      cout<<fact(10)<<endl;
      cout<<fact(10,2)<<endl;
}
