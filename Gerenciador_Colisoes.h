#pragma once
#include"ListaEntidades.h"
#include"stdafx.h"

namespace Gerenciadores
{
	class Gerenciador_Colisoes
	{
	private:
		ListaEntidades* listaPersonagens;
		ListaEntidades* listaObstaculos;

	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();

		void setListaPersonagens(ListaEntidades* listPers);
		void setListaObstaculos(ListaEntidades* listObsts);

		void GerenciarColisoes();

		//Calcula Colisao
		void CalculaColisao(Entidade* ent1, Entidade* ent2);
	};
}