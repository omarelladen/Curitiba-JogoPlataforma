#include "Entidade.h"
using namespace Entidades;

#include"Plataforma.h"

Entidade::Entidade(const IDs id, Vector2f tam_corpo) :
	Ente(id),
	corpo(tam_corpo),
	posicao(),
	esta_no_chao(true),
	tam_corpo(tam_corpo)
{
}

Entidade::~Entidade()
{
}

void Entidade::setColidiu(const bool c)
{
	esta_no_chao = c;
}

void Entidade::mover(const char* direcao)
{
}

void Entidade::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
}

void Entidade::desenhar_se()
{
	if (window_manager && window_manager->getJanela())
	{
		window_manager->desenhaEnte(corpo);
	}
	else
	{
		cout << "Ponteiro Janela nulo em Entidade" << endl;
	}
}

void Entidade::setPosicao(Vector2f pos)
{
	posicao = pos;
	corpo.setPosition(pos);
}

Vector2f Entidade::getPosicao() const
{
	return posicao;
}

Vector2f Entidade::getTamanho() const
{
	return tam_corpo;
}

const RectangleShape Entidades::Entidade::getCorpo() const
{
	return corpo;
}