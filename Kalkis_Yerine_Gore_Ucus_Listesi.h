#ifndef KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#define KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#include "String.h"
#include "Ucus.h"

class Kalkis_Yerine_Gore_Ucus_Listesi {
    friend ostream &operator<<(ostream &,Kalkis_Yerine_Gore_Ucus_Listesi &);
private:
    Ucus listeBasi;
public:
    Kalkis_Yerine_Gore_Ucus_Listesi();
    void ekle(Ucus *);
    Ucus *ara(int);
    void ara(String,int);
    void ara(String,String);
    void cikar(Ucus *);
};

#endif // KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
