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

void ListaObservadores::notificarMouseSolta(Event::MouseMoveEvent mouse)// Mouse::Button botaoMouse, 
{
	for (int i = 0; i < listaObservadores.getTam(); i++)
		if (listaObservadores.getClassOrigin(i)->getAtivado())
			listaObservadores.getClassOrigin(i)->botaoMouseSolta(Vector2f(mouse.x, mouse.y)); //botaoMouse,  Vector2f(mouse.x, mouse.y)
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
		if (listaObservadores[i]->getID() == id)
		{
			if (!listaObservadores[i]->getAtivado())
			{
				listaObservadores[i]->setAtivado(true);
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
	return listaObservadores[pos];
}
