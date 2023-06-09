#include"Gerenciador_Colisoes.h"
#include"Personagem.h"
using namespace Entidades;

Personagem::Personagem(const IDs id, Vector2f pos) :
    Entidade(id, pos),
    num_vidas(0),
    direita(true)
{
}

Personagem::~Personagem()
{
}

void Personagem::setNumVidas(const int vidas)
{
    num_vidas = vidas;
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}

void Personagem::setDireita(const bool dir)
{
    direita = dir;
}

const bool Personagem::getDireita()
{
    return direita;
}

void Personagem::atirar(const int dano)
{
    Projetil* pProj = nullptr;

    if (direita)
    {
        pProj = new Projetil(Vector2f(posicao.x + tam_corpo.x + 2.f, posicao.y + tam_corpo.y / 2.f));
        if(pProj == nullptr)
        {
            cout << "Erro alocacao de Projetil em Personagem" << endl;
            exit(1);
        }
    }
    else
    {
        //-9.f por causa do tamanho e pra ficar um pouco longe do personagem
        pProj = new Projetil(Vector2f(posicao.x - 9.f, posicao.y + tam_corpo.y / 2.f));
        if (pProj)
        {
            pProj->setVelocidade(Vector2f(-pProj->getVelocidade().x, pProj->getVelocidade().y));
        }
        else
        {
            cout << "Erro alocacao de Projetil em Personagem" << endl;
            exit(1);
        }
    }

    pProj->setAtirador(this);
    pProj->setDano(dano);

    Gerenciador_Colisoes::getGerenciadorColisoes()->addProjetil(static_cast<Entidade*>(pProj));
}

void Personagem::diminuirVida(int dano)
{
    num_vidas -= dano;
}
