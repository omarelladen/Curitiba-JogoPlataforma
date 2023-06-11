#include"Gerenciador_Estados.h"
using namespace Gerenciadores;
#include"EstadoJogar.h"
#include"EstadoMenuPrincipal.h"
#include"EstadoMenuPause.h"
#include"EstadoMenuGameOver.h"
#include"EstadoRanking.h"
using namespace Estados;
#include"Jogo.h"


//Gerenciadores::
Gerenciador_Estados* Gerenciador_Estados::pGerenciadorEstados = nullptr;

Gerenciador_Estados::Gerenciador_Estados() :
	pJogo(nullptr),
	pilhaEstados()
{
}

Gerenciador_Estados::~Gerenciador_Estados()
{
	pJogo = nullptr;

	// limpar pilhaEstados
	for (int i = 0; i < (int)pilhaEstados.size(); i++)
	{
		Estado* estado = pilhaEstados.top();
		pilhaEstados.pop();
		if (estado)
		{
			delete (estado);
		}
	}
}

Gerenciador_Estados* Gerenciador_Estados::getGerenciadorEstados()
{
	if (pGerenciadorEstados == nullptr)
		pGerenciadorEstados = new Gerenciador_Estados();
	return pGerenciadorEstados;
}

Estado* Gerenciador_Estados::criarEstadoJogar(IDs id_fase)
{
	Estado* estado = new EstadoJogar(id_fase);
	return estado;
}

Estado* Gerenciador_Estados::criarEstadoMenuPrincipal()
{
	return static_cast<Estado*>(new EstadoMenuPrincipal());
}

Estado* Gerenciador_Estados::criarEstadoMenuPause()
{
	return static_cast<Estado*>(new EstadoMenuPause());
}

Estado* Gerenciador_Estados::criarEstadoMenuGameOver(Jogador* jog)
{
	return static_cast<Estado*>(new EstadoMenuGameOver(jog));
}

Estado* Gerenciador_Estados::criarEstadoRanking()
{
	return static_cast<Estado*>(new EstadoRanking());
}


void Gerenciador_Estados::removerEstado(int n) // n: numero de estados a serem desempilhados - mais reutilizável
{
	for (int i = 0; i < n; i++)
	{
		Estado* estado = pilhaEstados.top();
		pilhaEstados.pop();
		if (estado)
		{
			delete (estado);
		}
	}
}

void Gerenciador_Estados::addEstado(Estado* pE)
{
	if (pE)
		pilhaEstados.push(pE);
}

Estado* Gerenciador_Estados::getEstadoAtual()
{
	return pilhaEstados.top();
}

Jogo* Gerenciador_Estados::getJogo()
{
	if (pJogo)
		return pJogo;
	return nullptr;
}

void Gerenciador_Estados::executar()
{
	if (!pilhaEstados.empty() && pilhaEstados.top())
		pilhaEstados.top()->executar();
}