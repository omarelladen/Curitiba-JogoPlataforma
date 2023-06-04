#pragma once
#include"Gerenciador_Grafico.h"
using namespace Gerenciadores;
#include<string>
using namespace std;
#include"IDs.h"
#include<iostream>
using namespace std;

class Ente
{
protected:
	const IDs ID;
	static int cont;
	static Gerenciador_Grafico* window_manager;

public:
	Ente(const IDs id = {});
	~Ente();

	const IDs getID() const;
	static Gerenciador_Grafico* getManager();

	virtual void executar() = 0;
};