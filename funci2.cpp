#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <deque>
#include <sstream>

using namespace std;

float toFloat(string s) {
  float r = 0;
  istringstream ss(s);
  ss >> r;
  return r;
}


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

	string obterData() 
	{
		ostringstream os_data; 
		string data;
		if(dia_ < 10)
		{
			if(mes_ < 10)
			{
				os_data << "0" << dia_ << "/0" << mes_ << "/" << ano_;
				data = os_data.str();
				return data;
			}
			else
			{
				os_data << "0" << dia_ << "/" << mes_ << "/" << ano_;
				data = os_data.str();
				return data;
			}
			
		}
		else if(mes_ < 10)
		{
			os_data << dia_ << "/0" << mes_ << "/" << ano_;
			data = os_data.str();
			return data;
		}
		else
		{
			os_data << dia_ << "/" << mes_ << "/" << ano_;
			data = os_data.str();
			return data;
		}
		
	}

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

bool operator==(CNPJ const& cnpj1, CNPJ const& cnpj2){
	return cnpj1.obterCNPJ() == cnpj2.obterCNPJ();
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

	string obterRG() {return rg_; }
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

	string obterTelefone() {return tel_; }
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

	string obterRua() { return rua_; }
	string obterNumero() {return numero_; }
	string obterBairro() {return bairro_; }
	string obterCEP() {return cep_;}
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
		cin.ignore();
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

	string obterPessoaNome() {return nome_;}
	Endereco obterPessoaEndereco() { return endereco_;}
	Telefone obterPessoaTelefone() {return telefone_;}

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
		cin.ignore();
		cout << " Nome: ";
		getline(cin,produto_nome_);
		cin.ignore();
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

	string obterProdutoNome() {return produto_nome_;}
	float obterPreco() {return preco_;}
	int obterQuantidade() {return quantidade_;}

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
		cin.ignore();
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

	string obterLivroEditora() {return editora_;}
	string obterLivroVolume() {return volume_;}
	string obterLivroGenero() {return livro_genero_;}

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
		cin.ignore();
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

	string obterRevistaEdicao() {return edicao_;}
	string obterRevistaPublicador() {return publicador_;}
	string obterRevistaGenero() {return revista_genero_;}

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
		cin.ignore();
		Cliente::leiaCliente();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
	}

	void mostreCliente_F(){
		Cliente::mostreCliente();
		cpf_.mostreCPF();
		rg_.mostreRG();
	}

	CPF const& obterCPF() const{
		return cpf_;
	}
	RG obterClienteFRG() { return rg_;}
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
		cin.ignore();
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
	string obterRazaoSocial() { return razaosocial_;}
private:
	CNPJ cnpj_;
	string razaosocial_;
};

class Funcionario : public Pessoa{
public:
	Funcionario(Pessoa pessoa, CPF cpf, RG rg, Data dataContratacao, float salario) :
	Pessoa{pessoa}, cpf_{cpf}, rg_{rg} ,dataContratacao_{dataContratacao}, salario_{salario} {}
	Funcionario() : Pessoa{}, cpf_{}, rg_{}, dataContratacao_{}, salario_{0.0} {}

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
	RG obterRG() {return rg_;}
	Data obterData() { return dataContratacao_;}
private:
	CPF cpf_;
	RG rg_;
	Data dataContratacao_;
	float salario_;
};

class Gerente : public Funcionario
{
public:
	Gerente(Funcionario funcionario) : Funcionario{funcionario} {}
	Gerente() : Funcionario{} {}

	void leiaGerente(){
		Funcionario::leiaFuncionario();
	}

	void mostreGerente(){
		Funcionario::mostreFuncionario();
	}

