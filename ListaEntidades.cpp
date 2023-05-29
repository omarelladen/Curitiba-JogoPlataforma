#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() :
    LEs()
{
}

ListaEntidades::~ListaEntidades()
{
}

void Listas::ListaEntidades::clear()
{
    LEs.clear();
}

void ListaEntidades::setEntidade(Entidade* entid)
{
    LEs.setElemento(entid);
}

void ListaEntidades::deleteEntidade(Entidade* entid)
{
    LEs.deleteElemento(entid);
}

Entidade* ListaEntidades::getEntidade(int pos)
{
    return LEs.getClassOrigin(pos);
}

const int ListaEntidades::getTamLista() const
{
    return LEs.getTam();
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