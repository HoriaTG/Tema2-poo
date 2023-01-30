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

class ani_insuficienti : public eroare
{
public :
    explicit ani_insuficienti(const std::string &string_) : eroare(" nu promoveaza..." + string_){}
};

class stoc_redus : public eroare
{
public :
    explicit stoc_redus(const std::string &string_) : eroare(" stoc redus ..." + string_){}
};
#endif // EXCEPTII_H
