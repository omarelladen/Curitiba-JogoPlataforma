#include "ObservadorMenuPrincipal.h"

ObservadorMenuPrincipal::ObservadorMenuPrincipal(MenuPrincipal* pMP):
	Observador(IDs::menuPrincipal)
{
	if(pMP)
		pMenuPrincipal = pMP;
}

ObservadorMenuPrincipal::~ObservadorMenuPrincipal()
{
}

void ObservadorMenuPrincipal::moveMouse(const Vector2f posMouse)
{
	pMenuPrincipal->atualizarBotoes(posMouse);
	pMenuPrincipal->acessarBotao(posMouse);
}

void ObservadorMenuPrincipal::botaoMouseSolta(const Mouse::Button botaoMouse)
{

}
