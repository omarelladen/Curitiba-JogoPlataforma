#include"Personagem.h"
using namespace Entidades;

Personagem::Personagem(const IDs id, Vector2f pos) :
    Entidade(id, pos),
    velocidade(Vector2f(0.f, 0.f)),
    num_vidas(0),
    projetil(nullptr)
{
}

Personagem::~Personagem()
{
    projetil = nullptr;
}

void Personagem::operator--()
{
    num_vidas--;
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

void Personagem::setVelocidade(Vector2f vel)
{
    velocidade = vel;
}
