#pragma once
#include "Estado.h"

class EstadoMenuPrincipal : public Estado
{
private:
	MenuPrincipal* menu_principal; // agregado aqui

public:
	EstadoMenuPrincipal();
	~EstadoMenuPrincipal();

	void executar();
};

