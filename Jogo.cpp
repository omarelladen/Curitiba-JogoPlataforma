#include "Jogo.h"
#include "IDs.h"

Jogo::Jogo()
{
	// Manda criar e adicionar o Estado Menu Principal
	Gerenciador_Estados::getGerenciadorEstado()->adicionarEstado
	(
		Gerenciador_Estados::getGerenciadorEstado()->criarEstadoMenuPrincipal()
	);
	//gerenciador_estados->
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

	// Loop infinito (até fechar o jogo) - roda a fase
	while (gerenciador_grafico->getJanela()->isOpen())
	{
		gerenciador_eventos->executar();

		gerenciador_grafico->limpaJanela();

		gerenciador_estados->executar();

		gerenciador_grafico->mostraEnte();

	}
}
