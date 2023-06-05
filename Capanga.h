#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Capanga : public Inimigo
		{
		private:
			int nivel_tiro;
			int nivel_estupidez;
			int tempo_congelado;
			bool congelado;

		public:
			Capanga(Vector2f pos = Vector2f(0.f, 0.f), Capivara* pJ = nullptr);
			~Capanga();

			void inicializaAtributos();
			const int getNivelEstupidez() const;

			void mover(const char* direcao);
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		};
	}
}