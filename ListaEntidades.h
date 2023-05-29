#pragma once
#include"Lista.h"
#include"Entidade.h"
using namespace Entidades;

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> LEs;

	public:
		ListaEntidades();
		~ListaEntidades();

		void clear();

		void setEntidade(Entidade* entid);
		void deleteEntidade(Entidade* entid);

		Entidade* getEntidade(int pos);

		const int getTamLista() const;

		void executar();
	};
}