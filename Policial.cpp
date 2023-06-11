#include "Policial.h"

Policial::Policial(Vector2f pos) :
	Jogador(IDs::policial, pos),
	pente_arma(0),
	atirar(false)
{
}

Policial::~Policial()
{
}

void Policial::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    esta_no_chao = false;
    switch (id)
    {
    case IDs::capanga:
    {
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x

            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;

                //Colisao Esquerda

                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Direita

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }

            //Colisao em y

            else
            {
                distancia_colisao.x = 0.f;

                //Colisao Cima

                if (posicao.y < ent->getPosicao().y)
                {
                    esta_no_chao = true;
                    executar();
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Baixo

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
        }

        Capanga* pCapa = static_cast<Capanga*>(ent);
        if (pCapa->getNivelMaldade() > 10)
        {
            if (pCapa->getNivelEstupidez() > 5)
            {
                pCapa->operator--();
                this->operator++();
            }
            else
            {
                pCapa->operator++();
                this->operator--();
            }
        }
    }
    break;

    case IDs::jacare:
    {
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x

            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;

                //Colisao Esquerda

                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Direita

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }

            //Colisao em y

            else
            {
                distancia_colisao.x = 0.f;

                //Colisao Cima

                if (posicao.y < ent->getPosicao().y)
                {
                    esta_no_chao = true;
                    executar();
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Baixo

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
        }

        Jacare* pJac = static_cast<Jacare*>(ent);
        if (pJac->getNivelMaldade() > 10)
        {
            if (pJac->getNivelMordida() < 10)
            {
                pJac->operator--();
                this->operator++();
            }
            else
            {
                pJac->operator++();
                this->operator--();
            }
        }
    }
    break;

    case IDs::chefeMafia:
    {
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x

            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;

                //Colisao Esquerda

                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Direita

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }

            //Colisao em y

            else
            {
                distancia_colisao.x = 0.f;

                //Colisao Cima

                if (posicao.y < ent->getPosicao().y)
                {
                    esta_no_chao = true;
                    executar();
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Baixo

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
        }

        ChefeMafia* pChefMaf = static_cast<ChefeMafia*>(ent);
        if (pChefMaf->getNivelMaldade() > 10)
        {
            if (pChefMaf->getNivelForca() < 10)
            {
                if (pChefMaf->getNivelMedo() > 10)
                {
                    pChefMaf->operator++();
                    this->operator--();
                }
                else
                {
                    pChefMaf->operator--();
                    this->operator++();
                }
            }
            else
            {
                pChefMaf->operator++();
                this->operator--();
            }
        }
    }
    break;

    case IDs::plataforma:
    {
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x

            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;

                //Colisao Esquerda

                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                }

                //Colisao Direita

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }

            //Colisao em y

            else
            {
                distancia_colisao.x = 0.f;
                //Colisao Cima

                if (posicao.y < ent->getPosicao().y)
                {
                    esta_no_chao = true;
                    executar();
                    setPosicao(posicao + distancia_colisao);
                }
                //Colisao Baixo

                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
        }
    }
    break;

    case IDs::projetil:
    {
        this->operator--();
    }

    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }
    break;

    default: {
        cout << "Erro Colisao Jogador" << endl;
    }
           break;
    }
}

const int Policial::getPenteArma() const
{
    return pente_arma;
}

const bool Policial::getAtirar() const
{
    return atirar;
}
