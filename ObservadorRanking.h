#pragma once
#include"Observador.h"
#include"Ranking.h"

namespace Observers
{
	class ObservadorRanking : public Observador
	{
	private:
		Ranking* pLeaderBoard;

	public:
		ObservadorRanking(Ranking* pLB = nullptr);
		~ObservadorRanking();

		void teclaPressionada(const Keyboard::Key tecla);
		void teclaSolta(const Keyboard::Key tecla);
	};
}
