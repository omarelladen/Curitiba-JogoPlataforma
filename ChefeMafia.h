#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class ChefeMafia : public Inimigo
		{
		private:
			int nivel_forca;
			int num_capangas;

		public:
			ChefeMafia(Vector2f pos = Vector2f(0.f, 0.f), Jogador* pJ = nullptr);
			~ChefeMafia();
		};
	}
}