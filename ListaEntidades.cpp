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

    ListaEntidades* pListJog = jogador.recuperar();

    ListaEntidades* pListInim = mafioso.recuperar();
    pListInim->operator=(capanga.recuperar());
    pListInim->operator=(crocodilo.recuperar());

    ListaEntidades* pListObsts = arvore.recuperar();
    pListObsts->operator=(lixao.recuperar());
    pListObsts->operator=(bike.recuperar());
    pListObsts->operator=(piso.recuperar());

    for (int i = 0; i < pListInim->getTamLista(); i++)
    {
        Inimigo* pInim = static_cast<Inimigo*>(pListInim->getEntidade(i));
        if (pInim)
        {
            pInim->setAlvo(static_cast<Capivara*>(pListJog->getEntidade(0)));
        }
    }

    this->operator=(*pListJog);
    this->operator=(*pListInim);
    this->operator=(*pListObsts);
}

const int ListaEntidades::getTamLista() const
{
    return listaEntidades.getTam();
}

void ListaEntidades::operator=(ListaEntidades* list)
{
    for (int i = 0; i < list->getTamLista(); i++)
    {
        addEntidade(list->getEntidade(i));
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