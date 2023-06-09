#include "ConstrutorEntidade.h"

    ConstrutorEntidade::ConstrutorEntidade() :
    pJogador(nullptr)
{
}

ConstrutorEntidade::~ConstrutorEntidade()
{
    pJogador = nullptr;
}

void ConstrutorEntidade::setJogador(Capivara* pJ)
{
    if (pJ)
        pJogador = pJ;
    else
        cout << "Setando ponteiro Jogador nulo em ContrutorEntidade" << endl;
}

Capivara* ConstrutorEntidade::getJogador()
{
    return pJogador;
}

Entidade* ConstrutorEntidade::criarPlataforma(Vector2f pos) // criar derivadas da plataforma
{
    Chao* pP = new Chao(Vector2f(pos.x * 50.f, pos.y * 50));
    if(pP)
        return static_cast<Entidade*>(pP);
    else
    {
        cout << "Entidade nula" << endl;
        exit(1);
    }
}

Entidade* ConstrutorEntidade::criarBicicleta(Vector2f pos)
{
    Bicicleta* pB = new Bicicleta(Vector2f(pos.x * 50.f, pos.y * 50));
    if (pB)
        return static_cast<Entidade*>(pB);
    else
    {
        cout << "Entidade nula" << endl;
        exit(1);
    }
}
/*Entidade* ConstrutorEntidade::criarCapivara(Vector2f pos)
{
    Capivara* pC = new Capivara(Vector2f(pos.x * 50, pos.y * 50));
    return static_cast<Entidade*>(pC);
}

Entidade* ConstrutorEntidade::criarPolicial(Vector2f(pos))
{
    Policial* pP = new Policial(Vector2f(pos.x * 50, pos.y * 50));
    return static_cast<Entidade*>(pP);
}*/

Entidade* ConstrutorEntidade::criarJacare(Vector2f pos)
{
    Jacare* pJ = new Jacare(Vector2f(pos.x * 50.f, pos.y * 50));
    if (pJ)
    {
        pJ->setAlvo(pJogador);
        return static_cast<Entidade*>(pJ);
    }
    else
    {
        cout << "Entidade nula" << endl;
        exit(1);
    }
}

Entidade* ConstrutorEntidade::criarCapanga(Vector2f(pos))
{
    Capanga* pC = new Capanga(Vector2f(pos.x * 50.f, pos.y * 50));
    if (pC)
    {
        pC->setAlvo(pJogador);
        return static_cast<Entidade*>(pC);
    }
    else
    {
        cout << "Entidade nula" << endl;
        exit(1);
    }
}

Entidade* ConstrutorEntidade::criarChefeMafia(Vector2f(pos))
{
    ChefeMafia* pCM = new ChefeMafia(Vector2f(pos.x * 50.f, pos.y * 50));
    if (pCM)
    {
        pCM->setAlvo(pJogador);
        return static_cast<Entidade*>(pCM);
    }
    else
    {
        cout << "Entidade nula" << endl;
        exit(1);
    }
}