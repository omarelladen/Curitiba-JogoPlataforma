#include"ListaEntidades.h"
#include"Jacare.h"

Jacare::Jacare(Vector2f pos):
	Inimigo(IDs::jacare, pos, Vector2f(0.f, 0.f), Vector2f((float) Ente::getManager()->getJanela()->getSize().x, 0.f)),
	nivel_mordida(0),
    raio_super_pulo(0)
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

    //Esquerda
    projetil = new Projetil(Vector2f(posicao.x - 7.f, posicao.y + tam_corpo.y / 2.f));
    if (projetil)
    {
        projetil->setAtirador(this);
        projetil->setTamanho(Vector2f(5.f, 5.f));
    }
    else
    {
        cout << "Erro de alocacao de Projetil em Jacare" << endl;
    }

    time_t t;
    srand((unsigned)time(&t));

    nivel_mordida = rand() % 3 + 5;
    raio_super_pulo = rand() % 101 + 100;
    num_vidas = rand() % 6 + 15;
}

void Jacare::setNivelMordida(const int mordida)
{
    nivel_mordida = mordida;
}

const int Jacare::getNivelMordida() const
{
	return nivel_mordida;
}

void Jacare::setRaioSuperPulo(const int raio_pulo)
{
    raio_super_pulo = raio_pulo;
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
        << indo << ' '
        << nivel_mordida << ' '
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
    bool indo;
    int mordida;
    int raio_pulo;

    while (RecuperaSaveJacare >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >>
        indo >> mordida >> raio_pulo)
    {
        pJac = new Jacare(pos);
        if (pJac)
        {
            pJac->setNumVidas(vidas);
            pJac->setVelocidade(vel);
            pJac->setIndo(indo);
            pJac->setNivelMordida(mordida);
            pJac->setRaioSuperPulo(raio_pulo);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pJac));
        }
    }
    RecuperaSaveJacare.close();

    return pListaEntidades;
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
