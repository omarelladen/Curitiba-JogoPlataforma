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

    num_vidas = 50;
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
        Jacare* pJac = static_cast<Jacare*>(ent);

        tempo = relogio_gravidade.getElapsedTime();
        if (tempo.asSeconds() >=  pJac->getRapidezMordida())
        {
            diminuirVida(pJac->getForcaMordida());

            relogio_gravidade.restart();
        }
    }
    break;

    case IDs::chefeMafia:
    {
        ChefeMafia* pCM = static_cast<ChefeMafia*>(ent);

        if (pCM->getNivelMedo() >= 5)
        {
            diminuirVida(pCM->getNivelForca());
        }
    }
    break;

    case IDs::chao:
    {
        
    }
    break;

    case IDs::bicicleta:
    {
        // Eh jogado para cima
        Bicicleta* pB = static_cast<Bicicleta*>(ent);
        velocidade.y = (-1.f) * pB->getNivelRicochete();

        // Perde vida
        diminuirVida(pB->getDano());

    }
    break;

    case IDs::projetil:
    {
    }

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
