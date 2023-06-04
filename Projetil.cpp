#include"Projetil.h"
#include"Inimigo.h"
using namespace Entidades::Personagens;

Projetil::Projetil(Vector2f pos, Vector2f vel) :
    Entidade(IDs::projetil, pos),
    velocidade(vel),
    dano(0),
    atirador(nullptr)
{
}

Projetil::~Projetil()
{
    atirador = nullptr;
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

void Projetil::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::capivara:
    {
        if (atirador && atirador->getID() == IDs::jacare)
        {
            Inimigo* pInim = static_cast<Personagens::Inimigo*>(atirador);
            pInim->operator++();
        }
    }
    break;

    case IDs::capanga:
    {
        if (atirador && atirador->getID() == IDs::policial)
        {
            Policial* pJog = static_cast<Policial*>(atirador);
            pJog->operator++();
        }
    }
    break;

    case IDs::plataforma:
    {

    }
    break;

    case IDs::canto:
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