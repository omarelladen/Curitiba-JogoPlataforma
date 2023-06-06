#pragma once
#include<list>
using namespace std;
#include"Personagem.h"
#include"Capivara.h"

#define RAIO_PERSEGUICAO_X 100.f

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo : public Personagem
		{
		protected:
			bool indo;
			Capivara* alvo;
			Vector2f pos_ini;
			Vector2f pos_fin;

		public:
			Inimigo(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f), 
					Vector2f pos_i = Vector2f(0.f, 0.f), Vector2f pos_f = Vector2f(0.f, 0.f));
			~Inimigo();

			void formaPadraoMover();
			void perseguirAlvo();

			void setAlvo(Capivara* target);

			void setIndo(const bool ind);

			void executar();

			virtual void salvar() = 0;
			virtual ListaEntidades* recuperar() = 0;
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			void mover(const char* direcao) = 0;
		};
	}
}