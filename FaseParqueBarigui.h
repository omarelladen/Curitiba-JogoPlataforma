#pragma once
#include"Fase.h"
#include"ObservadorFase.h"
#include"Gerenciador_Eventos.h"
#include<fstream>
#include<iostream>
using namespace std;

namespace Fases
{
	class FaseParqueBarigui : public Fase
	{
	private:
		// bool 

		// Fundo
		Texture textura_fundo;
		Sprite fundo;

	public:
		FaseParqueBarigui();
		~FaseParqueBarigui();

		void criarMapa();

		void executar();
	};
}
