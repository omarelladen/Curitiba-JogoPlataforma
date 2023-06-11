#pragma once
#include"Jogador.h"
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
		EstadoMenuGameOver(Jogador* jog = nullptr);
		~EstadoMenuGameOver();

		void executar();
	};

}