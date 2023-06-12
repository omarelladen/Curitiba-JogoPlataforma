#pragma once
#include"Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Chao : public Obstaculo
		{
		private:
			double atrito;

		public:
			Chao(Vector2f pos = Vector2f(0.f, 0.f));
			~Chao();

			void inicializaAtributos();

			void setAtrito(const double atri);
			const double getAtrito() const;

			void executar();
		};
	}
}