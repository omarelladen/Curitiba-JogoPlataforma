#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Ente.h"

#define TAM_BOTOES_X 400.f
#define TAM_BOTOES_Y 100.f

namespace Menus
{
	class Menu : public Ente//
	{
	protected:
		// botoes

		Text texto;

	public:
		Menu(const IDs id = {});
		~Menu();

		virtual void verificaClique(Vector2f posMouse) = 0;
		virtual void desenhar_se() = 0;
		virtual void executar() = 0;
	};
}
