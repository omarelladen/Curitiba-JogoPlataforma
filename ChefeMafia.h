#pragma once
#include "Inimigo.h"

#define NUM_MAX_VIDAS 70

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
			ChefeMafia(Vector2f pos = Vector2f(0.f, 0.f));
			~ChefeMafia();

			void inicializaAtributos();

			void setNivelForca(const int forca);
			const int getNivelForca() const;

			void setNivelMedo(const int medo);
			const int getNivelMedo() const;

			void setVidasRegeneradas(const int vidas);
			const int getVidasRegeneradas();

			void regeneraVida();

			void salvar();
			ListaEntidades* recuperar();

			void mover();
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
			void executar();
		};
	}
}