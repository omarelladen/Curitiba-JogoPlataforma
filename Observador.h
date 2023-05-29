#pragma once
#include"stdafx.h"
#include"Gerenciador_Estados.h"

class Observador : public Ente
{
protected:
	//Gerenciador_Estados* pGEstados;

private:
	bool ativado;

public:
	Observador(IDs id);
	~Observador();

	bool getAtivado();

	//
	void setAtivado(bool ativar);

	void desenhar_se();
	void executar();

	//Recebe do Gerenciador de Eventos:

	// Teclado
	virtual void teclaPressionada(const Keyboard::Key tecla); // = 0
	virtual void teclaSolta(const Keyboard::Key tecla); // = 0

	// Mouse
	virtual void moveMouse(const Vector2f posMouse);
	virtual void botaoMouseSolta(const Mouse::Button botaoMouse);


};