#pragma once
#include "Observador.h"
#include "Fase.h"
using namespace Fases;
#include"Gerenciador_Estados.h"

namespace Observers
{
	class ObservadorFase : public Observador
	{
	private:
		Fase* pFase;

	public:
		ObservadorFase(Fase* pF = nullptr);
		~ObservadorFase();

		//void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}