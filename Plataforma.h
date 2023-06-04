#pragma once
#include"Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo
		{
		private:
			double atrito;

		public:
			Plataforma(Vector2f pos);
			~Plataforma();

			const double getAtrito() const;
			void executar();
		};
	}
}