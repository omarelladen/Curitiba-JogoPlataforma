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
		//void deleteEntidade(Entidade* entid);
		//void deleteEntidade(int pos);

		Entidade* getEntidade(int pos);
		Entidade* operator[](int pos);

		const int getTamLista() const;

		Entidade* search(const int RG);

		void operator=(ListaEntidades& list);

		void executar();
	};
}*/

#pragma once
#include"Lista.h"
#include"Projetil.h"
#include"Capivara.h"
#include"Capanga.h"
#include"ChefeMafia.h"
#include"Jacare.h"
#include"Chao.h"
#include"Arvore.h"
#include"Lixo.h"
#include"Bicicleta.h"

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

		void salvarEntidades();
		void recuperarEntidades();

		const int getTamLista() const;

		void operator=(ListaEntidades& list);

		void executar();
	};
}