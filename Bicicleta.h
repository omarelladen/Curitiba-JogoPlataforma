#pragma once
#include "Obstaculo.h"
#include"Personagem.h"
using namespace Personagens;

namespace Entidades
{
	namespace Obstaculos
	{
		class Bicicleta : public Obstaculo//, public Personagem
		{
		private:
			bool pula;

		public:
			Bicicleta(Vector2f pos = Vector2f(0.f, 0.f));
			~Bicicleta();

			void mover(const char* direcao);
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
			void executar();
		};
	}
}