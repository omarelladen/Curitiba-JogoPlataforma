#include "Obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(const IDs id, Vector2f tam_corpo) :
	Entidade(id, tam_corpo),
	danoso(false)
{
	time_t t;
	srand((unsigned)time(&t));
	if (rand() % 10 == 1)
	{
		danoso = true;
	}
}

Obstaculo::~Obstaculo()
{
}

const bool Obstaculo::getDanoso() const
{
	return danoso;
}
