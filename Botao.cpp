#include "Botao.h"

Botao::Botao(Vector2f pos, Vector2f tam, string t, const int tamTexto, Color c) :
	forma(),
	fonte(nullptr),
	texto(),
	cor(c)
{
	forma.setPosition(pos);
	forma.setSize(tam);
	forma.setFillColor(c);

	fonte = new Font();

	fonte->loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf");

	texto.setFont(*fonte);
	texto.setString(t);
	texto.setFillColor(Color::Black);
	texto.setOutlineColor(Color::White);
	texto.setOutlineThickness(1.f);
	texto.setCharacterSize(tamTexto);
	texto.setPosition(forma.getPosition().x + forma.getSize().x / 2.f - texto.getGlobalBounds().width / 2.f,
		forma.getPosition().y + forma.getSize().y / 2.f - texto.getGlobalBounds().height);
}

Botao::~Botao()
{
}

Vector2f Botao::getPosicao()
{
	return forma.getPosition();
}

void Botao::atualizarPosicao(Vector2f pos)
{
	forma.setPosition(pos);
	texto.setPosition(forma.getPosition().x + forma.getSize().x / 2.f - texto.getGlobalBounds().width / 2.f,
		forma.getPosition().y + forma.getSize().y / 2.f - texto.getGlobalBounds().height);
}

void Botao::selecionado()
{
	forma.setOutlineThickness(5.f);
	forma.setOutlineColor(Color::White);
}

void Botao::naoSelecionado()
{
	forma.setOutlineThickness(0.f);
}

void Botao::render()
{
	// Retangulo
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(forma);

	// Texto
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(texto);
}