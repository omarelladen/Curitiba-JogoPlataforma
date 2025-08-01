#pragma once
#include"Fase.h"
#include"ObservadorFase.h"
#include"Gerenciador_Eventos.h"
#include<fstream>
#include<iostream>
using namespace std;


namespace Fases
{
	class FaseBeco : public Fase
	{
	private:
		Texture textura_fundo;
		Sprite fundo;

	public:
		FaseBeco();
		~FaseBeco();

		void criarEntidade(const char simbolo, Vector2f pos);

		void criarMapa();

		void executar();
	};
}