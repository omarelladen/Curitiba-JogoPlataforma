#include "Botao.h"

Botao::Botao(float x, float y, float l, float h, Font* f, string t, Color c1, Color c2, Color c3):
	estado(1)
{
	forma.setPosition(Vector2f(x, y));
	forma.setSize(Vector2f(l, h));

	fonte = f;

	texto.setFont(*this->fonte);
	texto.setString(t);
	texto.setFillColor(Color::Red);
	texto.setCharacterSize(15);
	texto.setPosition(forma.getPosition().x / 2.f - texto.getGlobalBounds().width / 2.f,
		forma.getPosition().y / 2.f - texto.getGlobalBounds().width / 2.f);

	cor1 = c1;
	cor2 = c2;
	cor3 = c3;

	forma.setFillColor(c1);
}

Botao::~Botao()
{
}

const bool Botao::pressionado()
{
	return (estado == 3);
}

void Botao::render(RenderTarget* target) // gerenciador grafico chama ???
{
	target->draw(forma);
}

void Botao::atualizar(Vector2f posMouse) // vem a posicao do gerenciador_eventos (?)
{

	if (forma.getGlobalBounds().contains(posMouse))
	{
		estado = 2;

		if (Mouse::isButtonPressed(Mouse::Left)) // desacoplar
		{
			estado = 3;
		}
	}
	else
		estado = 1;

	switch (estado)
	{
	default:
		forma.setFillColor(cor1);
		break;

	case 1:
	{
		forma.setFillColor(cor1);
	}
		break;
	case 2:
	{
		forma.setFillColor(cor2);
	}
		break;
	case 3:
	{
		forma.setFillColor(cor3);
	}
		break;
	}
}
