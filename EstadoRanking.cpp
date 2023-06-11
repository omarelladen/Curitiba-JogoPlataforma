#include "EstadoRanking.h"

EstadoRanking::EstadoRanking():
	Estado(IDs::estadoRanking),
	ranking(nullptr)
{
	ranking = new Ranking();
}

EstadoRanking::~EstadoRanking()
{
	delete ranking;
	ranking = nullptr;
}

void EstadoRanking::executar()
{
	ranking->executar();
}
