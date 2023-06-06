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
			Capanga(Vector2f pos = Vector2f(0.f, 0.f));
			~Capanga();

			void inicializaAtributos();

			void salvar();
			ListaEntidades* recuperar();

			void setNivelTiro(const int tiro);
			const int getNivelTiro() const;

			void setNivelEstupidez(const int estupidez);
			const int getNivelEstupidez() const;

			void setTempoCongelado(const int tc);
			const int getTempoCongelado() const;

			void setCongelado(const bool conge);
			const bool getCongelado() const;

			void mover(const char* direcao);
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		};
	}
}