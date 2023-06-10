#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Gerenciador_Grafico.h"//
using namespace Gerenciadores;//

class Botao
{
private:
	//int estado;

	RectangleShape forma;

	Font* fonte;
	Text texto;
	Color cor;

public:
	Botao(Vector2f pos = Vector2f(0.f, 0.f), Vector2f tam = Vector2f(0.f, 0.f), string t = "", const int tamTexto = 25, Color c = Color::Black);
	~Botao();

	Vector2f getPosicao();

	const bool pressionado(Vector2f posMouse);

	void render();
};

