#include "MenuPrincipal.h"
using namespace Menus;
#include"ObservadorMenuPrincipal.h"

constexpr auto TAM_BOTOES_X = 400.f;
constexpr auto TAM_BOTOES_Y = 100.f;

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

	RenderWindow* janela = Gerenciador_Grafico::getGerenciadorGrafico()->getJanela();

	// Alocacao Botoes
	botao_jogarBarigui = new Botao(Vector2f((janela->getSize().x/2.f) - TAM_BOTOES_X/2.f, (janela->getSize().y / 4.f) - TAM_BOTOES_Y/2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Fase Barigui", Color::Green);
	botao_jogarCooperativoBarigui = new Botao(Vector2f((janela->getSize().x / 2.f) - TAM_BOTOES_X / 2.f, (janela->getSize().y / 2.f) - TAM_BOTOES_Y / 2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Fase Barigui Cooperativo", Color::Green);
	botao_sair = new Botao(Vector2f((janela->getSize().x / 2.f) - TAM_BOTOES_X / 2.f, ((janela->getSize().y*3.f) / 4.f) - TAM_BOTOES_Y / 2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Sair", Color::Red);
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
			Gerenciador_Estados::getGerenciadorEstados()->addEstado
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