#include"Bicicleta.h"
using namespace Obstaculos;

Bicicleta::Bicicleta(Vector2f pos) :
	Obstaculo(IDs::bicicleta, pos),
	nivel_ricochete(0),
	velocidade()
{
}

Bicicleta::~Bicicleta()
{
}

void Bicicleta::inicializaAtributos()
{
	time_t t;
	srand((unsigned)time(&t));

	nivel_ricochete = rand() % 101 + 150;
	velocidade = Vector2f((rand() % 5 + 1) / -10.f, 0.f);
}

void Bicicleta::mover()
{
	corpo.move(velocidade);
	posicao = corpo.getPosition();
}

void Bicicleta::executar()
{
	desenhar_se();
}