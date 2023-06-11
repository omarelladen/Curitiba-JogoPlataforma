#pragma once
#include"Estado.h"
#include"Ranking.h"

namespace Estados
{
	class EstadoRanking : public Estado
	{
	private:
		Ranking* ranking;

	public:
		EstadoRanking();
		~EstadoRanking();

		void executar();
	};
}
