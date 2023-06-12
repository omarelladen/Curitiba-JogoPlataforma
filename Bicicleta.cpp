#include"ListaEntidades.h"
#include"Bicicleta.h"

Bicicleta::Bicicleta(Vector2f pos) :
	Obstaculo(IDs::bicicleta, pos),
	nivel_ricochete(0),
    dano(0)
{
    inicializaAtributos();
}

Bicicleta::~Bicicleta()
{
}

void Bicicleta::inicializaAtributos()
{
    setTextura("Texturas/Sprite-bike-ciclista-teste.png");
    setTamanho(Vector2f(50.f, 50.f));

	time_t t;
	srand((unsigned)time(&t));

    danoso = true;
    dano = 1; // rand() % 3 + 5;
	nivel_ricochete = rand() % 101 + 150;
	velocidade = Vector2f((rand() % 5 + 5) / -10.f, 0.f);
}

void Bicicleta::setNivelRicochete(const int ricochete)
{
    nivel_ricochete = ricochete;
}

const int Bicicleta::getNivelRicochete() const
{
    return nivel_ricochete;
}

void Entidades::Obstaculos::Bicicleta::setDano(const int damage)
{
}

const int Entidades::Obstaculos::Bicicleta::getDano() const
{
    return dano;
}

void Bicicleta::mover()
{
	corpo.move(velocidade);
	posicao = corpo.getPosition();
}

void Bicicleta::executar()
{
    mover();
	desenhar_se();
}