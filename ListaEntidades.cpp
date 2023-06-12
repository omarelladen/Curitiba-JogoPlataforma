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

void ListaEntidades::addEntidade(Entidade* entid)
{
    if(entid)
        listaEntidades.addElemento(entid);
    else
    {
        cout << "Adicionando Entidade nula na Lista" << endl;
    }
}

void ListaEntidades::deleteEntidade(Entidade* entid)
{
    listaEntidades.deleteElemento(entid);
}

Entidade* ListaEntidades::getEntidade(int pos)
{
    return listaEntidades[pos];
}

Entidade* ListaEntidades::operator[](int pos)
{
    return listaEntidades[pos];
}

const int ListaEntidades::getTamLista() const
{
    return listaEntidades.getTam();
}

void ListaEntidades::operator=(ListaEntidades* list)
{
    if (list)
    {
        for (int i = 0; i < list->getTamLista(); i++)
        {
            addEntidade(list->getEntidade(i));
        }
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