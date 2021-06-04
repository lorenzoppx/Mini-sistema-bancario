// Declara as bibliotecas
#include "contabancaria.h"
#include <iostream>
#include <string>

// Construtor
ContaBancaria::ContaBancaria( int conta_User, double saldo_User)
{
	//std::cout << "\t->construtor ContaBancaria() " << std::endl;
	
	this->conta = conta_User;
	this->saldo = saldo_User;
	
}

// Destrutor
ContaBancaria::~ContaBancaria( )
{
	//std::cout << std::endl << "\t->destrutor ContaBancaria() " << std::endl;
	
}

// Transferencia da conta atual para uma conta receptora que é argumento do método
void ContaBancaria::transferir( double valor, ContaBancaria* ContaReceptora )
{
	//std::cout << std::endl << "\t->transferir ContaBancaria() " << std::endl << std::endl;
	
	std::cout << "\tConta atual:" << this->conta << std::endl;
	std::cout << "\tConta receptora:" << (*ContaReceptora).conta << std::endl;
	
	if( this->sacar( valor ) )
	{
		(*ContaReceptora).depositar( valor );
		std::cout << std::endl << "\t-->transferencia aprovada.. " << std::endl;
	}
	
	else
	{
		std::cout << std::endl << "\t-->transferencia nao aprovada.. " << std::endl;
	}
	
}

// Retorna a conta, que é um dado protected
int ContaBancaria::get_conta( ) const
{
	
	return this->conta;
	
}
