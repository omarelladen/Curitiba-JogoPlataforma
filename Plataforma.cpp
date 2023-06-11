#include "Plataforma.h"
using namespace Obstaculos;

Plataforma::Plataforma(Vector2f pos) :
	Obstaculo(IDs::plataforma, pos),
	atrito(0.6)
{
	corpo.setFillColor(Color::Green);
}

Plataforma::~Plataforma()
{
}

const double Plataforma::getAtrito() const
{
	return atrito;
}

void Plataforma::executar()
{
	desenhar_se();
}
