#pragma once
#include "Observador.h"

namespace Menus
{
	class MenuPause;
}
using namespace Menus;

namespace Observers
{
	class ObservadorMenuPause : public Observador
	{
	private:
		MenuPause* pMenuPause;

	public:
		ObservadorMenuPause(MenuPause* pMP);
		~ObservadorMenuPause();

		void botaoMouseSolta(Vector2f posMouse);
	};
}
