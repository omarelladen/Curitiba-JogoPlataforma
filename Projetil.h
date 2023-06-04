#pragma once
#include"Capivara.h"
#include"Policial.h"
using namespace Personagens;

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo;
	}
	using namespace Personagens;

	class Projetil : public Entidade
	{
	private:
		Personagem* atirador;
		Vector2f velocidade;
		int dano;

	public:
		Projetil(Vector2f pos = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f));
		~Projetil();

		void setAtirador(Personagem* atir);

		void setDano(const int d);
		const int getDano() const;

		void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

		void mover();
		void executar();
	};
}