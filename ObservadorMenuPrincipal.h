#pragma once
#include "Observador.h"
#include "MenuPrincipal.h"
using namespace Menus;

namespace Observers
{
	class ObservadorMenuPrincipal : public Observador
	{
	private:
		MenuPrincipal* pMenuPrincipal; //dupla

	public:
		ObservadorMenuPrincipal(MenuPrincipal* pMP);
		~ObservadorMenuPrincipal();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}
