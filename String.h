#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>

using namespace std;

class String {
    friend ostream &operator<<(ostream &,const String &);
    friend istream &operator>>(istream &,String &);
private:
    int boyut;
    char *ptr;
public:
    String(int=21);
    bool operator==(const String &);
    bool operator>(const String &);
    bool operator>=(const String &);
};

#endif // STRING_H_INCLUDED
