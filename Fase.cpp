#include "Fase.h"
#include"stdafx.h"

Fase::Fase():
	listaPersonagens(NULL),
	listaObstaculos(NULL),
	gerenciador_colisoes(NULL),
	construtorEntidade(NULL)
{
}

Fase::~Fase()
{
}

void Fase::criarEntidade(const char simbolo, Vector2f pos)
{
	switch (simbolo)
	{
	case 'p':
		listaObstaculos->setEntidade(construtorEntidade->criarPlataforma(pos));
		break;

	// case '':

	}
}

