#pragma once
#include"Gerenciador_Estados.h"
#include"ListaEntidades.h"

namespace Entidades
{
	class Entidade;
}
using namespace Entidades;

namespace Gerenciadores
{
	class Gerenciador_Colisoes
	{
	private:
		ListaEntidades* listaPersonagens;
		ListaEntidades* listaObstaculos;
		ListaEntidades* listaProjeteis;

		Jogador* pJogador;

		static Gerenciador_Colisoes* pGerenciadorColisoes;

		Gerenciador_Colisoes();
	public:
		~Gerenciador_Colisoes();

		static Gerenciador_Colisoes* getGerenciadorColisoes();

		void setListaPersonagens(ListaEntidades* list);
		void setListaObstaculos(ListaEntidades* list);
		void setJogador(Jogador* pJ);

		void salvar();

		void addProjetil(Entidade* proj);

		void GerenciarColisoes();

		//Calcula Colisao
		void CalculaColisao(Entidade* ent1, Entidade* ent2);

		void executar();
	};
}