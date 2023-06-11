#pragma once
#include "Jogador.h"
#include"Jacare.h"
#include"Capanga.h"
#include"ChefeMafia.h"

namespace Entidades
{
	namespace Personagens
	{
		class Policial : public Jogador
		{
		private:
			int pente_arma;
			bool atirar;

		public:
			Policial(Vector2f pos = Vector2f(0.f, 0.f));
			~Policial();

			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

			const int getPenteArma() const;
			const bool getAtirar() const;
		};
	}
}