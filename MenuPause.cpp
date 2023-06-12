#include"ObservadorMenuPause.h"
#include "MenuPause.h"
using namespace Menus;

//
MenuPause::MenuPause() :
	Menu(IDs::menuPause),
	observadorMenuPause(nullptr),
	botao_voltar(nullptr),
	botao_sair(nullptr)
{
	//Alocacao observador
	observadorMenuPause = new ObservadorMenuPause(this); // this para setar la tambem

	//Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->addObservador(observadorMenuPause);

	titulo.setString("PAUSE");

	// Alocacao Botoes
	botao_voltar = new Botao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y + TAM_BOTOES_Y),
		Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Voltar", 25, Color::Green);

	botao_sair = new Botao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f, centro_janela.y + TAM_BOTOES_Y + 90.f),
		Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Sair", 25, Color::Red);

	selecionaBotao(false);
}

MenuPause::~MenuPause()
{
	delete observadorMenuPause;
	delete botao_voltar;
	delete botao_sair;

	observadorMenuPause = nullptr;
	botao_sair = nullptr;
	botao_voltar = nullptr;
}

void MenuPause::selecionaBotao(const bool enter)
{
	if (opcao == 1)
	{
		//Botoes nao selecionados
		botao_voltar->naoSelecionado();

		//VOLTAR PARA O MENU PRINCIPAL

		botao_sair->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			pGEventos->ativaObservador(IDs::menuPrincipal);

			//Desempilha 2 estados (pause e jogo) pra voltar ao menu principal
			pGEstados->deleteEstado(2);
		}
	}
	else if (opcao == 2)
	{
		//Botoes nao selecionados
		botao_sair->naoSelecionado();

		//VOLTAR PARA O ESTADO JOGAR

		botao_voltar->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			//Ativa observadores pertinentes ao jogo
			pGEventos->ativaObservador(IDs::jogo);

			//Desempilha Menu Pause para voltar
			pGEstados->deleteEstado(1);
		}
	}
}

void MenuPause::atualizarPosicao()
{
	centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();

	titulo.setPosition(Vector2f(centro_janela.x - titulo.getGlobalBounds().width / 2.f,
		centro_janela.y - TAM_BOTOES_Y * 2.f));

	botao_voltar->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f,
		centro_janela.y + TAM_BOTOES_Y));
	botao_sair->atualizarPosicao(Vector2f(centro_janela.x - TAM_BOTOES_X / 2.f,
		centro_janela.y + TAM_BOTOES_Y + 90.f));
}

void MenuPause::desenhar_se()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(titulo);
	botao_voltar->render();
	botao_sair->render();
}

void MenuPause::executar()
{
	atualizarPosicao();
	desenhar_se();
}