	void inicializarProdutos()
	{
		string nome, str_quantidade, str_preco, revista_genero, livro_editora, livro_volume, livro_genero, revista_edicao ,revista_publicadora;
		int quantidade;
		float preco;
		ifstream arquivoLivros, arquivoRevistas, arquivoDiversos;
		arquivoLivros.open("produtos_livros.txt");
		arquivoRevistas.open("produtos_revistas.txt");
		arquivoDiversos.open("produtos_diversos.txt");
		/*while(!arquivoLivros.eof())
		{
			getline(arquivoLivros, nome);
			getline(arquivoLivros, str_quantidade);
			getline(arquivoLivros, str_preco);
			getline(arquivoLivros, livro_genero);
			getline(arquivoLivros, livro_volume);
			getline(arquivoLivros, livro_editora);
			
			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
        	size_t pos_genero = livro_genero.find(": ");
        	size_t pos_volume= livro_volume.find(": ");
        	size_t pos_editora = livro_editora.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 4);
        	livro_genero = livro_genero.substr(pos_genero + 2);
        	livro_volume = livro_volume.substr(pos_volume + 2);
        	livro_editora = livro_editora.substr(pos_editora + 2);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	Produto p(nome,quantidade,preco);
        	Livro l(p,livro_editora,livro_volume,livro_genero);
        	stockLivros_.push_back(l);
		}

		while(!arquivoRevistas.eof())
		{
			getline(arquivoRevistas, nome);
			getline(arquivoRevistas, str_quantidade);
			getline(arquivoRevistas, str_preco);
			getline(arquivoRevistas, revista_genero);
			getline(arquivoRevistas, revista_edicao);
			getline(arquivoRevistas, revista_publicadora);

			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
        	size_t pos_genero = revista_genero.find(": ");
        	size_t pos_edicao= revista_edicao.find(": ");
        	size_t pos_publicadora = revista_publicadora.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 4);
        	revista_genero = revista_genero.substr(pos_genero + 2);
        	revista_edicao = revista_edicao.substr(pos_edicao + 2);
        	revista_publicadora = revista_publicadora.substr(pos_publicadora + 2);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	Produto p(nome,quantidade,preco);
        	Revista r(p,revista_edicao,revista_publicadora,revista_genero);
        	stockRevistas_.push_back(r);

		}
		*/
		while(!arquivoDiversos.eof())
		{
			getline(arquivoDiversos, nome);
			getline(arquivoDiversos, str_quantidade);
			getline(arquivoDiversos, str_preco);

			

			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
   			
        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 4);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	cout << nome << endl;
			cout << str_quantidade << endl;
			cout << str_preco << endl;
        	//Produto p(nome,quantidade,preco);
        	//stockProdutos_.push_back(p);

		}

