#include "Fase.h"
using namespace Fases;
#include"ObservadorFase.h"
using namespace Observers;

Fase::Fase(const IDs id) :
	Ente(id),
	listaPersonagens(nullptr),
	listaObstaculos(nullptr),
	gerenciadorColisoes(nullptr),
	observadorFase(nullptr),
	pJogador(nullptr),
	num_inimigos(0),
	num_obstaculos(0),
	contador_inimigos(0),
	contador_obstaculos(0)
{
	//Cria Listas de Entidades
	listaPersonagens = new ListaEntidades();
	listaObstaculos = new ListaEntidades();

	//Cria Gerenciador
	gerenciadorColisoes = Gerenciador_Colisoes::getGerenciadorColisoes();

	gerenciadorColisoes->setListaObstaculos(listaObstaculos);
	gerenciadorColisoes->setListaPersonagens(listaPersonagens);

	// Cria seu Observador:
	observadorFase = new ObservadorFase(this); // this para setar la tambem Observers::

	// Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->addObservador(observadorFase);

	time_t t;
	srand((unsigned)time(&t));
	num_inimigos = rand() % 15 + 3;
	num_obstaculos = rand() % 20 + 3;
}

Fase::~Fase()
{
	if (listaObstaculos)
	{
		listaObstaculos->clear();
	}
	if (listaPersonagens)
	{
		listaPersonagens->clear();
	}

	listaPersonagens = nullptr;
	listaObstaculos = nullptr;
	gerenciadorColisoes = nullptr;
	observadorFase = nullptr;
	pJogador = nullptr;
}

void Fase::addJogador(Jogador* pJ)
{
	if (pJ)
	{
		listaPersonagens->addEntidade(pJ);

		setJogador(pJ);
		gerenciadorColisoes->setJogador(pJ);
	}
}

void Fase::setJogador(Jogador* pJ)
{
	if (pJ)
		pJogador = pJ;
}
