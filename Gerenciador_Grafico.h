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

		static Gerenciador_Grafico* pGerenciadorGrafico;

		Gerenciador_Grafico();
	public:
		~Gerenciador_Grafico();

		static Gerenciador_Grafico* getGerenciadorGrafico();

		RenderWindow* getJanela();

		void setCentro(Vector2f pos_jog);
		void limpaJanela();
		void desenhaNaJanela(RectangleShape body);
		void desenhaNaJanela(Text texto);
		void printaJogo();
		void fechaJanela();

		const Vector2f getCentroJanela() const;

		const bool VerificaSeJanelaAberta();
	};
}