#include"FaseParqueBarigui.h"
using namespace Fases;

FaseParqueBarigui::FaseParqueBarigui() :
	Fase(IDs::fase_barigui)
{
	// Textura Fundo
	if (!textura_fundo.loadFromFile("Fundo/parque.jpg"))
	{
		cout << "Erro ao carregar a textura do fundo" << endl;
		exit(1);
	}
	fundo.setTexture(textura_fundo);
	fundo.setScale(Vector2f(1.6f, 1.5f));///
}

FaseParqueBarigui::~FaseParqueBarigui()
{
}

void FaseParqueBarigui::criarMapa()
{
	ifstream arquivo;
	string linha;

	arquivo.open("Mapas/MapaParqueBarigui.txt");

	
	if (!arquivo.is_open())
	{
		cout << "Erro ao abrir arquivo mapa" << endl;
		exit(1);
	}
	for (int j = 0; getline(arquivo, linha); j++)
		for (int i = 0; i < (int)linha.size(); i++)
			if (linha[i] != ' ')
				criarEntidade(linha[i], Vector2f((float)i, (float)j)); // criarEntidade da classe Fase
}

void FaseParqueBarigui::criarEntidade(const char simbolo, Vector2f pos)
{

	switch (simbolo)
	{
	case '#':
	{
		Chao* pP = new Chao(Vector2f(pos.x * 50.f, pos.y * 50));
		if (pP)
		{
			listaObstaculos->addEntidade(static_cast<Entidade*>(pP));
		}
		else
		{
			cout << "Entidade nula" << endl;
			exit(1);
		}
	}
	break;

	case 'j':
	{
		if (contador_inimigos < num_inimigos)
		{
			Jacare* pJ = new Jacare(Vector2f(pos.x * 50.f, pos.y * 50));
			if (pJ)
			{
				pJ->setAlvo(static_cast<Capivara*>(pJogador));
				listaPersonagens->addEntidade(static_cast<Entidade*>(pJ));
				contador_inimigos++;
			}
			else
			{
				cout << "Entidade nula" << endl;
				exit(1);
			}
		}
	}
	break;

	case 'b':
	{
		if (contador_obstaculos < num_obstaculos)
		{
			Bicicleta* pB = new Bicicleta(Vector2f(pos.x * 50.f, pos.y * 50));
			if (pB)
			{
				listaObstaculos->addEntidade(static_cast<Entidade*>(pB));
				contador_obstaculos++;
			}
			else
			{
				cout << "Entidade nula" << endl;
				exit(1);
			}
		}
	}
	break;

	case 'c':
	{
		if (contador_inimigos < num_inimigos)
		{
			Capanga* pC = new Capanga(Vector2f(pos.x * 50.f, pos.y * 50));
			if (pC)
			{
				pC->setAlvo(static_cast<Capivara*>(pJogador));
				listaPersonagens->addEntidade(static_cast<Entidade*>(pC));
				contador_inimigos++;
			}
			else
			{
				cout << "Entidade nula" << endl;
				exit(1);
			}
		}
	}
	break;

	case 'a':
	{
		if (contador_obstaculos < num_obstaculos)
		{
			Arvore* pA = new Arvore(Vector2f(pos.x * 50.f, pos.y * 50));
			if (pA)
			{
				listaObstaculos->addEntidade(static_cast<Entidade*>(pA));
				contador_obstaculos++;
			}
			else
			{
				cout << "Entidade nula" << endl;
				exit(1);
			}
		}
	}
	break;

	default:
		break;
	}
}

void FaseParqueBarigui::executar()
{
	fundo.setPosition(Vector2f(pJogador->getPosicao().x - 490, 100));
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(fundo);

	if(gerenciadorColisoes)
		gerenciadorColisoes->executar();
}