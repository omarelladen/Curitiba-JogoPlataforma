#include"ListaEntidades.h"
#include"Personagem.h"
#include"Projetil.h"

Projetil::Projetil(Vector2f pos) :
    Entidade(IDs::projetil, pos),
    dano(0),
    atirador(nullptr)
{
    //Textura

    inicializaAtributos();
}

Projetil::~Projetil()
{
    atirador = nullptr;
}

void Projetil::inicializaAtributos()
{
    //setTextura("Texturas/Sprite-projetil.png");

    corpo.setFillColor(sf::Color::Red);//
    setTamanho(Vector2f(10.f, 10.f));//

    time_t t;
    srand((unsigned)time(&t));

    velocidade = Vector2f(0.7f, 0.f); //(rand() % 11 + 10) / 10.f em x
}

void Projetil::setAtirador(Personagem* atir)
{
    atirador = atir;
}

Personagem* Projetil::getAtirador()
{
    return atirador;
}

void Projetil::setDano(const int d)
{
    dano = d;
}

const int Projetil::getDano() const
{
    return dano;
}

void Projetil::mover()
{
    corpo.move(velocidade);
    posicao = corpo.getPosition();
}

void Projetil::executar()
{
    mover();
    //efeitoGravidade();
    desenhar_se();
}