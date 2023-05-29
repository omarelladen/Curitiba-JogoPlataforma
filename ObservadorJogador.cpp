#include"ObservadorJogador.h"

ObservadorJogador::ObservadorJogador(Jogador* pJ):
	Observador(IDs::jogo)
{
	if (pJ)
		pJogador = pJ;
}

ObservadorJogador::~ObservadorJogador()
{
}

void ObservadorJogador::teclaPressionada(const Keyboard::Key tecla)
{
	switch (tecla)
	{
	case (Keyboard::W):
	{

	}
	break;

	case (Keyboard::A):
	{

	}
	break;

	case (Keyboard::S):
	{

	}
	break;

	case (Keyboard::D):
	{

	}
	break;
	}
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
	}
}
