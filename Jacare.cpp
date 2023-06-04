#include "Jacare.h"

Jacare::Jacare(Vector2f pos, Jogador* pJ):
	Inimigo(IDs::jacare, pos, pJ),
	nivel_mordida(0)
{
}

Jacare::~Jacare()
{
}