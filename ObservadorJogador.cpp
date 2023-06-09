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
		pJogador->setDireita(false);
		pJogador->setTextura("Texturas/Sprite-capivara-esquerda.png");
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
		pJogador->setDireita(true);
		pJogador->setTextura("Texturas/Sprite-capivara-direita.png");
		pJogador->mover("Direita");
	}
		break;

	default:
		//cout << "Tecla que nao faz nada" << endl;
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

	case (Keyboard::F):
	{
		Capivara* pC = static_cast<Capivara*>(pJogador);
		pC->atirar(pC->getForcaCuspe());
	}
	break;

	default:
		//cout << "Tecla que nao faz nada" << endl;
		break;
	}
}