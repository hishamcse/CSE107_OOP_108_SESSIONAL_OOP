#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
    char *s;
    int len;
public:
    String(){s='\0';len=0;}
    String(char *p);
    char* getString();
    char* operator+(char *str);
    char* operator+(int n);
    char* operator-();
    char* operator*(int m);
};
String::String(char *p)
{
   len=strlen(p);
   s=new char[len];
   strcpy(s,p);
}

char* String::getString()
{
    return s;
}

char* String::operator+(char *str)
{
    strcat(s,str);
    return s;
}

char* String::operator+(int n)
{
    char* t=new char[10];
    int temp=n;
    int size=0;
    while(temp>0){
        t[size++]='0'+temp%10;
        temp/=10;
    }
    t[size]='\0';
    char* ord=new char[size];
    for(int i=0;i<size;i++){
        ord[i]=t[size-i-1];
    }
    strcat(s,ord);
    return s;
}
char* String::operator-()
{
    int k=strlen(s);
    char *m=new char[k];
    int j=0;
    for(int i=k-1;i>=0;i--){
        m[j]=s[i];
        j++;
    }
    m[j]='\0';
    return m;
}
char* String::operator*(int m)
{
    char* k=new char[len*m];
    int l=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<len;j++){
            k[l]=s[j];
            l++;
        }
    }
    k[l]='\0';
    return k;
}
int main()
{
    String s("BUET");
    String s1,s2;
    cout<<s.getString()<<endl;
    s = s+"CSE";
    cout<<s.getString()<<endl;
    s1=s;
    s1 =s=s+108;
    cout<<s1.getString()<<endl;
    s= - s;
    cout<<s.getString()<<endl;
    s2=s1*3;
    cout<<s2.getString()<<endl;
}
