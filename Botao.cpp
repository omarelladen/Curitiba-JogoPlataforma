#include "Botao.h"

Botao::Botao(Vector2f pos, Vector2f tam, string t, const int tamTexto, Color c):
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
	texto.setCharacterSize(tamTexto);
	texto.setPosition(forma.getPosition().x + forma.getSize().x / 2.f - texto.getGlobalBounds().width / 2.f,
					  forma.getPosition().y + forma.getSize().y / 2.f - texto.getGlobalBounds().height);
}

Botao::~Botao()
{
}

const bool Botao::pressionado(Vector2f posMouse)
{
	return ((posMouse.x >= forma.getPosition().x && posMouse.x <= forma.getPosition().x + forma.getSize().x)
		 && (posMouse.y >= forma.getPosition().y && posMouse.y <= forma.getPosition().y + forma.getSize().y));

	//return (forma.getGlobalBounds().contains(posMouse));
}

void Botao::render()
{
	// Retangulo
	Gerenciador_Grafico::getGerenciadorGrafico()->desenhaEnte(forma);

	// Texto
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(texto);
}