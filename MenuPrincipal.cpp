#include "MenuPrincipal.h"
using namespace Menus;
#include"ObservadorMenuPrincipal.h"

MenuPrincipal::MenuPrincipal() :
	Menu(IDs::menuPrincipal),
	observadorMenuPrincipal(nullptr),
	botao_jogarBarigui(nullptr),
	botao_jogarBeco(nullptr),
	botao_sair(nullptr)
{
	//Alocacao observador
	observadorMenuPrincipal = new ObservadorMenuPrincipal(this); // this para setar la tambem

	//Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->addObservador(observadorMenuPrincipal);

	titulo.setString("MENU PRINCIPAL");

	//Alocacao dos botoes

	botao_jogarBarigui = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Jogar Fase Barigui", 20, Color::Green);

	botao_jogarBeco = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Jogar Fase Beco", 20, Color::Green);

	botao_sair = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Sair", 20, Color::Red);

	selecionaBotao(false);
}

MenuPrincipal::~MenuPrincipal()
{
	delete observadorMenuPrincipal;
	delete botao_jogarBarigui;
	delete botao_jogarBeco;
	delete botao_sair;

	observadorMenuPrincipal = nullptr;
	botao_jogarBarigui = nullptr;
	botao_jogarBeco = nullptr;
	botao_sair = nullptr;
}

void MenuPrincipal::selecionaBotao(const bool enter)
{
	if (opcao == 1)
	{
		//Botoes nao selecionados
		botao_jogarBeco->naoSelecionado();
		botao_sair->naoSelecionado();

		//JOGAR FASE PARQUE BARIGUI

		botao_jogarBarigui->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			pGEstados->addEstado(pGEstados->criarEstadoJogar(IDs::fase_barigui));
		}
	}
	else if (opcao == 2)
	{
		//Botoes nao selecionados
		botao_jogarBarigui->naoSelecionado();
		botao_sair->naoSelecionado();

		//JOGAR FASE BECO

		botao_jogarBeco->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			pGEstados->addEstado(pGEstados->criarEstadoJogar(IDs::fase_beco));
		}

	}
	else if (opcao == 3)
	{
		//Botoes nao selecionados;
		botao_jogarBarigui->naoSelecionado();
		botao_jogarBeco->naoSelecionado();

		//FECHAR JOGO

		botao_sair->selecionado();

		if (enter)
		{
			Gerenciador_Grafico::getGerenciadorGrafico()->fechaJanela();
		}
	}
}

void MenuPrincipal::atualizarPosicao()
{
	centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();

	titulo.setPosition(Vector2f(centro_janela.x - titulo.getGlobalBounds().width / 2.f,
		centro_janela.y - TAM_BOTOES_Y * 4));

	botao_jogarBarigui->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y));

	botao_jogarBeco->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y + 90.f));

	botao_sair->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y + 180.f));
}

void MenuPrincipal::desenhar_se()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(titulo);
	botao_jogarBarigui->render();
	botao_jogarBeco->render();
	botao_sair->render();
}

void MenuPrincipal::executar()
{
	atualizarPosicao();
	desenhar_se();
}