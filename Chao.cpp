#include"ListaEntidades.h"
#include"Chao.h"
using namespace Obstaculos;

Chao::Chao(Vector2f pos) :
	Obstaculo(IDs::chao, pos),
	atrito(0.0)
{
    inicializaAtributos();
}

Chao::~Chao()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Chao::inicializaAtributos()
{
    if (!textura.loadFromFile("Texturas/Sprite-chao-parque.png"))
        cout << "Erro ao carregar a textura";
    else
        corpo.setTexture(&textura);

    setTamanho(Vector2f(50.f, 50.f));

	time_t t;
	srand((unsigned)time(&t));

	atrito = (double) (rand() % 9 + 1) / (double) 10;
}

void Chao::salvar()
{
    ofstream SalvaPlataforma("SavePlataforma.dat", ios::out);

    if (!SalvaPlataforma)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }
    
    SalvaPlataforma << posicao.x << ' '
        << posicao.y << ' '
        << atrito << endl;

    SalvaPlataforma.close();
}

ListaEntidades* Chao::recuperar()
{
    ifstream RecuperaSavePlataforma("SavePlataforma.dat", ios::in);

    if (!RecuperaSavePlataforma)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    pListaEntidades = new ListaEntidades();
    Chao* pPlat = nullptr;
    Vector2f pos;
    double atrito;

    while (RecuperaSavePlataforma >> pos.x >> pos.y >> atrito)
    {
        pPlat = new Chao(pos);
        if (pPlat)
        {
            pPlat->setAtrito(atrito);
            pListaEntidades->addEntidade(static_cast<Entidade*>(pPlat));
        }
    }
    RecuperaSavePlataforma.close();

    return pListaEntidades;
}

void Chao::setAtrito(const double atri)
{
    atrito = atri;
}

const double Chao::getAtrito() const
{
	return atrito;
}

void Chao::executar()
{
	desenhar_se();
}
