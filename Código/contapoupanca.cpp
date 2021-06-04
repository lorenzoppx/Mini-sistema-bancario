// Declara as bibliotecas
#include "imprimivel.h"
#include "contabancaria.h"
#include "contapoupanca.h"
#include <iostream>

// Construtor
ContaPoupanca::ContaPoupanca( int conta_User, double saldo_User, double LimiteCredito_User ) : \
ContaBancaria( conta_User, saldo_User )
{ 
	//std::cout << "\t->construtor ContaPoupanca() " << std::endl << std::endl;
	
	this->LimiteCredito = LimiteCredito_User; 
};

// Imprime os dados referente a conta poupanca
void ContaPoupanca::mostrarDados( )
{
	//std::cout << "\t->mostrarDados() conta poupanca " << std::endl;
	
	std::cout << "\t-------------------------------" << std::endl;
	std::cout << "\t----Impressao ContaPoupanca----" << std::endl;
	std::cout << "\t-------------------------------" << std::endl;
	std::cout << "\t*Numero da conta: " << this->conta << std::endl;
	std::cout << "\t*Saldo: " << this->saldo << std::endl;
	std::cout << "\t*Limite De Credito: " << LimiteCredito << std::endl;
	std::cout << std::endl << "\t----------FimImpresao----------" << std::endl << std::endl;
	std::cout << std::endl;
	
}

// Adiciona um valor double à conta
void ContaPoupanca::depositar( double valor )
{
	//std::cout << "\t->depositar() conta poupanca " << std::endl;
	
	std::cout << "\t-->Valor a ser depositado: " << valor << std::endl;
	this->saldo += valor; 
	std::cout << "\t--->Operacao aprovada.. \n"<< std::endl;
	
}

// Retira um valor double à conta
int ContaPoupanca::sacar( double valor )
{
	//std::cout << "\t->sacar() conta poupanca " << std::endl;
	
	std::cout << "\t-->Saldo: " << this->saldo << std::endl;
	std::cout << "\t-->Valor a ser sacado: " << valor << std::endl;

	// Fora do credito especial
	if(  this->saldo >= valor )
	{
		this->saldo -= valor;
		std::cout << "\t--->Operacao aprovada.. \n"<< std::endl;
		return 1;
	}
	std::cout << "\t--->Operacao nao aprovada.. \n"<< std::endl;
	// Ja dentro do credito especial
	if( this->saldo < 0 )
	{
		if( ( -(this->saldo) ) >= LimiteCredito )
		{
			std::cout << "\t--->Credito especial nao aprovado.. \n"<< std::endl;
			return 0;
		}
	}
	// Credito especial
	if( valor <= (this->saldo + LimiteCredito ) )
	{
		std::cout << "\t--->Credito especial aprovado.. \n"<< std::endl;
		std::cout << "\t---->Operacao aprovada.. \n"<< std::endl;
		this->saldo -= valor;
		return 1;
	}
	// Else
	std::cout << "\t---->Operacao nao aprovada.. \n"<< std::endl;
	
	return 0;
}


