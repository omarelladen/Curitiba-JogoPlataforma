#pragma once
#include"FaseParqueBarigui.h"
#include"Botao.h"
#include"Gerenciador_Eventos.h"
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
		Botao* botao_jogarCooperativoBarigui;
		//Botao* botao_continuar;
		Botao* botao_sair;
		//Botao* botao_configuracoes;


	public:
		MenuPrincipal();
		~MenuPrincipal();

		void verificaClique(Vector2f posMouse); //const Mouse::Button botaoMouse,

		void desenhar_se(); // chamado pelo gerenciador grafico??
		void executar();
	};
}