#pragma once
#include "Observador.h"
#include "MenuPrincipal.h"
using namespace Menus;

namespace Observers
{
	class ObservadorMenuPrincipal : public Observador
	{
	private:
		MenuPrincipal* pMenuPrincipal;

	public:
		ObservadorMenuPrincipal(MenuPrincipal* pMP = nullptr);
		~ObservadorMenuPrincipal();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}
