#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

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

class Pessoa_fisica : public Pessoa
{	
public:
	Pessoa_fisica(Pessoa pessoa, CPF cpf, RG rg) :
	Pessoa{pessoa}, cpf_{cpf}, rg_{rg} {}
	Pessoa_fisica() : Pessoa{}, cpf_{}, rg_{} {}

	void leiaPessoa_F(){
		Pessoa::leiaPessoa();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
	}

	void mostrePessoa_F(){
		Pessoa::mostrePessoa();
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

class Pessoa_juridica : public Pessoa
{	
public:
	Pessoa_juridica(Pessoa pessoa, CNPJ cnpj, string razaosocial) :
	Pessoa{pessoa}, cnpj_{cnpj}, razaosocial_{razaosocial} {}
	Pessoa_juridica() : Pessoa{}, cnpj_{}, razaosocial_{} {}

	void leiaPessoa_J(){
		Pessoa::leiaPessoa();
		cout << " CNPJ: " << endl;
		cnpj_.leiaCNPJ();
		cout << " Razao Social: " << endl;
		cin >> razaosocial_;
	}

	void mostrePessoa_J(){
		Pessoa::mostrePessoa();
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

class Funcionario : public Pessoa_fisica{
public:
	Funcionario(Pessoa_fisica pessoa_f, Data dataContratacao, float salario) :
	Pessoa_fisica{pessoa_f}, dataContratacao_{dataContratacao}, salario_{salario} {}
	Funcionario() : Pessoa_fisica{}, dataContratacao_{}, salario_{0.0} {}

	void leiaFuncionario(){
		Pessoa_fisica::leiaPessoa_F();
		cout << " Data de Contratacao: " << endl;
		dataContratacao_.leiaData();
		cout << " Salario: ";
		cin >> salario_;
	}

	void mostreFuncionario(){
		Pessoa_fisica::mostrePessoa_F();
		cout << " Data de Contratacao: ";
		dataContratacao_.mostreData();
		cout << " Salario: R$ " << fixed << setprecision(2) << salario_ << endl;
	}

	float const obterSalario() const {
		return salario_;
	}
	void buscarProdutos();
	void adicionarCliente();
private:
	Data dataContratacao_;
	float salario_;
};

class Gerente : public Funcionario{
public:
	Gerente(Funcionario funcionario) :
	Funcionario{funcionario}{}
	Gerente(): Funcionario{}{}
	void leiaGerente(){
		Funcionario::leiaFuncionario()

	}
	void adicionarVendedor(Funcionario funcionario){
		funcionario.leiaFuncionario();
	};
	void modificarVendedor();
	void removerVendedor();
	void adicionarProduto();
	void modificarProduto();
	void removerProduto();
	void modificarCliente();
	void removerCliente();
private:
	vector<Funcionario> listaFuncionarios;
};

class ListaProdutos{

};

int main(){
	Funcionario f;
	f.leiaFuncionario();
	cout << endl;
	f.mostreFuncionario();
	cout << endl;
}
