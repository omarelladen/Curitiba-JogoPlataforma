#pragma once
#include"Gerenciador_Estados.h"
#include "Ente.h"//

namespace Observers
{
	class Observador : public Ente
	{
	protected:
		Gerenciador_Estados* pGEstados;

	private:
		bool ativado;

	public:
		Observador(IDs id);
		~Observador();

		void setAtivado(const bool ativar);
		const bool getAtivado() const;

		void executar();

		//Recebe do Gerenciador de Eventos:

		// Teclado
		virtual void teclaPressionada(const Keyboard::Key tecla) = 0;
		virtual void teclaSolta(const Keyboard::Key tecla) = 0;
	};
}