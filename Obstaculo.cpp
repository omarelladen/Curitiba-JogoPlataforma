#include "Obstaculo.h"
using namespace Obstaculos;

Obstaculo::Obstaculo(const IDs id, Vector2f pos) :
	Entidade(id, pos),
	danoso(false)
{
}

Obstaculo::~Obstaculo()
{
}

const bool Obstaculo::getDanoso() const
{
	return danoso;
}
