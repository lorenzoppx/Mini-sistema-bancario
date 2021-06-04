#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

// Declara as bibliotecas
#include <string>
#include "imprimivel.h"
#include "contabancaria.h"

// Declara a classe ContaPoupanca
class ContaPoupanca : public virtual ContaBancaria, public virtual Imprimivel
{
	public:
		ContaPoupanca( int , double , double );
		void mostrarDados( );
		void depositar( double );
		int sacar( double );
	protected:
	private:
		double LimiteCredito;
};

#endif
