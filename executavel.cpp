// Declara as bibliotecas
#include <iostream>
#include "contabancaria.h"
#include "contacorrente.h"
#include "contapoupanca.h"
#include "relatorio.h"
#include "executavel.h"

// Construtor
Executavel::Executavel( )
{
	//std::cout << "\t->Executavel" << std::endl << std::endl;
	
	Relatorio mostrar;

	// ContaCorrente
	int conta = 777777777;
	double saldo = 0;
	double taxaDeOperacao = 2;
    ContaCorrente empresarial( conta, saldo , taxaDeOperacao );
    
    // ContaPoupanca
    conta = 700700700;
    double LimiteCredito = 100;
    ContaPoupanca pessoal( conta, saldo , LimiteCredito );
    
	// Deposita nas contas
	std::cout << std::endl << "\t----------Deposito na ContaPoupanca----------" << std::endl;
    empresarial.depositar( 50 );
    std::cout << "\t----------Deposito na ContaCorrente----------" << std::endl;
    pessoal.depositar( 50 );
    
	// Imprimi relatório
	mostrar.gerarRelatorio( &pessoal );
	mostrar.gerarRelatorio( &empresarial );
	
	// Saca nas contas
	std::cout << "\t----------Saca na ContaPoupanca----------" << std::endl;
    pessoal.sacar( 150 );
    std::cout << "\t----------Saca na ContaCorrente----------" << std::endl;
    empresarial.sacar( 50 );
	
	// Imprimi relatório
	mostrar.gerarRelatorio( &pessoal );
	mostrar.gerarRelatorio( &empresarial );
	
}

