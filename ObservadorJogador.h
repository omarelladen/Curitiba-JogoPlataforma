#pragma once
#include"Observador.h"
#include"IDs.h"
#include"Jogador.h"

namespace Observers
{
	class ObservadorJogador : public Observador
	{
	private:
		Jogador* pJogador;

	public:
		ObservadorJogador(Jogador* pJ);
		~ObservadorJogador();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}