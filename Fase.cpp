#include "Fase.h"
using namespace Fases;
#include"ObservadorFase.h"
using namespace Observers;

Fase::Fase(const IDs id):
	Ente(id),
	listaPersonagens(nullptr),
	listaObstaculos(nullptr),
	gerenciadorColisoes(nullptr),
	construtorEntidade(nullptr),
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

	//Cria Construtor de Entidades
	construtorEntidade = new ConstrutorEntidade();

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
	construtorEntidade = nullptr;
	observadorFase = nullptr;
}

void Fase::adicionarJogador(Jogador* pJ)
{
	if (pJ)
	{
		construtorEntidade->setJogador(static_cast<Capivara*>(pJ));//
		listaPersonagens->addEntidade(pJ);


		setJogador(pJ);
	}
	
}

void Fases::Fase::setJogador(Jogador* pJ)
{
	if (pJ)
		pJogador = pJ;
}

void Fase::criarEntidade(const char simbolo, Vector2f pos)
{
	
	switch (simbolo)
	{
		// abstrata: x
	/*case 'J':
		listaObstaculos->setEntidade(construtorEntidade->criarJogador(pos));
		break;*/
	case '#':
	{
		listaObstaculos->addEntidade(construtorEntidade->criarPlataforma(pos));
	}
		break;

	case 'j':
	{
		listaPersonagens->addEntidade(construtorEntidade->criarJacare(pos));
	}
		break;

	// Fonte de erros
	/*case 'c':
		listaPersonagens->setEntidade(construtorEntidade->criarCapivara(pos));
		break;

	case 'p':
		listaPersonagens->setEntidade(construtorEntidade->criarPolicial(pos));
		break;*/

	case 'b':
	{
		listaObstaculos->addEntidade(construtorEntidade->criarBicicleta(pos));
	}
		break;

	case 'c':
	{
		listaPersonagens->addEntidade(construtorEntidade->criarCapanga(pos));
	}
		break;

	case 'B':
	{
		listaPersonagens->addEntidade(construtorEntidade->criarChefeMafia(pos));
	}
		break;
	default:
		break;
	}
}

void Fase::salvar()
{
	listaObstaculos->salvarEntidades();
	listaPersonagens->salvarEntidades();
}
