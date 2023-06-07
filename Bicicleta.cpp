#include"ListaEntidades.h"
#include"Bicicleta.h"

Bicicleta::Bicicleta(Vector2f pos) :
	Obstaculo(IDs::bicicleta, pos),
	nivel_ricochete(0),
    dano(0)
{
    inicializaAtributos();
}

Bicicleta::~Bicicleta()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Bicicleta::inicializaAtributos()
{
    setTamanho(Vector2f(60.f, 40.f));

	time_t t;
	srand((unsigned)time(&t));

    dano = rand() % 3 + 5;
	nivel_ricochete = rand() % 101 + 150;
	velocidade = Vector2f((rand() % 5 + 1) / -10.f, 0.f);
}

void Bicicleta::salvar()
{
    ofstream SalvaBicicleta("SaveBicicleta.dat", ios::out);

    if (!SalvaBicicleta)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaBicicleta << posicao.x << ' '
        << posicao.y << ' '
        << velocidade.x << ' '
        << velocidade.y << ' '
        << nivel_ricochete << ' '
        << dano << endl;

    SalvaBicicleta.close();
}

ListaEntidades* Bicicleta::recuperar()
{
    ifstream RecuperaSaveBicicleta("SaveBicicleta.dat", ios::in);

    if (!RecuperaSaveBicicleta)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Bicicleta* pBike = nullptr;
    Vector2f pos;
    Vector2f vel;
    int ricochete;
    int damage;

    while (RecuperaSaveBicicleta >> pos.x >> pos.y >> vel.x >> vel.y >> ricochete >> damage)
    {
        pBike = new Bicicleta(pos);
        if (pBike)
        {
            pBike->setVelocidade(vel);
            pBike->setNivelRicochete(ricochete);
            pBike->setDano(damage);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pBike));
        }
    }
    RecuperaSaveBicicleta.close();

    return pListaEntidades;
}

void Bicicleta::setNivelRicochete(const int ricochete)
{
    nivel_ricochete = ricochete;
}

const int Bicicleta::getNivelRicochete() const
{
    return nivel_ricochete;
}

void Entidades::Obstaculos::Bicicleta::setDano(const int damage)
{
}

const int Entidades::Obstaculos::Bicicleta::getDano() const
{
    return 0;
}

void Bicicleta::mover()
{
	corpo.move(velocidade);
	posicao = corpo.getPosition();
}

void Bicicleta::executar()
{
	desenhar_se();
}