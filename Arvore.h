#pragma once
#include"Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Arvore : public Obstaculo
		{
		private:
			Texture textura_tronco;
			RectangleShape tronco;
			int altura;

		public:
			Arvore(Vector2f pos = Vector2f(0.f, 0.f));
			~Arvore();

			void inicializaAtributos();

			void setAltura(const int alt);
			const int getAltura() const;

			void executar();
		};
	}
}