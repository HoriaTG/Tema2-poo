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
    std::vector<std::shared_ptr<undita>> undite;
    std::vector<std::shared_ptr<carlig>> carlige ;
    std::vector<std::shared_ptr<mamaliga>> mamaligi;

    std::shared_ptr<echipament> ech1 = std::make_shared<undita>("Bambus",50,80,6);
    std::shared_ptr<echipament> ech2 = std::make_shared<undita>("Lemn",80,100,5);
    ech2 = ech1->clone();
    std::cout<<*ech1<<std::endl<<*ech2<<std::endl;

    try
    {
        angajat ang1("Carp","Horia",1700,15);
        angajat ang2("Fishin'Legends","Florin",2000,10);
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

        undite.push_back(p1);
        undite.push_back(p2);
        undite.push_back(p3);

        carlige.push_back(p4);
        carlige.push_back(p5);
        carlige.push_back(p6);

        mamaligi.push_back(p7);
        mamaligi.push_back(p8);
        mamaligi.push_back(p9);

        for(auto i:v1)
            i.promovare();

        pachet_de_pescuit pac(undite,carlige,mamaligi);
        pac.Afisare();
        pac.CalculInventar();
        pac.Eficienta();
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
    catch(ani_insuficienti &err)
    {
        std::cout<<err.what()<<std::endl;
    }

    magazin mag("Kogalniceanu 14",v1);

    return 0;
}
