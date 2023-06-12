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


void Gerenciador_Eventos::addObservador(Observador* observador)
{
	listaObservadores->addObservador(observador);
}


void Gerenciador_Eventos::ativaObservador(IDs id)
{
	listaObservadores->ativaObservador(id);
}

void Gerenciador_Eventos::desativaObservadores()
{
	listaObservadores->desativaObservadores();
}

void Gerenciador_Eventos::executar()
{
	Event evento;
	Gerenciador_Grafico* pGrafico = Gerenciador_Grafico::getGerenciadorGrafico();
	while (pGrafico->getJanela()->pollEvent(evento))
	{
		// Teclado
		if (evento.type == Event::KeyPressed)
			listaObservadores->notificaTeclaPressionada(evento.key.code);
		else if (evento.type == Event::KeyReleased)
			listaObservadores->notificaTeclaSolta(evento.key.code);

		// Exit
		else if (evento.type == Event::Closed)
			pGrafico->fechaJanela();
	}
}