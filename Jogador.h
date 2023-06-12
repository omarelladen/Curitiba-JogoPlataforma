#pragma once
#include"Personagem.h"
using namespace Entidades;

namespace Gerenciadores
{
	class Gerenciador_Eventos;
}
using namespace Gerenciadores;

namespace Observers
{
	class ObservadorJogador;
}
using namespace Observers;

namespace Entidades
{
	namespace Personagens
	{
		class Jogador : public Personagem
		{
		protected:
			ObservadorJogador* observadorJogador;

			int pontos;

		public:
			Jogador(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Jogador();

			void operator++();

			void setPontos(const int pon);
			const int getPontos() const;

			void mover(const char* direcao);
			void parar();
			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao) = 0;
			void executar();
		};
	}
}