#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Capanga : public Inimigo
		{
		private:
			int nivel_estupidez;

		public:
			Capanga(Vector2f pos = Vector2f(0.f, 0.f), Jogador* pJ = nullptr);
			~Capanga();
		};
	}
}