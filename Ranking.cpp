#include"ObservadorRanking.h"
#include"Ranking.h"

Ranking::Ranking():
	Ente(IDs::ranking),
	observadorRanking(nullptr),
	botao_voltar(nullptr),
	fonte(),
	linhasRanking()
{
	//Alocacao do observador
	observadorRanking = new ObservadorRanking(this);

	Gerenciador_Eventos::getGerenciadorEventos()->adicionarObservador(observadorRanking);

	fonte.loadFromFile("Fonte/SparkyStonesRegular-BW6ld.ttf");

	// Alocacao Botoes
	botao_voltar = new Botao(Vector2f(0.f, 0.f), Vector2f(250.f, 70.f), "Voltar", 25, Color::Green);

	botao_voltar->selecionado();
}

Ranking::~Ranking()
{
	delete observadorRanking;
	delete botao_voltar;

	for (int i = 0; i < (int)linhasRanking.size(); i++)
	{
		if (linhasRanking[i])
		{
			delete linhasRanking[i];
			linhasRanking[i] = nullptr;
		}
	}
	linhasRanking.clear();

	observadorRanking = nullptr;
	botao_voltar = nullptr;
}

void Ranking::selecionaBotao(const bool enter)
{
	if (enter)
	{
		//VOLTAR PARA O MENU PRINCIPAL

		Gerenciador_Eventos::getGerenciadorEventos()->desativaObservadores();

		Gerenciador_Eventos::getGerenciadorEventos()->ativaObservador(IDs::menuPrincipal);

		//Desempilha um estado (Ranking) pra voltar ao menu principal
		Gerenciador_Estados::getGerenciadorEstados()->removerEstado(1);
	}
}

void Ranking::atualizarPosicao()
{
	Vector2f centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();

	botao_voltar->atualizarPosicao(Vector2f(centro_janela.x - 125.f, centro_janela.y + 300.f));
}

void Ranking::construirRanking()
{
	ifstream arquivo("Ranking.dat", ios::in);;

	if (!arquivo) {
		ofstream novoArquivo("Ranking.dat", ios::out);
		novoArquivo.close();
	}

	int points;
	string name;
	string textString;
	string pointsString;

	Text* txt;

	for (int i = 0; i < 10; i++) {
		name = "";
		points = 0;
		pointsString = "";

		getline(arquivo, pointsString);
		getline(arquivo, name);

		textString = to_string((i + 1) / 10) + to_string((i + 1) % 10) + " - " + name + " ";

		if (pointsString.length() > 0) {

			points = stoi(pointsString);

			pointsString = to_string(points / 1000000);
			points %= 1000000;

			pointsString += to_string(points / 100000);
			points %= 100000;

			pointsString += to_string(points / 10000);
			points %= 10000;

			pointsString += to_string(points / 1000);
			points %= 1000;

			pointsString += to_string(points / 100);
			points %= 100;

			pointsString += to_string(points / 10);
			points %= 10;

			pointsString += to_string(points);
		}

		while (textString.length() + pointsString.length() < 50) {
			textString += ".";
		}

		txt = new Text();
		txt->setFont(fonte);
		txt->setCharacterSize(48);

		Vector2f centro_janela = Gerenciador_Grafico::getGerenciadorGrafico()->getCentroJanela();
		centro_janela.y /= 4.f;

		txt->setPosition(Vector2f(centro_janela.x, centro_janela.y + (txt->getGlobalBounds().height * i) + (10.f * i))); //
		txt->setFillColor(Color::Black);
		linhasRanking.push_back(txt);
	}

	arquivo.close();
}

void Ranking::desenhar_se()
{
	construirRanking();

	for (int i = 0; i < (int)linhasRanking.size(); i++)
	{
		if (linhasRanking[i])
		{
			Gerenciador_Grafico::getGerenciadorGrafico()->desenhaNaJanela(*(linhasRanking[i]));
		}
		else
		{
			cout << "Texto nulo em Ranking" << endl;
		}
	}

	botao_voltar->render();
}

void Ranking::executar()
{
	atualizarPosicao();
	desenhar_se();
}