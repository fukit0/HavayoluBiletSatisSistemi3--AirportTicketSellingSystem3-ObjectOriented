#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "String.h"
#include "Ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"

using namespace std;

int menuSecim();
void baslikYazdir();
void hakkinda();
void beklet();

int main()
{
    system("title Havayolu Ucus Takip Sistemi");
    system("color f9");

    Ucus *ucus;
    Ucus_Numarasina_Gore_Ucus_Listesi liste1;
    Kalkis_Yerine_Gore_Ucus_Listesi liste2;
    String *kalkisYeri,*varisYeri,*kalkisZamani;
    int ucusNo,normalKoltukSayisi,luksKoltukSayisi;
    int secim;

    do{
        secim=menuSecim();
        switch(secim)
        {
            case 1:
                cout<<"\n\t >> Lutfen Ucus Numarasini Giriniz : ";
                cin>>ucusNo;
                if(liste1.ara(ucusNo)==NULL)
                {
                    kalkisYeri=new String();
                    varisYeri=new String();
                    kalkisZamani=new String();
                    cout<<"\n\t >> Kalkis Yerini Giriniz : ";
                    fflush(stdin);
                    cin>>*kalkisYeri;
                    cout<<"\n\t >> Varis Yerini Giriniz : ";
                    fflush(stdin);
                    cin>>*varisYeri;
                    cout<<"\n\t >> Kalkis Zamanini Giriniz : ";
                    fflush(stdin);
                    cin>>*kalkisZamani;
                    cout<<"\n\t >> Normal Koltuk Sayisini Giriniz : ";
                    cin>>normalKoltukSayisi;
                    luksKoltukSayisi=0;
                    ucus=new Ucus(ucusNo,*kalkisYeri,*varisYeri,*kalkisZamani,normalKoltukSayisi,luksKoltukSayisi);
                    liste1.ekle(ucus);
                    liste2.ekle(ucus);
                    cout<<"\n\t *** Ucusunuz Basariyla Eklenmistir..."<<endl;
                }
                else
                {
                    cout<<"\n\t >>> Bu Numaraya Sahip Ucus Daha Onceden Eklenmistir...!"<<endl;
                    PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
                }
                break;

            case 2:
                cout<<"\n\t >> Lutfen Ucus Numarasini Giriniz : ";
                cin>>ucusNo;
                if(liste1.ara(ucusNo)==NULL)
                {
                    kalkisYeri=new String();
                    varisYeri=new String();
                    kalkisZamani=new String();
                    cout<<"\n\t >> Kalkis Yerini Giriniz : ";
                    fflush(stdin);
                    cin>>*kalkisYeri;
                    cout<<"\n\t >> Varis Yerini Giriniz : ";
                    fflush(stdin);
                    cin>>*varisYeri;
                    cout<<"\n\t >> Kalkis Zamanini Giriniz : ";
                    fflush(stdin);
                    cin>>*kalkisZamani;
                    cout<<"\n\t >> Normal Koltuk Sayisini Giriniz : ";
                    cin>>normalKoltukSayisi;
                    cout<<"\n\t >> Luks Koltuk Sayisini Giriniz : ";
                    cin>>luksKoltukSayisi;
                    ucus=new Ucus(ucusNo,*kalkisYeri,*varisYeri,*kalkisZamani,normalKoltukSayisi,luksKoltukSayisi);
                    liste1.ekle(ucus);
                    liste2.ekle(ucus);
                    cout<<"\n\t *** Ucusunuz Basariyla Eklenmistir..."<<endl;
                }
                else
                {
                    cout<<"\n\t >>> Bu Numaraya Sahip Ucus Daha Onceden Eklenmistir...!"<<endl;
                    PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
                }
                break;

            case 3:
                cout<<"\n\t >> Lutfen Ucus Numarasini Giriniz : ";
                cin>>ucusNo;
                if((ucus=liste1.ara(ucusNo))==NULL)
                {
                    cout<<"\n\t >>> Malesef Bu Numarali Bir Ucus Bulunmamaktadir...!"<<endl;
                    PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
                }
                else
                {
                    cout<<"\n\t >> Lutfen Yeni Luks Koltuk Sayisini Giriniz : ";
                    cin>>luksKoltukSayisi;
                    ucus->luksKoltukAyarla(luksKoltukSayisi);
                    cout<<"\n\t *** Koltuk Sayisi Basariyla Guncellenmistir..."<<endl;
                }
                break;

            case 4:
                cout<<"\n\t >> Lutfen Ucus Numarasini Giriniz : ";
                cin>>ucusNo;
                if((ucus=liste1.ara(ucusNo))==NULL)
                {
                    cout<<"\n\t >>> Malesef Bu Numarali Bir Ucus Bulunmamaktadir...!"<<endl;
                    PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
                }
                else
                {
                    liste1.cikar(ucus);
                    liste2.cikar(ucus);
                    delete ucus;
                    cout<<"\n\t *** Ucus Basariyla Iptal edilmistir..."<<endl;
                }
                break;

            case 5:
                cout<<"\n\t >> Lutfen Ucus Numarasini Giriniz : ";
                cin>>ucusNo;
                if((ucus=liste1.ara(ucusNo))==NULL)
                {
                    cout<<"\n\t >>> Malesef Bu Numarali Bir Ucus Bulunmamaktadir...!"<<endl;
                    PlaySound(TEXT("SystemHand"),NULL,SND_ALIAS);
                }
                else
                {
                    baslikYazdir();
                    cout<<*ucus;
                }
                break;

            case 6:
                baslikYazdir();
                liste1.luksListele();
                break;

            case 7:
                varisYeri=new String();
                cout<<"\n\t >> Lutfen Varis Yerini Giriniz : ";
                fflush(stdin);
                cin>>*varisYeri;
                baslikYazdir();
                liste2.ara(*varisYeri,1);
                delete varisYeri;
                break;

            case 8:
                kalkisYeri=new String();
                cout<<"\n\t >> Lutfen Kalkis Yerini Giriniz : ";
                fflush(stdin);
                cin>>*kalkisYeri;
                baslikYazdir();
                liste2.ara(*kalkisYeri,0);
                delete kalkisYeri;
                break;

            case 9:
                kalkisYeri=new String();
                varisYeri=new String();
                cout<<"\n\t >> Lutfen Kalkis Yerini Giriniz : ";
                fflush(stdin);
                cin>>*kalkisYeri;
                cout<<"\n\t >> Lutfen Varis Yerini Giriniz : ";
                fflush(stdin);
                cin>>*varisYeri;
                baslikYazdir();
                liste2.ara(*kalkisYeri,*varisYeri);
                delete kalkisYeri;
                delete varisYeri;
                break;

            case 10:
                baslikYazdir();
                cout<<liste1;
                cout<<endl;
                baslikYazdir();
                cout<<liste2;
                break;

            case 11:
                hakkinda();
        }
    }while(secim!=11);

    return 0;
}

