#pragma once
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
using namespace sf;
#include<iostream>
using namespace std;
#include "MenuPrincipal.h"

namespace Gerenciadores
{
	class Gerenciador_Estados;
}

class Jogo
{
private:
	Gerenciador_Eventos* gerenciador_eventos;
	Gerenciador_Grafico* gerenciador_grafico;
	Gerenciador_Estados* gerenciador_estados;

public:
	Jogo();
	~Jogo();

	void executar();
};

