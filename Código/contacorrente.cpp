// Declara as bibliotecas
#include <iostream>
#include <string>
#include "contacorrente.h"

// Construtor
ContaCorrente::ContaCorrente( int conta_User, double saldo_User, double taxaDeOperacao_User ) : \
ContaBancaria( conta_User, saldo_User )
{ 
	//std::cout << "\t->construtor ContaCorrente() " << std::endl << std::endl;
	
	this->taxaDeOperacao = taxaDeOperacao_User; 
};

// Imprime os dados referente a conta corrente
void ContaCorrente::mostrarDados( )
{
	//std::cout << "\t->mostrarDados() conta corrente" << std::endl;
	
	std::cout << "\t-------------------------------" << std::endl;
	std::cout << "\t----Impressao ContaCorrente----" << std::endl;
	std::cout << "\t-------------------------------" << std::endl;
	std::cout << "\t*Numero da conta: " << this->conta << std::endl;
	std::cout << "\t*Saldo: " << this->saldo << std::endl;
	std::cout << "\t*Taxa De Operacao: " << taxaDeOperacao << std::endl;
	std::cout << std::endl << "\t----------FimImpresao----------" << std::endl << std::endl;
	std::cout << std::endl;
	
}

// Adiciona um valor double à conta
void ContaCorrente::depositar( double valor )
{
	//std::cout << "\t->depositar() " << std::endl;
	
	std::cout << "\t-->Valor a ser depositado: " << valor << std::endl;
	this->saldo += valor; 
	std::cout << "\t--->Operacao aprovada.. \n"<< std::endl;
}

// Retira um valor double à conta
int ContaCorrente::sacar( double valor )
{
	//std::cout << "\t->sacar() conta corrente" << std::endl;
	
	std::cout << "\t-->Saldo: " << this->saldo << std::endl;
	std::cout << "\t-->Valor a ser sacado: " << valor << std::endl;
	if( valor <= ( this->saldo - this->taxaDeOperacao ) )
	{
		this->saldo -= valor + this->taxaDeOperacao;
		std::cout << "\t--->Operacao aprovada.. \n"<< std::endl;
		return 1;
	}
	//else
	std::cout << "\t--->Operacao nao aprovada.. \n"<< std::endl;
	
	return 0;
}
