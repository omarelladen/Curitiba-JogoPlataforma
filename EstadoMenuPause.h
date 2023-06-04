#pragma once
#include"Estado.h"
#include"MenuPause.h"
using namespace Menus;

namespace Estados
{

	class EstadoMenuPause : public Estados::Estado
	{
	private:
		MenuPause* menu_pause;

	public:
		EstadoMenuPause();
		~EstadoMenuPause();

		void executar();
	};
}
