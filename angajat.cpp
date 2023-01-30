#include "angajat.h"
#include "exceptii.h"

angajat::angajat(const std::string &nume_firma_arg,const std::string &nume, double salariu,int ani_experienta)
{
    angajat::nume_firma = nume_firma_arg;
    this->nume = nume;
    this->salariu = salariu;
    this->ani_experienta = ani_experienta;
    if(this->ani_experienta < 5 )
        throw necalificat("Minim 5 ani de experienta in domeniu");
}

std::string angajat::nume_firma = "Fishin'Legends";

std::ostream &operator<<(std::ostream &os,const angajat &ang)
{
        os<<"Firma : "<<ang.nume_firma<<std::endl<<"Nume : "<<ang.nume<<std::endl<<"Salariu : "<<ang.salariu<<std::endl<<"Ani experienta : "<<ang.ani_experienta<<std::endl;
    return os;
}

void angajat::promovare()
{
    std::cout<<"Angajatul "<<nume;
    if(ani_experienta>5 && ani_experienta<10)
        throw ani_insuficienti(" ani insuficienti");
    else
    if(ani_experienta>=10 && ani_experienta<15)
        std::cout<<" promoveaza la functia de sef de tura"<<std::endl<<std::endl;
    else
    if(ani_experienta>=15)
        std::cout<<" promoveaza la functia de sef general"<<std::endl<<std::endl;
}
