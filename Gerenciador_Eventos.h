#pragma once
#include "ListaObservadores.h"
#include"IDs.h"
#include"Gerenciador_Grafico.h"
using namespace Gerenciadores;

namespace Gerenciadores
{
	class Gerenciador_Eventos
	{
	private:
		//Gerenciador_Grafico* pGrafico;
		//Gerenciador_Estados* pEstados;



		static ListaObservadores* listaObservadores;

		// S T A T I C
		static Gerenciador_Eventos* pGerenciadorEventos;

		Gerenciador_Eventos(); ////////// arrumas static no argumento? isso ??, onde chama??  sgt
	public:
		~Gerenciador_Eventos();

		// S T A T I C
		static Gerenciador_Eventos* getGerenciadorEventos(); // static pra poder acessar diretamente pra add observador na lista


		void adicionarObservador(Observador* observador);
		void ativaObservador(IDs id);///
		void desativaObservadores();//

		void executar();
	};
}