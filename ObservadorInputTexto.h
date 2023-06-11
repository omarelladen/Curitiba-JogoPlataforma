#pragma once
#include "Observador.h"
#include<string>
using namespace std;

namespace Observers
{
    class ObservadorInputTexto : public Observador
    {
    private:
        string texto;
        bool escrevendo;

    public:
        ObservadorInputTexto();
        ~ObservadorInputTexto();

        void resetaTexto();
        string getTexto();

        const bool getEscrevendo() const;

        char tranformaTeclaEmCaractere(const Keyboard::Key tecla);

        void teclaPressionada(const Keyboard::Key tecla);
        void teclaSolta(const Keyboard::Key tecla);
    };
}
