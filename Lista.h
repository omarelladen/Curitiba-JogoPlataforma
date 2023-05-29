#pragma once
#include"stdafx.h"

namespace Listas
{
	template <class TypeL>
	class Lista
	{
	public:

		/*-------------------------------------------------------------------------------------------*/
		/*-------------------------------------------------------------------------------------------*/

		//Elemento

		template<class TypeE = TypeL>
		class Elemento
		{
		private:
			Elemento<TypeE>* pProx;
			TypeE* pClass_origin;

		public:
			Elemento();
			~Elemento();

			void setPProx(Elemento<TypeE>* pprox);
			Elemento<TypeE>* getPProx();

			void setClassOrigin(TypeE* co);
			TypeE* getClassOrigin();
		};

		/*-------------------------------------------------------------------------------------------*/
		/*-------------------------------------------------------------------------------------------*/

	private:
		Elemento<TypeL>* pPrimeiro;
		Elemento<TypeL>* pUltimo;
		static int tam;

	public:
		Lista();
		~Lista();

		void clear();

		void setElemento(TypeL* elem);
		void deleteElemento(TypeL* elem);
		TypeL* getClassOrigin(int pos);

		static const int getTam(); //const; do problema por algum motivo
	};
}
using namespace Listas;


/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

//Lista

template<class TypeL>
int Lista<TypeL>::tam(0);

template<class TypeL>
Lista<TypeL>::Lista()
{
	pPrimeiro = NULL;
	pUltimo = NULL;
}

template<class TypeL>
Lista<TypeL>::~Lista()
{
	clear();
}

template<class TypeL>
inline void Lista<TypeL>::clear()
{
	Elemento<TypeL>* temp = pPrimeiro;
	Elemento<TypeL>* temp2 = NULL;

	while (temp != NULL)
	{
		if (temp)
		{
			temp2 = temp->getPProx();
			delete temp;
			temp = temp2;
		}
	}

	pPrimeiro = NULL;
	pUltimo = NULL;
}

template<class TypeL>
void Lista<TypeL>::setElemento(TypeL* class_o)
{
	if (class_o)
	{
		if (pPrimeiro == NULL)
		{
			pPrimeiro = new Elemento<TypeL>();
			if (pPrimeiro)
			{
				pPrimeiro->setClassOrigin(class_o);
				pUltimo = pPrimeiro;
			}
			else
			{
				cout << "Erro de alocacao de ponteiro Elemento<TypeL> na Lista" << endl;
			}

		}
		else
		{
			Elemento<TypeL>* temp = new Elemento<TypeL>();
			temp->setClassOrigin(class_o);
			pUltimo->setPProx(temp);
			pUltimo = temp;
			temp = NULL;
		}
		tam++;
	}
	else
	{
		cout << "Tentativa de inclusao de ponteiro nulo na Lista" << endl;
	}

}

template<class TypeL>
void Lista<TypeL>::deleteElemento(TypeL* elem)
{
	Elemento<TypeL>* temp = pPrimeiro;
	Elemento<TypeL>* ant = NULL;

	bool achou = false;

	if (pPrimeiro)
	{
		if (temp->getClassOrigin() == elem)
		{
			pPrimeiro = pPrimeiro->getPProx();
			delete temp;
			temp = NULL;
			achou = true;
		}
	}
	else
	{
		cout << "Lista vazia" << endl;
	}

	while (temp != NULL)
	{
		ant = temp;
		temp = temp->getPProx();

		if (temp && temp->getClassOrigin() == elem)
		{
			ant->setPProx(temp->getPProx());
			delete temp;
			temp = NULL;
			ant = NULL;
			achou = true;
			break;
		}
	}

	if (achou)
	{
		tam--;
	}

}

template<class TypeL>
TypeL* Lista<TypeL>::getClassOrigin(int pos)
{
	Elemento<TypeL>* temp = pPrimeiro;

	if (pos >= 0 && pos < tam)
	{
		if (pPrimeiro)
		{
			for (int i = 0; i < pos; i++)
			{
				if (temp)
				{
					temp = temp->getPProx();
				}
			}
			return temp->getClassOrigin();
		}
		else
		{
			cout << "Lista vazia" << endl;
			return NULL;
		}
	}
	else
	{
		cout << "Acesso de posicao invalida" << endl;
		return NULL;
	}
}

template<class TypeL>
const int Lista<TypeL>::getTam()
{
	return tam;
}


/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

//Elemento

template<class TypeL>
template<class TypeE>
inline Lista<TypeL>::Elemento<TypeE>::Elemento()
{
	pProx = NULL;
	pClass_origin = NULL;
}

template<class TypeL>
template<class TypeE>
inline Listas::Lista<TypeL>::Elemento<TypeE>::~Elemento()
{
	pProx = NULL;
	pClass_origin = NULL;
}

template<class TypeL>
template<class TypeE>
inline void Listas::Lista<TypeL>::Elemento<TypeE>::setPProx(Elemento<TypeE>* pprox)
{
	pProx = pprox;
}

template<class TypeL>
template<class TypeE>
inline Listas::Lista<TypeL>::Elemento<TypeE>* Listas::Lista<TypeL>::Elemento<TypeE>::getPProx()
{
	return pProx;
}

template<class TypeL>
template<class TypeE>
inline void Listas::Lista<TypeL>::Elemento<TypeE>::setClassOrigin(TypeE* co)
{
	pClass_origin = co;
}

template<class TypeL>
template<class TypeE>
inline TypeE* Listas::Lista<TypeL>::Elemento<TypeE>::getClassOrigin()
{
	return pClass_origin;
}


/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/