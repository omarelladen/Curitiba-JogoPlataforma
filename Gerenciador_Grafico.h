#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gerenciadores
{
	class Gerenciador_Grafico
	{
	private:
		RenderWindow* janela;
		static Gerenciador_Grafico* pManager;

		Gerenciador_Grafico();
	public:
		~Gerenciador_Grafico();

		static Gerenciador_Grafico* getGerenciadorGrafico();

		RenderWindow* getJanela();

		void limpaJanela();
		void desenhaEnte(RectangleShape body);
		void mostraEnte();
		void fechaJanela();

		const bool VerificaSeJanelaAberta();
	};
}