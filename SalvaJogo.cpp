#include "SalvaJogo.h"
#include<iostream>
using namespace std;

SalvaJogo::SalvaJogo():
    listaEntidades(nullptr),
    pFase(nullptr)
{
}

SalvaJogo::~SalvaJogo()
{
    listaEntidades = nullptr;
}

void SalvaJogo::save()
{
    ofstream SalvamentoJogo("SaveJogo.dat", ios::out);

    if (!SalvamentoJogo)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Entidade* auxEnt = nullptr;

    if (listaEntidades)
    {
        for (int i = 0; i < listaEntidades->getTamLista(); i++)
        {
            auxEnt = listaEntidades[i][0];
            if (auxEnt)
            {
                int id = (int) auxEnt->getID();
                SalvamentoJogo << auxEnt->getPosicao().x << ' '
                               << auxEnt->getPosicao().y << ' '
                               << auxEnt->getTamanho().x << ' '
                               << auxEnt->getTamanho().y << ' '
                               << id << endl;
            }
        }
    }
    SalvamentoJogo.close();
}

void SalvaJogo::saveRelacoes()
{

}

void SalvaJogo::recuperaSave()
{
    ifstream RecuperaSave("SaveJogo.dat", ios::in);

    if (!RecuperaSave)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    if (listaEntidades)
        listaEntidades->clear();
    else
        listaEntidades = new ListaEntidades();

    Entidade* auxEnt = nullptr;
    Vector2f pos;
    Vector2f tam;
    short id;
    

    while (RecuperaSave >> pos.x >> pos.y >> tam.x >> tam.y >> id)
    {
        if (id == (int) IDs::capivara)
        {
            auxEnt = new Capivara(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::policial)
        {
            auxEnt = new Policial(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::chefeMafia)
        {
            auxEnt = new ChefeMafia(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::jacare)
        {
            auxEnt = new Jacare(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::capanga)
        {
            auxEnt = new Capanga(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::projetil)
        {
            auxEnt = new Projetil(tam);
            if (auxEnt)
            {
                auxEnt->setPosicao(pos);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        else if (id == (int) IDs::plataforma)
        {
            auxEnt = new Plataforma(tam);
            if (auxEnt)
            {
                auxEnt->setPosicao(pos);
                listaEntidades->addEntidade(auxEnt);
            }
        }
        /*else if (id == IDs::bicicleta)
        {
            auxEnt = new Bicicleta(pos);
            if (auxEnt)
            {
                auxEnt->setTamanho(tam);
                listaEntidades->setEntidade(auxEnt);
            }
        }*/
    }
    RecuperaSave.close();
}

void SalvaJogo::recuperaRelacoes()
{
}
