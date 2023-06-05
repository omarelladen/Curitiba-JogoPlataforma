#pragma once
#include"Entidade.h"
using namespace Entidades;

constexpr auto MAX_VEL = 16.f;
constexpr auto MAX_VEL_AR = 1.0f;
constexpr auto INCRE_VEL = 8.f;

namespace Entidades
{
	namespace Personagens
	{
		class Personagem : public Entidade
		{
		protected:
			int num_vidas;
			Vector2f velocidade;

		public:
			Personagem(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Personagem();

			void operator--();

			// Funcoes exclusivamente para polimorfismo
			virtual void mover(const char* direcao) = 0;
			virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			virtual void executar() = 0;


			const int getNumVidas() const;
		};
	}
}