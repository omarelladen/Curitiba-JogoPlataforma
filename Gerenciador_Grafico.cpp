#include"Botao.h"
#include"Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;
#include<iostream>
using namespace std;

Gerenciador_Grafico* Gerenciador_Grafico::pGerenciadorGrafico(nullptr);

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(nullptr),
	camera(),
	game_over(),
	fonte()
{
	janela = new RenderWindow(VideoMode(1000, 700), "Jogo");////
	if (janela == nullptr)
	{
		cerr << "Erro - Alocacao de janela nao realizada" << endl;
	}

	
	fonte.loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf");

	game_over.setFont(fonte);
	game_over.setString("Game Over");
	game_over.setFillColor(Color::Black);
	game_over.setOutlineColor(Color::White);
	game_over.setCharacterSize(60);
	game_over.setPosition(Vector2f(0.f, 0.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	if (janela)
	{
		delete janela;
		janela = nullptr;
	}
	delete this; //
}

Gerenciador_Grafico* Gerenciador_Grafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr)
	{
		pGerenciadorGrafico = new Gerenciador_Grafico();
	}
	return pGerenciadorGrafico;
}

RenderWindow* Gerenciador_Grafico::getJanela()
{
	return janela;
}

void Gerenciador_Grafico::setCentro(Vector2f pos_jog)
{
	janela->setView(camera);
	camera.setCenter(pos_jog);
}

void Gerenciador_Grafico::limpaJanela()
{
	janela->clear();
}

void Gerenciador_Grafico::desenhaEnte(RectangleShape body)
{
	janela->draw(body);
}

void Gerenciador_Grafico::mostraEnte()
{
	janela->display();
}

void Gerenciador_Grafico::fechaJanela()
{
	janela->close();
}

void Gerenciador_Grafico::gameOver()
{
	janela->draw(game_over);
}

void Gerenciador_Grafico::setPosicaoGameOver(Vector2f pos_jog)
{
	game_over.setPosition(Vector2f(pos_jog.x - game_over.getGlobalBounds().width / 2.f, pos_jog.y - game_over.getGlobalBounds().height / 2.f));
}

const bool Gerenciador_Grafico::VerificaSeJanelaAberta()
{
	return janela->isOpen();
}