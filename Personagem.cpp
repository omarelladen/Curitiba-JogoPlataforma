#include"Gerenciador_Colisoes.h"
#include"Personagem.h"
using namespace Entidades;


Personagem::Personagem(const IDs id, Vector2f pos) :
    Entidade(id, pos),
    num_vidas(0),
    direita(true),
    relogio_ataque(),
    barra_vidas()
    //listaProjeteis()///////
{
    //listaProjeteis = new ListaEntidades();

    // Barra vidas;
    barra_vidas.setFillColor(Color::Red);
    barra_vidas.setOutlineColor(Color::Black);
    barra_vidas.setSize(Vector2f((float)(num_vidas * 20), 2));
    barra_vidas.setPosition(Vector2f(pos.x, pos.y + 100));

    relogio_ataque.restart();
}

Personagem::~Personagem()
{
}


void Entidades::Personagens::Personagem::addProje(Entidade* pP)
{
    listaProjeteis->addEntidade(pP);
}

void Personagem::setNumVidas(const int vidas)
{
    num_vidas = vidas;
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}

void Personagem::imprimirBarraVidas()
{
    barra_vidas.setSize(Vector2f((float)num_vidas, 4.f));
    barra_vidas.setPosition(Vector2f(posicao.x, posicao.y - 10.f));
    Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(barra_vidas);
}

void Personagem::setDireita(const bool dir)
{
    direita = dir;
}

const bool Personagem::getDireita() const
{
    return direita;
}

void Personagem::atirar(const int dano)
{
    // TESTE PROJETIL
    /*Projetil* pP = new Projetil(Vector2f(posicao.x + 100, posicao.y));
    pP->setAtirador(this);
    pP->setDano(10);*/
    















    Projetil* pProj = nullptr;

    if (direita)
    {
        pProj = new Projetil(Vector2f(posicao.x + tam_corpo.x + 5.f, posicao.y + tam_corpo.y / 2.f));
        if (pProj == nullptr)
        {
            cout << "Erro alocacao de Projetil em Personagem" << endl;
            exit(1);
        }
    }
    else
    {
        //-30.f por causa do tamanho e pra ficar um pouco longe do personagem
        pProj = new Projetil(Vector2f(posicao.x - 25.f, posicao.y + tam_corpo.y / 2.f));
        if (pProj)
        {
            pProj->setVelocidade(Vector2f(-pProj->getVelocidade().x, 0.f));
        }
        else
        {
            cout << "Erro alocacao de Projetil em Personagem" << endl;
            exit(1);
        }
    }

    pProj->setAtirador(this);
    pProj->setDano(dano);

    //Gerenciador_Colisoes::getGerenciadorColisoes()->addProjetil(static_cast<Entidade*>(pProj));
    addProje(static_cast<Entidade*>(pProj));
}

void Personagem::diminuirVida(int dano)
{
    num_vidas -= dano;
}
