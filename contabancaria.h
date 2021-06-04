#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

// Declara as bibliotecas
#include <string>

// Declara a classe ContaBancaria
class ContaBancaria
{
	public:
		ContaBancaria( int , double );
		~ContaBancaria( );
		virtual void depositar( double ) = 0; // funcao puramente virtual
		virtual int sacar( double ) = 0; // funcao puramente virtual
		virtual void mostrarDados( ) = 0; // funcao puramente virtual
		void transferir( double , ContaBancaria* ); 
		int get_conta( ) const;
	protected:
		int conta;
		double saldo;	
};


#endif
