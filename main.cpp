#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include "angajat.h"
#include "magazin.h"
#include "produse.h"
#include "exceptii.h"

int main()
{
    std::shared_ptr<undita> p1,p2,p3;
    std::shared_ptr<carlig> p4,p5,p6;
    std::shared_ptr<mamaliga> p7,p8,p9;
    std::vector<angajat> v1;

    try
    {
        angajat ang1("Horia",1700,6);
        angajat ang2("Florin",2000,10);
        v1.push_back(ang1);
        v1.push_back(ang2);

        p1 = std::make_shared<undita>("Carbon",100,10,5);
        p2 = std::make_shared<undita>("Plastic",200,15,3);
        p3 = std::make_shared<undita>("Carbon",300,20,4);
        p4 = std::make_shared<carlig>("Fier",20,10,6);
        p5 = std::make_shared<carlig>("Otel",30,15,8);
        p6 = std::make_shared<carlig>("Fier",40,20,12);
        p7 = std::make_shared<mamaliga>("Malai",10,5,"Rosu","Pepene");
        p8 = std::make_shared<mamaliga>("Malai",20,10,"Roz","Zmeura");
        p9 = std::make_shared<mamaliga>("Malai",20,30,"Alb","Usturoi");
    }
    catch(lungime_eronata &err)
    {
        std::cout<<err.what()<<std::endl;
    }
    catch(dimensiune_eronata &err)
    {
        std::cout<<err.what()<<std::endl;
    }
    catch(necalificat &err)
    {
        std::cout<<err.what()<<std::endl;
    }

    magazin mag("Kogalniceanu 14",v1);
    std::cout<<mag;

    std::shared_ptr<echipament> ech1 = std::make_shared<undita>("Bambus",50,80,6);
    std::shared_ptr<echipament> ech2 = std::make_shared<undita>("Lemn",80,100,5);
    ech2 = ech1->clone();
    std::cout<<*ech1<<std::endl<<*ech2<<std::endl;

    std::vector<std::shared_ptr<undita>> undite;
    undite.push_back(p1);
    undite.push_back(p2);
    undite.push_back(p3);
    std::vector<std::shared_ptr<carlig>> carlige ;
    carlige.push_back(p4);
    carlige.push_back(p5);
    carlige.push_back(p6);
    std::vector<std::shared_ptr<mamaliga>> mamaligi;
    mamaligi.push_back(p7);
    mamaligi.push_back(p8);
    mamaligi.push_back(p9);

    for(unsigned i=0; i<undite.size(); i++)
        std::cout<<*undite[i]<<std::endl;
    for(unsigned i=0; i<carlige.size(); i++)
        std::cout<<*carlige[i]<<std::endl;
    for(unsigned i=0; i<mamaligi.size(); i++)
        std::cout<<*mamaligi[i]<<std::endl;

    std::vector<std::shared_ptr<echipament> > sor;
    for(auto i:undite)
        sor.push_back(i);
    for(auto i:carlige)
        sor.push_back(i);
    for(auto i:mamaligi)
        sor.push_back(i);

    static int val;
    for(auto i:sor)
    {
        val = val + i->valoare_inventar();
    }
    std::cout<<"Valoarea totala a inventarului : "<<val<<std::endl;

    for(auto i:v1)
        i.promovare();

    for(auto i:undite)
        if(i->Eficienta() == 1)
            std::cout<<"Eficienta ridicata"<<std::endl;
        else std::cout<<"Eficienta scazuta"<<std::endl;
    for(auto i:carlige)
        if(i->Eficienta() == 1)
            std::cout<<"Eficienta ridicata"<<std::endl;
        else std::cout<<"Eficienta scazuta"<<std::endl;
    for(auto i:mamaligi)
        if(i->Eficienta() == 1)
            std::cout<<"Eficienta ridicata"<<std::endl;
        else std::cout<<"Eficienta scazuta"<<std::endl;

    return 0;
}
