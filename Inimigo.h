#pragma once
#include<list>
using namespace std;
#include"Personagem.h"

namespace Entidades
{
	namespace Personagens
	{
		class Capivara;

		class Inimigo : public Personagem
		{
		protected:
			int raio_ataque;
			Capivara* alvo;
			Vector2f pos_ini;
			Vector2f pos_fin;

		public:
			Inimigo(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Inimigo();

			//void formaPadraoMover();
			void perseguirAlvo();

			void setAlvo(Capivara* target);

			virtual void salvar() = 0;
			virtual ListaEntidades* recuperar() = 0;
			virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			virtual void executar() = 0;
		};
	}
}