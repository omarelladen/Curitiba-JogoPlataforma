#pragma once
#include"Observador.h"
#include"Capivara.h"

namespace Observers
{
	class ObservadorJogador : public Observador
	{
	private:
		Jogador* pJogador;

	public:
		ObservadorJogador(Jogador* pJ = nullptr);
		~ObservadorJogador();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}