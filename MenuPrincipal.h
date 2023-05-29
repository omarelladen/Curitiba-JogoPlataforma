#pragma once
#include "Fase1.h"
#include "Jogo.h"
#include "ObservadorMenuPrincipal.h"
#include "Botao.h"

class MenuPrincipal
{
private:
	ObservadorMenuPrincipal* observadorMenuPrincipal; //dupla// precisa?

	Botao* botao_jogarFase1;
	Botao* botao_sair;
	//Botao* botao_configuracoes;


public:
	MenuPrincipal();
	~MenuPrincipal();

	void atualizarBotoes(const Vector2f posMouse);
	void acessarBotao(const Vector2f posMouse);


	//void desenhar(); // chamado pelo gerenciador grafico??
};

