/*#pragma once
#include"Lista.h"
#include"Entidade.h"
using namespace Entidades;

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> listaEntidades;

	public:
		ListaEntidades();
		~ListaEntidades();

		void clear();

		void addEntidade(Entidade* entid);
		void deleteEntidade(Entidade* entid);
		void deleteEntidade(int pos);

		Entidade* getEntidade(int pos);
		Entidade* operator[](int pos);

		const int getTamLista() const;

		void executar();
	};
}*/

#pragma once
#include"Lista.h"
#include"Entidade.h"
using namespace Entidades;

#include <vector>//

namespace Listas
{
	class ListaEntidades
	{
	private:
		vector<Entidade*> listaEntidades;

	public:
		ListaEntidades();
		~ListaEntidades();

		void clear();

		void addEntidade(Entidade* entid);
		//void deleteEntidade(Entidade* entid);
		//void deleteEntidade(int pos);

		Entidade* getEntidade(int pos);
		Entidade* operator[](int pos);

		const int getTamLista() const;

		void executar();
	};
}