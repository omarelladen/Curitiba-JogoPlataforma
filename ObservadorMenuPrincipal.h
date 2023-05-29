#pragma once
#include "Observador.h"
#include "MenuPrincipal.h"

class ObservadorMenuPrincipal : public Observador
{
private:
	MenuPrincipal* pMenuPrincipal; //dupla
public:
	ObservadorMenuPrincipal(MenuPrincipal* pMP);
	~ObservadorMenuPrincipal();


	void moveMouse(const Vector2f posMouse);
	void botaoMouseSolta(const Mouse::Button botaoMouse);

	// teclado=0 ou mouse

	/*
	// criar funções e funcionalidades pros botoes
	pGEstados->adicionarEstado( pGEstados->criarEstadoJogar(IDs::fase1) );
	*/
};