		arquivoLivros.close();
		arquivoRevistas.close();
		arquivoDiversos.close();
	}

	void inicializarFuncionarios()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg, data, salario;
		ifstream arquivoFuncionarios;
		arquivoFuncionarios.open("funcionarios.txt");
		while(!arquivoFuncionarios.eof())
		{
			getline(arquivoFuncionarios, nome);
			getline(arquivoFuncionarios, e_rua);
			getline(arquivoFuncionarios, e_num);
			getline(arquivoFuncionarios, e_bairro);
			getline(arquivoFuncionarios, e_cep);
			getline(arquivoFuncionarios, telefone);
			getline(arquivoFuncionarios, cpf);
			getline(arquivoFuncionarios, rg);
			getline(arquivoFuncionarios, data);
			getline(arquivoFuncionarios, salario);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cpf = cpf.find(": ");
        	size_t pos_rg = rg.find(": ");
        	size_t pos_data = data.find(": ");
        	size_t pos_salario = salario.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cpf = cpf.substr(pos_cpf + 2);
        	rg = rg.substr(pos_rg + 2);
        	data = data.substr(pos_data + 2);
        	salario = salario.substr(pos_salario + 4);


        	string str_dia, str_mes, str_ano;

        	str_dia = data.substr(0,2);
        	str_mes = data.substr(3,2);
        	str_ano = data.substr(6,4);

        	int dia, mes, ano;

        	dia = stoi(str_dia);
        	mes = stoi(str_mes);
        	ano = stoi(str_ano);

        	float salario_f = toFloat(salario);

        	Endereco e_f(e_num, e_rua, e_bairro, e_cep);
        	CPF cpf_f(cpf);
        	RG rg_f(rg);
        	Data data_f(dia,mes,ano);
        	Telefone tel_f(telefone);

        	Pessoa p(nome,e_f,tel_f);
        	Funcionario f_p(p,cpf_f,rg_f,data_f,salario_f);

        	cadastroFuncionario_.push_back(f_p);


		}

		arquivoFuncionarios.close();
	}

	void inicializarClientesF()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg;
		string blank_line;
		ifstream arquivoClientesF;
		arquivoClientesF.open("clientes_fisicos.txt");
		while(!arquivoClientesF.eof())
		{
			getline(arquivoClientesF, nome);
			getline(arquivoClientesF, e_rua);
			getline(arquivoClientesF, e_num);
			getline(arquivoClientesF, e_bairro);
			getline(arquivoClientesF, e_cep);
			getline(arquivoClientesF, telefone);
			getline(arquivoClientesF, cpf);
			getline(arquivoClientesF, rg);
			getline(arquivoClientesF, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cpf = cpf.find(": ");
        	size_t pos_rg = rg.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cpf = cpf.substr(pos_cpf + 2);
        	rg = rg.substr(pos_rg + 2);

        	CPF cpf_p(cpf);
        	RG rg_p(rg);
        	Endereco e_p(e_num, e_rua, e_bairro, e_cep);
        	Telefone tel_p(telefone);

        	Pessoa p(nome,e_p,tel_p);
        	Cliente c_p(p);
        	Cliente_fisico cf_p(c_p, cpf_p, rg_p);
        	cadastroClienteF_.push_back(cf_p);
		}

		arquivoClientesF.close();
	}

	void inicializarClientesJ()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cnpj, razaosocial;
		string blank_line;
		ifstream arquivoClientesJ;
		arquivoClientesJ.open("clientes_juridicos.txt");
		while(!arquivoClientesJ.eof())
		{
			getline(arquivoClientesJ, nome);
			getline(arquivoClientesJ, e_rua);
			getline(arquivoClientesJ, e_num);
			getline(arquivoClientesJ, e_bairro);
			getline(arquivoClientesJ, e_cep);
			getline(arquivoClientesJ, telefone);
			getline(arquivoClientesJ, cnpj);
			getline(arquivoClientesJ, razaosocial);
			getline(arquivoClientesJ, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cnpj = cnpj.find(": ");
        	size_t pos_razaosocial = razaosocial.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cnpj = cnpj.substr(pos_cnpj + 2);
        	razaosocial = razaosocial.substr(pos_razaosocial + 2);

        	CNPJ cnpj_j(cnpj);
        	Endereco e_p(e_num, e_rua, e_bairro, e_cep);
        	Telefone tel_p(telefone);

        	Pessoa p(nome,e_p,tel_p);
        	Cliente c_p(p);
        	Cliente_juridico cj_p(c_p, cnpj_j, razaosocial);
        	cadastroClienteJ_.push_back(cj_p);
		}

		arquivoClientesJ.close();
	}

	void mostrarCadastroClientesF()
	{
		int size = cadastroClienteF_.size();
		for(int i = 0; i < size; i++)
		{
			
			cadastroClienteF_[i].mostreCliente_F();
			cout << endl;
		}
	}

	void mostrarCadastroClientesJ()
	{
		int size = cadastroClienteJ_.size();
		for(int i = 0; i < size; i++)
		{
			
			cadastroClienteJ_[i].mostreCliente_J();
			cout << endl;
		}
	}

	void mostrarCadastroClientes()
	{
		mostrarCadastroClientesF();
		mostrarCadastroClientesJ();
	}

	void mostrarCadastroProdutosDiversos()
	{
		int size = stockProdutos_.size();
		for(int i = 0; i < size; i++)
		{

			stockProdutos_[i].mostreProduto();
			cout << endl;
		}
	}

	void mostrarCadastroLivros()
	{
		int size = stockLivros_.size();
		for(int i = 0; i < size; i++)
		{

			stockLivros_[i].mostreLivro();
			cout << endl;
		}
	}

	void mostrarCadastroRevistas()
	{
		int size = stockRevistas_.size();
		for(int i = 0; i < size; i++)
		{

			stockRevistas_[i].mostreRevista();
			cout << endl;
		}
	}

	void mostrarCadastroProdutos()
	{
		mostrarCadastroLivros();
		mostrarCadastroRevistas();
		mostrarCadastroProdutosDiversos();
	}

	void mostrarCadastroFuncionarios()
	{
		int size = cadastroFuncionario_.size();
		for(int i = 0; i < size; i++)
		{

			cadastroFuncionario_[i].mostreFuncionario();
			cout << endl;
		}
	}
	void adicionarCliente()
	{
		cout << "Qual o tipo do cliente? 1 - Físico | 2 - Jurídico" << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{adicionarClienteF();break;}
			case 2:{adicionarClienteJ();break;}
		}

		cout << endl;
	}
	void adicionarClienteF()
	{
		Cliente_fisico cf;
		cf.leiaCliente_F();
		cadastroClienteF_.push_back(cf);
		cout << "\nCliente adicionado com sucesso!" << endl;
		cout << endl;
		salvarClientesF();
	}
	void adicionarClienteJ()
	{
		Cliente_juridico cj;
		cj.leiaCliente_J();
		cadastroClienteJ_.push_back(cj);
		cout << "\nCliente adicionado com sucesso!" << endl;
		cout << endl;
		salvarClientesJ();
	}
	void adicionarFuncionario() 
	{
		Funcionario f;
		f.leiaFuncionario();
		cadastroFuncionario_.push_back(f);
		cout << "\nFuncionário adicionado com sucesso!" << endl;
		cout << endl;
		salvarFuncionarios();
	}
	void adicionarProduto()
	{
		cout << "Qual o tipo de produto? 1 - Livro | 2 - Revista | 3 - Diverso " << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{adicionarLivro(); break;}
			case 2:{adicionarRevista(); break;}
			case 3:{adicionarDiverso(); break;}
		}
		cout << endl;
	}

	void adicionarLivro()
	{
		Livro l;
		l.leiaLivro();
		stockProdutos_.push_back(l);
		cout << "\nProduto adicionado com sucesso!" << endl;
		cout << endl;
		salvarLivros();
	}
	void adicionarRevista()
	{
		Revista r;
		r.leiaRevista();
		stockProdutos_.push_back(r);
		cout << "\nProduto adicionado com sucesso!" << endl;
		cout << endl;
		salvarRevistas();
	}
	void adicionarDiverso()
	{
		Produto p;
		p.leiaProduto();
		stockProdutos_.push_back(p);
		cout << "\nProduto adicionado com sucesso!" << endl;
		cout << endl;
		salvarProdutosDiversos();
	}

	int buscarClienteF(string str_cpf)
	{
		CPF key(str_cpf);
		int size = cadastroClienteF_.size();

		for(int i = 0; i < size; i++)
		{
			if((cadastroClienteF_[i].obterCPF().obterCPF()).find(str_cpf))
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarClienteJ(string str_cnpj)
	{
		CNPJ key(str_cnpj);
		int size = cadastroClienteJ_.size();

		for(int i = 0; i < size; i++)
		{
			if(key == cadastroClienteJ_[i].obterCNPJ())
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarFuncionario(string str_cpf)
	{
		CPF key(str_cpf);
		int size = cadastroFuncionario_.size();

		for(int i = 0; i < size; i++)
		{
			if(key == cadastroFuncionario_[i].obterCPF())
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarProdutoDiverso(string str_nome)
	{
		
		int size = stockProdutos_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockProdutos_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	int buscarLivro(string str_nome)
	{
		
		int size = stockLivros_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockLivros_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	int buscarRevista(string str_nome)
	{
		
		int size = stockRevistas_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockRevistas_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	void removerProdutoDiverso()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarProdutoDiverso(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockProdutos_.erase(stockProdutos_.begin() + indice);
			cout << "Produto removido com sucesso!" << endl;
			cout << endl;
		}
	}

	void removerLivro()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarLivro(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockLivros_.erase(stockLivros_.begin() + indice);
			cout << "Produto removido com sucesso!" << endl;
			cout << endl;
		}
	}

	void removerRevista()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarRevista(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockRevistas_.erase(stockRevistas_.begin() + indice);
			cout << "Produto removido com sucesso!" << endl;
			cout << endl;
		}
	}

	void removerProduto()
	{
		int op;
		cout << "Qual tipo de produto deseja remover? 1 - Livro | 2 - Revista | 3 - Produto Diverso" << endl;
		cin >> op;
		switch(op)
		{
			case 1: {removerLivro();break;}
			case 2: {removerRevista();break;}
			case 3: {removerProdutoDiverso();break;}
		}
		cout << endl;
		
	}


	void removerFuncionario()
	{
		string key;
		cout << " Digite o cpf do funcionario que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		
		int indice = buscarFuncionario(key);

		if(indice == -1)
		{
			cout << "Funcionario não existe! " << endl;
		}
		else
		{
			cadastroFuncionario_.erase(cadastroFuncionario_.begin() + indice);
			cout << "Funcionario removido com sucesso!" << endl;
			cout << endl;
		}
	}
	void removerClienteF()
	{
		string key;
		cout << " Digite o cpf do cliente que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarClienteF(key);

		if(indice == -1)
		{
			cout << "Cliente não existe! " << endl;
		}
		else
		{
			cadastroClienteF_.erase(cadastroClienteF_.begin() + indice);
			cout << "Cliente removido com sucesso!" << endl;
			cout << endl;
		}
	}

	void removerClienteJ()
	{
		string key;
		cout << " Digite o cnpj do cliente que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarClienteJ(key);

		if(indice == -1)
		{
			cout << "Cliente não existe! " << endl;
		}
		else
		{
			cadastroClienteJ_.erase(cadastroClienteJ_.begin() + indice);
			cout << "Cliente removido com sucesso!" << endl;
			cout << endl;
		}
	}

	void removerCliente()
	{
		cout << "Qual o tipo do cliente? 1 - Físico | 2 - Jurídico" << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{removerClienteF();break;}
			case 2:{removerClienteJ();break;}
		}

		cout << endl;
	}

	void salvarClientesF()
	{
		ofstream clientesf;
		clientesf.open("clientes_fisicos.txt");
		int size = cadastroClienteF_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cpf,os_rg;
			os_nome << "Nome: " << cadastroClienteF_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroClienteF_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroClienteF_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroClienteF_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroClienteF_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroClienteF_[i].obterPessoaTelefone().obterTelefone();
			os_cpf << "CPF: " << cadastroClienteF_[i].obterCPF().obterCPF();
			os_rg << "RG: " << cadastroClienteF_[i].obterClienteFRG().obterRG();

			string nome, rua, numero, bairro, cep, telefone, cpf, rg;
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cpf = os_cpf.str();
			rg = os_rg.str();

			

			clientesf << nome << endl;
			clientesf << rua << endl;
			clientesf << numero << endl;
			clientesf << bairro << endl;
			clientesf << cep << endl;
			clientesf << telefone << endl;
			clientesf << cpf << endl;
			clientesf << rg << endl;
			
		}
		clientesf.close();
	}

	void salvarClientesJ()
	{
		ofstream clientesj;
		clientesj.open("clientes_juridicos.txt");
		int size = cadastroClienteJ_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cnpj,os_razaosocial;
			os_nome << "Nome: " << cadastroClienteJ_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroClienteJ_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroClienteJ_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroClienteJ_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroClienteJ_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroClienteJ_[i].obterPessoaTelefone().obterTelefone();
			os_cnpj << "CNPJ: " << cadastroClienteJ_[i].obterCNPJ().obterCNPJ();
			os_razaosocial << "Razão Social: " << cadastroClienteJ_[i].obterRazaoSocial();

			string nome, rua, numero, bairro, cep, telefone, cnpj, razaosocial;
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cnpj = os_cnpj.str();
			razaosocial = os_razaosocial.str();

			

			clientesj << nome << endl;
			clientesj << rua << endl;
			clientesj << numero << endl;
			clientesj << bairro << endl;
			clientesj << cep << endl;
			clientesj << telefone << endl;
			clientesj << cnpj << endl;
			clientesj << razaosocial << endl; 
			
		}
		clientesj.close();
	}

	void salvarClientes()
	{
		salvarClientesF();
		salvarClientesJ();
	}

	void salvarProdutosDiversos()
	{
		ofstream produtos_diversos;
		produtos_diversos.open("produtos_diversos.txt");
		int size = stockProdutos_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_produto_nome,os_produto_quantidade,os_produto_preco;
			os_produto_nome << "Nome: " << stockProdutos_[i].obterProdutoNome();
			os_produto_quantidade << "Quantidade: " << stockProdutos_[i].obterQuantidade();
			os_produto_preco << "Preço: R$" << stockProdutos_[i].obterPreco();
			

			string produto_nome, produto_quantidade, produto_preco;
			produto_nome = os_produto_nome.str();
			produto_quantidade = os_produto_quantidade.str();
			produto_preco = os_produto_preco.str();
			

			

			produtos_diversos << produto_nome << endl;
			produtos_diversos << produto_quantidade << endl;
			produtos_diversos << produto_preco << endl; 
			
		}
		produtos_diversos.close();
	}
	void salvarLivros()
	{
		ofstream produtos_livros;
		produtos_livros.open("produtos_livros.txt");
		int size = stockLivros_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_livro_nome,os_livro_quantidade,os_livro_preco, os_livro_genero, os_livro_volume, os_livro_editora;
			os_livro_nome << "Nome: " << stockLivros_[i].obterProdutoNome();
			os_livro_quantidade << "Quantidade: " << stockLivros_[i].obterQuantidade();
			os_livro_preco << "Preço: R$" << stockLivros_[i].obterPreco();
			os_livro_genero << "Gênero: " << stockLivros_[i].obterLivroGenero();
			os_livro_volume << "Volume: " << stockLivros_[i].obterLivroVolume();
			os_livro_editora << "Editora: " << stockLivros_[i].obterLivroEditora();
			

			string livro_nome, livro_quantidade, livro_preco, livro_genero, livro_volume, livro_editora;;

			livro_nome = os_livro_nome.str();
			livro_quantidade = os_livro_quantidade.str();
			livro_preco = os_livro_preco.str();
			livro_genero = os_livro_genero.str();
			livro_volume = os_livro_volume.str();
			livro_editora = os_livro_editora.str();			

			produtos_livros << livro_nome << endl;
			produtos_livros << livro_quantidade << endl;
			produtos_livros << livro_preco << endl;
			produtos_livros << livro_genero << endl;
			produtos_livros << livro_volume << endl;
			produtos_livros << livro_editora << endl;

			
		}
		produtos_livros.close();
	}
	void salvarRevistas()
	{
		ofstream produtos_revistas;
		produtos_revistas.open("produtos_revistas.txt");
		int size = stockRevistas_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_revistas_nome,os_revistas_quantidade,os_revistas_preco, os_revistas_genero, os_revistas_edicao, os_revistas_publicador;
			os_revistas_nome << "Nome: " << stockRevistas_[i].obterProdutoNome();
			os_revistas_quantidade << "Quantidade: " << stockRevistas_[i].obterQuantidade();
			os_revistas_preco << "Preço: R$" << stockRevistas_[i].obterPreco();
			os_revistas_genero << "Gênero: " << stockRevistas_[i].obterRevistaGenero();
			os_revistas_edicao << "Edição: " << stockRevistas_[i].obterRevistaEdicao();
			os_revistas_publicador << "Publicador: " << stockRevistas_[i].obterRevistaPublicador();
			

			string revistas_nome, revistas_quantidade, revistas_preco, revistas_genero, revistas_edicao, revistas_publicador;
			revistas_nome = os_revistas_nome.str();
			revistas_quantidade = os_revistas_quantidade.str();
			revistas_preco = os_revistas_preco.str();
			revistas_genero = os_revistas_genero.str();
			revistas_edicao = os_revistas_edicao.str();
			revistas_publicador = os_revistas_publicador.str();
			

			

			produtos_revistas << revistas_nome << endl;
			produtos_revistas << revistas_quantidade << endl;
			produtos_revistas << revistas_preco << endl;
			produtos_revistas << revistas_genero << endl;
			produtos_revistas << revistas_edicao << endl;
			produtos_revistas << revistas_publicador << endl;
			
		}
		produtos_revistas.close();
	}
	void salvarProdutos()
	{
		salvarProdutosDiversos();
		salvarLivros();
		salvarRevistas();
	}
	void salvarFuncionarios()
	{
		ofstream funcionarios;
		funcionarios.open("funcionarios.txt");
		int size = cadastroFuncionario_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cpf,os_rg, os_data, os_salario;
			os_nome << "Nome: " << cadastroFuncionario_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroFuncionario_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroFuncionario_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroFuncionario_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroFuncionario_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroFuncionario_[i].obterPessoaTelefone().obterTelefone();
			os_cpf << "CPF: " << cadastroFuncionario_[i].obterCPF().obterCPF();
			os_rg << "RG: " << cadastroFuncionario_[i].obterRG().obterRG();
			os_data << "Data de Contratação: " << cadastroFuncionario_[i].obterData().obterData();
			os_salario << "Salário: R$ " << cadastroFuncionario_[i].obterSalario();

			string nome, rua, numero, bairro, cep, telefone, cpf, rg, data, salario;
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cpf = os_cpf.str();
			rg = os_rg.str();
			data = os_data.str();
			salario = os_salario.str();

			

			funcionarios << nome << endl;
			funcionarios << rua << endl;
			funcionarios << numero << endl;
			funcionarios << bairro << endl;
			funcionarios << cep << endl;
			funcionarios << telefone << endl;
			funcionarios << cpf << endl;
			funcionarios << rg << endl;
			funcionarios << data << endl;
			funcionarios << salario << endl; 
			
		}
		funcionarios.close();
	}
	
	void alterarProdutos()
	{
		mostrarCadastroProdutos();
		cout << "Selecione a ação que deseja fazer: 1 - Adicionar Produto | 2 - Remover Produto" << endl;
		int op2;
		cin >> op2;
		switch(op2)
		{
			case 1:{adicionarProduto(); break;}
			case 2:{removerProduto(); break;}
		}

	}
	void alterarClientes()
	{
		mostrarCadastroClientes();
		cout << "Selecione a ação que deseja fazer: 1 - Adicionar Cliente | 2 - Remover Cliente" << endl;
		int op2;
		cin >> op2;
		switch(op2)
		{
			case 1:{adicionarCliente(); break;}
			case 2:{removerCliente(); break;}
		}
	}
	void alterarFuncionarios()
	{
		mostrarCadastroFuncionarios();
		cout << "Selecione a ação que deseja fazer: 1 - Adicionar Funcionario | 2 - Remover Funcionario" << endl;
		int op2;
		cin >> op2;
		switch(op2)
		{
			case 1:{adicionarFuncionario(); break;}
			case 2:{removerFuncionario(); break;}
		}
	}
	void escolha_sua_interacao()
	{
		cout << "Bem vindo a Booksoft!" << endl;
		cout << "Escolha com que deseja interagir: 1 - Produtos | 2 - Clientes | 3 - Funcionarios " << endl;
		int op1;
		cin >> op1;
		switch(op1)
		{
			case 1:{alterarProdutos(); break;}
			case 2:{alterarClientes(); break;}
			case 3:{alterarFuncionarios(); break;}
		}
	}
	void iniciar_programa()
	{
		escolha_sua_interacao();

	}

private:
	deque<Produto> stockProdutos_;
	deque<Livro> stockLivros_;
	deque<Revista> stockRevistas_;
	deque<Cliente_fisico> cadastroClienteF_;
	deque<Cliente_juridico> cadastroClienteJ_;
	deque<Funcionario> cadastroFuncionario_;

};


int main(){
	Gerente g;
	g.inicializarClientesF();
	g.inicializarClientesJ();
	g.inicializarFuncionarios();
	g.inicializarProdutos();
};