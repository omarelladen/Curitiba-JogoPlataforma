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
	janela = new RenderWindow(VideoMode(1000, 900), "Jogo");////
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

void Gerenciador_Grafico::printaJogo()
{
	janela->display();
}

void Gerenciador_Grafico::fechaJanela()
{
	janela->close();
}

Vector2f Gerenciadores::Gerenciador_Grafico::getCentroJanela()
{
	return camera.getCenter();
}

const bool Gerenciador_Grafico::VerificaSeJanelaAberta()
{
	return janela->isOpen();
}