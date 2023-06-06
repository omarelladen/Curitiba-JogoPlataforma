#pragma once
#include"Jogador.h"
using namespace Personagens;

namespace Entidades
{
	namespace Personagens
	{
		class Capivara : public Jogador
		{
		private:
			int forca_cuspe;
			int golpe_especial;

		public:
			Capivara(Vector2f pos = Vector2f(0.f, 0.f));
			~Capivara();

			void inicializaAtributos();
			void AtirarCuspe();

			void setForcaCuspe(const int cuspe);
			const int getForcaCuspe() const;

			void setGolpeEspecial(const int especial);
			const int getGolpeEspecial() const;

			void salvar();
			ListaEntidades* recuperar();

			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		};
	}
}