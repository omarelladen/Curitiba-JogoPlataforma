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
}

void Capanga::inicializaAtributos()
{
    setTextura("Texturas/sprite-capanga-direita.png");
    setTamanho(Vector2f(50.f, 100.f));

    time_t t;
    srand((unsigned)time(&t));

    nivel_estupidez = rand() % 15 + 1;//
    tempo_congelado = rand() % 5 + 10;
    nivel_tiro = rand() % 3 + 2;
    num_vidas = rand() % 5 + 15;
}

const int Capanga::getNivelEstupidez() const
{
	return nivel_estupidez;
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

        if (dis_alvo_y <= 50 && dis_alvo_x <= raio_ataque) //Perseguir se tem que ter a memsa altura ou proxima e esta dentro do raio
        {
            perseguirAlvo();

            tempo = relogio_ataque.getElapsedTime();
            if (tempo.asSeconds() >= 1)
            {
                atirar(nivel_tiro);
                relogio_ataque.restart();
            }
        }
        else
        {
            velocidade.x = 0.f;
        }

        if (esta_no_chao)
        {
            tempo = relogio_gravidade.restart();
            velocidade.y = 0.f;
            corpo.move(velocidade);
        }
        posicao = corpo.getPosition();
    }
    else
    {
        velocidade.x = 0.f;
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

    case IDs::capivara:
    {

    }

    case IDs::chao:
    {
        //o if de distancia_colisao t� ao contrario pq umas das distancia_colisao � zerada no gerenciador de colisoes, asssim mudando quem � maior
        //Colisao Cima 
        if (ent->getPosicao().y >= posicao.y + tam_corpo.y && distancia_colisao.x > distancia_colisao.y)
        {
            setEstaNoChao(true);

            //Forca de atrito
            Chao* pChao = static_cast<Chao*>(ent);
            if (velocidade.x > 0.f)
            {
                velocidade.x -= (float)pChao->getAtrito() / 100.f;
            }
            else if (velocidade.x < 0.f)
            {
                velocidade.x += (float)pChao->getAtrito() / 100.f;
            }
        }
        else
        {
            setEstaNoChao(false);
        }
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
                setCongelado(true);
            }
        }
    }
    break;

    case IDs::jacare:
    {

    }
    break;

    case IDs::chefeMafia:
    {

    }
    break;

    case IDs::bicicleta:
    {
        // Eh jogado para cima
        Bicicleta* pB = static_cast<Bicicleta*>(ent);
        velocidade.y = (-0.02f) * pB->getNivelRicochete();
    }
    break;

    default: {
        //cout << "Erro Colisao Capanga" << endl;
    }
           break;
    }
}

void Capanga::executar()
{
    if (listaProjeteis)
    {
        listaProjeteis->executar();
    }


    imprimirBarraVidas();

    desenhar_se();
    efeitoGravidade();
    mover();


    if (velocidade.x > 0)
        direita = true;
    else if (velocidade.x <= 0)
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
