#include "MenuPrincipal.h"
using namespace Menus;
#include"ObservadorMenuPrincipal.h"

MenuPrincipal::MenuPrincipal() :
	Menu(IDs::menuPrincipal),
	observadorMenuPrincipal(nullptr),
	botao_jogarBarigui(nullptr),
	botao_jogarbeco(nullptr),
	botao_ranking(nullptr),
	botao_sair(nullptr)
{
	//Alocacao observador
	observadorMenuPrincipal = new ObservadorMenuPrincipal(this); // this para setar la tambem

	//Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorMenuPrincipal);

	titulo.setString("MENU PRINCIPAL");

	//Alocacao dos botoes

	botao_jogarBarigui = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Jogar Fase Barigui", 20, Color::Green);

	botao_jogarbeco = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Jogar Fase Beco", 20, Color::Green);

	botao_ranking = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Ranking", 20, Color::Green);

	botao_sair = new Botao(Vector2f(0.f, 0.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Sair", 20, Color::Red);

	selecionaBotao(false);
}

MenuPrincipal::~MenuPrincipal()
{
	delete observadorMenuPrincipal;
	delete botao_jogarBarigui;
	delete botao_jogarbeco;
	delete botao_ranking;
	delete botao_sair;

	observadorMenuPrincipal = nullptr;
	botao_jogarBarigui = nullptr;
	botao_jogarbeco = nullptr;
	botao_ranking = nullptr;
	botao_sair = nullptr;
}

void MenuPrincipal::selecionaBotao(const bool enter)
{
	if (opcao == 1)
	{
		//Botoes nao selecionados
		botao_jogarbeco->naoSelecionado();
		botao_ranking->naoSelecionado();
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
		botao_ranking->naoSelecionado();
		botao_sair->naoSelecionado();

		//JOGAR FASE BECO

		botao_jogarbeco->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			pGEstados->addEstado(pGEstados->criarEstadoJogar(IDs::fase_beco));
		}

	}
	else if (opcao == 3)
	{
		botao_jogarBarigui->naoSelecionado();
		botao_jogarbeco->naoSelecionado();
		botao_sair->naoSelecionado();

		//ABRIR RANKING

		botao_ranking->selecionado();

		if (enter)
		{
			//Desativa todos os observadores ativados
			pGEventos->desativaObservadores();

			//Cria o EstadoRanking e coloca ele no topo da pilha
			pGEstados->addEstado(pGEstados->criarEstadoRanking());
		}
	}
	else if (opcao == 4)
	{
		//Botoes nao selecionados;
		botao_jogarBarigui->naoSelecionado();
		botao_jogarbeco->naoSelecionado();
		botao_ranking->naoSelecionado();

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

	botao_jogarbeco->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y + 90.f));

	botao_ranking->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y + 180.f));

	botao_sair->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y - TAM_BOTOES_Y + 270.f));
}

void MenuPrincipal::desenhar_se()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(titulo);
	botao_jogarBarigui->render();
	botao_jogarbeco->render();
	botao_ranking->render();
	botao_sair->render();
}

void MenuPrincipal::executar()
{
	atualizarPosicao();
	desenhar_se();
}