#include "Gerenciador_Eventos.h"

Gerenciador_Eventos* Gerenciador_Eventos::pGerenciadorEventos(nullptr);
ListaObservadores* Gerenciador_Eventos::listaObservadores(new ListaObservadores());

Gerenciador_Eventos::Gerenciador_Eventos()
{
}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
}

Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos()
{
	if (pGerenciadorEventos == nullptr)
		pGerenciadorEventos = new Gerenciador_Eventos();
	return pGerenciadorEventos;
}


void Gerenciador_Eventos::adicionarObservador(Observador* observador)
{
	listaObservadores->adicionarObservador(observador);
}


void Gerenciador_Eventos::ativaObservador(IDs id)
{
	listaObservadores->ativaObservador(id);
}

void Gerenciador_Eventos::desativaObservadores()
{
	listaObservadores->desativarObservadores();
}

void Gerenciador_Eventos::executar()
{
	sf::Event evento;
	Gerenciador_Grafico* pGrafico = Gerenciador_Grafico::getGerenciadorGrafico();
	while (pGrafico->getJanela()->pollEvent(evento))
	{
		// Teclado
		if (evento.type == Event::KeyPressed)
			listaObservadores->notificarTeclaPressionada(evento.key.code);
		else if (evento.type == Event::KeyReleased)
			listaObservadores->notificarTeclaSolta(evento.key.code);

		// Mouse
		else if (Mouse::isButtonPressed(Mouse::Left))//evento.type == Event::MouseButtonReleased
		{
			listaObservadores->notificarMouseSolta(evento.mouseMove);//evento.mouseButton.button
		}
		// Exit
		else if (evento.type == Event::Closed)
			pGrafico->fechaJanela();
	}
}