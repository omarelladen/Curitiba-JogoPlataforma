#include"Inimigo.h"
#include"Capivara.h"
#include<list>
using namespace std;

Inimigo::Inimigo(const IDs id, Vector2f pos) :
    Personagem(id, pos),
    alvo(nullptr),
    //Arrumar
    pos_ini(pos),
    pos_fin(pos + tam_corpo),
    //
    relogio_ataque()
{
    relogio_ataque.restart();
}

Inimigo::~Inimigo()
{
    alvo = nullptr;
}

void Inimigo::formaPadraoMover()
{
    if (posicao.x >= pos_ini.x + 1.f
        && (posicao.x + tam_corpo.x) <= pos_fin.x - 1.f)
    {
        if (direita)
        {
            velocidade.x = 0.2f;
        }
        else
        {
            velocidade.x = -0.2f;
        }
    }
    else
    {
        direita = !direita;
        if (posicao.x <= pos_ini.x + 1.f)
        {
            posicao.x = pos_ini.x + 2.f;
            setPosicao(posicao);
        }
        else if ((posicao.x + tam_corpo.x) >= pos_fin.x - 1.f)
        {
            posicao.x = pos_fin.x - tam_corpo.x - 2.f;
            setPosicao(posicao);
        }
    }
}

void Inimigo::perseguirAlvo()
{
    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (pos_alvo.x > pos_perseguidor.x)
    {
        corpo.move(0.2f, 0.f);
    }
    else
    {
        corpo.move(-0.2f, 0.f);
    }
}

void Inimigo::setAlvo(Capivara* target)
{
    alvo = target;
}