#pragma once
#include<fstream>
using namespace std;
#include"Ente.h"

#define GRAVIDADE 9.81f

namespace Listas
{
	class ListaEntidades;
}
using namespace Listas;

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

		ListaEntidades* pListaEntidades;

	public:
		Entidade(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
		~Entidade();

		void setEstaNoChao(const bool c);
		const bool getEstaNoChao();

		void setPosicao(Vector2f pos);
		Vector2f getPosicao() const;

		void setTamanho(Vector2f tam);
		Vector2f getTamanho() const;

		void restartRelogio();

		const RectangleShape getCorpo() const;

		virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		virtual void mover(const char* direcao);
		void desenhar_se();

		virtual void salvar() = 0;
		virtual ListaEntidades* recuperar() = 0;
		virtual void executar() = 0;
	};
}