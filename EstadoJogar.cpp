#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(const IDs id_fase): 
	Estado(IDs::estadoJogar),
	fase(nullptr),
	jogador1(nullptr)
{
	// Cria a Fase
	if (id_fase == IDs::fase_barigui)
		fase = new FaseParqueBarigui();

	else if(id_fase == IDs::fase_beco)
		fase = new FaseBeco();

	jogador1 = new Capivara(Vector2f(200.f, 100.f));
	fase->addJogador(jogador1);
	fase->criarMapa();
}

EstadoJogar::~EstadoJogar()
{
	delete fase;
	delete jogador1;

	fase = nullptr;
	jogador1 = nullptr;
}

void EstadoJogar::salvarJogada()
{
	fase->salvarJogada();
}

void EstadoJogar::executar()
{
	fase->executar();
}
