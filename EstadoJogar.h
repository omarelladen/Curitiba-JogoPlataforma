#pragma once
#include "Estado.h"
#include "Fase.h"
#include "IDs.h"

class EstadoJogar : public Estado
{
private:
	Fase* fase; // agregado aqui
	Jogador* jogador;

public:
	EstadoJogar(IDs id_fase);
	~EstadoJogar();

	void executar();
};

