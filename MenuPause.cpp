#include "MenuPause.h"
using namespace Menus;

//
MenuPause::MenuPause():
	Menu(IDs::menuPause),
	observadorMenuPause(nullptr),
	botao_voltar(nullptr),
	botao_sair(nullptr),
	botao_salvar(nullptr)
{
	observadorMenuPause = new ObservadorMenuPause(this); // this para setar la tambem

	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorMenuPause);//

	RenderWindow* janela = Gerenciador_Grafico::getGerenciadorGrafico()->getJanela();

	// Alocacao Botoes
	botao_voltar = new Botao(Vector2f((janela->getSize().x / 2.f) - TAM_BOTOES_X / 2.f, (janela->getSize().y / 4.f) - TAM_BOTOES_Y / 2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Voltar", 25, Color::Green);
	botao_sair = new Botao(Vector2f((janela->getSize().x / 2.f) - TAM_BOTOES_X / 2.f, (janela->getSize().y / 2.f) - TAM_BOTOES_Y / 2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Sair", 25, Color::Red);
	botao_salvar = new Botao(Vector2f((janela->getSize().x / 2.f) - TAM_BOTOES_X / 2.f, ((janela->getSize().y * 3.f) / 4.f) - TAM_BOTOES_Y / 2.f), Vector2f(TAM_BOTOES_X, TAM_BOTOES_Y), "Salvar", 25, Color::Green);
}

MenuPause::~MenuPause()
{
	delete observadorMenuPause;
	delete botao_voltar;
	delete botao_sair;
	delete botao_salvar;

	observadorMenuPause = nullptr;
	botao_sair = nullptr;
	botao_voltar = nullptr;
	botao_salvar = nullptr;
}

void MenuPause::verificaClique(Vector2f posMouse)
{
	//if (Mouse::isButtonPressed(Mouse::Left)) //forma.getGlobalBounds().contains(posMouse))
	//{
		if (botao_voltar->pressionado(posMouse))
		{
			Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

			// ativar
			Gerenciador_Eventos::getGerenciadorEventos()->ativaObservador(IDs::jogo); // Obs ja existem
	

			// desempilha para voltar
			Gerenciador_Estados::getGerenciadorEstados()->removerEstado(1); // isso excluir estado, obj e obs

			
		}
		//else
		else if (botao_sair->pressionado(posMouse))
		{
			Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

			Gerenciador_Eventos::getGerenciadorEventos()->ativaObservador(IDs::menuPrincipal);

			// Desempilha 2 estados (pause e jogo) pra voltar ao menu principal
			Gerenciador_Estados::getGerenciadorEstados()->removerEstado(2); // desempilha o pause e o jog (n = 2)
		} 
		else if(botao_salvar->pressionado(posMouse))
		{
			//desempilhar menu pause
			//Usar o salvar do estado jogar
			//empilhar o menu pause
		}
	//}
}

void MenuPause::desenhar_se()
{
	botao_voltar->render();
	botao_sair->render();
}

void MenuPause::executar()
{
	Gerenciador_Grafico::getGerenciadorGrafico()->setCentro(botao_voltar->getPosicao());
	desenhar_se();
}
