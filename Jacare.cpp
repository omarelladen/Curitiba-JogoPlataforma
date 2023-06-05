#include "Jacare.h"
#include"Projetil.h"

Jacare::Jacare(Vector2f pos, Capivara* pJ):
	Inimigo(IDs::jacare, pos, pJ, Vector2f(0.f, 0.f), Vector2f(Ente::getManager()->getJanela()->getSize().x, 0.f)),
	nivel_mordida(0),
    raio_super_pulo(0)
{
    //Esquerda
    Projetil* pProj = new Projetil(Vector2f(pos.x - 7.f, pos.y + tam_corpo.y / 2.f), Vector2f(-1.f, 0.f));
    if (pProj)
    {
        pProj->setAtirador(this);
        pProj->setTamanho(Vector2f(5.f, 5.f));
        projs.push_back(pProj);
    }
    else
    {
        cout << "Erro de alocacao de Projetil em Jacare" << endl;
    }
    pProj = nullptr;

    pProj = new Projetil(Vector2f(pos.x + tam_corpo.x + 2.f, pos.y + tam_corpo.y / 2.f), Vector2f(1.f, 0.f));
    if (pProj)
    {
        pProj->setAtirador(this);
        pProj->setTamanho(Vector2f(5.f, 5.f));
        projs.push_back(pProj);
    }
    else
    {
        cout << "Erro de alocacao de Projetil em Jacare" << endl;
    }
    inicializaAtributos();
}

Jacare::~Jacare()
{
}

void Jacare::inicializaAtributos()
{
    setTamanho(Vector2f(100.f, 50.f));

    time_t t;
    srand((unsigned)time(&t));

    nivel_mordida = rand() % 3 + 5;
    raio_super_pulo = rand() % 101 + 100;
    num_vidas = rand() % 6 + 15;
}

const int Jacare::getNivelMordida() const
{
	return nivel_mordida;
}

void Jacare::mover(const char* direcao)
{
    atirar();

    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (fabs(pos_alvo.x - pos_perseguidor.x) < RAIO_PERSEGUICAO_X && nivel_mordida >= 10)
    {
        perseguirAlvo();
    }

    if (esta_no_chao)
    {
        tempo = relogio.restart();
        velocidade.y = 0.f;
        formaPadraoMover();
        corpo.move(velocidade);
    }
    else
    {
        //Efeito Gravidade

        if (velocidade.y <= MAX_VEL)
        {
            tempo = relogio.getElapsedTime();
            velocidade.y += (GRAVIDADE * (tempo.asSeconds() / (float)100.0));
        }
        corpo.move(0.f, velocidade.y);
    }
    posicao = corpo.getPosition();
}

void Jacare::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::plataforma:
    {
        pos_ini.x = ent->getPosicao().x;
        pos_fin.x = ent->getPosicao().x + ent->getTamanho().x;
    }
    break;

    case IDs::capivara:
    {
        if (nivel_mordida >= 10)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->operator--();
        }
    }
    break;

    case IDs::projetil:
    {
        
    }

    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }

    default: {
        cout << "Erro Colisao Jacare" << endl;
    }
           break;
    }
}
