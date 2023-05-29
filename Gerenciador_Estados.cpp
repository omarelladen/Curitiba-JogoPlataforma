#include "Gerenciador_Estados.h"

Gerenciador_Estados* Gerenciador_Estados::pGerenciadorEstados = nullptr;

Gerenciador_Estados::Gerenciador_Estados()
{

}

Gerenciador_Estados::~Gerenciador_Estados()
{
}

Gerenciador_Estados* Gerenciador_Estados::getGerenciadorEstado()
{
	if (pGerenciadorEstados == nullptr)
		pGerenciadorEstados = new Gerenciador_Estados();
	return pGerenciadorEstados;
}


Estado* Gerenciador_Estados::criarEstadoJogar(IDs id_fase)
{
	// melhorar: ConstrutorEstado
	Estado* estado = new EstadoJogar(id_fase);
	return estado;
}

Estado* Gerenciador_Estados::criarEstadoMenuPrincipal()
{
	Estado* estado = static_cast<Estado*>(new EstadoMenuPrincipal());
	return estado;
}

Estado* Gerenciador_Estados::criarEstadoMenuPause()
{
	Estado* estado = static_cast<Estado*>(new EstadoMenuPrincipal());
	return estado;
}


void Gerenciador_Estados::removerEstado()
{
}

void Gerenciador_Estados::adicionarEstado(Estado* pE)
{
	if (pE)
	{
		pilhaEstados.push(pE);
	}
}

void Gerenciador_Estados::getEstadoAtual()
{
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