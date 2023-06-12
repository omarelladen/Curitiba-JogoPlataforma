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
	RectangleShape forma;

	Font fonte;
	Text texto;
	Color cor;

public:
	Botao(Vector2f pos, Vector2f tam, string t, const int tamTexto, Color c);
	Botao();
	~Botao();

	void atualizarPosicao(Vector2f pos);

	void selecionado();
	void naoSelecionado();

	void render();
};
