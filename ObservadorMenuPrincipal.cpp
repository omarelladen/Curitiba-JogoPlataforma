#include "ObservadorMenuPrincipal.h"

ObservadorMenuPrincipal::ObservadorMenuPrincipal(MenuPrincipal* pMP) :
	Observador(IDs::menuPrincipal),
	pMenuPrincipal(nullptr)
{
	if (pMP)
		pMenuPrincipal = pMP;
}

ObservadorMenuPrincipal::~ObservadorMenuPrincipal()
{
	pMenuPrincipal = nullptr;
}

void ObservadorMenuPrincipal::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorMenuPrincipal::teclaSolta(const Keyboard::Key tecla)
{
	bool enter = false;

	if (tecla == Keyboard::Enter)
		enter = true;
	else
		enter = false;

	if (tecla == Keyboard::Down && pMenuPrincipal->getOpcao() < 4)
	{
		pMenuPrincipal->operator++();
	}
	else if (tecla == Keyboard::Up && pMenuPrincipal->getOpcao() > 1)
	{
		pMenuPrincipal->operator--();
	}

	pMenuPrincipal->selecionaBotao(enter);
}