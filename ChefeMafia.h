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
			int nivel_medo;
			int vidas_regeneradas;

		public:
			ChefeMafia(Vector2f pos = Vector2f(0.f, 0.f), Capivara* pJ = nullptr);
			~ChefeMafia();

			void inicializaAtributos();
			const int getNivelForca() const;
			const int getNivelMedo() const;
			void regeneraVida();

			void mover(const char* direcao);
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		};
	}
}