#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Botao;

namespace Gerenciadores
{
	class Gerenciador_Eventos;

	class Gerenciador_Grafico
	{
	private:
		RenderWindow* janela;
		View camera;
		Font fonte;
		Text game_over;

		static Gerenciador_Grafico* pGerenciadorGrafico;

		Gerenciador_Grafico();
	public:
		~Gerenciador_Grafico();

		static Gerenciador_Grafico* getGerenciadorGrafico();

		RenderWindow* getJanela();

		void setCentro(Vector2f pos_jog);
		void limpaJanela();
		void desenhaEnte(RectangleShape body);
		void printaJogo();
		void fechaJanela();

		Vector2f getCentroJanela();

		const bool VerificaSeJanelaAberta();
	};
}