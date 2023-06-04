#include "MenuPause.h"
using namespace Menus;

//
Menus::MenuPause::MenuPause():
	Menu(IDs::menuPause),
	observadorMenuPause(nullptr),
	botao_voltar(nullptr),
	botao_sair(nullptr)
{
	observadorMenuPause = new ObservadorMenuPause(this); // this para setar la tambem

	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorMenuPause);//

	// Alocacao Botoes
	botao_voltar = new Botao(Vector2f(100.f, 100.f), Vector2f(150.f, 50.f), "Fase Barigui", Color::Yellow);
	botao_sair = new Botao(Vector2f(100.f, 300.f), Vector2f(150.f, 50.f), "Sair", Color::Red);
	//botao_configuracoes = new Botao(100, 100, 150, 50, xxxxx, "Configuracoes", Color::Yellow, Color::Red);
}

Menus::MenuPause::~MenuPause()
{
	delete observadorMenuPause;
	delete botao_voltar;
	delete botao_voltar;

	observadorMenuPause = nullptr;
	botao_sair = nullptr;
	botao_voltar = nullptr;
}

void Menus::MenuPause::verificaClique(Vector2f posMouse)
{
	if (Mouse::isButtonPressed(Mouse::Left)) //forma.getGlobalBounds().contains(posMouse))
	{
		if (botao_voltar->pressionado(posMouse))
		{
			Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

			// ativar
			Gerenciador_Eventos::getGerenciadorEventos()->ativaObservador(IDs::estadoJogar); // Obs ja existem
	

			// desempilha para voltar
			Gerenciador_Estados::getGerenciadorEstados()->removerEstado(1); // isso excluir estado, obj e obs

			
		}
		//else
		if (botao_sair->pressionado(posMouse))
		{
			// Desempilha 2 estados (pause e jogo) pra voltar ao menu principal
			Gerenciador_Estados::getGerenciadorEstados()->removerEstado(2); // desempilha o pause e o jog (n = 2)
		}
	}
}

void Menus::MenuPause::desenhar_se()
{
	botao_voltar->render();
	botao_sair->render();
}

void Menus::MenuPause::executar()
{
	desenhar_se();
}
