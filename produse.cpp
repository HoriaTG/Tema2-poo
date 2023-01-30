#include "produse.h"
#include<iostream>
#include<vector>
#include<memory>
#include "exceptii.h"

echipament::echipament(const std::string &material,double pret,int stoc)
{
    this->material = material;
    this->pret = pret;
    this->stoc=stoc;
}

undita::undita(const std::string &material,double pret,int stoc,int lungime) : echipament(material,pret,stoc)
{
    this->lungime = lungime;
    if(this->lungime < 3 || this->lungime > 6)
        throw lungime_eronata("Lungimea minima a unditelor e 3 metri , iar cea maxima este 6 metri");
}

carlig::carlig(const std::string &material,double pret,int stoc,int dimensiune) : echipament(material,pret,stoc)
{
    this->dimensiune = dimensiune;
    if(this->dimensiune < 2 || this->dimensiune > 18)
        throw dimensiune_eronata("Dimensiunea minima a carligelor e 2 , iar cea maxima 18");
}

mamaliga::mamaliga(const std::string &material,double pret,int stoc,const std::string &culoare,const std::string &aroma) : echipament(material,pret,stoc)
{
    this->culoare = culoare;
    this->aroma = aroma;
}
std::ostream &operator<<(std::ostream &os,const undita &und)
{
        os<<"Material : "<<und.material<<std::endl<<"Pret : "<<und.pret<<std::endl
        <<"Stoc : "<<und.stoc<<std::endl<<"Lungime : "<<und.lungime<<std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os,const carlig &carr)
{
    os<<"Material : "<<carr.material<<std::endl<<"Pret : "<<carr.pret<<std::endl
    <<"Stoc : "<<carr.stoc<<std::endl<<"Dimensiune : "<<carr.dimensiune<<std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os,const mamaliga &mam)
{
    os<<"Material : "<<mam.material<<std::endl<<"Pret : "<<mam.pret<<std::endl
    <<"Stoc : "<<mam.stoc<<std::endl<<"Culoare : "<<mam.culoare<<std::endl<<"Aroma : "<<mam.aroma<<std::endl;
    return os;
}

std::shared_ptr<echipament> undita::clone()
{
    return std::make_shared<undita>(*this);
}

std::shared_ptr<echipament> carlig::clone()
{
    return std::make_shared<carlig>(*this);
}

std::shared_ptr<echipament> mamaliga::clone()
{
    return std::make_shared<mamaliga>(*this);
}

std::ostream &operator<<(std::ostream &os,const echipament &ech)
{
    os<<"Material : "<<ech.material<<std::endl<<"Pret : "<<ech.pret<<std::endl<<"Stoc : "<<ech.stoc<<std::endl;
    return os;
}

void echipament::swap( echipament &ech1, echipament &ech2)
{
    std::swap(ech1.material,ech2.material);
    std::swap(ech1.pret,ech2.pret);
    std::swap(ech1.stoc,ech2.stoc);
}

void undita::swap( undita &und1, undita &und2)
{
    std::swap(und1.material,und2.material);
    std::swap(und1.pret,und2.pret);
    std::swap(und1.stoc,und2.stoc);
    std::swap(und1.lungime,und2.lungime);
}

void carlig::swap( carlig &car1, carlig &car2)
{
    std::swap(car1.material,car2.material);
    std::swap(car1.pret,car2.pret);
    std::swap(car1.stoc,car2.stoc);
    std::swap(car1.dimensiune,car2.dimensiune);
}

void mamaliga::swap( mamaliga &mam1, mamaliga &mam2)
{
    std::swap(mam1.material,mam2.material);
    std::swap(mam1.pret,mam2.pret);
    std::swap(mam1.stoc,mam2.stoc);
    std::swap(mam1.aroma,mam2.aroma);
    std::swap(mam1.culoare,mam2.culoare);
}

echipament &echipament::operator=(echipament &other)
{
    swap(*this,other);
    return *this;
}

undita &undita::operator=(undita &other)
{
    swap(*this,other);
    return *this;
}

carlig &carlig::operator=(carlig &other)
{
    swap(*this,other);
    return *this;
}

mamaliga &mamaliga::operator=(mamaliga &other)
{
    swap(*this,other);
    return *this;
}

pachet_de_pescuit::pachet_de_pescuit(const std::vector<std::shared_ptr<undita> > &undite,const std::vector<std::shared_ptr<carlig> > &carlige,const std::vector<std::shared_ptr<mamaliga> > &mamaligi)
 {
     this->undite = undite;
     this->carlige = carlige;
     this->mamaligi = mamaligi;
 }
void pachet_de_pescuit::CalculInventar()
{
    int InvU,InvC,InvM;
    InvU = 0;
    InvC = 0;
    InvM = 0;

    for(auto i:this->undite)
        InvU = i->getPret()*i->getStoc() + InvU;
    for(auto i:this->carlige)
        InvC = i->getPret()*i->getStoc() + InvC;
    for(auto i:this->mamaligi)
        InvM = i->getPret()*i->getStoc() + InvM;

    std::cout<<"Pretul total al inventarului este : "<<InvU+InvC+InvM<<std::endl;
}

void undita::Calcul_Eficienta()
{
    if((pret/lungime)+10 > 30)
        std::cout<<"Eficienta ridicata "<<std::endl;
    else
        std::cout<<"Eficienta scazuta "<<std::endl;
}

void carlig::Calcul_Eficienta()
{
    if((dimensiune*pret)/stoc > 5)
         std::cout<<"Eficienta ridicata "<<std::endl;
    else
        std::cout<<"Eficienta scazuta "<<std::endl;
}

void mamaliga::Calcul_Eficienta()
{
    if((pret*pret)/4*stoc > 10)
        std::cout<<"Eficienta ridicata "<<std::endl;
    else
        std::cout<<"Eficienta scazuta "<<std::endl;
}

void pachet_de_pescuit::Eficienta()
{
    for(auto i:undite)
        i->Calcul_Eficienta();

    for(auto i:carlige)
        i->Calcul_Eficienta();

    for(auto i:mamaligi)
        i->Calcul_Eficienta();
}

void pachet_de_pescuit::Afisare()
{
    for(unsigned i=0; i<undite.size(); i++)
        std::cout<<*undite[i]<<std::endl;
    for(unsigned i=0; i<carlige.size(); i++)
        std::cout<<*carlige[i]<<std::endl;
    for(unsigned i=0; i<mamaligi.size(); i++)
        std::cout<<*mamaligi[i]<<std::endl;
}
