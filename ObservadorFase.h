#pragma once
#include "Observador.h"
#include "Fase.h"

class ObservadorFase : public Observador
{
private:
	Fase* pFase;

public:
	ObservadorFase(Fase* pF);
	~ObservadorFase();
	void teclaPressionada(const Keyboard::Key tecla);
	void teclaSolta(const Keyboard::Key tecla);
};

