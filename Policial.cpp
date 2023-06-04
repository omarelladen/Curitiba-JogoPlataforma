#include "Policial.h"

Policial::Policial(Vector2f pos) :
	Jogador(IDs::policial, pos),
	pente_arma(0),
	atirar(false)
{
}

Policial::~Policial()
{
}