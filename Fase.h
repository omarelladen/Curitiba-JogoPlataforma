#pragma once
#include"ListaEntidades.h"
#include"Gerenciador_Colisoes.h"
#include"Gerenciador_Eventos.h"
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

		ObservadorFase* observadorFase;

		Jogador* pJogador;

		int num_inimigos;
		int contador_inimigos;
		int num_obstaculos;
		int contador_obstaculos;

	public:
		Fase(const IDs id = {});
		~Fase();

		void addJogador(Jogador* pJ);

		void setJogador(Jogador* pJ);

		void salvarJogada();
		void recuperarJogada();

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