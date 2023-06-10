#include "Gerenciador_Colisoes.h"
#include"Entidade.h"
using namespace Gerenciadores;
#include<math.h>

Gerenciador_Colisoes* Gerenciador_Colisoes::pGerenciadorColisoes(nullptr);

Gerenciador_Colisoes::Gerenciador_Colisoes() :
	listaObstaculos(nullptr),
	listaPersonagens(nullptr),
	listaProjeteis(new ListaEntidades()),
	pJogador(nullptr)
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	delete listaProjeteis;

	listaObstaculos = nullptr;
	listaPersonagens = nullptr;
	listaProjeteis = nullptr;
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
	listaProjeteis->salvarEntidades();
}

void Gerenciador_Colisoes::addProjetil(Entidade* proj)
{
	if(listaProjeteis == nullptr)
	{
		listaProjeteis = new ListaEntidades();
	}
	listaProjeteis->addEntidade(proj);
}

void Gerenciador_Colisoes::GerenciarColisoes()
{
	Entidade* pEnt1 = nullptr;
	Entidade* pEnt2 = nullptr;
	Entidade* pEnt3 = nullptr;

	if (listaPersonagens && listaObstaculos && listaProjeteis)
	{
		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			pEnt1 = listaPersonagens->getEntidade(i);

			//Calcula colisao Personagem e Obstaculos

			for (int j = 0; j < listaObstaculos->getTamLista(); j++)
			{
				pEnt2 = listaObstaculos->getEntidade(j);

				CalculaColisao(pEnt1, pEnt2);

				//Calcula colisao Obstaculos e Projeteis

				for (int k = 0; k < listaProjeteis->getTamLista(); j++)
				{
					pEnt3 = listaProjeteis->getEntidade(j);

					CalculaColisao(pEnt2, pEnt3);
				}
			}

			//Calcula colisao Personagem e Personagem

			for (int j = i + 1; j < listaPersonagens->getTamLista(); j++)
			{
				pEnt2 = listaPersonagens->getEntidade(j);

				CalculaColisao(pEnt1, pEnt2);
			}

			//Calcula colisao Personagem e Projeteis

			for (int j = 0; j < listaProjeteis->getTamLista(); j++)
			{
				pEnt2 = listaProjeteis->getEntidade(j);

				if (pEnt2)
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

	/*if ((ent1->getID() == "Projetil"))
	{
		cout << "Distancia Entre centros: " << distancia_entre_centros.x << " " << distancia_entre_centros.y << " - "
			<< "Menor distancia colisao: " << menor_distancia_colisao.x << " " << menor_distancia_colisao.y << " = "
			<< "Distancia colisao: " << distancia_colisao.x << " " << distancia_colisao.y << endl;
		cout << ent1->getPosicao().x << " " << ent1->getPosicao().y << endl;
	}*/

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
				ent1->setPosicao(ent1->getPosicao() + distancia_colisao);
			}

			//Colisao Baixo
			else
			{
				ent1->setPosicao(ent1->getPosicao() - distancia_colisao);
			}
		}

		ent1->colisao(ent2->getID(), ent2, distancia_colisao);


		/*if (ent2->getID() == IDs::projetil)
		{
			listaProjeteis->deleteEntidade(ent2);
		}*/
	}
}

void Gerenciador_Colisoes::executar()
{
	bool chamar_executar = true;

	if (listaPersonagens)
	{
		//Verifica se os Personagens estao vivos
		for (int i = 0; i < listaPersonagens->getTamLista(); i++)
		{
			Personagem* pPerso =  static_cast<Personagem*>(listaPersonagens->getEntidade(i));
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
						pJogador->setVelocidade(Vector2f(0.f, 0.f));
						Gerenciador_Grafico::getGerenciadorGrafico()->setPosicaoGameOver(pJogador->getPosicao());
						Gerenciador_Grafico::getGerenciadorGrafico()->gameOver();
						chamar_executar = false;
					}
				}
			}
		}
		if(chamar_executar)
			listaPersonagens->executar();
	}

	if (chamar_executar)
	{
		if (listaObstaculos)
		{
			listaObstaculos->executar();
		}

		if (listaProjeteis)
		{
			listaProjeteis->executar();
		}
	}
	GerenciarColisoes();
}
