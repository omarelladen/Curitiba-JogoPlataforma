#include "Entidade.h"
using namespace Entidades;

Entidade::Entidade(const IDs id, Vector2f pos) : //
	Ente(id),
	corpo(),
	posicao(pos), // pos.x * cont
	tam_corpo(Vector2f(100.f, 100.f)),
	velocidade(Vector2f(0.f, 0.f)),
	tempo(),
	relogio_gravidade(),
	esta_no_chao(false),
	pListaEntidades(nullptr),
	textura()
{
	corpo.setPosition(pos);
	relogio_gravidade.restart();
	// rand
	// lista direto de Entidade* //
}

Entidade::~Entidade()
{
}

void Entidade::setTextura(const char* caminho_textura)
{
	if (!textura.loadFromFile(caminho_textura))
		cout << "Erro ao carregar a textura";
	else
		corpo.setTexture(&textura);
}

void Entidade::setEstaNoChao(const bool c)
{
	esta_no_chao = c;
}

const bool Entidades::Entidade::getEstaNoChao()
{
	return esta_no_chao;
}

void Entidade::efeitoGravidade()
{
	if (velocidade.y <= MAX_VEL)
	{
		tempo = relogio_gravidade.getElapsedTime();
		velocidade.y += (GRAVIDADE * (tempo.asSeconds()/100.f));
	}

	corpo.move(velocidade);
	posicao = corpo.getPosition();
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

void Entidade::setTamanho(Vector2f tam)
{
	tam_corpo = tam;
	corpo.setSize(tam);
}

Vector2f Entidade::getTamanho() const
{
	return tam_corpo;
}

void Entidade::setVelocidade(Vector2f vel)
{
	velocidade = vel;
}

const Vector2f Entidades::Entidade::getVelocidade() const
{
	return velocidade;
}

void Entidade::restartRelogio()
{
	tempo = relogio_gravidade.restart();
}

const RectangleShape Entidade::getCorpo() const
{
	return corpo;
}