#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char s[256];
public:
    String(){
    *s='\0';
    }
    String(char *p){
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
    String operator+(String p);
    String operator*(int m);
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
String String::operator+(String str)
{
    char *temp=new char[strlen(s)+1];
    strcpy(temp,s);
    strcat(temp,str.getString());
    return temp;
}
String String::operator*(int m)
{
    char *temp=new char[strlen(s)+1];
    strcpy(temp,s);
    for(int i=0;i<m;i++){
        strcat(s,temp);
    }
    return s;
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

