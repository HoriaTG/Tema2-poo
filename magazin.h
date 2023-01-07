#ifndef MAGAZIN_H
#define MAGAZIN_H
#include<vector>
#include<iostream>
#include<string>
#include "angajat.h"

class magazin
{
    private:
        std::string adresa;
        std::vector<angajat> ang;
    public:
        magazin(const std::string &adresa,const std::vector<angajat> &ang);
        friend std::ostream &operator<<(std::ostream &os,const magazin &mag);

};

#endif // MAGAZIN_H
