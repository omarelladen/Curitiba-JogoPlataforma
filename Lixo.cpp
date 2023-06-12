#include"ListaEntidades.h"
#include"Lixo.h"

Lixo::Lixo(Vector2f pos):
	Obstaculo(IDs::lixo, pos),
	dano(0),
	tempo_retardo(0),
	rapidez_intoxicacao(0)
{
	inicializaAtributos();
}

Lixo::~Lixo()
{
}

void Lixo::inicializaAtributos()
{
	setTextura("Texturas/Sprite-lixo.png");
	setTamanho(Vector2f(70.f, 70.f));

	time_t t;
	srand((unsigned)time(&t));

	danoso = true;
	dano = (rand() % 3 + 1);
	tempo_retardo = rand() % 3 + 3;
	rapidez_intoxicacao = rand() % 2 + 1;
}

void Lixo::setDano(const int d)
{
	dano = d;
}

const int Lixo::getDano() const
{
	return dano;
}

int Entidades::Obstaculos::Lixo::getRapidezIntoxicacao()
{
	return rapidez_intoxicacao;
}

void Lixo::setTempoRetardo(const int tr)
{
	tempo_retardo = tr;
}

const int Lixo::getTempoRetardo() const
{
	return tempo_retardo;
}

void Lixo::executar()
{
	desenhar_se();
}
