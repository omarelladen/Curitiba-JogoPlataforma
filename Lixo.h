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

			void salvar();
			ListaEntidades* recuperar();

			void setDano(const int d);
			const int getDano() const;

			void setTempoRetardo(const int tr);
			const int getTempoRetardo() const;

			void executar();
		};
	}
}
