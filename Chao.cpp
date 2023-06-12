#include"ListaEntidades.h"
#include"Chao.h"
using namespace Obstaculos;

Chao::Chao(Vector2f pos) :
	Obstaculo(IDs::chao, pos),
	atrito(0.0)
{
    inicializaAtributos();
}

Chao::~Chao()
{
}

void Chao::inicializaAtributos()
{
    // if (id barigui)
    setTextura("Texturas/Sprite-chao-parque.png");
    setTamanho(Vector2f(50.f, 50.f));

	time_t t;
	srand((unsigned)time(&t));

    atrito = (double)(rand() % 3 + 1) / (double)10;
}

void Chao::setAtrito(const double atri)
{
    atrito = atri;
}

const double Chao::getAtrito() const
{
	return atrito;
}

void Chao::executar()
{
	desenhar_se();
}
