#include "Beco.h"
using namespace Fases;

Beco::Beco():
	Fase(IDs::fase_beco)
{
	// Textura Fundo
	if (!textura_fundo.loadFromFile("Fundo/parque-generico.jpg"))
	{
		cout << "Erro ao carregar a textura do fundo" << endl;
		exit(1);
	}
	fundo.setTexture(textura_fundo);
}

Beco::~Beco()
{
}

void Beco::criarMapa()
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

void Beco::criarEntidade(const char simbolo, Vector2f pos)
{

	switch (simbolo)
	{
	case '#':
	{
		Chao* pP = new Chao(Vector2f(pos.x * 50.f, pos.y * 50));
		if (pP)
			listaObstaculos->addEntidade(static_cast<Entidade*>(pP));
		else
		{
			cout << "Entidade nula" << endl;
			exit(1);
		}
	}
	break;

	case 'c':
	{
		Capanga* pC = new Capanga(Vector2f(pos.x * 50.f, pos.y * 50));
		if (pC)
		{
			pC->setAlvo(static_cast<Capivara*>(pJogador));
			listaPersonagens->addEntidade(static_cast<Entidade*>(pC));
		}
		else
		{
			cout << "Entidade nula" << endl;
			exit(1);
		}
	}
	break;

	case 'B':
	{
		ChefeMafia* pCM = new ChefeMafia(Vector2f(pos.x * 50.f, pos.y * 50));
		if (pCM)
		{
			pCM->setAlvo(static_cast<Capivara*>(pJogador));
			listaPersonagens->addEntidade(static_cast<Entidade*>(pCM));
		}
		else
		{
			cout << "Entidade nula" << endl;
			exit(1);
		}
	}
	break;

	case 'l':
	{
		Lixo* pL = new Lixo(Vector2f(pos.x * 50.f, pos.y * 50));
		if (pL)
			listaObstaculos->addEntidade(static_cast<Entidade*>(pL));
		else
		{
			cout << "Entidade nula" << endl;
			exit(1);
		}
	}
	break;


	default:
		break;
	}
}

void Beco::executar()
{
	fundo.setPosition(Vector2f(pJogador->getPosicao().x - 490, 100));
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(fundo);

	gerenciadorColisoes->executar();
}