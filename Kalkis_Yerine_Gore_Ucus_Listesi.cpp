#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "String.h"
#include "Ucus.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"

using namespace std;

Kalkis_Yerine_Gore_Ucus_Listesi::Kalkis_Yerine_Gore_Ucus_Listesi() : listeBasi(0,0,0,0,0,0)
{
    listeBasi.oncekiAyarla(&listeBasi);
    listeBasi.cSonrakiAyarla(&listeBasi);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekle(Ucus *yeni)
{
    Ucus *gecici=listeBasi.cSonrakiOku();

    while((gecici!=&listeBasi) && ((yeni->kalkisYeriOku())>(gecici->kalkisYeriOku()))) //alfabetik siraya gore uygun yer araniyor
        gecici=gecici->cSonrakiOku();

    while(((yeni->kalkisYeriOku())==(gecici->kalkisYeriOku())) && ((yeni->zamanOku()>(gecici->zamanOku())))) //kalkis zamani icin uygun yer araniyor
        gecici=gecici->cSonrakiOku();

    yeni->cSonrakiAyarla(gecici);
    yeni->oncekiAyarla(gecici->oncekiOku());
    (gecici->oncekiOku())->cSonrakiAyarla(yeni);
    gecici->oncekiAyarla(yeni);
}

Ucus *Kalkis_Yerine_Gore_Ucus_Listesi::ara(int ucusNo)
{
    Ucus *gecici=listeBasi.cSonrakiOku();

    while(gecici!=&listeBasi)
    {
        if(gecici->ucusNoOku()==ucusNo) //bulunursa aranilan nesnenin adresi geriye donduruluyor
            return gecici;

        gecici=gecici->cSonrakiOku();
    }

    return NULL; //bulunamazsa geriye NULL donduruluyor
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ara(String aranan,int s)
{
    Ucus *gecici=listeBasi.cSonrakiOku();
    int sagSerbest=0;

    switch(s)
    {
        case 0: //kalkis yerine gore arama
            while((gecici!=&listeBasi) && (aranan>=(gecici->kalkisYeriOku())))
            {
                if((gecici->kalkisYeriOku())==aranan)
                {
                    sagSerbest++;
                    cout<<*gecici;
                }
                gecici=gecici->cSonrakiOku();
            }

            if(sagSerbest==0)
            {
                cout<<"\n\t >>> "<<aranan<<" Sehrinden Kalkan Bir Ucus Yok...!"<<endl;
                PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
            }
            break;

        case 1: //varis yerine gore arama
            while(gecici!=&listeBasi)
            {
                if((gecici->varisYeriOku())==aranan)
                {
                    sagSerbest++;
                    cout<<*gecici;
                }
                gecici=gecici->cSonrakiOku();
            }

            if(sagSerbest==0)
            {
                cout<<"\n\t >>> "<<aranan<<" Sehrine Olan Bir Ucus Yok...!"<<endl;
                PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
            }
            break;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ara(String kalkis,String varis)
{
    Ucus *gecici=listeBasi.oncekiOku();
    int sagSerbest=0;

    while((gecici!=&listeBasi) && ((gecici->kalkisYeriOku())>=kalkis))
    {
        if((gecici->kalkisYeriOku())==kalkis && (gecici->varisYeriOku())==varis)
        {
            sagSerbest++;
            cout<<*gecici;
        }
        gecici=gecici->oncekiOku();
    }

    if(sagSerbest==0)
    {
        cout<<"\n\t >>> "<<kalkis<<" Sehrinden "<<varis<<" Sehrine Olan Bir Ucus Yok...!"<<endl;
        PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::cikar(Ucus *cikarilan)
{
    (cikarilan->oncekiOku())->cSonrakiAyarla(cikarilan->cSonrakiOku());
    (cikarilan->cSonrakiOku())->oncekiAyarla(cikarilan->oncekiOku());
}

ostream &operator<<(ostream &cikti,Kalkis_Yerine_Gore_Ucus_Listesi &ucus) //<< operatoru asiri yukleniyor
{
    Ucus *gecici=(ucus.listeBasi).cSonrakiOku();

    while(gecici!=&(ucus.listeBasi))
    {
        cikti<<*gecici;
        gecici=gecici->cSonrakiOku();
    }

    return cikti;
}
