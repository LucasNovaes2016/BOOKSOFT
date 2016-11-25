#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Data{
public:
	Data(int dia, int mes, int ano) : dia_{dia}, mes_{mes}, ano_{ano} {}
	Data(Data const& d) : dia_{d.dia_}, mes_{d.mes_}, ano_{d.ano_} {}
	Data() = default;

	void leiaData() {
		cout << " Dia: ";
		cin >> dia_;
		cout << " Mes: ";
		cin >> mes_;
		cout << " Ano: ";
		cin >> ano_;
	}
	void mostreData() { cout << dia_ << "/" << mes_ << "/" << ano_ << endl; }

private:
	int dia_;
	int mes_;
	int ano_;
};

class CPF{
public:
	CPF(string cpf) : cpf_{cpf} {}
	CPF(CPF const& c) : cpf_{c.cpf_} {}
	CPF() = default;

	void leiaCPF() {
		cout << " Informe CPF: ";
		cin >> cpf_;
	}
	void mostreCPF() { cout << " CPF: " << cpf_ << endl; }

	string const& obterCPF() const {
		return cpf_;
	}
private:
	string cpf_;
};

class CNPJ{
public:
	CNPJ(string cnpj) : cnpj_{cnpj} {}
	CNPJ(CNPJ const& c) : cnpj_{c.cnpj_} {}
	CNPJ() = default;

	void leiaCNPJ() {
		cout << " Informe CNPJ: ";
		cin >> cnpj_;
	}
	void mostreCNPJ() { cout << " CNPJ: " << cnpj_ << endl; }

	string const& obterCNPJ() const {
		return cnpj_;
	}
private:
	string cnpj_;
};

bool operator==(CPF const& cpf1, CPF const& cpf2){
	return cpf1.obterCPF() == cpf2.obterCPF();
}

class RG{
public:
	RG(string rg) : rg_{rg} {}
	RG(RG const& r) : rg_{r.rg_} {}
	RG() = default;

	void leiaRG(){
		cout << " Informe RG: ";
		cin >> rg_;
	}

	void mostreRG() { cout << " RG: " << rg_ << endl; }
private:
	string rg_;
};

class Telefone{
public:
	Telefone(string tel) : tel_{tel} {}
	Telefone(Telefone const& t) : tel_{t.tel_} {}
	Telefone() = default;

	void leiaTelefone(){
		cout << " Informe Telefone: ";
		getline(cin,tel_);;
	}

	void mostreTelefone() { cout << " Telefone: " << tel_ << endl; }
private:
	string tel_;
};

class Endereco{
public:
	Endereco(string numero, string rua, string bairro, string cep) : numero_{numero}, rua_{rua}, bairro_{bairro}, cep_{cep} {}
	Endereco(Endereco const& e) : numero_{e.numero_}, rua_{e.rua_}, bairro_{e.bairro_}, cep_{e.cep_} {}
	Endereco() = default;

	void leiaEndereco() {
		cout << " Número: ";
		getline(cin,numero_);
		cout << " Logradouro: ";
		getline(cin,rua_);
		cout << " Bairro: ";
		getline(cin,bairro_);
		cout << " CEP: ";
		getline(cin,cep_);
	}
	void mostreEndereco() { cout << rua_ << " , Nº " << numero_ << "\n Bairro:  " << bairro_  << ", " << cep_ << endl; }

private:
	string numero_;
	string rua_;
	string bairro_;
	string cep_;
};


class Pessoa{
public:
	Pessoa(string nome, Endereco endereco, Telefone telefone)
	: nome_{nome}, endereco_{endereco}, telefone_{telefone} {}
	Pessoa(Pessoa const& p)
	: nome_{p.nome_}, endereco_{p.endereco_}, telefone_{p.telefone_} {}
	Pessoa() = default;

	void leiaPessoa(){
		cout << "Nome: ";
		getline(cin, nome_);
		cout << " Informe o endereco: \n";
		endereco_.leiaEndereco();
		cout << " Informe o telefone: \n";
		telefone_.leiaTelefone();
	}

	void mostrePessoa(){
		cout << " Nome: " << nome_ << "\n Endereco: ";
		endereco_.mostreEndereco();
		telefone_.mostreTelefone();
	}

private:
	string nome_;
	Endereco endereco_;
	Telefone telefone_;
};

class Produto
{
public:
	Produto(string produto_nome, int quantidade, float preco) :
	produto_nome_{produto_nome} , quantidade_{quantidade}, preco_{preco} {}
	Produto(Produto const& produto)
	: produto_nome_{produto.produto_nome_}, preco_{produto.preco_}, quantidade_{produto.quantidade_} {}
	Produto() = default;

	void leiaProduto(){
		cout << " Nome: ";
		getline(cin,produto_nome_);
		cout << " Quantidade: ";
		cin >> quantidade_;
		cout << " Preco: ";
		cin >> preco_;
	}

