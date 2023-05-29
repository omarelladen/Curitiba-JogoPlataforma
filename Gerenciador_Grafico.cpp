#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

#include"Gerenciador_Grafico.h"
#include"stdafx.h"

Gerenciador_Grafico* Gerenciador_Grafico::pManager(NULL);

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(NULL)
{
	janela = new RenderWindow(VideoMode(1000, 900), "Jogo");
	if (janela == NULL)
	{
		cerr << "Erro - Alocacao de janela nao realizada" << endl;
	}
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	if (janela)
	{
		delete janela;
		janela = NULL;
	}
	delete this;
}

Gerenciador_Grafico* Gerenciador_Grafico::getGerenciadorGrafico()
{
	if (pManager == NULL)
	{
		pManager = new Gerenciador_Grafico();
	}
	return pManager;
}

RenderWindow* Gerenciador_Grafico::getJanela()
{
	return janela;
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

const bool Gerenciador_Grafico::VerificaSeJanelaAberta()
{
	return janela->isOpen();
}