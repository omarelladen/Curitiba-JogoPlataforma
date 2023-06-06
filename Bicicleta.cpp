#include"ListaEntidades.h"
#include"Bicicleta.h"

Bicicleta::Bicicleta(Vector2f pos) :
	Obstaculo(IDs::bicicleta, pos),
	nivel_ricochete(0),
	velocidade()
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
        << nivel_ricochete << endl;

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

    while (RecuperaSaveBicicleta >> pos.x >> pos.y >> vel.x >> vel.y >> ricochete)
    {
        pBike = new Bicicleta(pos);
        if (pBike)
        {
            pBike->setVelocidade(vel);
            pBike->setNivelRicochete(ricochete);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pBike));
        }
    }
    RecuperaSaveBicicleta.close();

    return pListaEntidades;
}

void Bicicleta::setVelocidade(Vector2f vel)
{
    velocidade = vel;
}

const Vector2f Bicicleta::getVelocidade() const
{
    return velocidade;
}

void Bicicleta::setNivelRicochete(const int ricochete)
{
    nivel_ricochete = ricochete;
}

const int Bicicleta::getNivelRicochete() const
{
    return nivel_ricochete;
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