#pragma once
#include "Obstaculo.h"
using namespace Obstaculos;

namespace Entidades
{
	namespace Obstaculos
	{
		class Bicicleta : public Obstaculo
		{
		private:
			Vector2f velocidade;
			int nivel_ricochete;

		public:
			Bicicleta(Vector2f pos = Vector2f(0.f, 0.f));
			~Bicicleta();

			void inicializaAtributos();

			void salvar();
			ListaEntidades* recuperar();

			void setVelocidade(Vector2f vel);
			const Vector2f getVelocidade() const;

			void setNivelRicochete(const int ricochete);
			const int getNivelRicochete() const;

			void mover();
			void executar();
		};
	}
}