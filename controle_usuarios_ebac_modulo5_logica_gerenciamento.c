#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto região 
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//função tipo "int" + parenteses denomina função - essa função é responsável por cadastrar os usuários no sistema
{ //inicio dos comandos para o registro de nomes
	
	//inicio da criação de variáveis/string (variável tipo char entre "colchetes=string")
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf ("Digite o número de CPF que deseja cadastrar: "); //coletando informação do usuário - número de cpf
	scanf("%s", cpf); //comando %s para salvar na string
	
	strcpy(arquivo, cpf); //stringcopy responsável por copiar os valores das strings - aqui no caso escolhemos o cpf 
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "W"); //criar arquivo comando "w" para escrever novo arquivo
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo 
	fprintf (file,"cpf: "); //comando para incluir "cpf: " para uma melhor visualização do dado no software
	fclose(file); //fechar arquivo
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,cpf); //comando para salvar o cpf digitado pelo usuário no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //comando "a" atualizar informação no arquivo
	fprintf (file,","); //incluimos a vírgula
	fclose(file); //fechar arquivo
	
	printf("Digite o nome que deseja cadastrar: "); //coletando informação do usuário - nome 
	scanf ("%s",nome); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,"nome: "); //comando para incluir "nome: " para uma melhor visualização do dado no software
	fclose(file); //fechar arquivo
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf (file,nome); //comando para salvar o nome digitado pelo usuário no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" atualizar informação
	fprintf (file,","); //incluimos a vírgula
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome que deseja cadastrar: "); //coletando informação do usuário - sobrenome
	scanf ("%s",sobrenome); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo 
	fprintf (file,"sobrenome: "); //comando para incluir "sobrenome: " para uma melhor visualização do dado no software
	fclose(file); //fechar arquivo
	file = fopen (arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,sobrenome); //comando para salvar o sobrenome digitado pelo usuário no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,","); //incluimos a vírgula
	fclose(file); //fechar arquivo
	
	printf ("Digite o cargo que deseja cadastrar: "); //coletando informações do usuário - cargo
	scanf ("%s",cargo); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,"cargo: "); //comando para incluir "cargo: " para uma melhor visualização do dado no software
	fclose(file); //fechar arquivo
	file = fopen (arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,cargo); //comando para salvar o cargo digitado pelo usuário no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" atualizar informação
	fprintf (file,"."); //comando para incluir ponto final após os dados fornecidos pelo usuário
	fclose(file); //fechar arquivo
	

	printf ("\nSeus dados foram cadastrados com sucesso!\n \n"); //aviso ao usuário de que deu tudo certo 
     
	system("pause"); //comando para segurar a tela para o usuário conseguir visualizar o que está acontecendo
}
//fim dos comandos para registro de nomes

int consulta()//função de consulta - responsável por consultar os usuários cadastrados no sistema
{ //inicio dos comandos para consulta de nomes
	setlocale(LC_ALL, "Portuguese"); //ativando a linguagem para não ocorrer erros de pontuação no software

	//inicio da criação das variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação das variáveis
	
	printf ("Digite o CPF que deseja consultar: "); //comando para o usuário digitar o cpf que deseja informações
	scanf("%s",cpf); //comando "%s" para salvar na string
	
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" para realizar a leitura do arquivo
	
	if(file == NULL) //comandos para caso aconteça de não encontrar o arquivo desejado
	{
		printf ("\nEste usuário não foi localizado no nosso banco de dados! \n\n"); //mensagem para o usuário 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se encontrou o cadastro do usuário de até 200 caracteres, mostre os dados.
	{
		printf ("\nAqui estão as informações do usuário: "); //mensagem para o usuário
		printf ("%s", conteudo); //comando "%s" para salvar na string
		printf ("\n\n"); //comando para pular linhas, para uma melhor visualização no software
	}
	
	fclose(file); //fechar arquivo
	
	system("pause"); //pausar tela para que o usuário possa entender o que está acontecendo
}
//fim dos comandos para consulta de nomes

int deletar()//função de deletar nomes - responsável por excluir cadastros no sistema
{ //inicio dos comandos para deletar nomes

	//inicio da criação da variável
	char cpf[40];
	//fim da criação da variável
	
	printf ("Digite o número de CPF cadastrado que deseja deletar: "); //comando para o usuário digitar o número de cpf que deseja excluir do sistema
	scanf("%s",cpf); //comando "%s" para salvar na string
	
	remove(cpf); //comando para deletar o arquivo
	
	FILE *file;
	file = fopen (cpf,"r"); //comando "r" para realizar a leitura do arquivo
	
	if(file == NULL) //comando para quando ele não encontrar o arquivo, por não existir ou porquê ele encontrou e já deletou do sistema
	{
		printf("Esse usuário não se encontra no sistema! \n"); //mensagem para o usuário após exclusão do cadastro
		system("pause"); //comando para pausar a tela para que o usuário possa ler as informações
	}
	
	
}
//fim dos comandos para deletar os nomes

int main () //função do menu principal - responsável pelo menu do usuário com as opções disponíveis
{ // inicio dos comandos do menu principal
	
	int opcao=0; //comando para definir a variável
	int repeat=1; //comando para definir a variável de repetição - retorno ao menu
	
	for(repeat=1;repeat=1;) //comando para retornar ao menu principal
	{
		system("cls"); //comando para a limpeza de tela após a opção selecionada pelo usuário

		setlocale(LC_ALL, "Portuguese"); //comando para ativar o idioma e ativar os acentos utilizados nas palavras em português
	
		printf ("### Controle de usuários da EBAC ###\n\n"); //inicio do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n"); 
		printf ("Digite o número da sua opção: "); //fim do menu 
	
		scanf("%d", &opcao); //comando "%d" para armazenar a escolha do usuário
	
		system("cls"); //comando para a limpeza de tela do menu principal após seleção do usuário
		
		switch(opcao) //operador de repetição switch - inicio da seleção do usuário (escolha do menu)
		{	
			case 1:
			registro(); //chamada da função registro de nomes
			break;
			
			case 2:
			consulta(); //chamada da função consulta de nomes
			break;
			
			case 3:
			deletar(); //chamada da função deletar nomes
            break;
				
			default:
			printf ("Essa opção não está disponível, selecione uma das opções disponíveis no menu\n\n"); //mensagem para usuário que escolha uma opção indisponível 
			system("pause"); //esse carinha aqui pausa a tela
			break;
				
		}  //fim da seleção do usuário
		
	}
}
//fim dos comandos do menu principal
