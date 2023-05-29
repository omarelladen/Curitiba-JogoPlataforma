#pragma once
#include "Fase.h"
#include "Gerenciador_Estados.h"
#include "ObservadorFase.h"
#include <fstream>
#include <iostream>
using namespace std;

class Fase1 : public Fase
{
private:
	ObservadorFase* observadorFase1;

public:
	Fase1();
	~Fase1();

	void criarMapa();

	void executar();
};

