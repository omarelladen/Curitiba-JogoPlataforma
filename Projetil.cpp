#include"ListaEntidades.h"
#include"Personagem.h"
#include"Projetil.h"

Projetil::Projetil(Vector2f pos) :
    Entidade(IDs::projetil, pos),
    dano(0),
    atirador(nullptr)
{
    //Textura

    inicializaAtributos();
}

Projetil::~Projetil()
{
    atirador = nullptr;
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Projetil::inicializaAtributos()
{
    // Cor do tiro
    corpo.setFillColor(sf::Color::Red);//
    setTamanho(Vector2f(20.f, 20.f));//

    time_t t;
    srand((unsigned)time(&t));

    velocidade = Vector2f((rand() % 11 + 10) / 10.f, 0.f);
}

void Projetil::setAtirador(Personagem* atir)
{
    atirador = atir;
}

Personagem* Projetil::getAtirador()
{
    return atirador;
}

void Projetil::setDano(const int d)
{
    dano = d;
}

const int Projetil::getDano() const
{
    return dano;
}

/*void Projetil::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    if (atirador)
    {
        if (posicao.x > atirador->getPosicao().x)
        {
            setPosicao(Vector2f(atirador->getPosicao().x + atirador->getTamanho().x + 5.f,
                atirador->getPosicao().y + atirador->getTamanho().y / 2.f));
        }
        else
        {
            setPosicao(Vector2f(atirador->getPosicao().x - tam_corpo.x - 5.f,
                atirador->getPosicao().y + atirador->getTamanho().y / 2.f));
        }

        //id eh de quem eh atacado
        switch (id)
        {
        case IDs::capivara:
        {
            switch (atirador->getID())
            {
            case IDs::capanga:
            {

            }
            default:
                break;
            } 
        }
        break;

        case IDs::jacare:
        {

        }

        case IDs::capanga:
        {
            if (atirador->getID() == IDs::capivara)
            {
                Capanga* pCapa = static_cast<Capanga*>(ent);
                pCapa->restartRelogio();
                pCapa->setCongelado(true);
            }
        }
        break;

        case IDs::chefeMafia:
        {
            if (atirador->getID() == IDs::capivara)
            {
                ChefeMafia* pCM = static_cast<ChefeMafia*>(ent);
                Capivara* pCapi = static_cast<Capivara*>(atirador);
                pCM->diminuirVida(pCapi->getForcaCuspe());
            }
        }

        case IDs::plataforma:
        {

        }
        break;

        case IDs::canto:
        {

        }
        break;

        default: {
            cout << "Erro Colisao Projetil" << endl;
        }
               break;
        }
    }
    else
    {
        cout << "Erro - Projetil sem atirador" << endl;
    }
}*/

void Projetil::salvar()
{
    ofstream SalvaProjetil("SaveProjetil.dat", ios::out);

    if (!SalvaProjetil)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }
    
    SalvaProjetil << posicao.x << ' '
        << posicao.y << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << dano << endl;

    SalvaProjetil.close();
}

ListaEntidades* Projetil::recuperar()
{
    ifstream RecuperaSaveProjetil("SaveProjetil.dat", ios::in);

    if (!RecuperaSaveProjetil)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Projetil* pProj = nullptr;
    Vector2f pos;
    Vector2f vel;
    int dano;

    //FALTA RECUPERAR A RELACAO COM ATIRADOR
    while (RecuperaSaveProjetil >> pos.x >> pos.y >> vel.x >> vel.y >> dano)
    {
        pProj = new Projetil(pos);
        if (pProj)
        {
            pProj->setVelocidade(vel);
            pProj->setDano(dano);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pProj));
        }
    }
    RecuperaSaveProjetil.close();

    return pListaEntidades;
}

void Projetil::mover()
{
    corpo.move(velocidade);
    posicao = corpo.getPosition();
}

void Projetil::executar()
{
    cout << posicao.x << " / " << posicao.y << endl;
    desenhar_se();
    efeitoGravidade();
    mover();
}