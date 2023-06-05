#include"Personagem.h"
using namespace Personagens;

Personagem::Personagem(const IDs id, Vector2f pos) :
    Entidade(id, pos),
    velocidade(Vector2f(0.f, 0.f)),
    num_vidas(0)
{
}

Personagem::~Personagem()
{
}

void Personagem::operator--()
{
    num_vidas--;
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}