#include "ChefeMafia.h"

ChefeMafia::ChefeMafia(Vector2f pos, Jogador* pJ) :
	Inimigo(IDs::chefeMafia, pos, pJ),
	nivel_forca(0),
	num_capangas(0)
{
}

ChefeMafia::~ChefeMafia()
{
}