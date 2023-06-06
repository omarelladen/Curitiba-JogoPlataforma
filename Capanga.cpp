#include"ListaEntidades.h"
#include"Capanga.h"

Capanga::Capanga(Vector2f pos) :
	Inimigo(IDs::capanga, pos),
	nivel_estupidez(0),
    tempo_congelado(0),
    congelado(false),
    nivel_tiro(0)
{
    inicializaAtributos();
}

Capanga::~Capanga()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Capanga::inicializaAtributos()
{
    setTamanho(Vector2f(50.f, 100.f));

    time_t t;
    srand((unsigned)time(&t));

    nivel_estupidez = rand() % 20 + 1;
    tempo_congelado = rand() % 5 + 2;
    nivel_tiro = rand() % 3 + 2;
    num_vidas = rand() % 5 + 8;
}

const int Capanga::getNivelEstupidez() const
{
	return nivel_estupidez;
}

void Capanga::salvar()
{
    ofstream SalvaCapanga("SaveCapanga.dat", ios::out);

    if (!SalvaCapanga)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaCapanga << posicao.x << ' '
        << posicao.y << ' '
        << num_vidas << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << indo << ' '
        << nivel_tiro << ' '
        << nivel_estupidez << ' '
        << tempo_congelado << ' ' 
        << congelado << endl;

    SalvaCapanga.close();
}

ListaEntidades* Capanga::recuperar()
{
    ifstream RecuperaSaveCapanga("SaveCapanga.dat", ios::in);

    if (!RecuperaSaveCapanga)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Capanga* pCapan = nullptr;
    Vector2f pos;
    int vidas;
    Vector2f vel;
    bool indo;
    int tiro;
    int estupidez;
    int tempo_congelado;
    bool congelado;

    while (RecuperaSaveCapanga >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >> 
           indo >> tiro >> estupidez >> tempo_congelado >> congelado)
    {
        pCapan = new Capanga(pos);
        if (pCapan)
        {
            pCapan->setNumVidas(vidas);
            pCapan->setVelocidade(vel);
            pCapan->setIndo(indo);
            pCapan->setNivelTiro(tiro);
            pCapan->setNivelEstupidez(estupidez);
            pCapan->setTempoCongelado(tempo_congelado);
            pCapan->setCongelado(congelado);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pCapan));
        }
    }
    RecuperaSaveCapanga.close();

    return pListaEntidades;
}

void Capanga::setNivelTiro(const int tiro)
{
    nivel_tiro = tiro;
}

const int Capanga::getNivelTiro() const
{
    return nivel_tiro;
}

void Capanga::setNivelEstupidez(const int estupidez)
{
    nivel_estupidez = estupidez;
}

void Capanga::setTempoCongelado(const int tc)
{
    tempo_congelado = tc;
}

const int Capanga::getTempoCongelado() const
{
    return tempo_congelado;
}

void Capanga::setCongelado(const bool conge)
{
    congelado = conge;
}

const bool Capanga::getCongelado() const
{
    return congelado;
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
    else
    {
        tempo = relogio.getElapsedTime();
        if (tempo.asSeconds() >= tempo_congelado)
        {
            setCongelado(false);
        }
    }
}

void Capanga::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
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
