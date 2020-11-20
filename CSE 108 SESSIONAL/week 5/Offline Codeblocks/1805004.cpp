#include <iostream>
#include <cstring>
using namespace std;

class StringMath {
    char *s;
public:
    StringMath();
    StringMath(char *p);
    StringMath(const StringMath &p);

    StringMath &operator=(const StringMath &p);
    StringMath operator+(StringMath p);
    StringMath operator+(int n);

    bool operator>(StringMath p);
    bool operator>(int n);

    StringMath operator++(int unused);

    friend StringMath operator+(int n, StringMath p);

    void print();

    ~StringMath();
};

// helper methods (not member function)
bool validate(char *p) {
    int n = strlen(p);
    for (int i = 0; i < n; i++) {
        if (*(p + i) < 48 || *(p + i) > 57) {
            return false;
        }
    }
    return true;
}

int StringToInt(char *p) {
    int len = strlen(p);
    int num = 0, n = 1;
    for (int i = len - 1; i >= 0; i--) {
        num = num + (int) (*(p + i) - 48) * n;
        n = n * 10;
    }
    return num;
}

char *IntToString(int num) {
    int i = 0, c = 0;
    int num2 = num;
    while (num2 != 0) {
        num2 /= 10;
        c++;
    }
    char *buff = new char[c + 1];
    while (num != 0) {
        *(buff + i) = (num % 10) + '0';
        num /= 10;
        i++;
    }
    *(buff + i) = '\0';
    strrev(buff);
    return buff;
}

// constructor & copy constructor
StringMath::StringMath() {
    s = new char(0);
    *s = '\0';
}

StringMath::StringMath(char *p) {
    bool b = validate(p);
    if (b) {
        int len = strlen(p);
        s = new char[len + 1];
        strcpy(s, p);
    } else {
        s = new char(0);
        *s = '\0';
    }
}

StringMath::StringMath(const StringMath &p) {
    bool b = validate(p.s);
    if (b) {
        int len = strlen(p.s);
        s = new char[len + 1];
        strcpy(s, p.s);
    } else {
        s = new char(0);
        *s = '\0';
    }
}

// overloaded operator functions
StringMath &StringMath::operator=(const StringMath &p) {
    s = new char[strlen(p.s) + 1];
    strcpy(s, p.s);
    return *this;
}

StringMath StringMath::operator+(StringMath p) {
    bool b = validate(p.s);
    if (b) {
        int num1 = StringToInt(s);
        int num2 = StringToInt(p.s);
        StringMath q(IntToString(num1 + num2));
        return q;
    } else {
        return *this;
    }
}

StringMath StringMath::operator+(int n) {
    int num1 = StringToInt(s);
    StringMath q(IntToString(num1 + n));
    return q;
}

bool StringMath::operator>(StringMath p) {
    bool b = validate(p.s);
    if (b) {
        int num1 = StringToInt(s);
        int num2 = StringToInt(p.s);
        return num1 > num2;
    }
    return false;
}

bool StringMath::operator>(int n) {
    int num1 = StringToInt(s);
    return num1 > n;
}

StringMath StringMath::operator++(int unused) {
    int num = StringToInt(s);
    ++num;
    delete[]s;
    s = IntToString(num);
    StringMath q(s);
    return q;
}

StringMath operator+(int n, StringMath p) {
    StringMath q = p + n;
    return q;
}

void StringMath::print() {
    cout << s << endl;
}

StringMath::~StringMath() {
    delete[]s;
}

int main() {
    StringMath S1;
    StringMath S2("123");
    StringMath S3("757");
    StringMath S4("220");
    StringMath S5;
    int n = 345;
    S1 = S4;
    cout << "After Equal operation of S1 & S4 :" << endl;
    cout << "String for S1 ";
    S1.print();
    cout << "String for S4 ";
    S4.print();

    S1 = S2 + S3 + S4;
    cout << "After adding all strings :" << endl;
    cout << "String for S1 ";
    S1.print();
    cout << "String for S2 ";
    S2.print();
    cout << "String for S3 ";
    S3.print();
    cout << "String for S4 ";
    S4.print();

    S5 = S4 = S3;
    cout << "After Equal operation of S3,S4,S5 :" << endl;
    cout << "String for S3 ";
    S3.print();
    cout << "String for S4 ";
    S4.print();
    cout << "String for S5 ";
    S5.print();

    if (S3 > n) {
        S5 = S3 + n;
    }
    cout << "After adding n with S3 :" << endl;
    cout << "String for S5 ";
    S5.print();

    S5 = n + S2;
    cout << "After adding n with S2 :" << endl;
    cout << "String for S5 ";
    S5.print();

    if (S5 > S2) {
        S5++;          //Assume prefix increment
    }
    cout << "After prefix increment of S5:" << endl;
    cout << "String for S5 ";
    S5.print();
}
