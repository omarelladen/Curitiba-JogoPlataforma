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

		void botaoMouseSolta(Vector2f posMouse); // const Mouse::Button botaoMouse, 

		// teclado=0 ou mouse
	};
}

