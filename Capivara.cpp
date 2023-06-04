#include "Capivara.h"

Capivara::Capivara(Vector2f pos) :
	Jogador(IDs::capivara, pos),
	nivel_cuspe(0),
	nivel_pulo(0.f)
{
}

Capivara::~Capivara()
{
}