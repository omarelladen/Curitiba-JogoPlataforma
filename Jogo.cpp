#include "Jogo.h"
#include "Jogo.h"
#include"Gerenciador_Estados.h"

Jogo::Jogo() :
	gerenciador_eventos(Gerenciador_Eventos::getGerenciadorEventos()),
	gerenciador_grafico(Gerenciador_Grafico::getGerenciadorGrafico()),
	gerenciador_estados(Gerenciador_Estados::getGerenciadorEstados())
{
	// Manda criar e adicionar o Estado Menu Principal
	gerenciador_estados->addEstado(gerenciador_estados->criarEstadoMenuPrincipal());

	executar();
}

Jogo::~Jogo()
{
	gerenciador_eventos = nullptr;
	gerenciador_grafico = nullptr;
	gerenciador_estados = nullptr;
}

void Jogo::executar()
{

	// Loop infinito (até fechar o jogo)
	while (gerenciador_grafico->VerificaSeJanelaAberta())
	{
		gerenciador_eventos->executar();

		gerenciador_grafico->limpaJanela();

		gerenciador_estados->executar();

		gerenciador_grafico->printaJogo();

	}
}