#include"Jogador.h"
#include"Gerenciador_Eventos.h"
#include"ObservadorJogador.h"

Jogador::Jogador(const IDs id, Vector2f pos) :
    Personagem(id, pos),
    pontos(0),
    observadorJogador(nullptr)
{
    Vector2f pos_ini_player(0.f, 200.f);
    corpo.setFillColor(Color::Blue);
    corpo.setPosition(pos_ini_player);
    posicao = pos_ini_player;

    // Cria seu Observador:
    observadorJogador = new ObservadorJogador(this); // this para setar la tambem

    // Adiciona o seu Observador na lista de Observadores
    Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorJogador);
}

Jogador::~Jogador()
{
    observadorJogador = nullptr;
}

void Jogador::operator++()
{
    pontos++;
}

void Jogador::operator--()
{
    num_vidas--;
}

const int Jogador::getPontos()
{
    return pontos;
}

void Jogador::mover(const char* direcao)
{
    if (!esta_no_chao)
    {
        //Efeito da Gravidade
        tempo = relogio.getElapsedTime();
        if (velocidade.y <= MAX_VEL_AR)
        {
            velocidade.y += GRAVIDADE * (tempo.asSeconds() / (float)100.0);

            //Mergulho para baixo no Ar

            if (direcao == "Baixo")
            {
                velocidade.y += INCRE_VEL;
            }
        }
        corpo.move(0.f, velocidade.y);

        if (direcao != "")
        {
            if (velocidade.x <= MAX_VEL && velocidade.x >= (-1) * MAX_VEL)
            {
                if (direcao == "Direita")
                {
                    velocidade.x += INCRE_VEL;
                }
                if (direcao == "Esquerda")
                {
                    velocidade.x -= INCRE_VEL;
                }
            }
            corpo.move(velocidade.x, 0.f);
        }
        else
        {
            velocidade.x = 0.f;
        }
    }
    else
    {
        tempo = relogio.restart();
        if (direcao != "")
        {
            if (direcao == "Cima++")
            {
                velocidade.y = -3.f;
            }
            else if (direcao == "Cima")
            {
                velocidade.y = -1.f;
            }
            corpo.move(0.f, velocidade.y);


            if (velocidade.x <= MAX_VEL && velocidade.x >= -MAX_VEL)
            {
                if (direcao == "Direita")
                {
                    velocidade.x += INCRE_VEL;
                }
                if (direcao == "Esquerda")
                {
                    velocidade.x -= INCRE_VEL;
                }
            }
            else
            {
                velocidade.x = 0.f;
            }
            corpo.move(velocidade.x, 0.f);
        }
        else
        {
            parar();
        }
    }
    posicao = corpo.getPosition();
}

void Jogador::parar()
{
    velocidade.x = 0.f;
    velocidade.y = 0.f;
}

void Jogador::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
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

void Jogador::executar()
{
    desenhar_se();
}