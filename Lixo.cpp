#include "Lixo.h"
using namespace Obstaculos;

Lixo::Lixo(Vector2f pos):
	Obstaculo(IDs::lixo, pos),
	dano(0),
	tempo_retardo(0)
{
}

Lixo::~Lixo()
{
}

void Lixo::inicializaAtributos()
{
	time_t t;
	srand((unsigned)time(&t));

	dano = rand() % 3 + 1;
	tempo_retardo = rand() % 3 + 3;
}

const int Lixo::getDano() const
{
	return 0;
}

const int Lixo::getTempoRetardo() const
{
	return 0;
}
