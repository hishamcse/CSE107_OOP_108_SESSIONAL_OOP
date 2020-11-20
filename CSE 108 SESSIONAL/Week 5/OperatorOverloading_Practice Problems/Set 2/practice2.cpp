#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char *s;
    int len;
public:
    String(){
    s='\0';
    len=0;
    }
    String(char *p){
    len=strlen(p);
    s=new char[len];
    strcpy(s,p);
    }
    char* getString(){return s;}
    void print(){cout<<getString()<<endl;}
    bool operator>(String p);
    bool operator>=(String p);
    bool operator<(String p);
    bool operator<=(String p);
    bool operator==(String p);
    bool operator!=(String p);
    String &operator+(String &p);
    String &operator*(int m);
};
bool String::operator>(String t)
{
    if(strcmp(s,t.getString())>0){return true;}
    else{return false;}
}
bool String::operator>=(String p)
{
    if(strcmp(s,p.getString())>=0){return true;}
    else{return false;}
}
bool String::operator<(String p)
{
    if(strcmp(s,p.getString())<0){return true;}
    else{return false;}
}
bool String::operator<=(String p)
{
    if(strcmp(s,p.getString())<=0){return true;}
    else{return false;}
}
bool String::operator==(String p)
{
    if(strcmp(s,p.getString())==0){return true;}
    else{return false;}
}
bool String::operator!=(String p)
{
    if(strcmp(s,p.getString())!=0){return true;}
    else{return false;}
}
String &String::operator+(String &str)
{
    char *t=new char[len+strlen(str.getString())+1];
    strcpy(t,s);
    strcat(t,str.getString());
    String *temp=new String(t);
    delete[]t;
    return *temp;
}
String &String::operator*(int m)
{
    char* k=new char[len*m+1];
    int l=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<len;j++){
            k[l]=s[j];
            l++;
        }
    }
    k[l]='\0';
    String *ret_val=new String(k);
    delete[] k;
    return *ret_val;
}

int main()
{
    String s1("baby");
    String s2("babies");
    String s3=s2;
    String s4;

    if(s1>s2)
    {
        s1.print();
    }else
    {
    s2.print();
    }
    s4 = (s1 + s2) * 5;
    s4.print();

    (s1 + s2).print();

    s3 = (s1 + s2);
    s3.print();
}
