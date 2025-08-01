#include"ListaEntidades.h"
#include"ChefeMafia.h"
#include"Capivara.h"

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
}

void ChefeMafia::inicializaAtributos()
{
    setTextura("Texturas/Sprite-chefe-esquerda.png");
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

const int ChefeMafia::getVidasRegeneradas() const
{
    return vidas_regeneradas;
}

void ChefeMafia::regeneraVida()
{
    int tempo = (int) relogio_gravidade.getElapsedTime().asSeconds();
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

void ChefeMafia::mover()
{
    //atirar();

    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    float dis_alvo_x = fabs(pos_alvo.x - pos_perseguidor.x);
    float dis_alvo_y = fabs(pos_alvo.y - pos_perseguidor.y);

    if (dis_alvo_y <= 50 && dis_alvo_x <= raio_ataque) //Perseguir se tem que ter a memsa altura ou proxima e esta dentro do raio
    {
        perseguirAlvo();

        tempo = relogio_ataque.getElapsedTime();
        if (tempo.asSeconds() >= 1)//>= nivel_estupidez)
        {
            //cout << "Capanga atira" << endl;
            atirar(nivel_forca);
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
        //formaPadraoMover();
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
        //o if de distancia_colisao t� ao contrario pq umas das distancia_colisao � zerada no gerenciador de colisoes, asssim mudando quem � maior
        //Colisao Cima 
        if (ent->getPosicao().y >= posicao.y + tam_corpo.y && distancia_colisao.x > distancia_colisao.y)
        {
            setEstaNoChao(true);

            //Forca de atrito
            Chao* pChao = static_cast<Chao*>(ent);
            if (velocidade.x > 0.f)
            {
                velocidade.x -= (float) pChao->getAtrito() / 100.f;
            }
            else if (velocidade.x < 0.f)
            {
                velocidade.x += (float) pChao->getAtrito() / 100.f;
            }
        }
        else
        {
            setEstaNoChao(false);
        }
    }
    break;

    case IDs::capivara:
    {
        /*if (nivel_medo >= 5)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->diminuirVida(nivel_forca);
        }*/
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

    case IDs::bicicleta:
    {
        // Eh jogado para cima
        Bicicleta* pB = static_cast<Bicicleta*>(ent);
        velocidade.y = (-0.02f) * pB->getNivelRicochete();
    }
    break;


    default: {
        //cout << "Erro Colisao ChefeMafia" << endl;
    }
           break;
    }
}

void ChefeMafia::executar()
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
    else if (velocidade.x < 0)
        direita = false;

    // Atualizar textura
    if (direita)
    {
        setTextura("Texturas/sprite-chefe-direita.png");
    }
    else
    {
        setTextura("Texturas/sprite-chefe-esquerda.png");
    }
}
