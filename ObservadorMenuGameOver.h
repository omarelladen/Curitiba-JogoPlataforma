#pragma once
#include"Observador.h"
#include"MenuGameOver.h"
using namespace Menus;

namespace Observers
{
	class ObservadorMenuGameOver : public Observador
	{
	private:
		MenuGameOver* pMenuGameOver;

	public:
		ObservadorMenuGameOver(MenuGameOver* pMGO = nullptr);
		~ObservadorMenuGameOver();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}