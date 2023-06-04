#include "Observador.h"
using namespace Observers;

Observador::Observador(IDs id):
    Ente(id),
    ativado(true)
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
    // precisa ??? por causa do Ente??
}

void Observador::teclaPressionada(const Keyboard::Key tecla)
{
}

void Observador::teclaSolta(const Keyboard::Key tecla)
{
}


void Observador::botaoMouseSolta(Vector2f posMouse) // const Mouse::Button botaoMouse, 
{
}
