#include "ChefeMafia.h"

#define NUM_MAX_VIDAS 70

ChefeMafia::ChefeMafia(Vector2f pos, Capivara* pJ) :
	Inimigo(IDs::chefeMafia, pos, pJ),
	nivel_forca(0),
	nivel_medo(0),
    vidas_regeneradas(0)
{
}

ChefeMafia::~ChefeMafia()
{
}

void ChefeMafia::inicializaAtributos()
{
    setTamanho(Vector2f(75.f, 120.f));

    time_t t;
    srand((unsigned)time(&t));

    nivel_forca = rand() % 6 + 10;
    nivel_medo = rand() % 21;
    vidas_regeneradas = rand() % 5 + 1;

    num_vidas = NUM_MAX_VIDAS;
}

const int ChefeMafia::getNivelForca() const
{
	return nivel_forca;
}

const int ChefeMafia::getNivelMedo() const
{
	return nivel_medo;
}

void ChefeMafia::regeneraVida()
{
    int tempo = relogio.getElapsedTime().asSeconds();
    if (tempo % 10 == 0)
    {
        if ((num_vidas + vidas_regeneradas) < NUM_MAX_VIDAS)
        {
            num_vidas += vidas_regeneradas;
        }
        else
        {
            num_vidas = NUM_MAX_VIDAS;
        }
    }
}

void ChefeMafia::mover(const char* direcao)
{
    //atirar();

    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (fabs(pos_alvo.x - pos_perseguidor.x) < RAIO_PERSEGUICAO_X && nivel_medo >= 10)
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

void ChefeMafia::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::plataforma:
    {
        
    }
    break;

    case IDs::capivara:
    {
        if (nivel_medo >= 10)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->operator--();
        }
    }
    break;

    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }

    default: {
        cout << "Erro Colisao ChefeMafia" << endl;
    }
           break;
    }
}
