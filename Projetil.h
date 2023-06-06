#pragma once
#include"Entidade.h"

namespace Entidades
{
	namespace Personagens
	{
		class Personagem;
	}
	using namespace Personagens;

	class Projetil : public Entidade
	{
	private:
		Personagem* atirador;
		Vector2f velocidade;
		int dano;

	public:
		Projetil(Vector2f pos = Vector2f(0.f, 0.f));
		~Projetil();

		void inicializaAtributos();

		void setAtirador(Personagem* atir);
		void setVelocidade(Vector2f vel);

		void setDano(const int d);
		const int getDano() const;

		//void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

		void salvar();
		ListaEntidades* recuperar();

		void mover();
		void executar();
	};
}