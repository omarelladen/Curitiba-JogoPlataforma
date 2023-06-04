#pragma once
#include"ListaEntidades.h"

namespace Gerenciadores
{
	class Gerenciador_Colisoes
	{
	private:
		ListaEntidades* listaPersonagens;
		ListaEntidades* listaObstaculos;

	public:
		Gerenciador_Colisoes(ListaEntidades* LPs = nullptr, ListaEntidades* LOs = nullptr);
		~Gerenciador_Colisoes();

		void GerenciarColisoes();

		//Calcula Colisao
		void CalculaColisao(Entidade* ent1, Entidade* ent2);
	};
}