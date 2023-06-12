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

		Jogador* pJogador;

		static Gerenciador_Colisoes* pGerenciadorColisoes;

		Gerenciador_Colisoes();
	public:
		~Gerenciador_Colisoes();

		static Gerenciador_Colisoes* getGerenciadorColisoes();

		void setListaPersonagens(ListaEntidades* list);
		void setListaObstaculos(ListaEntidades* list);
		void setJogador(Jogador* pJ);

		void GerenciarColisoes();

		void CalculaColisao(Entidade* ent1, Entidade* ent2);

		void executar();
	};
}