#pragma once

#include"stdafx.h"

#include"Gerenciador_Grafico.h"
using namespace Gerenciadores;

#include<string>
using namespace std;

#include"IDs.h"

#include"stdafx.h"

class Ente
{
protected:
	const IDs ID;
	static int cont;
	static Gerenciador_Grafico* window_manager;

public:
	Ente(const IDs id);
	~Ente();

	virtual void desenhar_se() = 0;
	virtual void executar() = 0;
	const IDs getID() const;

	static Gerenciador_Grafico* getManager();
};