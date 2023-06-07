#include"Personagem.h"
using namespace Entidades;

Personagem::Personagem(const IDs id, Vector2f pos) :
    Entidade(id, pos),
    num_vidas(0),
    projetil(nullptr)
{
}

Personagem::~Personagem()
{
    projetil = nullptr;
}

void Personagem::setNumVidas(const int vidas)
{
    num_vidas = vidas;
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}

void Personagem::setProjetil(Projetil* proj)
{
    projetil = proj;
}

Projetil* Personagem::getProjetil()
{
    return projetil;
}

void Personagem::atirar()
{
    //Lembrar que projetil nao eh colocado na listaEntidades
    if (projetil)
    {
        projetil->executar();
    }
}

void Personagem::diminuirVida(int dano)
{
    num_vidas -= dano;
}
