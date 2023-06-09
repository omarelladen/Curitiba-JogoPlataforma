#include"Jogador.h"
#include"Gerenciador_Eventos.h"
#include"ObservadorJogador.h"

Jogador::Jogador(const IDs id, Vector2f pos) :
    Personagem(id, pos),
    pontos(0),
    observadorJogador(nullptr)
{
    Vector2f pos_ini_player(200.f, 100.f);
    //corpo.setFillColor(Color::Blue);
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

void Jogador::setPontos(const int pon)
{
    pontos = pon;
}

const int Jogador::getPontos() const
{
    return pontos;
}

void Jogador::mover(const char* direcao)
{
    if (!esta_no_chao)
    {
        if (velocidade.y <= MAX_VEL_AR)
        {
            if (direcao == "Baixo")
            {
                velocidade.y += INCRE_VEL;
            }
        }
        corpo.move(0.f, velocidade.y);

        if (velocidade.x <= MAX_VEL / 2.f && velocidade.x >= -MAX_VEL / 2.f)
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
        restartRelogio();
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
        corpo.move(velocidade.x, 0.f);
    }
    posicao = corpo.getPosition();
}

void Jogador::parar()
{
    velocidade.x = 0.f;
}

void Jogador::executar()
{
    //cout << esta_no_chao << endl;
    window_manager->setCentro(posicao);
    efeitoGravidade();
    desenhar_se();
}