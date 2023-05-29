#include"Inimigo.h"
#include"Plataforma.h"

Inimigo::Inimigo( Vector2f tam_corp, Vector2f pos_i, Vector2f pos_f, Jogador* player) :
    Personagem(IDs::inimigo, tam_corp),
    alvo(player),
    nivel_maldade(0),
    indo(true),
    projs(),
    pos_ini(pos_i),
    pos_fin(pos_f)
{
    velocidade.x = 2.f;
    corpo.setFillColor(Color::Red);
}

Inimigo::~Inimigo()
{
    alvo = NULL;
}

void Inimigo::operator++()
{
    nivel_maldade++;
}

void Inimigo::mover(const char* direcao)
{
    atirar();

    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (fabs(pos_alvo.x - pos_perseguidor.x) < RAIO_PERSEGUICAO_X && nivel_maldade >= 10)
    {
        perseguirAlvo();
    }

    tempo = relogio.restart();
    velocidade.y = 0.f;
    formaPadraoMover();
    corpo.move(velocidade);

    //Efeito Gravidade

    if (velocidade.y <= MAX_VEL)
    {
        tempo = relogio.getElapsedTime();
        velocidade.y += (GRAVIDADE * (tempo.asSeconds() / (float)100.0));
    }
    corpo.move(0.f, velocidade.y);

    posicao = corpo.getPosition();
}

void Inimigo::formaPadraoMover()
{
    if (posicao.x >= pos_ini.x + 1.f
        && (posicao.x + tam_corpo.x) <= pos_fin.x - 1.f)
    {
        if (indo)
        {
            velocidade.x = 0.2f;
        }
        else
        {
            velocidade.x = -0.2f;
        }
    }
    else
    {
        indo = !indo;
        if (posicao.x <= pos_ini.x + 1.f)
        {
            posicao.x = pos_ini.x + 2.f;
            setPosicao(posicao);
        }
        else if ((posicao.x + tam_corpo.x) >= pos_fin.x - 1.f)
        {
            posicao.x = pos_fin.x - tam_corpo.x - 2.f;
            setPosicao(posicao);
        }
    }
}

void Inimigo::perseguirAlvo()
{
    Vector2f pos_alvo = alvo->getPosicao() + alvo->getTamanho() / 2.f;
    Vector2f pos_perseguidor = posicao + tam_corpo / 2.f;

    if (pos_alvo.x > pos_perseguidor.x)
    {
        corpo.move(0.1f, 0.f);
    }
    else
    {
        corpo.move(-0.1f, 0.f);
    }
}

void Inimigo::setProjetil(Projetil* proj)
{
    if (proj)
        projs.push_back(proj);
}

void Inimigo::colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao)
{
    switch (id)
    {
    case IDs::plataforma:
    {
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x
            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;
                //Colisao Esquerda
                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                    esta_no_chao = false;
                }
                //Colisao Direita
                else
                {
                    setPosicao(posicao - distancia_colisao);
                    esta_no_chao = false;
                }
            }
            //Colisao em y
            else
            {
                distancia_colisao.x = 0.f;
                //Colisao Cima
                if (posicao.y < ent->getPosicao().y)
                {
                    setPosicao(posicao + distancia_colisao);
                    esta_no_chao = true;
                }
                //Colisao Baixo
                else
                {
                    setPosicao(posicao - distancia_colisao);
                    esta_no_chao = false;
                }
            }
        }
    }
    break;

    case IDs::jogador:
    {
        if (nivel_maldade >= 10)
        {
            Jogador* pJog = static_cast<Jogador*>(ent);
            pJog->operator--();
        }
        if (distancia_colisao != Vector2f(0.f, 0.f))
        {
            //Colisao em x
            if (distancia_colisao.x > distancia_colisao.y)
            {
                distancia_colisao.y = 0.f;
                //Colisao Esquerda
                if (posicao.x < ent->getPosicao().x)
                {
                    setPosicao(posicao + distancia_colisao);
                }
                //Colisao Direita
                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
            //Colisao em y
            else
            {
                distancia_colisao.x = 0.f;
                //Colisao Cima
                if (posicao.y < ent->getPosicao().y)
                {
                    setPosicao(posicao + distancia_colisao);
                }
                //Colisao Baixo
                else
                {
                    setPosicao(posicao - distancia_colisao);
                }
            }
        }
    }
    break;

    //Cantos
    case IDs::canto:
    {
        setPosicao(posicao - distancia_colisao);
    }
    break;

    default: {
        cout << "Erro Colisao Inimigo" << endl;
    }
           break;
    }
}

void Inimigo::atirar()
{
    list<Projetil*>::iterator it;
    for (it = projs.begin(); it != projs.end(); it++)
    {
        if (*it)
        {
            if ((*it)->getPosicao().x >= pos_ini.x && (*it)->getPosicao().x <= pos_fin.x)
            {
                (*it)->mover();
            }
            else
            {
                (*it)->colisao("Canto", NULL, Vector2f(0.f, 0.f));
            }
        }
    }
}

void Inimigo::executar()
{
    desenhar_se();
    mover("");
}

