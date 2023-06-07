#include"ListaEntidades.h"
#include"ChefeMafia.h"

ChefeMafia::ChefeMafia(Vector2f pos) :
	Inimigo(IDs::chefeMafia, pos),
	nivel_forca(0),
	nivel_medo(0),
    vidas_regeneradas(0)
{
    inicializaAtributos();
}

ChefeMafia::~ChefeMafia()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
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

void ChefeMafia::setNivelForca(const int forca)
{
    nivel_forca = forca;
}

const int ChefeMafia::getNivelForca() const
{
	return nivel_forca;
}

void ChefeMafia::setNivelMedo(const int medo)
{
    nivel_medo = medo;
}

const int ChefeMafia::getNivelMedo() const
{
	return nivel_medo;
}

void ChefeMafia::setVidasRegeneradas(const int vidas)
{
    vidas_regeneradas = vidas;
}

void ChefeMafia::regeneraVida()
{
    int tempo = (int) relogio.getElapsedTime().asSeconds();
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

void ChefeMafia::salvar()
{
    ofstream SalvaChefeMafia("SaveChefeMafia.dat", ios::out);

    if (!SalvaChefeMafia)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaChefeMafia << posicao.x << ' '
        << posicao.y << ' '
        << num_vidas << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << indo << ' '
        << nivel_forca << ' '
        << nivel_medo << ' '
        << vidas_regeneradas << endl;

    SalvaChefeMafia.close();
}

ListaEntidades* ChefeMafia::recuperar()
{
    ifstream RecuperaSaveChefeMafia("SaveChefeMafia.dat", ios::in);

    if (!RecuperaSaveChefeMafia)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    ChefeMafia* pCM = nullptr;
    Vector2f pos;
    int vidas;
    Vector2f vel;
    bool indo;
    int forca; //força
    int medo;
    int vidas_rege;

    while (RecuperaSaveChefeMafia >> pos.x >> pos.y >> vidas >> vel.x >> vel.y >>
        indo >> forca >> medo >> vidas_rege)
    {
        pCM = new ChefeMafia(pos);
        if (pCM)
        {
            pCM->setNumVidas(vidas);
            pCM->setVelocidade(vel);
            pCM->setIndo(indo);
            pCM->setNivelForca(forca);
            pCM->setNivelMedo(medo);
            pCM->setVidasRegeneradas(vidas_rege);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pCM));
        }
    }
    RecuperaSaveChefeMafia.close();

    return pListaEntidades;
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
    posicao = corpo.getPosition();
}

void ChefeMafia::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::chao:
    {
        
    }
    break;

    case IDs::capivara:
    {
        if (nivel_medo >= 5)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->diminuirVida(nivel_forca);
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
