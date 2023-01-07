#ifndef EXCEPTII_H
#define EXCEPTII_H

#include<stdexcept>
#include<string>
#include<vector>

class eroare : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class lungime_eronata : public eroare
{
public :
    explicit lungime_eronata(const std::string &string_) : eroare("Eroare lungime..." + string_){}
};

class dimensiune_eronata : public eroare
{
public :
    explicit dimensiune_eronata(const std::string &string_) : eroare("Eroare dimensiune..." + string_) {}
};

class necalificat : public eroare
{
public :
    explicit necalificat(const std::string &string_) : eroare("Eroare angajat..." + string_) {}
};
class optiune_gresita : public eroare
{
    public :
    explicit optiune_gresita(const std::string &string_) : eroare("Eroare optiune..." + string_){}
};
#endif // EXCEPTII_H
