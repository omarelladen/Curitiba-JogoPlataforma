#pragma once
#include <iostream>
#include <stack>
using namespace std;
#include"IDs.h"

class Jogo;

namespace Estados
{
	class Estado;
}

namespace Gerenciadores
{
	class Gerenciador_Estados
	{
	private:
		Jogo* pJogo;//

		stack<Estados::Estado*> pilhaEstados;



		// S T A T I C
		static Gerenciador_Estados* pGerenciadorEstados;

		Gerenciador_Estados();
	public:
		~Gerenciador_Estados();

		// S T A T I C
		static Gerenciador_Estados* getGerenciadorEstados();



		// Criacao de Estados
		Estados::Estado* criarEstadoJogar(IDs id_fase);
		Estados::Estado* criarEstadoMenuPrincipal();
		Estados::Estado* criarEstadoMenuPause();


		// Gestão de Estados
		void removerEstado(int n); // pop delete e fecha janela se empty
		void adicionarEstado(Estados::Estado* pE);
		//void getEstadoAtual();


		Jogo* getJogo();

		void executar(); // no loop do Jogo(Principal) ele executa o topo da pilha
	};
}

