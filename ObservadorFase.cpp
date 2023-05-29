#include "ObservadorFase.h"

ObservadorFase::ObservadorFase(Fase* pF):
	Observador(IDs::jogo)
{
	if (pF)
		pFase = pF;
}

ObservadorFase::~ObservadorFase()
{
}

void ObservadorFase::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorFase::teclaSolta(const Keyboard::Key tecla)
{
	switch (tecla)
	{
	case (Keyboard::Escape):
		{
			pGEstados->adicionarEstado(pGEstados->criarEstadoMenuPause());
			// pausar - criar menu_pause e Estado Pause
		}
	}
}
