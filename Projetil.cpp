#include"Projetil.h"
#include"Inimigo.h"
using namespace Entidades::Personagens;

Projetil::Projetil(Vector2f tam_corpo, Vector2f vel) :
    Entidade(IDs::projetil, tam_corpo),
    velocidade(vel),
    dano(0),
    atirador(NULL)
{
}

Projetil::~Projetil()
{
    atirador = NULL;
}

void Projetil::setAtirador(Personagem* atir)
{
    atirador = atir;
}

void Projetil::setDano(const int d)
{
    dano = d;
}

const int Projetil::getDano() const
{
    return dano;
}

void Entidades::Projetil::colisao(const string id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id.c_str()[0])
    {
        //Colisão Jogador

    case 'J':
    {
        if (atirador && atirador->getID() == IDs::inimigo)
        {
            Inimigo* pInim = static_cast<Personagens::Inimigo*>(atirador);
            pInim->operator++();
        }
    }
    break;

    case 'I':
    {
        if (atirador && atirador->getID() == IDs::jogador)
        {
            Jogador* pJog = static_cast<Jogador*>(atirador);
            pJog->operator++();
        }
    }
    break;

    case 'P':
    {

    }
    break;

    //Colisao Cantos

    case 'C':
    {
        if (atirador)
        {
            if (posicao.x > atirador->getPosicao().x)
            {
                setPosicao(Vector2f(atirador->getPosicao().x + atirador->getTamanho().x + 5.f,
                    atirador->getPosicao().y + atirador->getTamanho().y / 2.f));
            }
            else
            {
                setPosicao(Vector2f(atirador->getPosicao().x - tam_corpo.x - 5.f,
                    atirador->getPosicao().y + atirador->getTamanho().y / 2.f));
            }
        }
        else
        {
            cout << "Erro - Projetil sem atirador" << endl;
        }
    }
    break;

    default: {
        cout << "Erro Colisao Projetil" << endl;
    }
           break;
    }
}

void Projetil::mover()
{
    corpo.move(velocidade);
    posicao = corpo.getPosition();
}

void Projetil::executar()
{
    desenhar_se();
    //Mover é chamado pelo atirador.
}