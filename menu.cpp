// Declara as bibliotecas
#include <iostream>
#include <vector>
#include "menu.h"
#include "contabancaria.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include "banco.h"
#include "relatorio.h"

// Contem o loop que chama Entrada() at� que seu retorno seja igual a 5
void Menu::Start( )
{
	
	// Usando o operador * para pegar a inst�ncia atual
	while( (*this).Entrada() != 5 ){}
	
}

// Menu inicial
int Menu::Entrada( )
{
	
	// Declara vari�vel local
	int input = 0;
	
	// Interface entrada-sa�da
	std::cout << std::endl;
	std::cout << "\t------------------------------" << std::endl;
	std::cout << "\t-------------Menu-------------" << std::endl;
	std::cout << "\t------------------------------" << std::endl << std::endl;
	std::cout << "\t1.Criar conta" << std::endl;
	std::cout << "\t2.Selecionar conta" << std::endl;
	std::cout << "\t3.Remover conta" << std::endl;
	std::cout << "\t4.Gerar relatorio" << std::endl;
	std::cout << "\t5.Finalizar" << std::endl << std::endl;
	input = Menu::validaNumeroPositivoInt("\tOpcao: ");
	std::cout << std::endl << "\t------------FimMenu-----------" << std::endl << std::endl;
	std::cout << std::endl;
	
	// O switch chama cada respectiva opcao caso ela for v�lida
	switch( input )
	{
		case 0:
			std::cout << "\t\n Opcao invalida. \n" << std::endl;
			break;
		case 1:
			Menu::Opcao1( );
			break;
		case 2:
			Menu::Opcao2( );
			break;
		case 3:
			Menu::Opcao3( );
			break;
		case 4: 
			Menu::Opcao4( );
			break;
		case 5:
			std::cout << std::endl << "\t--------------Fim-------------" << std::endl << std::endl;
			break;
		default:
			std::cout << std::endl << "\tOpcao invalida." << std::endl << std::endl;
			break;
	}
	
	return input;
}

// Primeira opc�o
void Menu::Opcao1( )
{
	//std::cout << "\t->Opcao1()" << std::endl;
	
	// Declara��o vari�vel local
	int input = 0;
	
	// Interface entrada-sa�da
	std::cout << "\t------------------------------" << std::endl;
	std::cout << "\t---------Criar conta----------" << std::endl;
	std::cout << "\t------------------------------" << std::endl << std::endl;
	std::cout << "\t1.Conta poupanca" << std::endl;
	std::cout << "\t2.Conta corrente" << std::endl << std::endl;;
	input = Menu::validaNumeroPositivoInt("\tOpcao: ");
	std::cout << std::endl << "\t---------Criar conta----------" << std::endl << std::endl;
	
	// Instancias
	ContaPoupanca* obj1 = new ContaPoupanca( 0 , 0 , 0 );
	ContaCorrente* obj2 = new ContaCorrente( 0 , 0 , 0 );
	
	// Chama um switch com input ja validado
	switch( input )
	{
		case 1:
			if(  Menu::CriarContaPoupanca( *obj1 ) )
			{
				obj1->mostrarDados( );
				(this->banco).inserir( obj1 );
			}
			break;
		case 2:
			if(  Menu::CriarContaCorrente( *obj2 ) )
			{
				obj2->mostrarDados( );
				(this->banco).inserir( obj2 );
			}
			break;
		default:
		    std::cout << std::endl << "\tOpcao invalida." << std::endl << std::endl;
		    break;
	}
	
}

// Segunda opc�o
void Menu::Opcao2( )
{
	//std::cout << "\t->Opcao2()" << std::endl;
	
	// Declara��o vari�vel local
	int NumeroConta = 0;
	
	NumeroConta = Menu::validaNumeroConta( );
	ContaBancaria* pointer = banco.procurarConta( NumeroConta );
	
	// Testa se o ponteiro � diferente de NULL
	if( pointer )
    {
    	std::cout << std::endl << "\t->Conta encontrada.." << std::endl << std::endl;
		while( Menu::Selecionar( pointer )!=5 )
		{
			// A op��o 5 faz com que o loop se encerre e volte ao menu principal
		}
	}
	
	else
	{
		std::cout << std::endl << "\t->Conta inexistente.." << std::endl << std::endl;
	}
	
}

