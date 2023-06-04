#pragma once
#include"ListaEntidades.h"
#include"Gerenciador_Colisoes.h"
#include"Gerenciador_Eventos.h"
#include"ConstrutorEntidade.h"
#include"Jogador.h"

namespace Observers
{
	class ObservadorFase;
}
using namespace Observers;

namespace Fases
{
	class Fase : public Ente
	{
	protected:
		ListaEntidades* listaPersonagens;
		ListaEntidades* listaObstaculos;

		Gerenciador_Colisoes* gerenciadorColisoes;

		ConstrutorEntidade* construtorEntidade;

		// fundo - imagem/camada

		ObservadorFase* observadorFase;

	public:
		Fase(const IDs id = {});
		~Fase();

		void adicionarJogador(Jogador* pJ);

		void criarEntidade(const char simbolo, Vector2f pos);

		virtual void criarMapa() = 0;
		virtual void executar() = 0;
	};
}
/*
private:
	
	ConstrutorEntidade* contrutorEntidades;


public:
	Fase();
	~Fase();

	void criarMapa(); //c

	virtual void gerenciar_colisoes() = 0;
	virtual void executar() = 0; // n pura na vdd pelo video
*/