#include "Gerenciador_Eventos.h"

Gerenciador_Eventos* Gerenciador_Eventos::pGerenciadorEventos = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos()
{
}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
}

Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos()
{
	if (pGerenciadorEventos == NULL)
		pGerenciadorEventos = new Gerenciador_Eventos();
	return pGerenciadorEventos;
}


void Gerenciador_Eventos::adicionarObservador(Observador* observador)
{
	listaObservadores->adicionarObservador(observador);
}

void Gerenciador_Eventos::removerObservador(Observador* observador)
{
}

void Gerenciador_Eventos::removerObservador(int pos)
{
}

void Gerenciador_Eventos::desativarObservadores()
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
		else if (evento.type = Event::MouseMoved)
			listaObservadores->notificarMovimentoMouse(evento.mouseMove);
		else if (evento.type = Event::MouseButtonReleased)
			listaObservadores->notificarMouseSolta(evento.mouseButton.button);

		// Exit
		else if (evento.type == Event::Closed)
			pGrafico->fechaJanela();
	}
}