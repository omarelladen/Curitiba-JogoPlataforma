#pragma once
#include"Entidade.h"
using namespace Entidades;

constexpr auto MAX_VEL = static_cast<float>(0.7);
constexpr auto MAX_VEL_AR = static_cast<float>(2.0);
constexpr auto INCRE_VEL = static_cast<float>(0.2);

namespace Entidades
{
	namespace Personagens
	{
		class Personagem : public Entidade
		{
		protected:
			int num_vidas;
			Time tempo;
			Clock relogio;
			Vector2f velocidade;

		public:
			Personagem(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Personagem();

			// Funcoes exclusivamente para polimorfismo
			virtual void mover(const char* direcao) = 0;
			virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			virtual void executar() = 0;


			const int getNumVidas() const;
		};
	}
}