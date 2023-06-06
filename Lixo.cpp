#include"ListaEntidades.h"
#include"Lixo.h"

Lixo::Lixo(Vector2f pos):
	Obstaculo(IDs::lixo, pos),
	dano(0),
	tempo_retardo(0)
{
	inicializaAtributos();
}

Lixo::~Lixo()
{
	delete pListaEntidades;
	pListaEntidades = nullptr;
}

void Lixo::inicializaAtributos()
{
	setTamanho(Vector2f(40.f, 50.f));

	time_t t;
	srand((unsigned)time(&t));

	dano = rand() % 3 + 1;
	tempo_retardo = rand() % 3 + 3;
}

void Lixo::salvar()
{
	ofstream SalvaLixo("SaveLixo.dat", ios::out);

	if (!SalvaLixo)
	{
		cerr << "Arquivo nao pode ser aberto" << endl;
		exit(1);
	}

	SalvaLixo << posicao.x << ' '
		<< posicao.y << ' '
		<< dano << ' '
		<< tempo_retardo << endl;

	SalvaLixo.close();
}

ListaEntidades* Lixo::recuperar()
{
	ifstream RecuperaSaveLixo("SaveArvore.dat", ios::in);

	if (!RecuperaSaveLixo)
	{
		cerr << "Arquivo nao pode ser aberto" << endl;
		exit(1);
	}

	pListaEntidades = new ListaEntidades();
	Lixo* pLixo = nullptr;
	Vector2f pos;
	int dano;
	int tr; //tempo_retardo

	while (RecuperaSaveLixo >> pos.x >> pos.y >> dano >> tr)
	{
		pLixo = new Lixo(pos);
		if (pLixo)
		{
			pLixo->setDano(dano);
			pLixo->setTempoRetardo(tr);
			pListaEntidades->addEntidade(static_cast<Entidade*>(pLixo));
		}
	}
	RecuperaSaveLixo.close();

	return pListaEntidades;
}

void Lixo::setDano(const int d)
{
	dano = d;
}

const int Lixo::getDano() const
{
	return dano;
}

void Lixo::setTempoRetardo(const int tr)
{
	tempo_retardo = tr;
}

const int Lixo::getTempoRetardo() const
{
	return tempo_retardo;
}

void Lixo::executar()
{
	desenhar_se();
}
