#include "ConstrutorEntidade.h"

Entidade* ConstrutorEntidade::criarPlataforma(Vector2f pos)
{
    Plataforma* pP = new Plataforma(pos);

    return pP;
}

Entidade* ConstrutorEntidade::criarJogador(Vector2f pos)
{
    return nullptr;
}

Entidade* ConstrutorEntidade::criarObstaculo1(Vector2f pos)
{
    return nullptr;
}

Entidade* ConstrutorEntidade::criarInimigo1(Vector2f pos)
{
    return nullptr;
}
