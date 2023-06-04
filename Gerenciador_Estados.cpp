#include "Gerenciador_Estados.h"
using namespace Gerenciadores;
#include "EstadoJogar.h"
#include "EstadoMenuPrincipal.h"
using namespace Estados;
#include "Jogo.h"


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
	for (int i = 0; i < pilhaEstados.size(); i++)
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


Estado* Gerenciador_Estados::criarEstadoJogar(IDs id_fase) //(, bool dupla)
{
	//Ver onde esta sendo desalocado
	// melhorar: ConstrutorEstado
	Estado* estado = new EstadoJogar(id_fase); //(, bool dupla)
	return estado;
}

Estado* Gerenciador_Estados::criarEstadoMenuPrincipal()
{
	//Ver onde esta sendo desalocado
	Estado* estado = static_cast<Estado*>(new EstadoMenuPrincipal());
	return estado;
}

Estado* Gerenciador_Estados::criarEstadoMenuPause()
{
	//Ver onde esta sendo desalocado
	Estado* estado = static_cast<Estado*>(new EstadoMenuPrincipal());
	return estado;
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

void Gerenciador_Estados::adicionarEstado(Estado* pE)
{
	if (pE)
		pilhaEstados.push(pE);
}

Jogo* Gerenciador_Estados::getJogo()
{
	if (pJogo)
		return pJogo;
}

void Gerenciador_Estados::executar()
{
	if (!pilhaEstados.empty())
		pilhaEstados.top()->executar();
}