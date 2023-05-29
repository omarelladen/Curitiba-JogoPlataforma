#pragma once
#include"Jogador.h"
using namespace Personagens;

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo;
	}

	class Projetil : public Entidade
	{
	private:
		Personagem* atirador;
		Vector2f velocidade;
		int dano;

	public:
		Projetil(Vector2f tam_corpo = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f));
		~Projetil();

		void setAtirador(Personagem* atir);

		void setDano(const int d);
		const int getDano() const;

		void colisao(const string id, Entidade* ent, Vector2f distancia_colisao);

		void mover();
		void executar();
	};
}
