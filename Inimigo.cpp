#include"Inimigo.h"
#include"Projetil.h"
#include<list>
using namespace std;

Inimigo::Inimigo(const IDs id, Vector2f pos, Capivara* player, Vector2f pos_i, Vector2f pos_f) :
    Personagem(id, pos),
    alvo(player),
    nivel_maldade(0),
    indo(true),
    projs(),
    pos_ini(pos_i),
    pos_fin(pos_f)
{
    corpo.setFillColor(Color::Red);
    corpo.setSize(tam_corpo);
    corpo.setPosition(pos);
}

Inimigo::~Inimigo()
{
    alvo = nullptr;
}

const int Inimigo::getNivelMaldade() const
{
    return nivel_maldade;
}

void Inimigo::operator++()
{
    nivel_maldade++;
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

void Inimigo::setProjetil(Projetil* proj)
{
    if (proj)
        projs.push_back(proj);
}

void Inimigo::atirar()
{
    list<Projetil*>::iterator it;
    for (it = projs.begin(); it != projs.end(); it++)
    {
        if (*it)
        {
            if ((*it)->getPosicao().x >= pos_ini.x && (*it)->getPosicao().x <= pos_fin.x)
            {
                (*it)->executar();
            }
            else
            {
                (*it)->colisao(IDs::canto, nullptr, Vector2f(0.f, 0.f));
            }
        }
    }
}

void Inimigo::executar()
{
    desenhar_se();
    mover("");
}
