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

			const bool getDanoso() const;

			virtual void salvar() = 0;
			virtual ListaEntidades* recuperar() = 0;
			virtual void executar() = 0;
		};
	}
}