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
    //Pequeno problema com desalocacao

    Capivara jogador;
    ChefeMafia mafioso;
    Capanga capanga;
    Jacare crocodilo;
    Arvore arvore;
    Lixo lixao;
    Bicicleta bike;
    Chao piso;

    ListaEntidades* pListJog = new ListaEntidades();
    pListJog = jogador.recuperar();

    ListaEntidades* pListInim = new ListaEntidades();
    pListInim = mafioso.recuperar();
    pListInim = capanga.recuperar();
    pListInim = crocodilo.recuperar();

    ListaEntidades* pListObsts = new ListaEntidades();
    pListObsts = arvore.recuperar();
    pListObsts = lixao.recuperar();
    pListObsts = bike.recuperar();
    pListObsts = piso.recuperar();

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