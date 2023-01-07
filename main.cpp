#include <iostream>
#include <vector>
#include <memory>
#include "angajat.h"
#include "magazin.h"
#include "produse.h"
#include "exceptii.h"

int main()
{
    try
    {
        angajat ang1("Horia",1700,6);
        angajat ang2("Florin",2000,10);

        std::vector<angajat> v1;
        v1.push_back(ang1);
        v1.push_back(ang2);

        magazin mag("Kogalniceanu 14",v1);
        std::cout<<mag;

        std::shared_ptr<undita> p1 = std::make_shared<undita>("Carbon",100,10,5);
        std::shared_ptr<undita> p2 = std::make_shared<undita>("Plastic",200,15,3);
        std::shared_ptr<undita> p3 = std::make_shared<undita>("Carbon",300,20,4);

        std::shared_ptr<echipament> ech1 = std::make_shared<undita>("Bambus",50,80,6);
        std::shared_ptr<echipament> ech2 = std::make_shared<undita>("Lemn",80,100,5);
        ech2 = ech1->clone();
        std::cout<<*ech1<<std::endl<<*ech2<<std::endl;

        std::vector<std::shared_ptr<undita>> undite;
        undite.push_back(p1);
        undite.push_back(p2);
        undite.push_back(p3);

        std::shared_ptr<carlig> p4 = std::make_shared<carlig>("Fier",20,10,6);
        std::shared_ptr<carlig> p5 = std::make_shared<carlig>("Otel",30,15,8);
        std::shared_ptr<carlig> p6 = std::make_shared<carlig>("Fier",40,20,12);

        std::vector<std::shared_ptr<carlig>> carlige ;
        carlige.push_back(p4);
        carlige.push_back(p5);
        carlige.push_back(p6);

        std::shared_ptr<mamaliga> p7 = std::make_shared<mamaliga>("Malai",10,5,"Rosu","Pepene");
        std::shared_ptr<mamaliga> p8 = std::make_shared<mamaliga>("Malai",20,10,"Roz","Zmeura");
        std::shared_ptr<mamaliga> p9 = std::make_shared<mamaliga>("Malai",20,30,"Alb","Usturoi");
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

        for(unsigned i=0; i<v1.size(); i++)
            v1[i].promovare();

        double valoare_inventar = 0;
        double valoare_undite = 0;
        double valoare_carlige = 0;
        double valoare_mamaligi = 0;
        for(unsigned i=0; i<undite.size(); i++)
        {
            valoare_inventar = valoare_inventar + undite[i]->pret_total();
            valoare_undite = valoare_undite + undite[i]->pret_total();
            undite[i]->Descriere_inventar_general();
        }

        for(unsigned i=0; i<carlige.size(); i++)
        {
            valoare_inventar = valoare_inventar + carlige[i]->pret_total();
            valoare_carlige = valoare_carlige + carlige[i]->pret_total();
            carlige[i]->Descriere_inventar_general();
        }

        for(unsigned i=0; i<mamaligi.size(); i++)
        {
            valoare_inventar = valoare_inventar + mamaligi[i]->pret_total();
            valoare_mamaligi = valoare_mamaligi + mamaligi[i]->pret_total();
            mamaligi[i]->Descriere_inventar_general();
        }
        std::cout<<"Valoarea totala a unditelor : "<<valoare_undite<<std::endl;
        std::cout<<"Valoarea totala a carligelor : "<<valoare_carlige<<std::endl;
        std::cout<<"Valoarea totala a mamaligilor : "<<valoare_mamaligi<<std::endl;
        std::cout<<"Valoarea totala a inventarului : "<<valoare_inventar<<std::endl<<std::endl;


        double sum;
        std::cout<<"Introdu o suma de bani : ";
        std::cin>>sum;
        std::cout<<"Ce vrei sa cumperi ? 0 = undite , 1 = carlige , 2 = mamaligi . Introdu un numar"<<std::endl;
        int optiune;
        std::cin>>optiune;
        if(optiune<0 || optiune >3)
            throw optiune_gresita("Optiunea trebuie sa fie 0,1,2 . Orice alta valoare nu e buna");
        switch(optiune)
        {
        case 0 :
        {
            for(unsigned i=0; i<undite.size(); i++) undite[i]->shopping(sum);
            break;
        }
        case 1 :
        {
            for(unsigned i=0; i<carlige.size(); i++) carlige[i]->shopping(sum);
            break;
        }
        case 2 :
        {
            for(unsigned i=0; i<mamaligi.size(); i++) mamaligi[i]->shopping(sum);
            break;
        }

        }
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
    catch(optiune_gresita &err)
    {
        std::cout<<err.what()<<std::endl;
    }

    return 0;
}
