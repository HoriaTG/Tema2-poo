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
    virtual std::shared_ptr<echipament> clone() = 0 ;
    virtual ~echipament() = default;
    virtual void Calcul_Eficienta() = 0;
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
    std::shared_ptr<echipament> clone() override;
    virtual ~undita() = default;
    double getPret() const {return pret;}
    int getStoc() const {return stoc;}
    int getLungime() const {return lungime;}
    void Calcul_Eficienta() override;
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
    std::shared_ptr<echipament> clone() override;
    virtual ~carlig() = default;
    double getPret() const {return pret;}
    int getStoc() const {return stoc;}
    int getDimensiune() const {return dimensiune;}
    void Calcul_Eficienta() override;
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
    std::shared_ptr<echipament> clone() override;
    virtual ~mamaliga() = default;
    double getPret() const {return pret;}
    int getStoc() const {return stoc;}
    void Calcul_Eficienta() override;
};

class pachet_de_pescuit
{
private :
    std::vector<std::shared_ptr<undita> > undite;
    std::vector<std::shared_ptr<carlig> > carlige;
    std::vector<std::shared_ptr<mamaliga> > mamaligi;
public :
    pachet_de_pescuit(const std::vector<std::shared_ptr<undita> > &undite,const std::vector<std::shared_ptr<carlig> > &carlige,const std::vector<std::shared_ptr<mamaliga> > &mamaligi);
    void Eficienta();
    void CalculInventar();
    void Afisare();
};
#endif // PRODUSE_H
