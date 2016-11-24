#include "cliente.hpp"

Cliente::Cliente(Pessoa_fisica pf, Pessoa_juridica pj/*, exclusividades de clientes*/) 
	: Pessoa_fisica{pf}, Pessoa_fisica{pj}/*, exclusividades de clientes*/ {}

Cliente::Cliente()
	: Pessoa_fisica{}, Pessoa_juridica {}/*, exclusividades de clientes*/ {}