#include "angajat.h"
#include "exceptii.h"

angajat::angajat(const std::string &nume, double salariu,int ani_experienta)
{
    this->nume = nume;
    this->salariu = salariu;
    this->ani_experienta = ani_experienta;
    if(this->ani_experienta < 5 )
        throw necalificat("Minim 5 ani de experienta in domeniu");
}

std::ostream &operator<<(std::ostream &os,const angajat &ang)
{
        os<<"Nume : "<<ang.nume<<std::endl<<"Salariu : "<<ang.salariu<<std::endl<<"Ani experienta : "<<ang.ani_experienta<<std::endl;
    return os;
}

void angajat::promovare()
{
    std::cout<<"Angajatul "<<nume;
    if(ani_experienta>5 && ani_experienta<10)
        std::cout<<" nu promoveaza"<<std::endl<<std::endl;
    else
    if(ani_experienta>=10 && ani_experienta<15)
        std::cout<<" promoveaza la functia de sef de tura"<<std::endl<<std::endl;
    else
    if(ani_experienta>=15)
        std::cout<<" promoveaza la functia de sef general"<<std::endl<<std::endl;
}
