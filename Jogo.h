#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "MenuPrincipal.h"
#include "Gerenciador_Estados.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Ente.h"
#include "Fase.h"
#include "Jogador.h"
using namespace std;
using namespace sf;



class Jogo
{
private:
	//MenuPrincipal* menu_principal; // com escolher fases, escolher personagem e mostra leaderboard


	// tirar talvez para deixar static:: :
	Gerenciador_Eventos* gerenciador_eventos;
	Gerenciador_Grafico* gerenciador_grafico;
	Gerenciador_Estados* gerenciador_estados;

	Jogador* jogador;


public:
	Jogo();
	~Jogo();

	

	void executar();

};

