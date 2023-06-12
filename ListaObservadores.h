#pragma once
#include "Lista.h"
#include "Observador.h"
using namespace Observers;
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Listas
{
	class ListaObservadores
	{
	private:
		Lista<Observador> listaObservadores;

	public:
		ListaObservadores();
		~ListaObservadores();

		void addObservador(Observador* observador);
		void deleteObservador(Observador* observador);

		void ativaObservador(IDs id);

		const int getTamanho() const;
		Observador* operator[](int pos);

		//Teclado
		void notificaTeclaPressionada(const Keyboard::Key tecla);
		void notificaTeclaSolta(const Keyboard::Key tecla);

		void desativaObservadores();
	};
}