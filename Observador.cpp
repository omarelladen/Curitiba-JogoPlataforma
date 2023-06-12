#include "Observador.h"
using namespace Observers;

Observador::Observador(const IDs id) :
    Ente(id),
    ativado(true),
    pGEstados(Gerenciador_Estados::getGerenciadorEstados())
{
}

Observador::~Observador()
{
}

void Observador::setAtivado(bool ativar)
{
    ativado = ativar;
}

const bool Observador::getAtivado() const
{
    return ativado;
}

void Observador::executar()
{
}