// Terceira opc�o
void Menu::Opcao3( )
{
	//std::cout << "\t->Opcao3()" << std::endl;	
	
	// Declara��o vari�vel local
	int NumeroConta = 0;
	
	NumeroConta = validaNumeroPositivoInt("\tInforme o numero da conta: ");
	ContaBancaria* pointer = banco.procurarConta( NumeroConta );
	
	// Testa se o ponteiro � diferente de NULL
	if( pointer )
	{
		banco.remover( pointer );
	}
	else
	{
		std::cout << std::endl << "\t->Conta inexistente.." << std::endl << std::endl;
	}
}

// Quarta op��o
void Menu::Opcao4( )
{
	//std::cout << "\t->Opcao4()" << std::endl;
	
	Relatorio output;
	output.gerarRelatorio( &banco );
	
}

// Quinta op��o
void Menu::Opcao5( )
{
	//std::cout << "\t->Opcao5()" << std::endl;
}

// Submenu selecionar
int Menu::Selecionar( ContaBancaria *pointer )
{
	// Declara��o vari�vel local
	int input = 0;
	
	// Interface entrada-sa�da
	std::cout << "\t------------------------------" << std::endl;
	std::cout << "\t----------Selecionar----------" << std::endl;
	std::cout << "\t------------------------------" << std::endl << std::endl;
	std::cout << "\t1.Depositar" << std::endl;
	std::cout << "\t2.Sacar" << std::endl;
	std::cout << "\t3.Transferir" << std::endl;
	std::cout << "\t4.Gerar relatorio" << std::endl;
	std::cout << "\t5.Retornar ao menu anterior" << std::endl << std::endl;
	input = Menu::validaNumeroPositivoInt("\tOpcao: ");
	std::cout << std::endl << "\t---------FimSelecionar--------" << std::endl << std::endl;
	std::cout << std::endl;
	
	// Chama um switch com input ja validado
	switch( input )
	{
		case 0:
			std::cout << std::endl << "\tOpcao invalida." << std::endl << std::endl;
			break;
		case 1:
			Menu::Deposito( pointer );
			break;
		case 2:
			Menu::Saque( pointer );
			break;
		case 3:
			Menu::Transfere( pointer );
			break;
		case 4:
			(*pointer).mostrarDados( );
		 	break;
		case 5:
			std::cout << std::endl << "\t----RetornandoAoMenuInicial----" << std::endl << std::endl;
			break;
		default:
			std::cout << std::endl << "\tOpcao invalida." << std::endl << std::endl;
			break;
	}
	
	return input;
}

// Recebe uma passagem por refer�ncia de ContaCorrente e realiza a respectiva opera��o
int Menu::CriarContaCorrente( ContaCorrente &conta_input )
{
	// Declara��o vari�veis locais
	int NumeroConta = 0;
	double SaldoConta = 0;
	double TaxaDeOperacaoConta = 0;
	
	// Interface entrada-sa�da
	std::cout << "\t------------------------------" << std::endl;
	std::cout << "\t------CriarContaCorrente------" << std::endl;
	std::cout << "\t------------------------------" << std::endl << std::endl;
    NumeroConta = Menu::validaNumeroConta( );
    
    // Testa se n�o existe uma conta com o numero informado
    if( !banco.procurarConta( NumeroConta ) )
    {
        SaldoConta = Menu::validaSaldoConta( );
		TaxaDeOperacaoConta = Menu::validaTaxaDeOperacao( );
		std::cout << std::endl << "\t---------FimCriarContaCorrente--------" << std::endl << std::endl;
		ContaCorrente conta_output( NumeroConta, SaldoConta, TaxaDeOperacaoConta );
		
		// Modifica o valor atrav�s da passagem por refer�ncia
		conta_input = conta_output;
		
		// Retorna 1 caso a cria��o de conta foi bem concluida com sucesso
		return 1;
	}
	std::cout << std::endl << "\t->Ja existe uma conta com o numero informado.." << std::endl << std::endl;

	// Retorna 0 caso a cria��o de conta n�o foi concluida com sucesso
	return 0;
}

// Recebe uma passagem por refer�ncia de ContaPoupanca e realiza a respectiva opera��o
int Menu::CriarContaPoupanca( ContaPoupanca &conta_input )
{
	// Declara��o vari�veis locais
	int NumeroConta = 0;
	double SaldoConta = 0;
	double LimiteDeCreditoConta = 0;
	
	// Interface entrada-sa�da
	std::cout << "\t------------------------------" << std::endl;
	std::cout << "\t------CriarContaPoupanca------" << std::endl;
	std::cout << "\t------------------------------" << std::endl << std::endl;
	NumeroConta = Menu::validaNumeroConta( );

	// Testa se n�o existe uma conta com o numero informado
	if( !banco.procurarConta( NumeroConta ) )
    {
	    SaldoConta = Menu::validaSaldoConta( );
	    LimiteDeCreditoConta = Menu::validaLimiteDeCredito( );
	    
		std::cout << std::endl << "\t---------FimCriarContaPoupanca--------" << std::endl << std::endl;
		ContaPoupanca conta_output( NumeroConta, SaldoConta, LimiteDeCreditoConta );
		
		// Modifica o valor atrav�s da passagem por refer�ncia
		conta_input = conta_output;
		
		// Retorna 1 caso a cria��o de conta foi bem concluida com sucesso
		return 1;
	}
	std::cout << std::endl << "\t->Ja existe uma conta com o numero informado.." << std::endl << std::endl;

	// Retorna 0 caso a cria��o de conta n�o foi concluida com sucesso
	return 0;
}

