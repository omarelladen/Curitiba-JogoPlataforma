#pragma once
#include<string.h>
#include<fstream>
using namespace std;
#include"Ente.h"
#include"Gerenciador_Eventos.h"
#include"Botao.h"

namespace Observers
{
	class ObservadorRanking;
}
using namespace Observers;

class Ranking : public Ente
{
private:
	ObservadorRanking* observadorRanking;

	Botao* botao_voltar;

	Font fonte;
	vector<Text*> linhasRanking;

public:
	Ranking();
	~Ranking();

	void selecionaBotao(const bool enter);
	void atualizarPosicao();

	void construirRanking();

	void desenhar_se();
	void executar();
};

