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
    setTextura("Texturas/sprite-capivara-direita.png");
    setTamanho(Vector2f(80.f, 70.f));

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
        Capanga* pCap = static_cast<Capanga*>(ent);

        float intervalo_ataque = (float) pCap->getNivelEstupidez();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(1);

            relogio_ataque.restart();
        }


        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            /*Quanto mais estupido mais leva dano quando a capivara pula em cima
            pCap->diminuirVida(pCap->getNivelEstupidez());*/
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::jacare:
    {
        Jacare* pJac = static_cast<Jacare*>(ent);

        float intervalo_ataque = (float) pJac->getRapidezMordida();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(pJac->getForcaMordida());

            relogio_ataque.restart();
        }

        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            //pJac->diminuirVida(1);
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::chefeMafia:
    {
        ChefeMafia* pCM = static_cast<ChefeMafia*>(ent);

        float intervalo_ataque = 100.f / pCM->getNivelMedo();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= intervalo_ataque)
        {
            diminuirVida(pCM->getNivelForca());

            relogio_ataque.restart();
        }

        //Para ricochetear
        //Colisao em x
        if (distancia_colisao.x < distancia_colisao.y)
        {
            //Jogador na Esquerda
            if (ent->getPosicao().x > posicao.x)
            {
                velocidade.x = -2.f;
            }
            else //Jogador na Direita
            {
                velocidade.x = 2.f;
            }
        }
        else //Colisao em y
        {
            /*Quanto maior o nivel medo, menos dano ele recebe quando a capivara pula em cima
            pCM->diminuirVida(20/pCM->getNivelMedo());*/
            velocidade.y = -5.f;
            velocidade.x = 2.f;
        }
    }
    break;

    case IDs::chao:
    {
        //o if de distancia_colisao tá ao contrario pq umas das distancia_colisao é zerada no gerenciador de colisoes, asssim mudando quem é maior
        //Colisao Cima 
        if (ent->getPosicao().y >= posicao.y + tam_corpo.y && distancia_colisao.x > distancia_colisao.y) 
        {
            setEstaNoChao(true);

            //Forca de atrito
            Chao* pChao = static_cast<Chao*>(ent);
            if (velocidade.x > 0.f)
            {
                velocidade.x -= (float) pChao->getAtrito() / 20.f;
            }
            else if (velocidade.x < 0.f)
            {
                velocidade.x += (float) pChao->getAtrito() / 20.f;
            }
        }
        else
        {
            setEstaNoChao(false);
        }
    }
    break;

    case IDs::bicicleta:
    {
        // Eh jogado para cima
        Bicicleta* pB = static_cast<Bicicleta*>(ent);
        velocidade.y = (-0.02f) * pB->getNivelRicochete();

        // Perde vida
        diminuirVida(pB->getDano());

    }
    break;

    case IDs::projetil:
    {
        cout << " Capivara Colisao com Projetil" << endl;
    }

    default: {
        //cout << "Erro Colisao Jogador" << endl;
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
