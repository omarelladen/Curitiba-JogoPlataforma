#pragma once
#include<list>
using namespace std;
#include"Personagem.h"
#include"Projetil.h"
#include"Jogador.h"

constexpr auto RAIO_PERSEGUICAO_X = static_cast<float>(100);

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo : public Personagem
		{
		protected:
			int nivel_maldade;
			bool indo;
			Jogador* alvo;
			list<Projetil*> projs;
			Vector2f pos_ini;
			Vector2f pos_fin;

		public:
			Inimigo(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f), Jogador* player = nullptr,
				Vector2f pos_i = Vector2f(0.f, 0.f), Vector2f pos_f = Vector2f(0.f, 0.f));
			~Inimigo();

			void operator++();
			void mover(const char* direcao);
			void formaPadraoMover();
			void perseguirAlvo();

			void setProjetil(Projetil* proj);
			void atirar();

			void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
			void executar();
		};
	}
}