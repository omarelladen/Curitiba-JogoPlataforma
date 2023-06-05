#pragma once
#include "Jogador.h"
#include"Projetil.h"

namespace Entidades
{
	namespace Personagens
	{
		class Capivara : public Jogador
		{
		private:
			int forca_cuspe;
			int golpe_especial;
			Projetil* pProje;

		public:
			Capivara(Vector2f pos = Vector2f(0.f, 0.f));
			~Capivara();

			void inicializaAtributos();
			void AtirarCuspe();

			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

			const int getNivelCuspe() const;
		};
	}
}