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

		void adicionarObservador(Observador* observador);
		void removerObservador(Observador* observador);

		void ativaObservador(IDs id);// especificos - igual nome do gerenciador chama essa
		int getTamanho();
		Observador* operator[](int pos);


		// Teclado
		void notificarTeclaPressionada(const Keyboard::Key tecla);
		void notificarTeclaSolta(const Keyboard::Key tecla);

		// Mouse
		void notificarMouseSolta(Event::MouseMoveEvent mouse); //Mouse::Button botaoMouse, 

		//
		void desativarObservadores();
	};
}


/*#pragma once
#include "Lista.h"
#include "Observador.h"
using namespace Observers;

#include <SFML/Graphics.hpp>
using namespace sf;

#include <vector>//

namespace Listas
{
	class ListaObservadores
	{
	private:
		vector<Observador*> listaObservadores;

	public:
		ListaObservadores();
		~ListaObservadores();

		void adicionarObservador(Observador* observador);
		//void removerObservador(Observador* observador);

		void ativaObservador(IDs id);// especificos - igual nome do gerenciador chama essa
		int getTamanho();
		Observador* operator[](int pos);


		// Teclado
		void notificarTeclaPressionada(const Keyboard::Key tecla);
		void notificarTeclaSolta(const Keyboard::Key tecla);

		// Mouse
		void notificarMouseSolta(Event::MouseMoveEvent mouse); //Mouse::Button botaoMouse, 

		//
		void desativarObservadores();
	};
}*/
