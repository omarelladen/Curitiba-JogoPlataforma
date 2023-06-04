#pragma once
#include "Ente.h"
#include "Gerenciador_Estados.h"

namespace Estados
{
	class Estado : public Ente
	{
	protected:
		Gerenciador_Estados* pGerenciadorEstados;

	public:
		Estado(const IDs id);
		~Estado();

		virtual void executar() = 0;
	};
}
