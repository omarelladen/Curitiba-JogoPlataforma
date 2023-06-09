#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(const IDs id_fase): //(, bool dupla) - default false
	Estado(IDs::estadoJogar),
	fase(nullptr),
	jogador1(nullptr)
{
	// Melhorar: ConstrutorFase

	// Cria a Fase
	if (id_fase == IDs::fase_barigui)
	{
		jogador1 = new Capivara(Vector2f(200.f, 100.f));
		fase = new FaseParqueBarigui();

		fase->addJogador(jogador1);
		fase->criarMapa();

		//if(dupla)
		//	jogador2 = new Policial(true);
		//else
		//	jogador2 = nullptr;
		
		
	}
	/*else if (id_fase == IDs::fase_cidade)
	{
		fase = new FaseCidade();

		jogador1 = new Policial();
		//if(dupla)
		//	jogador2 = new Capivara(true);
		//else
		//	jogador2 = nullptr;
		

	}*/
	
	//if (dupla)
		//fase->adicionarJogador(jogador2);



	// Cria o MAPA da Fase
	//fase->criarMapa(); - coloquei no FaseParqueBarigui()
}

EstadoJogar::~EstadoJogar()
{
	delete fase;
	delete jogador1;

	fase = nullptr;
	jogador1 = nullptr;
}

void EstadoJogar::executar()
{
	fase->executar();
}
