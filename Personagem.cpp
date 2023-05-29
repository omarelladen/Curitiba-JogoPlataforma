#include"Personagem.h"
using namespace Personagens;

int Personagem::numPersonagens(0);

Personagem::Personagem(const IDs id, Vector2f tam_corpo) :
    Entidade(id, tam_corpo),
    velocidade(Vector2f(0.f, 0.f)),
    num_vidas(4),
    tempo()
{
    //id = ID::Personagem();
    numPersonagens++;
}

Personagem::~Personagem()
{
}

void Personagem::executar()
{
}

void Personagem::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}

void Personagem::setVelocidade(Vector2f vel)
{
    velocidade = vel;
}

Vector2f Personagem::getVelocidade()
{
    return velocidade;
}
