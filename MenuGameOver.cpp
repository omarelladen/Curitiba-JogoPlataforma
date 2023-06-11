#include"ObservadorMenuGameOver.h"
#include "MenuGameOver.h"
using namespace Menus;

MenuGameOver::MenuGameOver(Jogador* jog) :
	Menu(IDs::menuGameOver),
	observadorMenuGameOver(nullptr),
	registroNome(nullptr),
	fonte(),
	pontos(),
	aux_pontos(),
	nome(),
	aux_nome(),
	botao_jogarNovamente(nullptr),
	botao_menuPrincipal(nullptr)
{
	aux_pontos = "Pontos: ";
	if (jog)
	{
		aux_pontos += to_string(jog->getPontos());
	}

	inicializaAtributos();
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

void MenuGameOver::inicializaAtributos()
{
	observadorMenuGameOver = new ObservadorMenuGameOver(this); // this para setar la tambem

	registroNome = new ObservadorInputTexto();

	pGEventos->adicionarObservador(static_cast<Observador*>(observadorMenuGameOver));//
	pGEventos->adicionarObservador(static_cast<Observador*>(registroNome));

	titulo.setString("GAME OVER");

	aux_nome = "Nome:  ";

	fonte.loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf");

	pontos.setFont(fonte);
	pontos.setString(aux_pontos);
	pontos.setCharacterSize(40);
	pontos.setFillColor(Color::Black);
	pontos.setOutlineColor(Color::White);
	pontos.setOutlineThickness(1.f);
	pontos.setPosition(Vector2f(centro_janela.x - pontos.getGlobalBounds().width/2.f, centro_janela.y));

	nome.setFont(fonte);
	nome.setString(aux_nome);
	nome.setCharacterSize(40);
	nome.setFillColor(Color::Black);
	nome.setOutlineColor(Color::White);
	nome.setOutlineThickness(1.f);
	nome.setPosition(Vector2f(centro_janela.x - nome.getGlobalBounds().width / 2.f , 
							  centro_janela.y + pontos.getGlobalBounds().height + 20.f));

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
								centro_janela.y - TAM_BOTOES_Y - titulo.getGlobalBounds().height * 3.f));

	botao_jogarNovamente->atualizarPosicao(Vector2f(centro_janela.x - (TAM_BOTOES_X * 3.f / 2.f),
													centro_janela.y + TAM_BOTOES_Y * 3));

	botao_menuPrincipal->atualizarPosicao(Vector2f(centro_janela.x + TAM_BOTOES_X / 2.f,
													centro_janela.y + TAM_BOTOES_Y * 3));
}

void MenuGameOver::desenhar_se()
{
	aux_nome = "Nome:  " + registroNome->getTexto();
	nome.setString(aux_nome);

	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(titulo);
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(pontos);
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(nome);

	botao_jogarNovamente->render();
	botao_menuPrincipal->render();
}

void MenuGameOver::executar()
{
	atualizarPosicao();
	desenhar_se();
}