#include"Inimigo.h"
#include<list>
using namespace std;

Inimigo::Inimigo(const IDs id, Vector2f pos, Vector2f pos_i, Vector2f pos_f) :
    Personagem(id, pos),
    alvo(nullptr),
    indo(true),
    pos_ini(pos_i),
    pos_fin(pos_f)
{
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
        if (indo)
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
        indo = !indo;
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

void Inimigo::setIndo(const bool ind)
{
    indo = ind;
}

void Inimigo::executar()
{
    desenhar_se();
    mover("");
}
