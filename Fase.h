#pragma once
#include"ListaEntidades.h"
#include"Gerenciador_Colisoes.h"
#include"ConstrutorEntidade.h"

class Fase
{
protected:
	ListaEntidades* listaPersonagens;
	ListaEntidades* listaObstaculos; 

	Gerenciador_Colisoes* gerenciador_colisoes;

	ConstrutorEntidade* construtorEntidade;
	
	// fundo - imagem/camada

public:
	Fase();
	~Fase();

	virtual void criarMapa() = 0;
	void criarEntidade(const char simbolo, Vector2f pos); //*

	virtual void executar() = 0;
};

/*
private:
	
	ConstrutorEntidade* contrutorEntidades;


public:
	Fase();
	~Fase();

	void criarMapa(); //c

	virtual void gerenciar_colisoes() = 0;
	virtual void executar() = 0; // n pura na vdd pelo video
*/