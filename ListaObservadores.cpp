#include "ListaObservadores.h"

ListaObservadores::ListaObservadores():
	listaObservadores()
{
}

ListaObservadores::~ListaObservadores()
{
}

void ListaObservadores::notificarTeclaPressionada(const Keyboard::Key tecla)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->teclaPressionada(tecla);
}

void ListaObservadores::notificarTeclaSolta(const Keyboard::Key tecla)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->teclaSolta(tecla);
}

void ListaObservadores::notificarMovimentoMouse(Event::MouseMoveEvent mouse)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->moveMouse(Vector2f(mouse.x, mouse.y));
}

void ListaObservadores::notificarMouseSolta(Mouse::Button botaoMouse)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->botaoMouseSolta(botaoMouse);
}


void ListaObservadores::desativarObservadores()
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->setAtivado(false);
}

void ListaObservadores::adicionarObservador(Observador* observador)
{
	listaObservadores.setElemento(observador);
}

void ListaObservadores::removerObservador(Observador* observador)
{
	listaObservadores.deleteElemento(observador);
}

void ListaObservadores::ativaObservador(IDs id)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
	{
		if (!listaObservadores.getClassOrigin(i)->getAtivado())
		{
			if (listaObservadores.getClassOrigin(i)->getID() == id)
			{
				listaObservadores.getClassOrigin(i)->setAtivado(true);
			}
		}
	}
}

int ListaObservadores::getTamanho()
{
	return listaObservadores.getTam();
}

Observador* ListaObservadores::operator[](int pos)
{
	return listaObservadores.getClassOrigin(pos);
}
