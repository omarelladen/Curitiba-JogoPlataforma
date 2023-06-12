#include "ObservadorMenuPause.h"
using namespace Observers;

ObservadorMenuPause::ObservadorMenuPause(MenuPause* pMP) :
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

void ObservadorMenuPause::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorMenuPause::teclaSolta(const Keyboard::Key tecla)
{
	bool enter = false;

	if (tecla == Keyboard::Enter)
		enter = true;
	else
		enter = false;

	if (tecla == Keyboard::Down && pMenuPause->getOpcao() > 1)
	{
		pMenuPause->operator--();
	}
	else if (tecla == Keyboard::Up && pMenuPause->getOpcao() < 2)
	{
		pMenuPause->operator++();
	}

	pMenuPause->selecionaBotao(enter);
}