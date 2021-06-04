// Declara as bibliotecas
#include <iostream>
#include "imprimivel.h"
#include "relatorio.h"

void Relatorio::gerarRelatorio( Imprimivel *obj1 )
{
	//std::cout << "\t->Relatorio" << std::endl << std::endl;
	
	(*obj1).mostrarDados( );
	
}

