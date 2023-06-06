#include "Ente.h"

int Ente::cont(0);
Gerenciador_Grafico* Ente::window_manager(Gerenciador_Grafico::getGerenciadorGrafico());

Ente::Ente(const IDs id) :
	ID(id)
{
	cont++;
}

Ente::~Ente()
{
}

const IDs Ente::getID() const
{
	return ID;
}

Gerenciador_Grafico* Ente::getManager()
{
	return window_manager;
}

void Ente::setCont(const int con)
{
	cont = con;
}

int Ente::getCont()
{
	return cont;
}
