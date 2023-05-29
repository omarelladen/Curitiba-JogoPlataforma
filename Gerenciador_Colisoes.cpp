#include "Gerenciador_Colisoes.h"
using namespace Gerenciadores;
#include<math.h>

Gerenciador_Colisoes::Gerenciador_Colisoes() :
	listaObstaculos(NULL),
	listaPersonagens(NULL)
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	listaObstaculos = NULL;
	listaPersonagens = NULL;
}

void Gerenciador_Colisoes::setListaPersonagens(ListaEntidades* listPers)
{
	listaPersonagens = listPers;
}

void Gerenciador_Colisoes::setListaObstaculos(ListaEntidades* listObsts)
{
	listaObstaculos = listObsts;
}

void Gerenciador_Colisoes::GerenciarColisoes()
{
	Entidade* pEnt1 = NULL;
	Entidade* pEnt2 = NULL;

	if (listaPersonagens && listaObstaculos)
	{
		//Calcula colisao Personagem e Obstaculos

		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			pEnt1 = listaPersonagens->getEntidade(i);
			for (int j = 0; j < listaObstaculos->getTamLista(); j++)
			{
				pEnt2 = listaObstaculos->getEntidade(j);

				CalculaColisao(pEnt1, pEnt2);
			}
		}

		//Calcula colisao Personagem e Personagens
		
		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			pEnt1 = listaPersonagens->getEntidade(i);
			for (int j = 0; j < listaObstaculos->getTamLista(); j++)
			{
				pEnt2 = listaPersonagens->getEntidade(i);

				CalculaColisao(pEnt1, pEnt2);
			}
		}
	}
	else
	{
		cout << "ListaEntidades nula em Gerenciador_colisoes" << endl;
	}
}

void Gerenciador_Colisoes::CalculaColisao(Entidade* ent1, Entidade* ent2)
{
	//Calcula colis?o usando os centros das entidades

	Vector2f tam_ent1 = ent1->getTamanho();
	Vector2f tam_ent2 = ent2->getTamanho();

	Vector2f pos_ent1 = ent1->getPosicao();
	Vector2f pos_ent2 = ent2->getPosicao();

	Vector2f distancia_entre_centros(fabs((pos_ent1.x + tam_ent1.x / 2.0f) - (pos_ent2.x + tam_ent2.x / 2.0f)),
		fabs((pos_ent1.y + tam_ent1.y / 2.0f) - (pos_ent2.y + tam_ent2.y / 2.0f)));

	Vector2f menor_distancia_colisao(tam_ent1.x / 2.0f + tam_ent2.x / 2.0f,
		tam_ent1.y / 2.0f + tam_ent2.y / 2.0f);

	Vector2f distancia_colisao = Vector2f(distancia_entre_centros.x - menor_distancia_colisao.x,
		distancia_entre_centros.y - menor_distancia_colisao.y);

	/*if ((ent1->getID() == "Projetil"))
	{
		cout << "Distancia Entre centros: " << distancia_entre_centros.x << " " << distancia_entre_centros.y << " - "
			<< "Menor distancia colisao: " << menor_distancia_colisao.x << " " << menor_distancia_colisao.y << " = "
			<< "Distancia colisao: " << distancia_colisao.x << " " << distancia_colisao.y << endl;
		cout << ent1->getPosicao().x << " " << ent1->getPosicao().y << endl;
	}*/

	//Testa se teve colis?o

	if (distancia_colisao.x < 0.f && distancia_colisao.y < 0.f) //distancia_entre_centros.x < menor_distancia_colisao.x && distancia_entre_centros.y < menor_distancia_colisao.y
	{
		ent1->colisao(ent2->getID(), ent2, distancia_colisao);
	}
	else
	{
		ent1->setColidiu(false);
	}

	//Testa se teve colis?o entre Ente e Cantos

	const RenderWindow* janela = Ente::getManager()->getJanela();

	if (pos_ent1.y < 0.f)
	{
		ent1->colisao(IDs::canto, NULL, Vector2f(0.f, pos_ent1.y));
	}
	else if (pos_ent1.x < 0.f)
	{
		ent1->colisao(IDs::canto, NULL, Vector2f(pos_ent1.x, 0.f));
	}
	else if (pos_ent1.x >= janela->getSize().x - ent1->getTamanho().x)
	{
		ent1->colisao(IDs::canto, NULL, Vector2f(pos_ent1.x - (janela->getSize().x - ent1->getTamanho().x), 0.f));
	}
	else if (pos_ent1.y >= janela->getSize().y - ent1->getTamanho().y)
	{
		ent1->colisao(IDs::canto, NULL, Vector2f(0.f, pos_ent1.y - (janela->getSize().x - ent1->getTamanho().x)));
	}
}