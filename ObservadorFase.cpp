#include "ObservadorFase.h"

ObservadorFase::ObservadorFase(Fase* pF) :
	Observador(IDs::jogo),
	pFase(nullptr)
{
	if (pF)
		pFase = pF;
}

ObservadorFase::~ObservadorFase()
{
	pFase = nullptr;
}


void ObservadorFase::teclaSolta(const Keyboard::Key tecla)
{
	switch (tecla)
	{
	case (Keyboard::Escape):
	{
		Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

		Gerenciador_Estados::getGerenciadorEstados()->addEstado
		(
			Gerenciador_Estados::getGerenciadorEstados()->criarEstadoMenuPause()
		);

	}break;
	}
}
