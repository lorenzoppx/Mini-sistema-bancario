#ifndef BANCO_H
#define BANCO_H

// Declara as bibliotecas
#include <iostream>
#include <string>
#include <vector>
#include "contabancaria.h"
#include "imprimivel.h"

// Declara a classe Banco
class Banco : public virtual Imprimivel
{
	public:
		void inserir( ContaBancaria* );
		void remover( ContaBancaria* );
		ContaBancaria* procurarConta( int );
		void mostrarDados( );
	protected:
	private:
		std::vector <ContaBancaria*> lista;

};

#endif
