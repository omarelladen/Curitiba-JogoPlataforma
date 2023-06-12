#pragma once
#include"Menu.h"
#include"Botao.h"
#include"Jogador.h"
#include"ObservadorInputTexto.h"

namespace Observers
{
	class ObservadorMenuGameOver;
}
using namespace Observers;

namespace Menus
{
	class MenuGameOver : public Menu
	{
	private:
		ObservadorMenuGameOver* observadorMenuGameOver;

		ObservadorInputTexto* registroNome;

		Text pontos;
		string aux_pontos;

		Text nome;
		string aux_nome;

		Botao* botao_menuPrincipal;
		Botao* botao_jogarNovamente;

	public:
		MenuGameOver(Jogador* jog = nullptr);
		~MenuGameOver();

		void inicializaAtributos();

		void selecionaBotao(const bool enter);
		void atualizarPosicao();

		void desenhar_se();
		void executar();
	};
}