#include "EstadoMenuPrincipal.h"

EstadoMenuPrincipal::EstadoMenuPrincipal():
	Estado(IDs::estadoMenuPrincipal)
{
	// Cria o Menu Principal
	menu_principal = new MenuPrincipal();///

}

EstadoMenuPrincipal::~EstadoMenuPrincipal()
{
}

void EstadoMenuPrincipal::executar()//id
{
	// n sei oq colocar aqui, talvez tipo se tivesse uma anima��o atras?????


	/* enquanto nao pressionou nenhum botao
	{
		if (menu_principal->botao_jogarFase1.pressionado())
		{
			//criar a fase 1(seus componentes)
			//empilhar => agora ela ser� executada

			Fase* pF = pGerenciadorEstados->getJogo()->getFase(1)
		}
	}
	*/
}
