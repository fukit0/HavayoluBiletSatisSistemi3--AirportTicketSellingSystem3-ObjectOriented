#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"

using namespace std;

Ucus_Numarasina_Gore_Ucus_Listesi::Ucus_Numarasina_Gore_Ucus_Listesi()
{
    ilk=NULL;
}

void Ucus_Numarasina_Gore_Ucus_Listesi::ekle(Ucus *yeni)
{
    Ucus *gecici,*onceki;

    if(ilk==NULL || yeni->ucusNoOku()<ilk->ucusNoOku()) //liste bossa veya en basa eklenecekse
    {
        yeni->sonrakiAyarla(ilk);
        ilk=yeni;
    }
    else
    {
        onceki=ilk;
        gecici=ilk->sonrakiOku();
        while((gecici!=NULL) && (gecici->ucusNoOku()<yeni->ucusNoOku())) //eklenecek uygun yer araniyor
        {
            onceki=gecici;
            gecici=gecici->sonrakiOku();
        }
        yeni->sonrakiAyarla(gecici); //onceki nesnesi ile gecici nesnesi arasina ekleniyor
        onceki->sonrakiAyarla(yeni);
    }
}

Ucus *Ucus_Numarasina_Gore_Ucus_Listesi::ara(int ucusNo)
{
    Ucus *gecici=ilk;

    while((gecici!=NULL) && (ucusNo>=gecici->ucusNoOku()))
    {
        if(gecici->ucusNoOku()==ucusNo) //bulunursa aranilan nesnenin adresi geriye donduruluyor
            return gecici;

        gecici=gecici->sonrakiOku();
    }

    return NULL; //bulunamazsa geriye NULL donduruluyor
}

void Ucus_Numarasina_Gore_Ucus_Listesi::cikar(Ucus *cikarilan)
{
    Ucus *gecici,*onceki=ilk;

    if(cikarilan==ilk) //cikarilan listenin ilk nesnesi ise
    {
        ilk=ilk->sonrakiOku();
    }
    else
    {
        gecici=onceki->sonrakiOku();
        while((gecici!=NULL) && (gecici!=cikarilan))
        {
            onceki=gecici;
            gecici=gecici->sonrakiOku();
        }
        onceki->sonrakiAyarla(gecici->sonrakiOku());
    }
}

void Ucus_Numarasina_Gore_Ucus_Listesi::luksListele()
{
    Ucus *gecici=ilk;
    int sagSerbest=0;

    while(gecici!=NULL)
    {
        if(gecici->luksKoltukOku()>0)
        {
            sagSerbest++;
            cout<<*gecici;
        }
        gecici=gecici->sonrakiOku();
    }

    if(sagSerbest==0)
    {
        cout<<"\n\t >>> Luks Koltuk Iceren Ucus Yok...!"<<endl;
        PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
    }
}

ostream &operator<<(ostream &cikti,const Ucus_Numarasina_Gore_Ucus_Listesi &ucus) //<< operatoru asiri yukleniyor
{
    Ucus *gecici=ucus.ilk;

    while(gecici!=NULL)
    {
        cikti<<*gecici;
        gecici=gecici->sonrakiOku();
    }

    return cikti;
}
