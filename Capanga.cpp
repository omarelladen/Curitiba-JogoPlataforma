#include "Capanga.h"

Capanga::Capanga(Vector2f pos, Capivara* pJ) :
	Inimigo(IDs::capanga, pos, pJ),
	nivel_estupidez(0),
    tempo_congelado(0),
    congelado(false),
    nivel_tiro(0)
{
}

Capanga::~Capanga()
{
}

void Capanga::inicializaAtributos()
{
    time_t t;
    srand((unsigned)time(&t));

    nivel_estupidez = rand() % 20 + 1;
    tempo_congelado = rand() % 5 + 2;
    nivel_tiro = rand() % 3 + 2;

    setTamanho(Vector2f(50.f, 100.f));

    num_vidas = rand() % 5 + 8;
}

const int Capanga::getNivelEstupidez() const
{
	return nivel_estupidez;
}

void Capanga::mover(const char* direcao)
{
    if (!congelado)
    {
        //atirar();

        Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
        Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

        if (fabs(pos_alvo.x - pos_perseguidor.x) < RAIO_PERSEGUICAO_X && nivel_tiro >= 10)
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
}

void Capanga::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::plataforma:
    {
        
    }
    break;

    case IDs::capivara:
    {
        if (nivel_tiro >= 10)
        {
            Capivara* pJog = static_cast<Capivara*>(ent);
            pJog->operator--();
        }
    }
    break;

    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }

    default: {
        cout << "Erro Colisao Capanga" << endl;
    }
           break;
    }
}
