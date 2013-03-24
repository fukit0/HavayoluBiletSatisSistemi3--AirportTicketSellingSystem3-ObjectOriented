#ifndef UCUS_H_INCLUDED
#define UCUS_H_INCLUDED
#include "String.h"

class Ucus {
    friend ostream &operator<<(ostream &,Ucus &);
private:
    const int ucusNo;
    const String kalkisYeri;
    const String varisYeri;
    const String zaman;
    const int normalKoltukSayisi;
    int luksKoltukSayisi;
    Ucus *onceki; //cift bagli liste icin onceki
    Ucus *sonraki; //tek bagli liste icin sonraki
    Ucus *cSonraki; //cift bagli liste icin sonraki
public:
    Ucus(const int,const String,const String,const String,const int,int,Ucus * = NULL,Ucus * = NULL,Ucus * = NULL);
    int ucusNoOku();
    String kalkisYeriOku();
    String varisYeriOku();
    String zamanOku();
    int normalKoltukOku();
    int luksKoltukOku();
    void luksKoltukAyarla(int);
    Ucus *oncekiOku();
    void oncekiAyarla(Ucus *);
    Ucus *sonrakiOku();
    void sonrakiAyarla(Ucus *);
    Ucus *cSonrakiOku();
    void cSonrakiAyarla(Ucus *);
};

#endif // UCUS_H_INCLUDED
