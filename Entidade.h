#pragma once
#include<fstream>
using namespace std;
#include"Ente.h"

#define GRAVIDADE 9.81f
#define MAX_VEL 2.f
#define MAX_VEL_AR 1.f
#define INCRE_VEL 0.5f

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
		Vector2f velocidade;
		Time tempo;
		Clock relogio_gravidade;
		bool esta_no_chao;

		Texture textura;

		ListaEntidades* pListaEntidades;

	public:
		Entidade(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
		~Entidade();

		void setTextura(const char* caminho_textura);

		void setEstaNoChao(const bool c);
		const bool getEstaNoChao();

		void setPosicao(Vector2f pos);
		Vector2f getPosicao() const;

		void setTamanho(Vector2f tam);
		Vector2f getTamanho() const;

		void setVelocidade(Vector2f vel);
		const Vector2f getVelocidade() const;

		const RectangleShape getCorpo() const;

		void restartRelogio();

		void efeitoGravidade();
		virtual void colisao(const IDs id, Entidade* ent, Vector2f distancia_colisao);
		void desenhar_se();

		virtual void salvar() = 0;
		virtual ListaEntidades* recuperar() = 0;
		virtual void executar() = 0;
	};
}