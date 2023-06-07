#include"ListaEntidades.h"
#include"Jacare.h"
#include"Capivara.h"

Jacare::Jacare(Vector2f pos):
	Inimigo(IDs::jacare, pos),
	forca_mordida(0),
    raio_super_pulo(0),
    rapidez_mordida(0)
{
    inicializaAtributos();
}

Jacare::~Jacare()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Jacare::inicializaAtributos()
{
    setTamanho(Vector2f(100.f, 50.f));

    time_t t;
    srand((unsigned)time(&t));

    forca_mordida = rand() % 3 + 5;
    raio_super_pulo = rand() % 101 + 100;
    num_vidas = rand() % 6 + 15;
    rapidez_mordida = rand() % 4 + 3;
}

void Jacare::setForcaMordida(const int mordida)
{
    forca_mordida = mordida;
}

const int Jacare::getForcaMordida() const
{
	return forca_mordida;
}

void Jacare::setRaioSuperPulo(const int raio_pulo)
{
    raio_super_pulo = raio_pulo;
}

const int Jacare::getRaioSuperPulo()
{
    return raio_super_pulo;
}

void Jacare::setRapidezMordida(const int tempo)
{
    rapidez_mordida = tempo;
}

const int Jacare::getRapidezMordida()
{
    return rapidez_mordida;
}

void Jacare::salvar()
{
    ofstream SalvaJacare("SaveJacare.dat", ios::out);

    if (!SalvaJacare)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaJacare << posicao.x << ' '
        << posicao.y << ' '
        << num_vidas << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << direita << ' '
        << forca_mordida << ' '
        << raio_super_pulo << endl;

    SalvaJacare.close();
}

ListaEntidades* Jacare::recuperar()
{
    ifstream RecuperaSaveJacare("SaveJacare.dat", ios::in);

    if (!RecuperaSaveJacare)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Jacare* pJac = nullptr;
    Vector2f pos;
    int vidas;
    Vector2f vel;
    bool dir;
    int mordida;
    int raio_pulo;

    while (RecuperaSaveJacare >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >>
        dir >> mordida >> raio_pulo)
    {
        pJac = new Jacare(pos);
        if (pJac)
        {
            pJac->setNumVidas(vidas);
            pJac->setVelocidade(vel);
            pJac->setDireita(dir);
            pJac->setForcaMordida(mordida);
            pJac->setRaioSuperPulo(raio_pulo);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pJac));
        }
    }
    RecuperaSaveJacare.close();

    return pListaEntidades;
}

void Jacare::mover()
{
    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (fabs(pos_alvo.x - pos_perseguidor.x) < raio_ataque)
    {
        perseguirAlvo();

        if (fabs(pos_alvo.x - pos_perseguidor.x) < raio_super_pulo)
        {
            if (pos_alvo.x > pos_perseguidor.x)
            {
                tempo = relogio_ataque.getElapsedTime();
                if (tempo.asSeconds() >= 5.f)
                {
                    velocidade.x = 3.f;
                    velocidade.y = 0.1f;
                    relogio_ataque.restart();
                }
            }
        }
    }

    if (esta_no_chao)
    {
        tempo = relogio_gravidade.restart();
        velocidade.y = 0.f;
        formaPadraoMover();
        corpo.move(velocidade);
    }
    posicao = corpo.getPosition();
}

void Jacare::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::chao:
    {
        pos_ini.x = ent->getPosicao().x;
        pos_fin.x = ent->getPosicao().x + ent->getTamanho().x;
    }
    break;

    case IDs::capivara:
    {
        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= rapidez_mordida)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->diminuirVida(forca_mordida);

            relogio_ataque.restart();
        }
    }
    break;

    case IDs::projetil:
    {
        Projetil* pProj = static_cast<Projetil*>(ent);
        if (pProj)
        {
            if (pProj->getAtirador()->getID() == IDs::capivara)
            {
                diminuirVida(pProj->getDano());
            }
        }
    }
    break;

    default: {
        cout << "Erro Colisao Jacare" << endl;
    }
           break;
    }
}

void Jacare::executar()
{
    desenhar_se();
    efeitoGravidade();
    mover();
}
