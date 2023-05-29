#include "Plataforma.h"
using namespace Obstaculos;

Plataforma::Plataforma(Vector2f tam_corpo) :
	Obstaculo(IDs::plataforma, tam_corpo)
{
	corpo.setFillColor(Color::Green);
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
	desenhar_se();
}
