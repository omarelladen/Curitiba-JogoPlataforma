/*#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() :
    listaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void Listas::ListaEntidades::clear()
{
    listaEntidades.clear();
}

void ListaEntidades::addEntidade(Entidade* entid) // mudar de set para add
{
    listaEntidades.addElemento(entid);
}

void ListaEntidades::deleteEntidade(Entidade* entid)
{
    listaEntidades.deleteElemento(entid);
}

void ListaEntidades::deleteEntidade(int pos) // precisa?
{
    listaEntidades.deleteElemento(listaEntidades[pos]);
}

Entidade* ListaEntidades::getEntidade(int pos)
{
    return listaEntidades.getClassOrigin(pos);
}

Entidade* ListaEntidades::operator[](int pos)
{
    return listaEntidades[pos];
}

const int ListaEntidades::getTamLista() const//
{
    return listaEntidades.getTam();
}

void ListaEntidades::executar()
{
    Entidade* temp = NULL;
    for (int i = 0; i < getTamLista(); i++)
    {
        temp = getEntidade(i);
        if (temp)
        {
            temp->executar();
        }
        else
        {
            Ente::getManager()->fechaJanela();
        }
    }
}*/


#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() :
    listaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::clear()
{
    listaEntidades.clear();
}

void ListaEntidades::addEntidade(Entidade* entid) // mudar de set para add
{
    listaEntidades.push_back(entid);
}

/*void ListaEntidades::deleteEntidade(Entidade entid)
{
    listaEntidades.deleteElemento(entid);
}

void ListaEntidades::deleteEntidade(int pos) // precisa?
{
    listaEntidades.deleteElemento(listaEntidades[pos]);
}*/

Entidade * ListaEntidades::getEntidade(int pos)
{
    return listaEntidades[pos];
}

Entidade* ListaEntidades::operator[](int pos)
{
    return listaEntidades[pos];
}

void ListaEntidades::salvarEntidades()
{
    for (int i = 0; i < getTamLista(); i++)
    {
        getEntidade(i)->salvar();
    }
}

void ListaEntidades::recuperarEntidades()
{
    Capivara jogador;
    ChefeMafia mafioso;
    Capanga capanga;
    Jacare crocodilo;
    Arvore arvore;
    Lixo lixao;
    Bicicleta bike;
    Chao piso;

    this->operator=(*(jogador.recuperar()));
    
}

const int ListaEntidades::getTamLista() const
{
    return listaEntidades.size();
}

void ListaEntidades::operator=(ListaEntidades& list)
{
    for (int i = 0; i < list.getTamLista(); i++)
    {
        addEntidade(list[i]);
    }
}

void ListaEntidades::executar()
{

    Entidade* temp = NULL;
    for (int i = 0; i < getTamLista(); i++)
    {
        temp = getEntidade(i);
        if (temp)
        {
            temp->executar();
        }
        else
        {
            Ente::getManager()->fechaJanela();
        }
    }
}