#include"ObservadorJogador.h"
using namespace Observers;

ObservadorJogador::ObservadorJogador(Jogador* pJ):
	Observador(IDs::jogo),
	pJogador(nullptr)
{
	if (pJ)
		pJogador = pJ;
}

ObservadorJogador::~ObservadorJogador()
{
	pJogador = nullptr;
}

void ObservadorJogador::teclaPressionada(const Keyboard::Key tecla)
{
	//if(!pJogador->jogador2)
	switch (tecla)
	{
	// Pular
	case (Keyboard::W):
	{
		//cout << pJogador->getEstaNoChao() << endl;
		if (pJogador->getEstaNoChao())
		{
			if (Keyboard::isKeyPressed(Keyboard::LShift))
				pJogador->mover("Cima++");
			else
				pJogador->mover("Cima");

			pJogador->setEstaNoChao(false);
		}
	}
		break;

	// Andar para a esquerda
	case (Keyboard::A):
	{
		pJogador->mover("Esquerda");
	}
		break;

	case (Keyboard::S):
	{
		if(!pJogador->getEstaNoChao())
			pJogador->mover("Baixo");
	}
		break;

	// Andar para a direita
	case (Keyboard::D):
	{
		pJogador->mover("Direita");
	}
		break;

	default:
	{
		//cout << "Erro Movimento Jogador no ObservadorJogador" << endl;
	}
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

void ObservadorJogador::teclaSolta(const Keyboard::Key tecla)
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
		pJogador->mover("");
		break;
	}
}