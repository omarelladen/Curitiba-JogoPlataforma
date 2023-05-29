#pragma once
#include"Ente.h"

constexpr auto GRAVIDADE = static_cast<float>(9.81);

namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
		RectangleShape corpo;
		Vector2f posicao;
		Vector2f tam_corpo;
		bool esta_no_chao;

	public:
		Entidade(const IDs id, Vector2f tam_corpo = Vector2f(0.f, 0.f));
		~Entidade();

		virtual void executar() = 0;
		virtual void mover(const char* direcao);
		void desenhar_se();

		void setColidiu(const bool c);
		virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);

		void setPosicao(Vector2f pos);
		Vector2f getPosicao() const;

		Vector2f getTamanho() const;
		const RectangleShape getCorpo() const;
	};
}