	void mostreProduto(){
		cout << " Nome: " << produto_nome_ << endl;
		cout << " Quantidade: " << quantidade_ << endl;
		cout << " Preco: R$ " << fixed << setprecision(2) << preco_ << endl;
	}

private:
	string produto_nome_;
	float preco_;
	int quantidade_;
};

class Livro : public Produto
{
public:
	Livro(Produto produto, string editora, string volume, string livro_genero ) :
	Produto{produto}, editora_{editora}, volume_{volume} , livro_genero_{livro_genero} {}
	Livro() : Produto{}, editora_{}, volume_{}, livro_genero_{} {}

	void leiaLivro(){
		Produto::leiaProduto();
		cout << " Genero: ";
		getline(cin, livro_genero_);
		cout << " Volume: ";
		getline(cin, volume_);
		cout << " Editora: ";
		getline(cin, editora_);
	}

	void mostreLivro(){
		Produto::mostreProduto();
		cout << " Genero: " << livro_genero_ << endl;
		cout << " Volume: " << volume_ << endl;
		cout << " Editora: " << editora_ << endl;
	}

private:
	string editora_, volume_, livro_genero_;
};

class Revista : public Produto
{
public:
	Revista(Produto produto, string edicao, string publicador, string revista_genero ) :
	Produto{produto}, edicao_{edicao}, publicador_{publicador}, revista_genero_{revista_genero} {}
	Revista() : Produto{}, edicao_{}, publicador_{}, revista_genero_{} {}

	void leiaRevista(){
		Produto::leiaProduto();
		cout << " Genero: ";
		getline(cin, revista_genero_);
		cout << " Edicao: ";
		getline(cin, edicao_);
		cout << " Publicador: ";
		getline(cin, publicador_);
	}

	void mostreRevista(){
		Produto::mostreProduto();
		cout << " Genero: " << revista_genero_ << endl;
		cout << " Edicao: " << edicao_ << endl;
		cout << " Publicador: " << publicador_ << endl;
	}

private:
	string edicao_, publicador_, revista_genero_;
};

class Cliente : public Pessoa{
public:
	Cliente(Pessoa pessoa ) : Pessoa{pessoa} {}
	Cliente() : Pessoa{} {}

	void leiaCliente()
	{
		Pessoa::leiaPessoa();
	}

	void mostreCliente()
	{
		Pessoa::mostrePessoa();
	}
private:
};

class Cliente_fisico : public Cliente
{	
public:
	Cliente_fisico(Cliente cliente, CPF cpf, RG rg) :
	Cliente{cliente}, cpf_{cpf}, rg_{rg} {}
	Cliente_fisico() : Cliente{}, cpf_{}, rg_{} {}

	void leiaCliente_F(){
		Cliente::leiaCliente();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
	}

	void mostrePessoa_F(){
		Cliente::mostreCliente();
		cpf_.mostreCPF();
		rg_.mostreRG();
	}

	CPF const& obterCPF() const{
		return cpf_;
	}

private:
	CPF cpf_;
	RG rg_;
};

class Cliente_juridico : public Cliente
{	
public:
	Cliente_juridico(Cliente cliente, CNPJ cnpj, string razaosocial) :
	Cliente{cliente}, cnpj_{cnpj}, razaosocial_{razaosocial} {}
	Cliente_juridico() : Cliente{}, cnpj_{}, razaosocial_{} {}

	void leiaCliente_J(){
		Cliente::leiaCliente();
		cout << " CNPJ: " << endl;
		cnpj_.leiaCNPJ();
		cout << " Razao Social: " << endl;
		cin >> razaosocial_;
	}

	void mostreCliente_J(){
		Cliente::mostreCliente();
		cnpj_.mostreCNPJ();
		cout << " Razao Social: " << razaosocial_ << endl;
	}

	CNPJ const& obterCNPJ() const{
		return cnpj_;
	}

private:
	CNPJ cnpj_;
	string razaosocial_;
};

class Funcionario : public Pessoa{
public:
	Funcionario(Pessoa pessoa, Data dataContratacao, float salario) :
	Pessoa{pessoa}, dataContratacao_{dataContratacao}, salario_{salario} {}
	Funcionario() : Pessoa{}, dataContratacao_{}, salario_{0.0} {}

	void leiaFuncionario(){
		Pessoa::leiaPessoa();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
		cout << " Data de Contratacao: " << endl;
		dataContratacao_.leiaData();
		cout << " Salario: ";
		cin >> salario_;
	}

	void mostreFuncionario(){
		Pessoa::mostrePessoa();
		cpf_.mostreCPF();
		rg_.mostreRG();
		cout << " Data de Contratacao: ";
		dataContratacao_.mostreData();
		cout << " Salario: R$ " << fixed << setprecision(2) << salario_ << endl;
	}

	float const obterSalario() const {
		return salario_;
	}

	CPF const& obterCPF() const{
		return cpf_;
	}

private:
	CPF cpf_;
	RG rg_;
	Data dataContratacao_;
	float salario_;
};

int main(){
	Funcionario f;
	f.leiaFuncionario();
	cout << endl;
	f.mostreFuncionario();
	cout << endl;
}