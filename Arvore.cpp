#include"ListaEntidades.h"
#include "Arvore.h"

Arvore::Arvore(Vector2f pos) :
    Obstaculo(IDs::arvore, pos),
    altura(0),
    tronco(),
    textura_tronco()
{
    inicializaAtributos();
}

Arvore::~Arvore()
{
    delete pListaEntidades;
    pListaEntidades = nullptr;
}

void Arvore::inicializaAtributos()
{
    setTextura("Texturas/Sprite-topo-arvore.png");
    setTamanho(Vector2f(50.f, 50.f));

    if (!textura_tronco.loadFromFile("Texturas/Sprite-tronco-arvore.png"))
    {
        cout << "Erro ao carregar a textura" << endl;
        exit(1);
    }
    else
        tronco.setTexture(&textura_tronco);

    time_t t;
    srand((unsigned)time(&t));

    altura = rand() % 21 + 130;
    tronco.setSize(Vector2f(40.f, posicao.y));
    tronco.setPosition(posicao + Vector2f(5.f, 25.f));
    //tronco.setScale(5.f, 5.f);
    
}

void Arvore::salvar()
{
    ofstream SalvaArvore("SaveArvore.dat", ios::out);

    if (!SalvaArvore)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }

    SalvaArvore << posicao.x << ' '
        << posicao.y << ' '
        << tam_corpo.x << ' '
        << tam_corpo.y << ' '
        << altura << endl;

    SalvaArvore.close();
}

ListaEntidades* Arvore::recuperar()
{
    ifstream RecuperaSaveArvore("SaveArvore.dat", ios::in);

    if (!RecuperaSaveArvore)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        salvo = false;
    }

    if (salvo)
    {
        pListaEntidades = new ListaEntidades();
        Arvore* pArv = nullptr;
        Vector2f pos;
        Vector2f tam;
        int alt;

        while (RecuperaSaveArvore >> pos.x >> pos.y >> tam.x >> tam.y >> alt)
        {
            pArv = new Arvore(pos);
            if (pArv)
            {
                pArv->setTamanho(tam);
                pArv->setAltura(alt);
                //pArv->getTronco().setSize(Vector2f((float)alt, 30.f));
                pListaEntidades->addEntidade(static_cast<Entidade*>(pArv));
            }
        }
    }
    RecuperaSaveArvore.close();
    
    return pListaEntidades;
}

void Arvore::setAltura(const int alt)
{
    altura = alt;
}

const int Arvore::getAltura() const
{
    return altura;
}


void Arvore::executar()
{
    Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(tronco);
    desenhar_se();
}
