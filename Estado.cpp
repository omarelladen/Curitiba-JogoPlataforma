#include "Estado.h"
using namespace Estados;

Estado::Estado(const IDs id) :
	Ente(id),
	pGerenciadorEstados(nullptr)
{
	pGerenciadorEstados = Gerenciador_Estados::getGerenciadorEstados();
}

Estado::~Estado()
{
	pGerenciadorEstados = nullptr;
}