// Recebe um ponteiro de ContaBancaria e realiza a respectiva opera��o
void Menu::Deposito( ContaBancaria *pointer )
{
	// Declara��o vari�vel local
	double deposito = 0;
	
	// Testa se o ponteiro � diferente de NULL
	if( pointer )
    {
    	deposito = Menu::validaNumeroPositivoDouble("\tInforme o valor a ser depositado: ");
    	(*pointer).depositar( deposito );
    }
    
} 

// Recebe um ponteiro de ContaBancaria e realiza a respectiva opera��o
void Menu::Saque( ContaBancaria *pointer )
{
	// Declara��o vari�vel local
	double saque = 0;
	
	// Testa se o ponteiro � diferente de NULL
	if( pointer )
    {
		saque = Menu::validaNumeroPositivoDouble( "\tInforme o valor a ser sacado: " );
		(*pointer).sacar( saque );
    }
    
}

// Recebe um ponteiro de ContaBancaria e realiza a respectiva opera��o
void Menu::Transfere( ContaBancaria *pointer )
{
	// Declara��o vari�veis locais
	double transfere = 0;
	int NumeroContaDestino = 0;
	
	// Testa se o ponteiro � diferente de NULL
	if( pointer )
    {
        NumeroContaDestino = Menu::validaNumeroPositivoInt("\tInforme a conta de destino: ", 9);
    	ContaBancaria* pointer_conta_destino = banco.procurarConta(NumeroContaDestino);
    	
    	if ( pointer_conta_destino && pointer != pointer_conta_destino )
    	{
    		transfere = Menu::validaNumeroPositivoDouble("\tInforme o valor a ser transferido: ");
	    	(*pointer).transferir( transfere, pointer_conta_destino );
		}
		else
		{
			std::cout << std::endl << "\t->Conta de destino invalida.." << std::endl << std::endl;
		}
		
    }
    
}

// Exibe uma mensagem e chama o respectivo validador passando um limite fixo de caracteres, depois retorna o valor validado
int Menu::validaNumeroConta( )
{
	// Declara��o vari�vel local
	int NumeroConta = 0;
	NumeroConta = Menu::validaNumeroPositivoInt("\tInforme o numero da conta: ", 9);
	
	return NumeroConta;
}

// Exibe uma mensagem e chama o respectivo validador, depois retorna o valor validado
double Menu::validaSaldoConta( )
{
	// Declara��o vari�vel local
	double SaldoConta = 0;
	SaldoConta = Menu::validaNumeroPositivoDouble("\tInforme o saldo da conta: ");
	
	return SaldoConta;
}

// Exibe uma mensagem e chama o respectivo validador, depois retorna o valor validado
double Menu::validaTaxaDeOperacao( )
{
	// Declara��o vari�vel local
	double TaxaDeOperacaoConta = 0;
	TaxaDeOperacaoConta = Menu::validaNumeroPositivoDouble("\tInforme a taxa de operacao: ");
	
	return TaxaDeOperacaoConta;
}

// Exibe uma mensagem e chama o respectivo validador, depois retorna o valor validado
double Menu::validaLimiteDeCredito( )
{
	// Declara��o vari�vel local
	double LimiteDeCreditoConta = 0;
	LimiteDeCreditoConta = Menu::validaNumeroPositivoDouble("\tInforme o limite de credito: ");
	
	return LimiteDeCreditoConta;
}

