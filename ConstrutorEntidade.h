#pragma once
#include"Entidade.h"
#include"Chao.h"
#include"Bicicleta.h"//
#include"Capivara.h"
#include"Jacare.h"//
#include"Capanga.h"//
#include"ChefeMafia.h"//
using namespace Obstaculos;
using namespace Entidades;

class ConstrutorEntidade
{
private:
	Capivara* pJogador;// NAO ESTA SENDO UTIL

public:
	ConstrutorEntidade();
	~ConstrutorEntidade();

	void setJogador(Capivara* pJ);
	Capivara* getJogador();

	Entidade* criarPlataforma(Vector2f pos);
	Entidade* criarBicicleta(Vector2f pos);
	//Entidade* criarCapivara(Vector2f pos);
	//Entidade* criarPolicial(Vector2f(pos));
	Entidade* criarJacare(Vector2f pos);
	Entidade* criarCapanga(Vector2f(pos));
	Entidade* criarChefeMafia(Vector2f(pos));
};
