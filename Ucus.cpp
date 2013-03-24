#include <iostream>
#include <iomanip>
#include "String.h"
#include "Ucus.h"

using namespace std;

Ucus::Ucus(int no,String kalkis,String varis,String zaman,int normal,int luks,Ucus *onceki,Ucus *sonraki,Ucus *cSonraki)
: ucusNo(no),kalkisYeri(kalkis),varisYeri(varis),zaman(zaman),normalKoltukSayisi(normal)
{
    luksKoltukAyarla(luks);
}

int Ucus::ucusNoOku()
{
    return ucusNo;
}

String Ucus::kalkisYeriOku()
{
    return kalkisYeri;
}

String Ucus::varisYeriOku()
{
    return varisYeri;
}

String Ucus::zamanOku()
{
    return zaman;
}

int Ucus::normalKoltukOku()
{
    return normalKoltukSayisi;
}

int Ucus::luksKoltukOku()
{
    return luksKoltukSayisi;
}

void Ucus::luksKoltukAyarla(int l)
{
    luksKoltukSayisi=l;
}

Ucus *Ucus::oncekiOku()
{
    return onceki;
}

void Ucus::oncekiAyarla(Ucus *o)
{
    onceki=o;
}

Ucus *Ucus::sonrakiOku()
{
    return sonraki;
}

void Ucus::sonrakiAyarla(Ucus *s)
{
    sonraki=s;
}

Ucus *Ucus::cSonrakiOku()
{
    return cSonraki;
}

void Ucus::cSonrakiAyarla(Ucus *s)
{
    cSonraki=s;
}

ostream &operator<<(ostream &cikti,Ucus &ucus) //<< operatoru asiri yukleniyor
{
    cikti<<"     "<<left<<setw(7)<<ucus.ucusNoOku()<<"   "
         <<left<<setw(11)<<ucus.kalkisYeriOku()<<"   "
         <<left<<setw(10)<<ucus.varisYeriOku()<<"   "
         <<right<<setw(5)<<ucus.zamanOku()<<"   "
         <<right<<setw(13)<<ucus.normalKoltukOku()<<"   "
         <<right<<setw(11)<<ucus.luksKoltukOku()<<endl;

    return cikti;
}
