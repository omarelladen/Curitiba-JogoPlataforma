#include "ObservadorRanking.h"
using namespace Observers;

ObservadorRanking::ObservadorRanking(Ranking* pLB):
	Observador(IDs::ranking),
	pLeaderBoard(nullptr)
{
	if (pLB)
		pLeaderBoard = pLB;
}

ObservadorRanking::~ObservadorRanking()
{
	pLeaderBoard = nullptr;
}

void ObservadorRanking::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorRanking::teclaSolta(const Keyboard::Key tecla)
{
	bool enter = false;

	if (tecla == Keyboard::Enter)
		enter = true;
	else
		enter = false;

	pLeaderBoard->selecionaBotao(enter);
}
