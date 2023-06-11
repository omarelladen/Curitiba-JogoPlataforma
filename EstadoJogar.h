#pragma once
#include"Estado.h"
#include"Fase.h"
#include"IDs.h"
#include"FaseParqueBarigui.h"
#include"FaseBeco.h"
#include"Capivara.h"
using namespace Fases;

namespace Estados
{
	class EstadoJogar : public Estado
	{
	private:
		//Agregados aqui
		Fase* fase; 
		Capivara* jogador1;

	public:
		EstadoJogar(const IDs id_fase = {});
		~EstadoJogar();

		void salvarJogada();

		void executar();
	};
}
