#include"ListaEntidades.h"
#include "Capivara.h"

#include "Gerenciador_Colisoes.h"

Capivara::Capivara(Vector2f pos) :
	Jogador(IDs::capivara, pos),
	forca_cuspe(0),
    golpe_especial(0)
{
    inicializaAtributos();
}

Capivara::~Capivara()
{
}

void Capivara::inicializaAtributos()
{
    setTextura("Texturas/sprite-capivara-direita.png");
    setTamanho(Vector2f(80.f, 70.f));

    time_t t;
    srand((unsigned)time(&t));
    forca_cuspe = rand() % 5 + 1;

    num_vidas = 100;
}

void Capivara::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::capanga:
    {
        Capanga* pCap = static_cast<Capanga*>(ent);

        float intervalo_ataque = (float) pCap->getNivelEstupidez();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(1);

            relogio_ataque.restart();
        }


        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::jacare:
    {
        Jacare* pJac = static_cast<Jacare*>(ent);

        float intervalo_ataque = (float) pJac->getRapidezMordida();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(pJac->getForcaMordida());

            relogio_ataque.restart();
        }

        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::chefeMafia:
    {
        ChefeMafia* pCM = static_cast<ChefeMafia*>(ent);

        float intervalo_ataque = 100.f / pCM->getNivelMedo();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(pCM->getNivelForca());

            relogio_ataque.restart();
        }

        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::chao:
    {
        esta_no_chao = true;

        //o if de distancia_colisao tá ao contrario pq umas das distancia_colisao é zerada no gerenciador de colisoes, asssim mudando quem é maior
        //Colisao Cima 
        if (ent->getPosicao().y >= posicao.y + tam_corpo.y && distancia_colisao.x > distancia_colisao.y) 
        {
            setEstaNoChao(true);

            //Forca de atrito
            Chao* pChao = static_cast<Chao*>(ent);
            if (velocidade.x > 0.f)
            {
                velocidade.x -= (float) pChao->getAtrito() / 20.f;
            }
            else if (velocidade.x < 0.f)
            {
                velocidade.x += (float) pChao->getAtrito() / 20.f;
            }
        }
        else
        {
            setEstaNoChao(false);
        }
    }
    break;

    case IDs::bicicleta:
    {
        // Eh jogado para cima
        Bicicleta* pB = static_cast<Bicicleta*>(ent);
        velocidade.y = (-0.02f) * pB->getNivelRicochete();

        // Perde vida
        diminuirVida(pB->getDano());

    }
    break;

    case IDs::projetil:
    {
        Projetil* pProj = static_cast<Projetil*>(ent);
        if (pProj)
        {
            if (!(pProj->getAtirador()->getID() == IDs::capivara))
            {
                diminuirVida(pProj->getDano());
            }
        }
    }
    break;

    case IDs::lixo:
    {
        esta_no_chao = true;

        tempo = relogio_ataque.getElapsedTime();
        Lixo* pL = static_cast<Lixo*>(ent);
        if (pL)
        {
            if (tempo.asSeconds() >= pL->getRapidezIntoxicacao())
            {
                diminuirVida(pL->getDano());
                relogio_ataque.restart();
            }
        }
    }
    break;

    case IDs::arvore:
    {
        esta_no_chao = true;
    }
    break;


    default: {
    }
           break;
    }
}

void Capivara::setForcaCuspe(const int cuspe)
{
    forca_cuspe = cuspe;
}

const int Capivara::getForcaCuspe() const
{
    return forca_cuspe;
}

void Capivara::setGolpeEspecial(const int especial)
{
    golpe_especial = especial;
}

const int Capivara::getGolpeEspecial() const
{
    return golpe_especial;
}
