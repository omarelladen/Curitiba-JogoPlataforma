#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(IDs id_fase): //(, bool dupla) - default false
	Estado(IDs::estadoJogar),
	fase(nullptr),
	jogador1(nullptr)
{
	// Melhorar: ConstrutorFase

	// Cria a Fase
	if (id_fase == IDs::fase_barigui)
	{
		fase = new FaseParqueBarigui();

		jogador1 = new Capivara(); // default -> talvez mtirar de (0,0)
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

	
	 
	fase->adicionarJogador(jogador1);
	
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
