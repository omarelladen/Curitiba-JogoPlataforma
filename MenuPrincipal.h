#pragma once
#include"FaseParqueBarigui.h"
#include"Botao.h"
#include"Menu.h"

namespace Observers
{
	class ObservadorMenuPrincipal;
}
using namespace Observers;

namespace Menus
{
	class MenuPrincipal : public Menu
	{
	private:
		ObservadorMenuPrincipal* observadorMenuPrincipal; //dupla// precisa?

		Botao* botao_jogarBarigui;
		Botao* botao_jogarbeco;
		Botao* botao_ranking;
		Botao* botao_sair;
		//Botao* botao_configuracoes;

	public:
		MenuPrincipal();
		~MenuPrincipal();

		void selecionaBotao(const bool enter);
		void atualizarPosicao();

		void desenhar_se();
		void executar();
	};
}