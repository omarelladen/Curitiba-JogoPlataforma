#pragma once
#include "Entidade.h"
#include "Plataforma.h"
using namespace Obstaculos;
using namespace sf;

class ConstrutorEntidade
{
public:
	Entidade* criarPlataforma(Vector2f pos);
	Entidade* criarJogador(Vector2f pos);
	Entidade* criarObstaculo1(Vector2f pos);
	Entidade* criarInimigo1(Vector2f pos);
};

