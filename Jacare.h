#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Jacare : public Inimigo
		{
		private:
			int nivel_mordida;
			int raio_super_pulo; // Pula até o jogador
			//int tamanho;

		public:
			Jacare(Vector2f pos = Vector2f(0.f, 0.f));
			~Jacare();

			void inicializaAtributos();

			void setNivelMordida(const int mordida);
			const int getNivelMordida() const;

			void setRaioSuperPulo(const int raio_pulo);

			void salvar();
			ListaEntidades* recuperar();

			void mover(const char* direcao);
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		};
	}
}
