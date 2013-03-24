#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include "String.h"

using namespace std;

String::String(int b)
{
    boyut=b;

    ptr=new char[boyut];

    for(int i=0;i<boyut;i++)
        ptr[i]='\0';
}

bool String::operator==(const String &str) //== operatoru asiri yukleniyor
{
    if(strcmp(ptr,str.ptr))
        return false;
    else
        return true;
}

bool String::operator>(const String &str) //> operatoru asiri yukleniyor
{
    if(strcmp(ptr,str.ptr)>0)
        return true;
    else
        return false;
}

bool String::operator>=(const String &str) //>= operatoru asiri yukleniyor
{
    if(strcmp(ptr,str.ptr)>=0)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &cikti,const String &str) //<< operatoru asiri yukleniyor
{
    int i;
    char s[21];

    for(i=0;i<str.boyut;i++)
    {
        if(str.ptr[i]!='\0')
            s[i]=str.ptr[i];
        else
            break;
    }
    s[i]='\0';

    cikti<<s;

    return cikti;
}

istream &operator>>(istream &girdi,String &str) //>> operatoru asiri yukleniyor
{
    char c;

    for(int i=0;i<str.boyut;i++)
    {
        c=getchar();
        if(c=='\n')
            break;
        else
            if(i==0) //ilk harf buyuk harfe cevriliyor
                c=toupper(c);
            else //diger harfler kucuk harfe cevriliyor
                c=tolower(c);
            str.ptr[i]=c;
    }

    return girdi;
}
