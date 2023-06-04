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

	fonte->loadFromFile("C:/Users/User/Desktop/tecprog2023.1/TesteJogo/TesteJogo/Fonte/SparkyStonesRegular-BW6ld.ttf"); //

	texto.setFont(*this->fonte);
	texto.setString(t);
	texto.setFillColor(Color::White);
	texto.setCharacterSize(15);
	texto.setPosition(forma.getPosition().x / 2.f - texto.getGlobalBounds().width / 2.f,
		forma.getPosition().y / 2.f - texto.getGlobalBounds().width / 2.f);

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
