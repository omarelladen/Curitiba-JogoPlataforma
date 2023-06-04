#pragma once
#include "Inimigo.h"

class Jacare : public Inimigo
{
private:
	int nivel_mordida;
	//int tamanho;

public:
	Jacare(Vector2f pos = Vector2f(0.f, 0.f), Jogador* pJogador = nullptr);
	~Jacare();
};

