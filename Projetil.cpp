#include"Projetil.h"
#include"Inimigo.h"
#include"Capivara.h"
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

        //id eh de quem eh atacado
        switch (id)
        {
        case IDs::capivara:
        {
            switch (atirador->getID())
            {
            case IDs::capanga:
            {

            }
            default:
                break;
            } 
        }
        break;

        case IDs::jacare:
        {

        }

        case IDs::capanga:
        {
            if (atirador->getID() == IDs::capivara)
            {
                Capivara* pJog = static_cast<Capivara*>(atirador);
                pJog->operator++();
            }
        }
        break;

        case IDs::chefeMafia:
        {

        }

        case IDs::plataforma:
        {

        }
        break;

        case IDs::canto:
        {

        }
        break;

        default: {
            cout << "Erro Colisao Projetil" << endl;
        }
               break;
        }
    }
    else
    {
        cout << "Erro - Projetil sem atirador" << endl;
    }
}

void Projetil::mover()
{
    //Efeito Gravidade

    if (velocidade.y <= MAX_VEL)
    {
        tempo = relogio.getElapsedTime();
        velocidade.y += (GRAVIDADE * (tempo.asSeconds() / (float)100.0));
    }
    corpo.move(0.f, velocidade.y);

    corpo.move(velocidade);
    posicao = corpo.getPosition();
}

void Projetil::executar()
{
    desenhar_se();
    mover();
}