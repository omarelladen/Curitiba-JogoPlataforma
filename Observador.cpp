#include "Observador.h"

Observador::Observador(IDs id):
    Ente(id),
    ativado(true)
{
}

Observador::~Observador()
{
}

bool Observador::getAtivado()
{
    return ativado;
}

void Observador::setAtivado(bool ativar)
{
    if (ativar)
        ativado = true;
    else
        ativado = false;
}

void Observador::desenhar_se()
{
}

void Observador::executar()
{
}

void Observador::teclaPressionada(const Keyboard::Key tecla)
{
}

void Observador::teclaSolta(const Keyboard::Key tecla)
{
}

void Observador::moveMouse(const Vector2f posMouse)
{
}

void Observador::botaoMouseSolta(const Mouse::Button botaoMouse)
{
}
