#pragma once
#include "Lista.h"
#include "Observador.h"

class ListaObservadores
{
private:
	Lista<Observador> listaObservadores;

public:
	ListaObservadores();
	~ListaObservadores();

	void adicionarObservador(Observador* observador);
	void removerObservador(Observador* observador);
	void ativaObservador(IDs id);
	int getTamanho();
	Observador* operator[](int pos);


	// Teclado
	void notificarTeclaPressionada(const Keyboard::Key tecla);
	void notificarTeclaSolta(const Keyboard::Key tecla);

	// Mouse
	void notificarMovimentoMouse(Event::MouseMoveEvent mouse);
	void notificarMouseSolta(Mouse::Button botaoMouse);

	//
	void desativarObservadores();
};

