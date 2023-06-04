#pragma once
#include<iostream>
using namespace std;

namespace Listas
{
	template <class TypeL>
	class Lista
	{
	private:
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
		TypeL* operator[] (int pos);

		static const int getTam(); //const; da problema por algum motivo
	};
}
using namespace Listas;


/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

//Lista

template<class TypeL>
int Lista<TypeL>::tam(0);

template<class TypeL>
Lista<TypeL>::Lista() :
	pPrimeiro(nullptr),
	pUltimo(nullptr)
{
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
	Elemento<TypeL>* temp2 = nullptr;

	while (temp != nullptr)
	{
		if (temp)
		{
			temp2 = temp->getPProx();
			delete temp;
			temp = temp2;
		}
	}

	pPrimeiro = nullptr;
	pUltimo = nullptr;
}

template<class TypeL>
void Lista<TypeL>::setElemento(TypeL* class_o)
{
	if (class_o)
	{
		if (pPrimeiro == nullptr)
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
			temp = nullptr;
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
	Elemento<TypeL>* ant = nullptr;

	bool achou = false;

	if (pPrimeiro)
	{
		if (temp->getClassOrigin() == elem)
		{
			pPrimeiro = pPrimeiro->getPProx();
			delete temp;
			temp = nullptr;
			achou = true;
		}
	}
	else
	{
		cout << "Lista vazia" << endl;
	}

	if (!achou)
	{
		while (temp != nullptr)
		{
			ant = temp;
			temp = temp->getPProx();

			if (temp && temp->getClassOrigin() == elem)
			{
				ant->setPProx(temp->getPProx());
				delete temp;
				temp = nullptr;
				ant = nullptr;
				achou = true;
				break;
			}
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
			return nullptr;
		}
	}
	else
	{
		cout << "Acesso de posicao invalida" << endl;
		return nullptr;
	}
}

template<class TypeL>
TypeL* Listas::Lista<TypeL>::operator[](int pos)
{
	return getClassOrigin(pos);
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
inline Lista<TypeL>::Elemento<TypeE>::Elemento() :
	pProx(nullptr),
	pClass_origin(nullptr)
{
}

template<class TypeL>
template<class TypeE>
inline Listas::Lista<TypeL>::Elemento<TypeE>::~Elemento()
{
	pProx = nullptr;
	pClass_origin = nullptr;
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