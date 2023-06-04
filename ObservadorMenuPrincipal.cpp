#include "ObservadorMenuPrincipal.h"

Observers::ObservadorMenuPrincipal::ObservadorMenuPrincipal(MenuPrincipal* pMP) :
	Observador(IDs::menuPrincipal),
	pMenuPrincipal(nullptr)
{
	if (pMP)
		pMenuPrincipal = pMP;
}

Observers::ObservadorMenuPrincipal::~ObservadorMenuPrincipal()
{
	pMenuPrincipal = nullptr;
}

void Observers::ObservadorMenuPrincipal::botaoMouseSolta(Vector2f posMouse) // const Mouse::Button botaoMouse, 
{
	pMenuPrincipal->verificaClique(posMouse); // botaoMouse,
}
