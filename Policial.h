#pragma once
#include "Jogador.h"

namespace Entidades
{
	namespace Personagens
	{
		class Policial : public Jogador
		{
		private:
			int pente_arma;
			bool atirar;

		public:
			Policial(Vector2f pos = Vector2f(0.f, 0.f));
			~Policial();
		};
	}
}