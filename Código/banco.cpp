// Declara as bibliotecas
#include <iostream>
#include <string>
#include <vector>
#include "contabancaria.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include "banco.h"

void Banco::inserir( ContaBancaria* input )
{
	//std::cout << "\t->Inserir()" << std::endl << std::endl;
	
	// Adiciona a conta ao vetor
	lista.push_back( input );
}

// Remove conta bancaria no vetor
void Banco::remover( ContaBancaria* input )
{
	//std::cout << "\t->Remover()" << std::endl << std::endl;
	
	int NumeroConta = (*input).get_conta( );
	int j;
	for( j=0; j < lista.size( ) ; j++ )
	{
		int conta_da_lista_pos_j = ( *(lista[j]) ).get_conta( );
		if( NumeroConta == conta_da_lista_pos_j )
		{
			std::cout << "\tConta " << conta_da_lista_pos_j << " removida.." << std::endl;
			lista.erase( lista.begin() + j );
		}
	}
	//std::cout << "\t-->Conta inexistente.." << std::endl << std::endl;
	
}

// Procura conta no vetor
ContaBancaria* Banco::procurarConta( int NumeroConta )
{
	//std::cout << "\t->ProcurarConta()" << std::endl << std::endl;
	
	int j;
	for( j=0; j < lista.size() ; j++ )
	{
		int conta_da_lista_pos_j = ( *(lista[j]) ).get_conta( );
		if( NumeroConta == conta_da_lista_pos_j )
		{
			//std::cout << "\t-->Conta encontrada.." << std::endl << std::endl;
			return ( lista[j] );
		}
	}
	//std::cout << "\t-->Conta inexistente.." << std::endl << std::endl;
	
	return NULL;
}

// Imprime os dados de cada conta
void Banco::mostrarDados( )
{
	//std::cout << "\t->mostrarDados Banco()" << std::endl << std::endl;
	
	int j ;
	for( j=0; j < lista.size( ) ; j++ )
	{
		std::cout << "\t-->Conta " << j << std::endl;
		( *(lista[j]) ).mostrarDados( );
	}
	
}
