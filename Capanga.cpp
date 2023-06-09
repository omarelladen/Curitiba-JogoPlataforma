#include"ListaEntidades.h"
#include"Capanga.h"
#include"Capivara.h"

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
    setTextura("Texturas/sprite-capanga-direita.png");

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
        << direita << ' '
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
    bool dir;
    int tiro;
    int estupidez;
    int tempo_congelado;
    bool congelado;

    while (RecuperaSaveCapanga >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >> 
           dir >> tiro >> estupidez >> tempo_congelado >> congelado)
    {
        pCapan = new Capanga(pos);
        if (pCapan)
        {
            pCapan->setNumVidas(vidas);
            pCapan->setVelocidade(vel);
            pCapan->setDireita(dir);
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

void Capanga::mover()
{
    if (!congelado)
    {
        Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
        Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

        float dis_alvo_x = fabs(pos_alvo.x - pos_perseguidor.x);
        float dis_alvo_y = fabs(pos_alvo.y - pos_perseguidor.y);

        if (dis_alvo_y < 50) // tem q ter a memsa altura ou proxima
        {
            if (dis_alvo_x <= raio_ataque)
            {
                perseguirAlvo();

                tempo = relogio_ataque.getElapsedTime();
                if (tempo.asSeconds() >= nivel_estupidez)
                {
                    atirar(nivel_tiro);
                    relogio_ataque.restart();
                }
            }

            if (esta_no_chao)
            {
                tempo = relogio_gravidade.restart();
                velocidade.y = 0.f;
                //formaPadraoMover();
                corpo.move(velocidade);
            }
            posicao = corpo.getPosition();
        }
    }
    else
    {
        tempo = relogio_gravidade.getElapsedTime();
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

    //Arrumar: Chao é varios blocos
    case IDs::chao:
    {
        pos_ini.x = ent->getPosicao().x;
        pos_fin.x = ent->getPosicao().x + ent->getTamanho().x;
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
        cout << "Erro Colisao Capanga" << endl;
    }
           break;
    }
}

void Capanga::executar()
{
    desenhar_se();
    efeitoGravidade();
    mover();


    if (velocidade.x > 0)
        direita = true;
    else if (velocidade.x < 0)
        direita = false;

    // Atualizar textura
    if (direita)
    {
        setTextura("Texturas/sprite-capanga-direita.png");
    }
    else
    {
        setTextura("Texturas/sprite-capanga-esquerda.png");
    }
}
