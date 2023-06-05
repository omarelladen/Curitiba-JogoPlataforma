#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Ente.h"
#include"SalvaJogo.h"

namespace Menus
{
	class Menu : public Ente//
	{
	protected:
		// botoes

		Text texto;
		SalvaJogo load;

	public:
		Menu(const IDs id = {});
		~Menu();

		virtual void verificaClique(Vector2f posMouse) = 0;
		virtual void desenhar_se() = 0;
		virtual void executar() = 0;
	};
}
