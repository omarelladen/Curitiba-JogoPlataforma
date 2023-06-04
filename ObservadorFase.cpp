#include "ObservadorFase.h"

Observers::ObservadorFase::ObservadorFase(Fase* pF) :
	Observador(IDs::jogo),
	pFase(nullptr)
{
	if (pF)
		pFase = pF;
}

Observers::ObservadorFase::~ObservadorFase()
{
	pFase = nullptr;
}


void Observers::ObservadorFase::teclaSolta(const Keyboard::Key tecla)
{
	switch (tecla)
	{
	case (Keyboard::Escape):
	{
		Gerenciador_Estados::getGerenciadorEstados()->adicionarEstado
		(
			Gerenciador_Estados::getGerenciadorEstados()->criarEstadoMenuPause()
		);

	}break;
	}
}
