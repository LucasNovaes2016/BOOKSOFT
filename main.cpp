class Data{}
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
class Produto{
	//string nome
	// int id
	//float preco
	//int quantidade
}
class Obra: Produto{
	//string genero
	//string editora
}
class Livro: Produto{
	//string autor
}
class Revista: Produtor{
	//string publicador
}
