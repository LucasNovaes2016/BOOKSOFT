#ifndef cliente_hpp
using namespace std; 

class Cliente : public Pessoa_fisica, Pessoa_juridica
{
public:
	Cliente(Pessoa_fisica pf, Pessoa_juridica pj/*, exclusividades de clientes*/);
	Cliente(); 
private:


};

#define cliente_hpp
#endif

/*Dúvidas: 

1) Como Cliente herda de Pessoa_fisica e Pessoa_juridica, que 
herdam de Pessoa, é preciso passar um objeto Pessoa para Cliente?
2) é preciso por "using namespace std;" aqui tb?
3)

*/