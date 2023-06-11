#include"ObservadorMenuGameOver.h"
#include "MenuGameOver.h"
using namespace Menus;

MenuGameOver::MenuGameOver() :
	Menu(IDs::menuGameOver),
	observadorMenuGameOver(nullptr),
	botao_jogarNovamente(nullptr),
	botao_menuPrincipal(nullptr)
{
	observadorMenuGameOver = new ObservadorMenuGameOver(this); // this para setar la tambem

	pGEventos->adicionarObservador(observadorMenuGameOver);//

	titulo.setString("GAME OVER");

	//Alocacao Botoes:

	//Botao Esquerda
	botao_menuPrincipal = new Botao(Vector2f(centro_janela.x + TAM_BOTOES_X / 2.f, (centro_janela.y * 3.f) / 2.f),
		Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Menu Principal", 25, Color::Green);

	//Botao Direita
	botao_jogarNovamente = new Botao(Vector2f(centro_janela.x - (TAM_BOTOES_X * 3.f / 2.f),
		(centro_janela.y * 3.f) / 2.f),
		Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Jogar Novamente", 25, Color::Green);

	selecionaBotao(false);
}

MenuGameOver::~MenuGameOver()
{
	delete observadorMenuGameOver;
	delete botao_jogarNovamente;
	delete botao_menuPrincipal;

	observadorMenuGameOver = nullptr;
	botao_jogarNovamente = nullptr;
	botao_menuPrincipal = nullptr;
}

void MenuGameOver::selecionaBotao(const bool enter)
{
	if (opcao == 1)
	{
		botao_jogarNovamente->naoSelecionado();

		//IR PARA O MENU PRINCIPAL

		botao_menuPrincipal->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			//Ativar observadores pertinentes
			pGEventos->ativaObservador(IDs::menuPrincipal);

			//Desempilha 2 estados (Game Over e Jogo) 
			pGEstados->removerEstado(2);
		}
	}
	else if (opcao == 2)
	{
		botao_menuPrincipal->naoSelecionado();

		//COMECAR UM NOVO JOGO

		botao_jogarNovamente->selecionado();

		if (enter)
		{
			pGEventos->desativaObservadores();

			pGEventos->ativaObservador(IDs::jogo);

			//Desempilha o Game Over e o Jogo para começar um novo jogo
			pGEstados->removerEstado(2);

			pGEstados->addEstado(pGEstados->criarEstadoJogar(IDs::fase_barigui));
		}
	}
}

void MenuGameOver::atualizarPosicao()
{
	centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();

	titulo.setPosition(Vector2f(centro_janela.x - titulo.getGlobalBounds().width / 2.f,
		centro_janela.y - TAM_BOTOES_Y - titulo.getGlobalBounds().height / 2.f));

	botao_jogarNovamente->atualizarPosicao(Vector2f(centro_janela.x - (TAM_BOTOES_X * 3.f / 2.f),
		(centro_janela.y * 3.f) / 2.f));

	botao_menuPrincipal->atualizarPosicao(Vector2f(centro_janela.x + TAM_BOTOES_X / 2.f,
		(centro_janela.y * 3.f) / 2.f));
}

void MenuGameOver::desenhar_se()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(titulo);
	botao_jogarNovamente->render();
	botao_menuPrincipal->render();
}

void MenuGameOver::executar()
{
	atualizarPosicao();
	desenhar_se();
}