int menuSecim()
{
    int secim;

    cout<<endl
        <<"\n    ************************ MENU ***************************"<<endl
        <<"\n\t 1. Luks koltuk icermeyen yeni bir ucusun eklenmesi"<<endl
        <<"\t 2. Luks koltuk iceren yeni bir ucusun eklenmesi"<<endl
        <<"\t 3. Bir ucusun luks koltuk sayisinin guncellenmesi"<<endl
        <<"\t 4. Bir ucusun iptal edilmesi"<<endl
        <<"\t 5. Bir ucusun bilgilerinin goruntulenmesi"<<endl
        <<"\t 6. Luks koltuk iceren ucuslarin listelenmesi"<<endl
        <<"\t 7. Bir yere olan ucuslarin listelenmesi"<<endl
        <<"\t 8. Bir yerden kalkan ucuslarin listelenmesi"<<endl
        <<"\t 9. Bir yerden bir yere olan ucuslarin listelenmesi"<<endl
        <<"\t10. Tum ucuslarin listelenmesi"<<endl
        <<"\t11. Cikis"<<endl
        <<endl;

    do{
        cout<<"\n\t >>> Lutfen seciminizi yapiniz : ";
        cin>>secim;
    }while(secim<1 || secim>11);

    return secim;
}

void baslikYazdir()
{
    cout<<endl
        <<"\n     Ucus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "
        <<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
        <<"     -------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "
        <<"-----"<<"   "<<"-------------"<<"   "<<"-----------"<<endl;
}

void hakkinda()
{
    for(int i=15;i>0;i--)
    {
        system("cls");
        for(int j=0;j<i;j++)
            cout<<endl;
        cout<<"\n\t ***...Programimizi Kullandiginiz Icin Tesekkur Ederiz...***\n\n"<<endl
            <<"\t                     Yapimcilar"<<endl
            <<"\t                     ----------\n"<<endl
            <<"\t                   Onur Cem Senel\n"<<endl
            <<"\t                  Furkan Tanriverdi\n"<<endl
            <<"\t                     Burak Yabar\n"<<endl;
        beklet();
    }
    PlaySound(TEXT("SystemExit"),NULL,SND_ALIAS);
}

void beklet()
{
    for(long int i=0;i<50000000;i++) {}
}
