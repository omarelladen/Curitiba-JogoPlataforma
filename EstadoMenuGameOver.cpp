#include"EstadoMenuGameOver.h"
using namespace Estados;

EstadoMenuGameOver::EstadoMenuGameOver(Jogador* jog) :
	Estado(IDs::estadoMenuGameOver)
{
	menu_game_over = new MenuGameOver(jog);
}

EstadoMenuGameOver::~EstadoMenuGameOver()
{
	delete menu_game_over;
	menu_game_over = nullptr;
}

void EstadoMenuGameOver::executar()
{
	menu_game_over->executar();
}