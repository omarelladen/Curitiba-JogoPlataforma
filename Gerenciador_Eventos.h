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
		static ListaObservadores* listaObservadores;

		static Gerenciador_Eventos* pGerenciadorEventos;

		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();

		static Gerenciador_Eventos* getGerenciadorEventos(); 

		void addObservador(Observador* observador);

		void ativaObservador(IDs id);
		void desativaObservadores();

		void executar();
	};
}