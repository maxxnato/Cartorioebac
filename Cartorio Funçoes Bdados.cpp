#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro() //Funçao responsavel por cadastrar os usuários no sistema
{
	//Inicio da Criação de variaveis / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/tring
	
	printf("Digite o CPF a ser cadastrado"); //coletando informação do usuário
	scanf("%s",cpf); //%s armazena/salva nas strings
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo white significa escrever
	fprintf(file,cpf);  //salvo o valor da varialvel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: "); // coletando informações do usuário
	scanf("%s",nome); //%s armazena/ salva nas strings
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file,nome); //salvo o valor da varialvel
	fclose(file);
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // a de atualizar
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo línguagem
	
	char cpf[40]; // variavel string
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se ele não achar o arquivo
	{
		printf("Não foi possivel Abrir o arquivo"); //fala pro usuario
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\nEssas são as informações do usuario:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	
}


int deletar()
{
	char cpf[40]; //criamos a string cpf
	
	printf("Digite o CPF do usuário a ser deletado: "); //pedimos pro usuario
	scanf("%s",cpf); //%s armazena/salva nas strings
	
	remove(cpf); //acessa a pasta e deleta
	
	FILE *file; // entra na biblioteca e acessa o arquivo
	file = fopen(cpf,"r"); //função de abrir e ler o cpf da string
	
	if(file == NULL) //se ele não achar o arquivo
	{
		printf("O usuário não se encontra no sistema!.\n"); //fala pro usuario
		system("pause"); // para o usuario ter tempo de ler e não passar direto
	}
	
}

int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //repete, volta ao inicio
	{
	
		system("cls"); //responsavel por limpar a tela
		setlocale(LC_ALL, "Portuguese"); //Definindo línguagem
		
	
		
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("t1 - Registrar nomes\n");
		printf("t2 - Consultar nomes\n");
		printf("t3 - Deletar nomes\n\n");
		printf("t4 - Sair do sistema\n\n");	
		printf("Opcão:"); //fim do menu
	
	
		scanf("%d",&opcao); // armazenado a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada da função registro 
			break;
		
			case 2:
			consulta();	//chamada da função consulta		
			break;
			
			case 3:
			deletar();	//chamada da função deletar		
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			defalt:
			printf("Essa opção não esta disponivel!\n"); //informa o usuario
			system("pause"); // para o usuario ter tempo de ler e não passar direto
			break;
		}//fim da seleção
		
	}
}


