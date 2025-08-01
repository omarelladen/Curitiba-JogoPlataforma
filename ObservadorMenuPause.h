#pragma once
#include"Observador.h"
#include"MenuPause.h"
using namespace Menus;

namespace Observers
{
	class ObservadorMenuPause : public Observador
	{
	private:
		MenuPause* pMenuPause;

	public:
		ObservadorMenuPause(MenuPause* pMP = nullptr);
		~ObservadorMenuPause();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}