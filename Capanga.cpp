#include "Capanga.h"

Capanga::Capanga(Vector2f pos, Jogador* pJ) :
	Inimigo(IDs::capanga, pos, pJ),
	nivel_estupidez(0)
{
	// pos_f e pos_i rand()
	// atributos rand()
}

Capanga::~Capanga()
{
}