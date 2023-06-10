#include"FaseParqueBarigui.h"
using namespace Fases;

FaseParqueBarigui::FaseParqueBarigui() :
	Fase(IDs::fase_barigui)
{
	// Textura Fundo
	if (!textura_fundo.loadFromFile("Fundo/fundo-barigui.jpg"))
	{
		cout << "Erro ao carregar a textura do fundo" << endl;
		exit(1);
	}
	fundo.setTexture(textura_fundo);
}

FaseParqueBarigui::~FaseParqueBarigui()
{
}

void FaseParqueBarigui::criarMapa()
{
	ifstream arquivo;
	string linha;

	arquivo.open("Mapas/MapaParqueBarigui.txt");

	
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
	fundo.setPosition(Vector2f(pJogador->getPosicao().x - 500, 50));
	Gerenciador_Grafico::getGerenciadorGrafico()->getJanela()->draw(fundo);

	gerenciadorColisoes->executar();
}