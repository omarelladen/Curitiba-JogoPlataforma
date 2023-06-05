#pragma once
#include<fstream>
using namespace std;
#include"Entidade.h"
#include"Capivara.h"
#include"Policial.h"
#include"Jacare.h"
#include"Capanga.h"
#include"ChefeMafia.h"
#include"Projetil.h"
#include"Plataforma.h"
#include"Bicicleta.h"
using namespace Obstaculos;
using namespace Entidades;
#include"ListaEntidades.h"
using namespace Listas;
#include"Fase.h"
using namespace Fases;

class SalvaJogo
{
private:
	ListaEntidades* listaEntidades;
	Fase* pFase;

public:
	SalvaJogo();
	~SalvaJogo();

	void save();
	void saveRelacoes();
	void recuperaSave();
	void recuperaRelacoes();
};
