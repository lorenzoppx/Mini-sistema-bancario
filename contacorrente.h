#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

// Declara as bibliotecas
#include <string>
#include "imprimivel.h"
#include "contabancaria.h"

// Declara a classe ContaCorrente
class ContaCorrente : public virtual ContaBancaria, public virtual Imprimivel
{
	public:
		ContaCorrente( int , double , double );
		void mostrarDados( );
		void depositar( double );
		int sacar( double );
	protected:
	private:
		double taxaDeOperacao;
};

#endif
