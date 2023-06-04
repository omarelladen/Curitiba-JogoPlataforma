#include "ObservadorMenuPause.h"
using namespace Observers;
#include"MenuPause.h"

ObservadorMenuPause::ObservadorMenuPause(MenuPause* pMP):
	Observador(IDs::menuPause),
	pMenuPause(nullptr)
{
	if (pMP)
		pMenuPause = pMP;
}

ObservadorMenuPause::~ObservadorMenuPause()
{
	pMenuPause = nullptr;
}

void ObservadorMenuPause::botaoMouseSolta(Vector2f posMouse)
{
	pMenuPause->verificaClique(posMouse);
}
