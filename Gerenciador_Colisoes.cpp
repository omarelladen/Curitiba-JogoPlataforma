#include "Gerenciador_Colisoes.h"
#include"Entidade.h"
using namespace Gerenciadores;
#include<math.h>

Gerenciador_Colisoes* Gerenciador_Colisoes::pGerenciadorColisoes = nullptr;

Gerenciador_Colisoes::Gerenciador_Colisoes() :
	listaObstaculos(nullptr),
	listaPersonagens(nullptr),
	pJogador(nullptr)
{

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	listaObstaculos = nullptr;
	listaPersonagens = nullptr;
	pJogador = nullptr;
}

Gerenciador_Colisoes* Gerenciador_Colisoes::getGerenciadorColisoes()
{
	if (pGerenciadorColisoes == nullptr)
	{
		return new Gerenciador_Colisoes();
	}
	return pGerenciadorColisoes;
}

void Gerenciador_Colisoes::setListaPersonagens(ListaEntidades* list)
{
	if (list)
	{
		listaPersonagens = list;
	}
}

void Gerenciador_Colisoes::setListaObstaculos(ListaEntidades* list)
{
	if (list)
	{
		listaObstaculos = list;
	}
}


void Gerenciador_Colisoes::setJogador(Jogador* pJ)
{
	if (pJ)
		pJogador = pJ;
}

void Gerenciador_Colisoes::salvar()
{
	listaObstaculos->salvarEntidades();
	listaPersonagens->salvarEntidades();
}

void Gerenciador_Colisoes::recuperar()
{
	if (listaObstaculos)
		listaObstaculos->recuperarEntidades();

	if (listaPersonagens)
		listaPersonagens->recuperarEntidades();
}

void Gerenciador_Colisoes::GerenciarColisoes()
{
	Entidade* pEnt1 = nullptr;
	Entidade* pEnt2 = nullptr;
	Entidade* pEnt3 = nullptr;

	if (listaPersonagens && listaObstaculos)
	{
		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			pEnt1 = listaPersonagens->getEntidade(i);

			//Calcula colisao Personagem e Obstaculos

			for (int j = 0; j < listaObstaculos->getTamLista(); j++)
			{
				pEnt2 = listaObstaculos->getEntidade(j);

				CalculaColisao(pEnt1, pEnt2);
			}

			//Calcula colisao Personagem e Personagem

			for (int j = i + 1; j < listaPersonagens->getTamLista(); j++)
			{
				pEnt2 = listaPersonagens->getEntidade(j);

				CalculaColisao(pEnt1, pEnt2);

				//Calcula colisao Personagem e Projetil 1

				for (int k = 0; k < pEnt2->getListaProje()->getTamLista(); k++)
				{
					pEnt3 = pEnt2->getListaProje()->operator[](k);

					CalculaColisao(pEnt1, pEnt3);
				}

				//Calcula colisao Personagem e Projetil 2

				for (int k = 0; k < pEnt1->getListaProje()->getTamLista(); k++)
				{
					pEnt3 = pEnt1->getListaProje()->operator[](k);

					CalculaColisao(pEnt2, pEnt3);
				}

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
	//Calcula colisao usando os centros das entidades

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

	//Testa se teve colisao
	if (distancia_colisao.x < 0.f && distancia_colisao.y < 0.f) 
	{
		//Colisao em x
		if (distancia_colisao.x > distancia_colisao.y)
		{
			distancia_colisao.y = 0.f;

			//Colisao Esquerda
			if (ent1->getPosicao().x < ent2->getPosicao().x)
			{
				ent1->setPosicao(ent1->getPosicao() + distancia_colisao);
			}

			//Colisao Direita
			else
			{
				ent1->setPosicao(ent1->getPosicao() - distancia_colisao);
			}
		}

		//Colisao em y
		else
		{
			distancia_colisao.x = 0.f;

			//Colisao Cima
			if (ent1->getPosicao().y < ent2->getPosicao().y)
			{
				ent1->setEstaNoChao(true);
				ent1->setPosicao(ent1->getPosicao() + distancia_colisao);
			}

			//Colisao Baixo
			else
			{
				ent1->setPosicao(ent1->getPosicao() - distancia_colisao);
			}
		}

		ent1->colisao(ent2->getID(), ent2, distancia_colisao);


		if (ent2->getID() == IDs::projetil)
		{
			Projetil* pP = static_cast<Projetil*>(ent2);// ou dynamic_cast
			if ( !( (ent1->getID() == IDs::capanga || ent1->getID() == IDs::jacare || ent1->getID() == IDs::chefeMafia) && 
				    (pP->getAtirador()->getID() == IDs::capanga || pP->getAtirador()->getID() == IDs::jacare || pP->getAtirador()->getID() == IDs::chefeMafia) ) )
			{
				if (pP)
				{
					ent2->setPosicao(Vector2f(0.f, 100000.f));//pP->getAtirador()->getListaProje()->deleteEntidade(ent2);
					ent2->setVelocidade(Vector2f(0.f, 0.f));
				}
			}
		}
	}
}

void Gerenciador_Colisoes::executar()
{
	if (listaPersonagens)
	{
		//Verifica se os Personagens estao vivos
		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			Personagem* pPerso = static_cast<Personagem*>(listaPersonagens->getEntidade(i));
			if (pPerso)
			{
				if (pPerso->getNumVidas() <= 0)
				{
					if (pPerso->getID() != IDs::capivara)
					{
						//Inimigo morto
						listaPersonagens->deleteEntidade(listaPersonagens->getEntidade(i));
						pJogador->setPontos(pJogador->getPontos() + 1);
					}
					else
					{
						//Morte do Jogador
						Gerenciador_Estados::getGerenciadorEstados()->addEstado
						(
							Gerenciador_Estados::getGerenciadorEstados()->criarEstadoMenuGameOver(pJogador)
						);
					}
				}
			}
		}

		listaPersonagens->executar();
	}

	if (listaObstaculos)
	{
		listaObstaculos->executar();
	}

	GerenciarColisoes();
}
