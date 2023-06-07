#include"ListaEntidades.h"
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
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Capivara::inicializaAtributos()
{
    setTamanho(Vector2f(100.f, 75.f));

    time_t t;
    srand((unsigned)time(&t));
    forca_cuspe = rand() % 5 + 1;

    projetil = new Projetil(Vector2f(posicao.x + tam_corpo.x, posicao.y + tam_corpo.y / 2.f));
    if (projetil)
    {
        projetil->setDano(forca_cuspe);
        projetil->setAtirador(this);
    }

    num_vidas = 50;
}

void Capivara::AtirarCuspe()
{
    projetil->executar();
}

void Capivara::salvar()
{
    ofstream SalvaCapivara("SaveCapivara.dat", ios::out);

    if (!SalvaCapivara)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaCapivara << posicao.x << ' '
        << posicao.y << ' '
        << num_vidas << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << pontos << ' '
        << forca_cuspe << ' '
        << golpe_especial << endl;

    SalvaCapivara.close();
}

ListaEntidades* Capivara::recuperar()
{
    ifstream RecuperaSaveJacare("SaveJacare.dat", ios::in);

    if (!RecuperaSaveJacare)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Capivara* pCapi = nullptr;
    Vector2f pos;
    int vidas;
    Vector2f vel;
    int pontos;
    int cuspe;
    int especial;

    while (RecuperaSaveJacare >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >> pontos >> cuspe >> especial)
    {
        pCapi = new Capivara(pos);
        if (pCapi)
        {
            pCapi->setNumVidas(vidas);
            pCapi->setVelocidade(vel);
            pCapi->setPontos(pontos);
            pCapi->setForcaCuspe(cuspe);
            pCapi->setGolpeEspecial(especial);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pCapi));
        }
    }
    RecuperaSaveJacare.close();

    return pListaEntidades;
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

    case IDs::chao:
    {
        
    }
    break;

    case IDs::bicicleta:
    {
        
    }
    break;

    case IDs::projetil:
    {
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

void Capivara::setForcaCuspe(const int cuspe)
{
    forca_cuspe = cuspe;
}

const int Capivara::getForcaCuspe() const
{
    return forca_cuspe;
}

void Capivara::setGolpeEspecial(const int especial)
{
    golpe_especial = especial;
}

const int Capivara::getGolpeEspecial() const
{
    return golpe_especial;
}
