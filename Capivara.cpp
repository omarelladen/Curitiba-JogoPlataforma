#include "Capivara.h"

Capivara::Capivara(Vector2f pos) :
	Jogador(IDs::capivara, pos),
	forca_cuspe(0),
    golpe_especial(0)
{
    inicializaAtributos();
}

Capivara::~Capivara()
{
}

void Capivara::inicializaAtributos()
{
    time_t t;
    srand((unsigned)time(&t));
    forca_cuspe = rand() % 5 + 1;

    pProje = new Projetil(Vector2f(posicao.x + tam_corpo.x, posicao.y + tam_corpo.y / 2.f), Vector2f(1.f, 0.f));
    if (pProje)
    {
        pProje->setDano(forca_cuspe);
        pProje->setAtirador(this);
    }
    setTamanho(Vector2f(100.f, 75.f));

    num_vidas = 50;
}

void Capivara::AtirarCuspe()
{
    pProje->executar();
}

void Capivara::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::capanga:
    {
        
    }
    break;

    case IDs::jacare:
    {
        
    }
    break;

    case IDs::chefeMafia:
    {
        
    }
    break;

    case IDs::plataforma:
    {
        
    }
    break;

    case IDs::bicicleta:
    {
        
    }
    break;

    case IDs::projetil:
    {
        this->operator--();

    }

    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }
    break;

    default: {
        cout << "Erro Colisao Jogador" << endl;
    }
           break;
    }
}

const int Capivara::getNivelCuspe() const
{
    return forca_cuspe;
}
