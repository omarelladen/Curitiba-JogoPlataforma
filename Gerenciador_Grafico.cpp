#include"Botao.h"
#include"Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;
#include<iostream>
using namespace std;

Gerenciador_Grafico* Gerenciador_Grafico::pGerenciadorGrafico(nullptr);

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(nullptr),
	camera()
{
	janela = new RenderWindow(VideoMode(1000, 900), "Jogo");
	if (janela == nullptr)
	{
		cerr << "Erro - Alocacao de janela nao realizada" << endl;
	}
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

void Gerenciador_Grafico::desenhaNaJanela(RectangleShape body)
{
	janela->draw(body);
}

void Gerenciador_Grafico::desenhaNaJanela(Text texto)
{
	janela->draw(texto);
}

void Gerenciador_Grafico::printaJogo()
{
	janela->display();
}

void Gerenciador_Grafico::fechaJanela()
{
	janela->close();
}

const Vector2f Gerenciador_Grafico::getCentroJanela() const
{
	return camera.getCenter();
}

const bool Gerenciador_Grafico::VerificaSeJanelaAberta()
{
	return janela->isOpen();
}