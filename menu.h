#ifndef MENU_H
#define MENU_H
// Declara as bibliotecas
#include <iostream>
#include <string>
#include <vector>
#include "contabancaria.h"
#include "contacorrente.h"
#include "contapoupanca.h"
#include "banco.h"

// Declara a classe Menu
class Menu
{
	public:
		void Start( );
		
		int Entrada( );
		void Opcao1( );
		void Opcao2( );
		void Opcao3( );
		void Opcao4( );
		void Opcao5( );
		
		void Deposito( ContaBancaria* );
		void Saque( ContaBancaria* );
		void Transfere( ContaBancaria* );
		
		int validaNumeroConta( );
		double validaSaldoConta( );
		double validaLimiteDeCredito( );
		double validaTaxaDeOperacao( );
		
		int validaNumeroPositivoInt( const std::string , int );
		int validaNumeroPositivoInt( const std::string );
		double validaNumeroPositivoDouble( const std::string );
		
		int Selecionar( ContaBancaria* );
		int CriarContaCorrente( ContaCorrente& );
		int CriarContaPoupanca( ContaPoupanca& );
    protected:
	private:
		Banco banco;
};

#endif
