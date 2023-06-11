#pragma once
#include"Estado.h"
#include "MenuGameOver.h"
using namespace Menus;

namespace Estados
{
	class EstadoMenuGameOver : public Estado
	{
	private:
		MenuGameOver* menu_game_over;

	public:
		EstadoMenuGameOver();
		~EstadoMenuGameOver();

		void executar();
	};

}