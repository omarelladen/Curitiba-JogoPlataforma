#include"Bicicleta.h"
using namespace Obstaculos;

Bicicleta::Bicicleta(Vector2f pos) :
	Obstaculo(IDs::bicicleta, pos),
	//Personagem(IDs::bicicleta, pos),
	pula(false)
{
}

Bicicleta::~Bicicleta()
{
}

void Bicicleta::mover(const char* direcao)
{
}

void Bicicleta::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
}

void Bicicleta::executar()
{
}