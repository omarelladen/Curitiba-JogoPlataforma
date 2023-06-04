#pragma once
#include"Estado.h"
#include"MenuPrincipal.h"
using namespace Menus;

namespace Estados
{
	class EstadoMenuPrincipal : public Estado
	{
	private:
		MenuPrincipal* menu_principal; // agregado aqui

	public:
		EstadoMenuPrincipal();
		~EstadoMenuPrincipal();

		void executar();
	};
}
