#include"Jogador.h"
#include"Gerenciador_Eventos.h"
#include"ObservadorJogador.h"

Jogador::Jogador(const IDs id, Vector2f pos) :
    Personagem(id, pos),
    pontos(0),
    observadorJogador(nullptr)
{
    Vector2f pos_ini_player(100.f, 300.f);
    corpo.setFillColor(Color::Blue);
    corpo.setSize(tam_corpo);
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
                velocidade.y = -2.5f;
            }
            else if (direcao == "Cima")
            {
                velocidade.y = -1.5f;
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
}

void Jogador::executar()
{
    if (!esta_no_chao)
        mover("");
    desenhar_se();
}