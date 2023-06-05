#include "Arvore.h"
using namespace Obstaculos;

Arvore::Arvore(Vector2f pos):
	Obstaculo(IDs::arvore, pos),
	altura(0)
{
}

Arvore::~Arvore()
{
}

void Arvore::inicializaAtributos()
{
	time_t t;
	srand((unsigned)time(&t));

	altura = rand() % 21 + 130;
	tronco.setSize(Vector2f((float)altura, 30.f));
}

void Arvore::executar()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaEnte(tronco);
	desenhar_se();
}
