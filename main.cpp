#include <iostream>
 using namespace std;
/*class Data{}
class Pessoa{
	//string nome
	//string endereco
	// int telefone
}
class Fisica: Pessoa{
	//int cpf
	//int rg
	//Data nascimento;
}
class Juridica: Pessoa{
	//int cnpj
	//string razaoSocial
	//int identificador
}
class Vendedor: Fisica{
	//int vendas
	//int salario
	//Data ingressao
	// senha
	//cadastrar cliente
	//alterar dados do cliente
	//checar carrinho de compras do cliente
	//fazer venda

}
class Gerente{
	//Alterar a senha do gerente
	//Cadastrar vendedor
	//Cadastrar Produto
	//Modificar Elementos(Produto, Cliente, Vendedor)
	//Remover Elementos
	//Visualizar Ranking de vendedores
	//Dar desconto
	}
class Cliente:virtual Fisica, virtual Juridica{
	//Buscar obra
	//Adicionar ao carrinho
	//Realize compra
	//Finalizar
}
*/
class Produto{
private:
	string nome;
	int id;
	float preco;
	int quantidade;
public:
	Produto(string nome, int id, float preco, int quantidade){
		this->nome = nome;
		this->id = id;
		this->preco = preco;
		this->quantidade = quantidade;
	}
	void setNome(string nome){
		this->nome = nome;
	}
	void setId(int id){
		this->id = id;
	}
	void setPreco(float preco){
		this->preco = preco;
	}
	 void setQuantidade(int quantidade){
		this->quantidade = quantidade;
	}
	string getNome(){
		return this->nome;
	}
	int getId(){
		return this->id;
	}
	float getPreco(){
		return this->preco;
	}
	int getQuantidade(int quantidade){
		return this->quantidade;
	}

};
/*class Obra: public Produto{
private:
	string genero;
	string editora;
public:
	Produto(string nome, int id, float preco, int quantidade) 
	Obra
	: Produto{string nome, int id, float preco, int quantidade}, genero{this->genero}, editora{this->editora}
	{}
}; */
int main(){
	Produto liquidificador("valita",555,25.90,10);
	cout << liquidificador.getNome();
}



/*
class Livro: Produto{
	string autor;
}
class Revista: Produtor{
	string publicador;
}*/
