#include "ListaObservadores.h"

ListaObservadores::ListaObservadores() :
	listaObservadores()
{
}

ListaObservadores::~ListaObservadores()
{
}

void ListaObservadores::notificaTeclaPressionada(const Keyboard::Key tecla)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores[i]->getAtivado())
			listaObservadores[i]->teclaPressionada(tecla);
}

void ListaObservadores::notificaTeclaSolta(const Keyboard::Key tecla)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores[i]->getAtivado())
			listaObservadores[i]->teclaSolta(tecla);
}

/*void ListaObservadores::notificarMouseSolta(Event::MouseMoveEvent mouse)// Mouse::Button botaoMouse,
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores[i]->getAtivado())
			listaObservadores[i]->botaoMouseSolta(Vector2f((float) mouse.x, (float) mouse.y)); //botaoMouse,  Vector2f(mouse.x, mouse.y)
}*/


void ListaObservadores::desativaObservadores()
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores[i]->getAtivado())
			listaObservadores[i]->setAtivado(false);
}

void ListaObservadores::addObservador(Observador* observador)
{
	listaObservadores.addElemento(observador);
}

void ListaObservadores::deleteObservador(Observador* observador)
{
	listaObservadores.deleteElemento(observador);
}

void ListaObservadores::ativaObservador(IDs id)
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
	{
		if (listaObservadores[i]->getID() == id)
		{
			if (!listaObservadores[i]->getAtivado())
			{
				listaObservadores[i]->setAtivado(true);
			}
		}
	}
}

const int ListaObservadores::getTamanho() const
{
	return listaObservadores.getTam();
}

Observador* ListaObservadores::operator[](int pos)
{
	return listaObservadores[pos];
}