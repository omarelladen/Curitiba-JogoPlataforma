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
	pJogador(nullptr)
{
	// NAO EH AQUI QUE CRIA O PERSONAGEM !!!!!
	/*// Cria o personagem
	construtorEntidade->setJogador(  (Jogador*)(construtorEntidade->criarCapivara(Vector2f(9, 8)))  );
	listaPersonagens->setEntidade(construtorEntidade->getJogador());
	// Player 2:*/

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
	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorFase);
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



void Fase::salvar()
{
	if (gerenciadorColisoes)
		gerenciadorColisoes->salvar();
}