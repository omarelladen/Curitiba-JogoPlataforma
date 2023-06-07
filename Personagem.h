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

		public:
			Personagem(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Personagem();

			void setNumVidas(const int vidas);
			const int getNumVidas() const;

			void setDireita(const bool dir);
			const bool getDireita();

			void atirar(const int dano);

			void diminuirVida(int dano);

			// Funcoes exclusivamente para polimorfismo
			virtual void salvar() = 0;
			virtual ListaEntidades* recuperar() = 0;
			virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			virtual void executar() = 0;
		};
	}
}