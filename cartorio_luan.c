#include <stdio.h>//Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h>


int registro()//Fun��o respons�vel ppor cadastrar o ussu�rio no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de v�tri�eis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%S refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abrindo e atualizando o arquivo salvo
	fprintf(file,",");//salvando informa��o dentro do arquivo
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",nome);//salvando a informa��o na vari�vel
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo salvo
	fprintf(file,nome);//Slavando informa��o dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,",");//salvando informa��o dentro do arquivo
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", sobrenome);//salvando informa��o na vari�vel
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,sobrenome);//salvando informa��o dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,","); //salvando informa��o na vari�vel
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//salvando informa��o na vari�vel
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,cargo);//salvando informa��o na vari�vel
	fclose(file);	//fechando o arquivo
	
	system("pause");//pausando as informa��es na tela
	
}

int consulta()//localizando o arquivo
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];//criando o arquivo
	char conteudo[200];//localizando o arquiv�l na vari�vel
	
	printf("Digite o CPF a ser consultado: ");//coletando a informa��o
	scanf("%s",cpf);//salvando o arquivel na variav�l
	
	FILE *file;//consulta do arquivo
	file = fopen(cpf,"r");//arindo o arquivo "r" significa ler
	
	if(file == NULL)//colocando valida��o caso n�o encontre o arquivo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");//passando a informa��o de que o arquivo n�o foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//usando um la�o
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];//criando a varia�vel fun��o
		
		printf("Digite o CPF do usu�rio a ser deletado:");//coletando informa��es
		scanf("%s", cpf);//lendo informa��es
		
		remove(cpf);//appagando arquivo
		
		FILE *file;//consultar o arquivo
		file = fopen (cpf,"r");//abrindo o arquivo "r" de ler

		if (file == NULL)//colocando a informa��o de que o arquivo n�o foi encontrado		
	
		{
		
		printf("CPF deletado!\n");//passando informa��o para o usu�rio
		printf("O usu�rio n�o se encontra no sistema!.\n");//passando informa��o para o usu�rio
		
		system ("pause");//pausando a mensagem para o usu�rio
		}
}

int main()
{
	setlocale(LC_ALL, "portuguese_Brazil");//Definindo linguagem
	
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//respons�vel por deletar a tela
	
		setlocale(LC_ALL, "Portuguese_Brazil");//Definindo linguagem
	
		printf("###Cart�rio da EBAC###\n\n");//Inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");//Fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1://chamada da fun��o Registro
			registro();
			break;
			
			case 2://chamada da fun��o Consulta
			consulta();
			break;
			
			case 3://chamada da faun��o Deletar
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
			
	}		
}
	
	
