#include "ObservadorMenuGameOver.h"
using namespace Observers;

ObservadorMenuGameOver::ObservadorMenuGameOver(MenuGameOver* pMGO) :
	Observador(IDs::menuGameOver),
	pMenuGameOver(nullptr)
{
	if (pMGO)
		pMenuGameOver = pMGO;
}

ObservadorMenuGameOver::~ObservadorMenuGameOver()
{
	pMenuGameOver = nullptr;
}

void ObservadorMenuGameOver::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorMenuGameOver::teclaSolta(const Keyboard::Key tecla)
{
	bool enter = false;

	if (tecla == Keyboard::Enter)
		enter = true;
	else
		enter = false;


	if (tecla == Keyboard::Left && pMenuGameOver->getOpcao() < 2)
	{
		pMenuGameOver->operator++();
	}
	else if (tecla == Keyboard::Right && pMenuGameOver->getOpcao() > 1)
	{
		pMenuGameOver->operator--();
	}

	pMenuGameOver->selecionaBotao(enter);
}
