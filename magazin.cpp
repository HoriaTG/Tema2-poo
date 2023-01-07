#include "magazin.h"
#include "angajat.h"

magazin::magazin(const std::string &adresa,const std::vector<angajat> &ang)
{
    this->adresa = adresa;
    this->ang = ang;
}

std::ostream &operator<<(std::ostream &os,const magazin &mag)
{
    for(unsigned i=0;i<mag.ang.size();i++)
        os<<"Adresa : "<<mag.adresa<<std::endl<<mag.ang[i]<<std::endl;
    return os;
}
