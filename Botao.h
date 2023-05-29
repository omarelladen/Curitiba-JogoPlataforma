#pragma once
#include "IDs.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Botao
{
private:
	int estado;

	RectangleShape forma;

	Font* fonte;
	Text texto;
	Color cor1;
	Color cor2;
	Color cor3;

public:
	Botao(float x, float y, float l, float h, Font* f, string t, Color c1, Color c2, Color c3);
	~Botao();

	const bool pressionado();

	void render(RenderTarget* target);
	void atualizar(Vector2f posMouse);

};

