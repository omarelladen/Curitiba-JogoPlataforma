#include "EstadoJogar.h"

EstadoJogar::EstadoJogar(IDs id_fase):
	Estado(IDs::estadoJogar)
{
	// Melhorar: ConstrutorFase
	if (id_fase == IDs::fase1)
	{
		fase = new Fase1();
	}
	
	// 
	jogador = new Jogador();

	fase->criarMapa();
}

EstadoJogar::~EstadoJogar()
{
}

void EstadoJogar::executar()
{
	fase->executar();
}
