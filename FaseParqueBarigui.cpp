#include"FaseParqueBarigui.h"
using namespace Fases;

FaseParqueBarigui::FaseParqueBarigui() :
	Fase(IDs::fase_barigui)
{
}

FaseParqueBarigui::~FaseParqueBarigui()
{
}

void FaseParqueBarigui::criarMapa()
{
	ifstream arquivo;
	string linha;

	arquivo.open("C:/Users/felpi/Documents/Jogo_Simao/Curitiba/Mapas/MapaParqueBarigui.txt");

	
	if (!arquivo.is_open())
	{
		cout << "Erro ao abrir arquivo mapa" << endl;
		exit(1);
	}
	for (int j = 0; getline(arquivo, linha); j++)
		for (int i = 0; i < (int)linha.size(); i++)
			if (linha[i] != ' ')
				criarEntidade(linha[i], Vector2f((float)i, (float)j)); // criarEntidade da classe Fase
}

void FaseParqueBarigui::executar()
{
	gerenciadorColisoes->executar();
}