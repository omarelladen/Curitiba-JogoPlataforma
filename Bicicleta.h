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
			int nivel_ricochete;
			int dano;

		public:
			Bicicleta(Vector2f pos = Vector2f(0.f, 0.f));
			~Bicicleta();

			void inicializaAtributos();

			void setNivelRicochete(const int ricochete);
			const int getNivelRicochete() const;

			void setDano(const int damage);
			const int getDano() const;

			void mover();
			void executar();
		};
	}
}