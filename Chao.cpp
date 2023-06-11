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
    // if (id barigui)
    setTextura("Texturas/Sprite-chao-parque.png");
    setTamanho(Vector2f(50.f, 50.f));

	time_t t;
	srand((unsigned)time(&t));

    atrito = (double)(rand() % 3 + 1) / (double)10;
}

void Chao::salvar()
{
    ofstream SalvaChao("SaveChao.dat", ios::out);

    if (!SalvaChao)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }
    
    SalvaChao << posicao.x << ' '
        << posicao.y << ' '
        << atrito << endl;

    SalvaChao.close();
}

ListaEntidades* Chao::recuperar()
{
    ifstream RecuperaSaveChao("SaveChao.dat", ios::in);

    if (!RecuperaSaveChao)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        salvo = false;
    }

    if (salvo)
    {
        pListaEntidades = new ListaEntidades();
        Chao* pPlat = nullptr;
        Vector2f pos;
        double atrito;

        while (RecuperaSaveChao >> pos.x >> pos.y >> atrito)
        {
            pPlat = new Chao(pos);
            if (pPlat)
            {
                pPlat->setAtrito(atrito);
                pListaEntidades->addEntidade(static_cast<Entidade*>(pPlat));
            }
        }
    }
    RecuperaSaveChao.close();

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
