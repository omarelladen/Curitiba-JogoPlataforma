#include "MenuPrincipal.h"
using namespace Menus;
#include"ObservadorMenuPrincipal.h"

MenuPrincipal::MenuPrincipal() :
	Menu(IDs::menuPrincipal),
	observadorMenuPrincipal(nullptr),
	botao_jogarBarigui(nullptr),
	botao_jogarCooperativoBarigui(nullptr),
	botao_sair(nullptr)
{
	// Alocacao observador
	observadorMenuPrincipal = new ObservadorMenuPrincipal(this); // this para setar la tambem

	// Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorMenuPrincipal);

	// Alocacao Botoes
	botao_jogarBarigui = new Botao(Vector2f(100.f, 100.f), Vector2f(150.f, 50.f), "Fase Barigui", Color::Yellow);
	botao_jogarCooperativoBarigui = new Botao(Vector2f(100.f, 500.f), Vector2f(150.f, 50.f), "Fase Barigui Cooperativo", Color::Green);
	botao_sair = new Botao(Vector2f(100.f, 300.f), Vector2f(150.f, 50.f), "Sair", Color::Red);
	//botao_configuracoes = new Botao(100, 100, 150, 50, xxxxx, "Configuracoes", Color::Yellow, Color::Red);
}

MenuPrincipal::~MenuPrincipal()
{
	delete observadorMenuPrincipal;
	delete botao_jogarBarigui;
	delete botao_jogarCooperativoBarigui;
	delete botao_sair;

	observadorMenuPrincipal = nullptr;
	botao_jogarBarigui = nullptr;
	botao_jogarCooperativoBarigui = nullptr;
	botao_sair = nullptr;
}

void MenuPrincipal::verificaClique(Vector2f posMouse) // const Mouse::Button botaoMouse, 
{
	//if (Mouse::isButtonPressed(Mouse::Left)) //forma.getGlobalBounds().contains(posMouse))
	//{
		// JOGAR FASE PARQUE BARIGUI	
		if (botao_jogarBarigui->pressionado(posMouse))
		{
			//
			Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

			// cria só o Player 1
			Gerenciador_Estados::getGerenciadorEstados()->adicionarEstado
			(
				Gerenciador_Estados::getGerenciadorEstados()->criarEstadoJogar(IDs::fase_barigui)
			);
		}
		/*if (botao_jogarDuplaBarigui->pressionado(posMouse))
		{
			Gerenciador_Eventos::getGerenciadorEventos()->desativarObservadores();


			// Player 1 & Player 2
			Gerenciador_Estados::getGerenciadorEstados()->adicionarEstado
			(
				Gerenciador_Estados::getGerenciadorEstados()->criarEstadoJogar(IDs::fase_barigui) //(, bool dupla)
			);
		}*/


		// SAIR DO JOGO (fechar)
		else if (botao_sair->pressionado(posMouse))
		{
			// precisa deletar td???
			Gerenciador_Grafico::getGerenciadorGrafico()->fechaJanela();
		}
	//}
}

void MenuPrincipal::desenhar_se()
{
	botao_jogarBarigui->render();
	botao_jogarCooperativoBarigui->render();
	botao_sair->render();
}

void MenuPrincipal::executar()
{
	desenhar_se();
}