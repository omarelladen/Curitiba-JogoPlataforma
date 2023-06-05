#pragma once
#include"Estado.h"
#include"Fase.h"
using namespace Fases;
#include"IDs.h"
#include"FaseParqueBarigui.h"
#include"Policial.h"
#include"Capivara.h"//

namespace Estados
{
	class EstadoJogar : public Estado
	{
	private:
		Fase* fase; // agregado aqui

		Capivara* jogador1;
		//Policial* jogador2; // criaria outro jogador com seu observador

	public:
		EstadoJogar(const IDs id_fase = {});
		~EstadoJogar();

		void executar();
	};
}
