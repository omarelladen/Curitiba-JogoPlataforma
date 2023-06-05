#pragma once
#include "Obstaculo.h"
using namespace Obstaculos;

namespace Entidades
{
	namespace Obstaculos
	{
		class Bicicleta : public Obstaculo
		{
		private:
			Vector2f velocidade;
			int nivel_ricochete;

		public:
			Bicicleta(Vector2f pos = Vector2f(0.f, 0.f));
			~Bicicleta();

			void inicializaAtributos();
			void mover();
			void executar();
		};
	}
}