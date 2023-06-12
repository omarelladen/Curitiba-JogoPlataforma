#include"Gerenciador_Estados.h"
using namespace Gerenciadores;
#include"EstadoJogar.h"
#include"EstadoMenuPrincipal.h"
#include"EstadoMenuPause.h"
#include"EstadoMenuGameOver.h"
using namespace Estados;
#include"Jogo.h"


//Gerenciadores::
Gerenciador_Estados* Gerenciador_Estados::pGerenciadorEstados = nullptr;

Gerenciador_Estados::Gerenciador_Estados() :
	pilhaEstados()
{
}

Gerenciador_Estados::~Gerenciador_Estados()
{
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

void Gerenciador_Estados::deleteEstado(const int n) // n: numero de estados a serem desempilhados e deletados
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

void Gerenciador_Estados::executar()
{
	if (!pilhaEstados.empty() && pilhaEstados.top())
		pilhaEstados.top()->executar();
}