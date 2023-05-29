#pragma once
#include "EstadoJogar.h"
#include "EstadoMenuPrincipal.h"
#include "Jogo.h"
#include "IDs.h"
#include <iostream>
#include <stack>
using std::stack;

class Gerenciador_Estados
{
private:
	Jogo* pJogo;//

	stack<Estado*> pilhaEstados;



	// S T A T I C
	static Gerenciador_Estados* pGerenciadorEstados;

	Gerenciador_Estados();
public:
	~Gerenciador_Estados();

	// S T A T I C
	static Gerenciador_Estados* getGerenciadorEstado();



	// Criacao de Estados
	Estado* criarEstadoJogar(IDs id_fase);
	Estado* criarEstadoMenuPrincipal();
	Estado* criarEstadoMenuPause();


	// Gestão de Estados
	void removerEstado(); // pop delete e fecha janela se empty
	void adicionarEstado(Estado* pE);
	void getEstadoAtual();

	Jogo* getJogo();

	void executar(); // no loop do Jogo(Principal) ele executa o topo da pilha
};


