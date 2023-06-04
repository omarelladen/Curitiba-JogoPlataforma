#pragma once
#include "Jogador.h"

namespace Entidades
{
	namespace Personagens
	{
		class Capivara : public Jogador
		{
		private:
			int nivel_cuspe;
			float nivel_pulo;

		public:
			Capivara(Vector2f pos = Vector2f(200.f, 200.f)); // default
			~Capivara();
		};
	}
}