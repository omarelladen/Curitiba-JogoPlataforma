#include "Fase1.h"


Fase1::Fase1()
{
	// Cria seu Observador:
	observadorFase1 = new ObservadorFase(this); // this para setar la tambem

	// Adiciona o seu Observador na lista de Observadores
	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorFase1);


	// criar Mapa () ????

}

Fase1::~Fase1()
{
}

void Fase1::criarMapa()
{
	std::ifstream arquivo;
	string linha;

	arquivo.open("string_arquivo");
	if (!arquivo.is_open())
	{
		cout << "Erro ao abrir arquivo mapa" << endl;
		exit(1);
	}
	for (int j = 0; getline(arquivo, linha); j++)
		for (int i = 0; i < linha.size(); i++)
			if (linha[i] != ' ')
				criarEntidade(linha[i], Vector2f(i, j)); // criarEntidade da classe Fase
}

void Fase1::executar()
{

}
