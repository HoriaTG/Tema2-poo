#ifndef ANGAJAT_H
#define ANGAJAT_H
#include<iostream>
#include<vector>
#include<string>

class angajat
{
    private:
        std::string nume;
        double salariu;
        int ani_experienta;
    public:
        angajat(const std::string &nume,double salariu,int ani_experienta);
        friend std::ostream &operator<<(std::ostream &os, const angajat &ang);
        void promovare();
};

#endif // ANGAJAT_H
