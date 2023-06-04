#include "ListaEntidades.h"

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

void ListaEntidades::setEntidade(Entidade* entid) // mudar de set para add
{
    listaEntidades.setElemento(entid);
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
}