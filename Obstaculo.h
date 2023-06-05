#pragma once
#include"Entidade.h"
using namespace Entidades;

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
			bool danoso;

		public:
			Obstaculo(const IDs id = {}, Vector2f pos = Vector2f(0.f, 0.f));
			~Obstaculo();

			virtual void executar() = 0;
			const bool getDanoso() const;
		};
	}
}