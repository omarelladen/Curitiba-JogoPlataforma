#include "Menu.h"
using namespace Menus;

Menu::Menu(const IDs id) :
	Ente(id),
	titulo(),
	fonte(),
	centro_janela(),
	pGEstados(Gerenciador_Estados::getGerenciadorEstados()),
	pGEventos(Gerenciador_Eventos::getGerenciadorEventos()),
	opcao(1)
{
	centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();

	fonte.loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf");

	titulo.setFont(fonte);
	titulo.setFillColor(Color::Cyan);
	titulo.setOutlineColor(Color::White);
	titulo.setCharacterSize(80);
}

Menu::~Menu()
{
}

void Menu::operator++()
{
	opcao++;
}

void Menu::operator--()
{
	opcao--;
}

const int Menu::getOpcao() const
{
	return opcao;
}