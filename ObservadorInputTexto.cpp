#include "ObservadorInputTexto.h"
using namespace Observers;

ObservadorInputTexto::ObservadorInputTexto():
	Observador(IDs::inputTexto),
	texto(""),
     escrevendo(true)
{
}

ObservadorInputTexto::~ObservadorInputTexto()
{
}

void ObservadorInputTexto::resetaTexto()
{
    texto = "";
}

string ObservadorInputTexto::getTexto()
{
    return texto;
}

const bool ObservadorInputTexto::getEscrevendo() const
{
    return escrevendo;
}

char ObservadorInputTexto::tranformaTeclaEmCaractere(const Keyboard::Key tecla)
{
    switch (tecla)
    {
    case Keyboard::Q:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'Q';
        else
            return 'q';
    }
    break;

    case Keyboard::W:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'W';
        else
            return 'w';
    }
    break;

    case Keyboard::E:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'E';
        else
            return 'e';
    }
    break;

    case Keyboard::R:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'R';
        else
            return 'r';
    }
    break;

    case Keyboard::T:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'T';
        else
            return 't';
    }
    break;

    case Keyboard::Y:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'Y';
        else
            return 'y';
    }
    break;

    case Keyboard::U:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'U';
        else
            return 'u';
    }
    break;

    case Keyboard::I:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'I';
        else
            return 'i';
    }
    break;

    case Keyboard::O:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'O';
        else
            return 'o';
    }
    break;

    case Keyboard::P:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'P';
        else
            return 'p';
    }
    break;

    case Keyboard::A:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'A';
        else
            return 'a';
    }
    break;

    case Keyboard::S:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'S';
        else
            return 's';
    }
    break;

    case Keyboard::D:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'D';
        else
            return 'd';
    }
    break;

    case Keyboard::F:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'F';
        else
            return 'f';
    }
    break;

    case Keyboard::G:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'G';
        else
            return 'g';
    }
    break;

    case Keyboard::H:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'H';
        else
            return 'h';
    }
    break;

    case Keyboard::J:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'J';
        else
            return 'j';
    }
    break;

    case Keyboard::K:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'K';
        else
            return 'k';
    }
    break;

    case Keyboard::L:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'L';
        else
            return 'l';
    }
    break;

    case Keyboard::Z:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'Z';
        else
            return 'z';
    }
    break;

    case Keyboard::X:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'X';
        else
            return 'x';
    }
    break;

    case Keyboard::C:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'C';
        else
            return 'c';
    }
    break;

    case Keyboard::V:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'V';
        else
            return 'v';
    }
    break;

    case Keyboard::B:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'B';
        else
            return 'b';
    }
    break;

    case Keyboard::N:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'N';
        else
            return 'n';
    }
    break;

    case Keyboard::M:
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
            return 'M';
        else
            return 'm';
    }
    break;

    default:
        break;
    }

    return ' ';
}

void ObservadorInputTexto::teclaPressionada(const Keyboard::Key tecla)
{
}

void ObservadorInputTexto::teclaSolta(const Keyboard::Key tecla)
{
    if (tecla == Keyboard::Enter)
        escrevendo = false;

    if (escrevendo)
    {
        if (tecla == Keyboard::BackSpace) 
        {
            if (texto.size() > 0)
                texto.pop_back();
        }

        else if (tecla == Keyboard::Space)
        {
            texto += " ";
        }
        else
        {
            texto += tranformaTeclaEmCaractere(tecla);;
        }
    }
}
