#pragma once
#include"Menu.h"
#include"Botao.h"
#include"EstadoJogar.h"

namespace Observers
{
	class ObservadorMenuPause;
}
using namespace Observers;

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

		void selecionaBotao(const bool enter);
		void atualizarPosicao();

		void desenhar_se();
		void executar();
	};
}