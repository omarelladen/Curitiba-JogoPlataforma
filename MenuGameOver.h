#pragma once
#include"Menu.h"
#include"Botao.h"

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

		Botao* botao_menuPrincipal;
		Botao* botao_jogarNovamente;

	public:
		MenuGameOver();
		~MenuGameOver();

		void selecionaBotao(const bool enter);
		void atualizarPosicao();

		void desenhar_se();
		void executar();
	};
}