#include "EstadoMenuPause.h"
using namespace Estados;

EstadoMenuPause::EstadoMenuPause():
	Estado(IDs::estadoMenuPause)
{
	menu_pause = new MenuPause();
}

EstadoMenuPause::~EstadoMenuPause()
{
	delete menu_pause;
	menu_pause = nullptr;
}

void EstadoMenuPause::executar()
{
	menu_pause->executar();
}
