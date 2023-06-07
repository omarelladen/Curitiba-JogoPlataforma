#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Jacare : public Inimigo
		{
		private:
			int forca_mordida;
			int raio_super_pulo;
			int rapidez_mordida;// Pula até o jogador

		public:
			Jacare(Vector2f pos = Vector2f(0.f, 0.f));
			~Jacare();

			void inicializaAtributos();

			void setForcaMordida(const int mordida);
			const int getForcaMordida() const;

			void setRaioSuperPulo(const int raio_pulo);
			const int getRaioSuperPulo();

			void setRapidezMordida(const int tempo);
			const int getRapidezMordida();

			void salvar();
			ListaEntidades* recuperar();

			void mover();
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
			void executar();
		};
	}
}
