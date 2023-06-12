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
