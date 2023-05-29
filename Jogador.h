#pragma once
#include"Personagem.h"
using namespace Personagens;

#include"ObservadorJogador.h"
#include"Gerenciador_Eventos.h"

namespace Entidades
{
	namespace Personagens
	{
		class Jogador : public Personagem
		{
		private:
			ObservadorJogador* observadorJogador;

			int pontos;

		public:
			Jogador(Vector2f tam_corpo = Vector2f(0.f, 0.f));
			~Jogador();

			void operator++();
			void operator--();

			void mover(const char* direcao);
			void parar();

			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

			void executar();
		};
	}
}