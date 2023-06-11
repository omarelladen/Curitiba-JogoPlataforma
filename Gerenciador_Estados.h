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
		Jogo* pJogo;

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
		Estado* criarEstadoRanking();

		// Gestão de Estados
		void removerEstado(int n); // pop delete e fecha janela se empty
		void addEstado(Estado* pE);
		Estado* getEstadoAtual();

		Jogo* getJogo();

		void executar(); // no loop do Jogo(Principal) ele executa o topo da pilha
	};
}
