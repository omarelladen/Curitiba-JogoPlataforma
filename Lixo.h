#pragma once
#include"Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Lixo : public Obstaculo
		{
		private:
			int dano;
			int tempo_retardo;

		public:
			Lixo(Vector2f pos = Vector2f(0.f, 0.f));
			~Lixo();

			void inicializaAtributos();
			const int getDano() const;
			const int getTempoRetardo() const;
		};
	}
}
