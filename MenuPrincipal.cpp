#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
	// Cria seu Observador:
	observadorMenuPrincipal = new ObservadorMenuPrincipal(this); // this para setar la tambem

	// Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorMenuPrincipal);

	//Arrumar

	//botao_jogarFase1 = new Botao(100, 100, 150, 50, xxxxx, "Jogar Fase 1", Color::White, Color::Yellow, Color::Red);
	//botao_sair = new Botao(100, 100, 150, 50, xxxxx, "Jogar Fase 1", Color::White, Color::Yellow, Color::Red);
		//botao_configuracoes = new Botao(100, 100, 150, 50, xxxxx, "Jogar Fase 1", Color::White, Color::Yellow, Color::Red);
}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::atualizarBotoes(const Vector2f posMouse)
{
	// manda atualizar a cor e o estado (id) do botao
	botao_jogarFase1->atualizar(posMouse);
	botao_sair->atualizar(posMouse);
	//botao_configuracoes->atualizar(posMouse);
}

void MenuPrincipal::acessarBotao(const Vector2f posMouse)
{
	

	if (botao_jogarFase1->pressionado())
	{
		//
		Gerenciador_Eventos::getGerenciadorEventos()->desativarObservadores();

		Gerenciador_Estados::getGerenciadorEstado()->adicionarEstado
		(
			Gerenciador_Estados::getGerenciadorEstado()->criarEstadoJogar(IDs::fase1)
		);
	}
	else if (botao_sair->pressionado())
	{
		Gerenciador_Grafico::getGerenciadorGrafico()->fechaJanela();
	}
	
}