// Valida um numero positivo inteiro com limite de caracteres fixo
int Menu::validaNumeroPositivoInt( const std::string txt, int limite )
{
	// Inicia as variaveis
	double NumeroPositivo = 0;
	std::string input;
	int i = 0;
	int trava = 0;
	
	// Chama o loop
	do
	{
		// Seta as variaveis utilizadas abaixo
		trava = 0;
		
		// Exibe a string recebida como argumento constante e recebe um valor digitado pelo usu�rio
	    std::cout << txt;
		std::cin >> input;
		
		// Testa se o tamanho da string � igual ao limite fixo setado
		if ( input.size() == limite )
		{
			//Testa se a string e composta somente por numeros
			for(i=0; i < input.size() ;i++)
			{	
				//Testa se string[i] e um numero
				if(input[i]>=48 && input[i]<=57)//Tabela ascii ((0 corresponde a 48)) e ((9 corresponde a 57))
				{
					//printf("%c",string[i]);
				}
				else
				{
					// Aciona a trava
					trava = 1;
				}
			}
			
			// Testa se a trava foi acionada durante o for que percorreu toda a string
			if( trava == 1 )
			{
				std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
			}
		}
		else
		{
			// Aciona a trava
			trava = 1; 
			std::cout << std::endl << "\tO numero da conta possui 9 algarismos.." << std::endl << std::endl;
		}
		
		// Testa se a trava n�o foi acionada e testa se o numero � nulo
		if( trava == 0)
		{
			// Converte uma string para inteiro
			NumeroPositivo = std::stoi(input);
			
			// Testa se o numero informado � nulo
			if( NumeroPositivo == 0 )
			{
				trava = 1;
				std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
			}
		}
		
	}while( trava == 1 );
	
	// Retorna o numero validado
	return NumeroPositivo;
}

// Valida um numero positivo inteiro
int Menu::validaNumeroPositivoInt( const std::string txt )
{
	// Inicia as variaveis
	double NumeroPositivo = 0;
	std::string input;
	int i = 0;
	int trava = 0;
	
	// Chama o loop
	do
	{
		// Seta as variaveis utilizadas abaixo
		trava = 0;
		
		// Exibe a string recebida como argumento constante e recebe um valor digitado pelo usu�rio
	    std::cout << txt;
		std::cin >> input;

		//Testa se a string e composta somente por numeros
		for(i=0; i < input.size() ;i++)
		{	
			//Testa se string[i] e um numero
			if(input[i]>=48 && input[i]<=57)//Tabela ascii ((0 corresponde a 48)) e ((9 corresponde a 57))
			{
				//printf("%c",string[i]);
			}
			else
			{
				// Aciona a trava
				trava = 1;
			}
		}
		
		// Testa se a trava foi acionada durante o for que percorreu toda a string
		if( trava == 1 )
		{
			std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
		}
		
		// Testa se a trava n�o foi acionada e testa se o numero � nulo
		if( trava == 0)
		{
			// Converte uma string para inteiro
			NumeroPositivo = std::stoi(input);
			
			// Testa se o numero informado � nulo
			if( NumeroPositivo == 0 )
			{
				trava = 1;
				std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
			}
		}
		
	}while( trava == 1 );
	
	// Retorna o numero validado
	return NumeroPositivo;
}

// Valida um numero positivo double
double Menu::validaNumeroPositivoDouble( const std::string txt )
{
	// Inicia as variaveis
	double NumeroPositivo = 0;
	std::string input;
	int i = 0;
	int trava = 0;
	int ponto = 0;
	
	// Chama o loop
	do
	{
		// Seta as variaveis utilizadas abaixo
		trava = 0;
		ponto = 0;
		
		// Exibe a string recebida como argumento constante e recebe um valor digitado pelo usu�rio
	    std::cout << txt;
		std::cin >> input;
		
		// Testa se a string e composta somente por numeros
		for(i=0; i < input.size() ;i++)
		{	
			
			// Testa se string[i] e um ponto
			if( input[i] == '.' )
			{
				ponto++;
				// Se a string possuir mais de dois pontos a trava � acionada
				if( ponto>=2 )
				{
					// Aciona a trava
					trava = 1;
				}
			}
			
			// Testa se string[i] e um numero
			else if( input[i]>=48 && input[i]<=57 )//Tabela ascii ((0 corresponde a 48)) e ((9 corresponde a 57))
			{
				// printf("%c",string[i]);
			}
			else
			{
				// Aciona a trava
				trava = 1;
			}	
		}
		
		// Testa se a trava foi acionada durante o for que percorreu toda a string
		if( trava == 1 )
		{
			std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
		}
		
		// Testa se a trava n�o foi acionada e testa se o numero � nulo
		if( trava == 0)
		{
			// Converte uma string para double
			NumeroPositivo = std::stod( input );
			
			// Testa se o numero informado � nulo
			if( NumeroPositivo == 0 )
			{
				trava = 1;
				std::cout << std::endl << "\tValor invalido.." << std::endl << std::endl;
			}
		}
		
	}while( trava == 1 );
	
	// Retorna o numero validado
	return NumeroPositivo;
}
