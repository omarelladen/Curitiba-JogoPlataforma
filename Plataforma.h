#pragma once
#include"Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo
		{
		private:

		public:
			Plataforma(Vector2f tam_corpo = Vector2f(0.f, 0.f));
			~Plataforma();

			void executar();
		};
	}
}