#include "EstadoMenuPrincipal.h"
using namespace Estados;

EstadoMenuPrincipal::EstadoMenuPrincipal():
	Estado(IDs::estadoMenuPrincipal),
	menu_principal(nullptr)
{
	// Cria o Menu Principal
	menu_principal = new MenuPrincipal();
}

EstadoMenuPrincipal::~EstadoMenuPrincipal()
{
	delete menu_principal;
	menu_principal = nullptr;
}

void EstadoMenuPrincipal::executar()
{
	menu_principal->executar();
}
