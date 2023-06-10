#pragma once
#include "Menu.h"
#include"ObservadorMenuPause.h"
using namespace Observers;
#include"Botao.h"
#include "Gerenciador_Eventos.h"//

namespace Menus
{
	class MenuPause : public Menu
	{
	private:
		ObservadorMenuPause* observadorMenuPause;

		Botao* botao_voltar;
		Botao* botao_sair;
		Botao* botao_salvar;

	public:
		MenuPause();
		~MenuPause();

		void verificaClique(Vector2f posMouse);

		void desenhar_se();
		void executar();
	};
}
