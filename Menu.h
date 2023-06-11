#pragma once
#include"Gerenciador_Eventos.h"
#include"Ente.h"
#include<SFML/Graphics.hpp>
using namespace sf;

#define TAM_BOTOES_X 250.f
#define TAM_BOTOES_Y 70.f

namespace Menus
{
	class Menu : public Ente//
	{
	protected:
		Font fonte;
		Text titulo;
		Vector2f centro_janela;

		Gerenciador_Estados* pGEstados;
		Gerenciador_Eventos* pGEventos;

		int opcao;

	public:
		Menu(const IDs id = {});
		~Menu();

		void operator++();
		void operator--();

		const int getOpcao() const;

		virtual void selecionaBotao(const bool enter) = 0;
		virtual void desenhar_se() = 0;
		virtual void executar() = 0;
	};
}