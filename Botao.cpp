#include "Botao.h"

Botao::Botao(Vector2f pos, Vector2f tam, string t, Color c):
	forma(),
	fonte(nullptr),
	texto(),
	cor(c)
{
	forma.setPosition(pos);
	forma.setSize(tam);

	fonte = new Font();

	fonte->loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf"); //

	texto.setFont(*fonte);
	texto.setString(t);
	texto.setFillColor(Color::Black);
	texto.setOutlineColor(Color::Magenta);
	texto.setCharacterSize(25);
	texto.setPosition(forma.getPosition().x + forma.getSize().x / 2.f - texto.getGlobalBounds().width / 2.f,
					  forma.getPosition().y + forma.getSize().y / 2.f - texto.getGlobalBounds().height);

	forma.setFillColor(c);
}

Botao::~Botao()
{
}

const bool Botao::pressionado(Vector2f posMouse)
{
	return (forma.getGlobalBounds().contains(posMouse));
}

void Botao::render()
{
	// Retangulo
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaEnte(forma);

	// Texto
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(texto);
}