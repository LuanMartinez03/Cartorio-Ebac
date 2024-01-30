#include <stdio.h>//Biblioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço em memória
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h>


int registro()//Função responsável ppor cadastrar o ussuário no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de vátriáeis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%S refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abrindo e atualizando o arquivo salvo
	fprintf(file,",");//salvando informação dentro do arquivo
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//salvando a informação na variável
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo salvo
	fprintf(file,nome);//Slavando informação dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,",");//salvando informação dentro do arquivo
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", sobrenome);//salvando informação na variável
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,sobrenome);//salvando informação dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,","); //salvando informação na variável
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//salvando informação na variável
	
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
	fprintf(file,cargo);//salvando informação na variável
	fclose(file);	//fechando o arquivo
	
	system("pause");//pausando as informações na tela
	
}

int consulta()//localizando o arquivo
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];//criando o arquivo
	char conteudo[200];//localizando o arquivél na variável
	
	printf("Digite o CPF a ser consultado: ");//coletando a informação
	scanf("%s",cpf);//salvando o arquivel na variavél
	
	FILE *file;//consulta do arquivo
	file = fopen(cpf,"r");//arindo o arquivo "r" significa ler
	
	if(file == NULL)//colocando validação caso não encontre o arquivo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");//passando a informação de que o arquivo não foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//usando um laço
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];//criando a variaável função
		
		printf("Digite o CPF do usuário a ser deletado:");//coletando informações
		scanf("%s", cpf);//lendo informações
		
		remove(cpf);//appagando arquivo
		
		FILE *file;//consultar o arquivo
		file = fopen (cpf,"r");//abrindo o arquivo "r" de ler

		if (file == NULL)//colocando a informação de que o arquivo não foi encontrado		
	
		{
		
		printf("CPF deletado!\n");//passando informação para o usuário
		printf("O usuário não se encontra no sistema!.\n");//passando informação para o usuário
		
		system ("pause");//pausando a mensagem para o usuário
		}
}

int main()
{
	setlocale(LC_ALL, "portuguese_Brazil");//Definindo linguagem
	
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//responsável por deletar a tela
	
		setlocale(LC_ALL, "Portuguese_Brazil");//Definindo linguagem
	
		printf("###Cartório da EBAC###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");//Fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1://chamada da função Registro
			registro();
			break;
			
			case 2://chamada da função Consulta
			consulta();
			break;
			
			case 3://chamada da faunção Deletar
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
			
	}		
}
	
	
