#ifndef PRODUSE_H
#define PRODUSE_H
#include<iostream>
#include<vector>
#include<memory>
#include<string>

class echipament
{
protected :
    std::string material;
    double pret;
    int stoc;
public :
    echipament(const std::string &material,double pret,int stoc);
    friend std::ostream &operator<<(std::ostream &os,const echipament &ech);
    echipament(const echipament &other) = default;
    echipament &operator=(echipament &other);
    void swap( echipament &ech1, echipament &ech2);
    int pret_total();
    virtual std::shared_ptr<echipament> clone() = 0 ;
    int valoare_inventar();
    virtual int Eficienta() = 0;
    virtual ~echipament() = default;
};

class undita : public echipament
{
private :
    int lungime;
public :
    undita(const std::string &material,double pret,int stoc,int lungime);
    friend std::ostream &operator<<(std::ostream &os,const undita &und);
    undita(const undita &other) = default;
    undita &operator=(undita &other);
    void swap( undita &und1, undita &und2);
    int pret_total();
    std::shared_ptr<echipament> clone() override;
    int Eficienta() override;
    virtual ~undita() = default;
};

class carlig : public echipament
{
private :
    int dimensiune;
public :
    carlig(const std::string &material,double pret,int stoc,int dimensiune);
    friend std::ostream &operator<<(std::ostream &os,const carlig &carr);
    carlig(const carlig &other) = default;
    carlig &operator=(carlig &other);
    void swap( carlig &car1, carlig &car2);
    int pret_total();
    std::shared_ptr<echipament> clone() override;
    int Eficienta() override;
    virtual ~carlig() = default;
};

class mamaliga : public echipament
{
private :
    std::string culoare;
    std::string aroma;
public :
    mamaliga(const std::string &material,double pret,int stoc,const std::string &culoare,const std::string &aroma);
    friend std::ostream &operator<<(std::ostream &os,const mamaliga &mam);
    mamaliga(const mamaliga &other) = default;
    mamaliga &operator=(mamaliga &other);
    void swap( mamaliga &mam1, mamaliga &mam2);
    int pret_total();
    std::shared_ptr<echipament> clone() override;
    int Eficienta() override;
    virtual ~mamaliga() = default;
};
#endif // PRODUSE_H
