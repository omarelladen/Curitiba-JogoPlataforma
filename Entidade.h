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
		Time tempo;
		Clock relogio;
		bool esta_no_chao;

	public:
		Entidade(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
		~Entidade();

		void setEstaNoChao(const bool c);
		const bool getEstaNoChao();

		void setPosicao(Vector2f pos);
		Vector2f getPosicao() const;

		void setTamanho(Vector2f tam);
		Vector2f getTamanho() const;

		const RectangleShape getCorpo() const;

		virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		virtual void mover(const char* direcao);
		void desenhar_se();
		virtual void executar() = 0;
	};
}