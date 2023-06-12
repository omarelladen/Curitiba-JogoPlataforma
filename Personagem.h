#pragma once
#include"Entidade.h"
#include"Projetil.h"

namespace Entidades
{
	namespace Personagens
	{
		class Personagem : public Entidade
		{
		protected:
			int num_vidas;
			bool direita;
			Clock relogio_ataque;

			RectangleShape barra_vidas;

		public:
			Personagem(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Personagem();

			void addProje(Entidade* pP);

			void setNumVidas(const int vidas);
			const int getNumVidas() const;

			void imprimirBarraVidas();

			void setDireita(const bool dir);
			const bool getDireita() const;

			void atirar(const int dano);

			void diminuirVida(int dano);

			// Funcoes exclusivamente para polimorfismo
			virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			virtual void executar() = 0;
		};
	}
}