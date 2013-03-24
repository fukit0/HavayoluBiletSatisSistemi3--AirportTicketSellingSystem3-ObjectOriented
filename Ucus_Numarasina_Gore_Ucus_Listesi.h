#ifndef UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#define UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#include "Ucus.h"

class Ucus_Numarasina_Gore_Ucus_Listesi {
    friend ostream &operator<<(ostream &,const Ucus_Numarasina_Gore_Ucus_Listesi &);
private:
    Ucus *ilk;
public:
    Ucus_Numarasina_Gore_Ucus_Listesi();
    void ekle(Ucus *);
    Ucus *ara(int);
    void cikar(Ucus *);
    void luksListele();
};

#endif // UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
