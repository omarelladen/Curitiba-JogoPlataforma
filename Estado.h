#pragma once
#include "Ente.h"
#include "Gerenciador_Estados.h"

class Estado : public Ente
{
protected:
	Gerenciador_Estados* pGerenciadorEstados;

public:
	Estado(const IDs id);
	~Estado();

	void desenhar_se();
	virtual void executar() = 0;
};

