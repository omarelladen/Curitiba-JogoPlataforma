#include"ObservadorJogador.h"
using namespace Observers;

Observers::ObservadorJogador::ObservadorJogador(Jogador* pJ):
	Observador(IDs::jogo),
	pJogador(nullptr)
{
	if (pJ)
		pJogador = pJ;
}

Observers::ObservadorJogador::~ObservadorJogador()
{
	pJogador = nullptr;
}

void Observers::ObservadorJogador::teclaPressionada(const Keyboard::Key tecla)
{
	//if(!pJogador->jogador2)
	switch (tecla)
	{
	// Pular
	case (Keyboard::W):
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			pJogador->mover("Cima++");
		else
			pJogador->mover("Cima");
	}
		break;

	// Andar para a esquerda
	case (Keyboard::A):
		pJogador->mover("Esquerda");
		break;

	case (Keyboard::S):
		pJogador->mover("Baixo");
		break;

	// Andar para a direita
	case (Keyboard::D):
		pJogador->mover("Direita");
		break;

	default:
		pJogador->mover("");
		break;
	}

	/*else
	{
		switch (tecla)
		{
		// Pular
		case (Keyboard::Up):
		{
			if (Keyboard::isKeyPressed(Keyboard::LShift))
				pJogador->mover("Cima++");
			else
				pJogador->mover("Cima");
		}
			break;

		// Andar para a esquerda
		case (Keyboard::Left):
			pJogador->mover("Esquerda");
			break;

		case (Keyboard::Down):
			pJogador->mover("Baixo");
			break;

		// Andar para a direita
		case (Keyboard::Right):
			pJogador->mover("Direita");
			break;

		default:
			pJogador->mover("");
			break;
		}
	}
	*/
}

void Observers::ObservadorJogador::teclaSolta(const Keyboard::Key tecla)
{
	switch (tecla)
	{
	case (Keyboard::A):
	{
		pJogador->parar();
	}
	break;

	case (Keyboard::D):
	{
		pJogador->parar();
	}
	break;

	default:
		break;
	}
}