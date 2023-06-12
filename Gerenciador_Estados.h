#pragma once
#include <iostream>
#include <stack>
using namespace std;
#include"IDs.h"
#include"Jogador.h"

class Jogo;

namespace Estados
{
	class Estado;
}
using namespace Estados;

namespace Gerenciadores
{
	class Gerenciador_Estados
	{
	private:
		stack<Estado*> pilhaEstados;

		static Gerenciador_Estados* pGerenciadorEstados;

		Gerenciador_Estados();
	public:
		~Gerenciador_Estados();

		static Gerenciador_Estados* getGerenciadorEstados();

		// Criacao de Estados
		Estado* criarEstadoJogar(IDs id_fase);
		Estado* criarEstadoMenuPrincipal();
		Estado* criarEstadoMenuPause();
		Estado* criarEstadoMenuGameOver(Jogador* jog);

		// Gestão de Estados
		void addEstado(Estado* pE);
		void deleteEstado(const int n);

		//Retorna o topo da pilha
		Estado* getEstadoAtual();

		//Chama o executar do Estado no topo da pilha
		void executar();
	};
}
