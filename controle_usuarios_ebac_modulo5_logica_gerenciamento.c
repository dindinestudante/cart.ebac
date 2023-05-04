#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o tipo "int" + parenteses denomina fun��o - essa fun��o � respons�vel por cadastrar os usu�rios no sistema
{ //inicio dos comandos para o registro de nomes
	
	//inicio da cria��o de vari�veis/string (vari�vel tipo char entre "colchetes=string")
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf ("Digite o n�mero de CPF que deseja cadastrar: "); //coletando informa��o do usu�rio - n�mero de cpf
	scanf("%s", cpf); //comando %s para salvar na string
	
	strcpy(arquivo, cpf); //stringcopy respons�vel por copiar os valores das strings - aqui no caso escolhemos o cpf 
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "W"); //criar arquivo comando "w" para escrever novo arquivo
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo 
	fprintf (file,"cpf: "); //comando para incluir "cpf: " para uma melhor visualiza��o do dado no software
	fclose(file); //fechar arquivo
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,cpf); //comando para salvar o cpf digitado pelo usu�rio no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //comando "a" atualizar informa��o no arquivo
	fprintf (file,","); //incluimos a v�rgula
	fclose(file); //fechar arquivo
	
	printf("Digite o nome que deseja cadastrar: "); //coletando informa��o do usu�rio - nome 
	scanf ("%s",nome); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,"nome: "); //comando para incluir "nome: " para uma melhor visualiza��o do dado no software
	fclose(file); //fechar arquivo
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf (file,nome); //comando para salvar o nome digitado pelo usu�rio no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" atualizar informa��o
	fprintf (file,","); //incluimos a v�rgula
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome que deseja cadastrar: "); //coletando informa��o do usu�rio - sobrenome
	scanf ("%s",sobrenome); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo 
	fprintf (file,"sobrenome: "); //comando para incluir "sobrenome: " para uma melhor visualiza��o do dado no software
	fclose(file); //fechar arquivo
	file = fopen (arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,sobrenome); //comando para salvar o sobrenome digitado pelo usu�rio no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,","); //incluimos a v�rgula
	fclose(file); //fechar arquivo
	
	printf ("Digite o cargo que deseja cadastrar: "); //coletando informa��es do usu�rio - cargo
	scanf ("%s",cargo); //comando %s para salvar na string
	
	file = fopen(arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,"cargo: "); //comando para incluir "cargo: " para uma melhor visualiza��o do dado no software
	fclose(file); //fechar arquivo
	file = fopen (arquivo, "a"); //comando "a" para atualizar o arquivo
	fprintf (file,cargo); //comando para salvar o cargo digitado pelo usu�rio no arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" atualizar informa��o
	fprintf (file,"."); //comando para incluir ponto final ap�s os dados fornecidos pelo usu�rio
	fclose(file); //fechar arquivo
	

	printf ("\nSeus dados foram cadastrados com sucesso!\n \n"); //aviso ao usu�rio de que deu tudo certo 
     
	system("pause"); //comando para segurar a tela para o usu�rio conseguir visualizar o que est� acontecendo
}
//fim dos comandos para registro de nomes

int consulta()//fun��o de consulta - respons�vel por consultar os usu�rios cadastrados no sistema
{ //inicio dos comandos para consulta de nomes
	setlocale(LC_ALL, "Portuguese"); //ativando a linguagem para n�o ocorrer erros de pontua��o no software

	//inicio da cria��o das vari�veis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das vari�veis
	
	printf ("Digite o CPF que deseja consultar: "); //comando para o usu�rio digitar o cpf que deseja informa��es
	scanf("%s",cpf); //comando "%s" para salvar na string
	
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" para realizar a leitura do arquivo
	
	if(file == NULL) //comandos para caso aconte�a de n�o encontrar o arquivo desejado
	{
		printf ("\nEste usu�rio n�o foi localizado no nosso banco de dados! \n\n"); //mensagem para o usu�rio 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se encontrou o cadastro do usu�rio de at� 200 caracteres, mostre os dados.
	{
		printf ("\nAqui est�o as informa��es do usu�rio: "); //mensagem para o usu�rio
		printf ("%s", conteudo); //comando "%s" para salvar na string
		printf ("\n\n"); //comando para pular linhas, para uma melhor visualiza��o no software
	}
	
	fclose(file); //fechar arquivo
	
	system("pause"); //pausar tela para que o usu�rio possa entender o que est� acontecendo
}
//fim dos comandos para consulta de nomes

int deletar()//fun��o de deletar nomes - respons�vel por excluir cadastros no sistema
{ //inicio dos comandos para deletar nomes

	//inicio da cria��o da vari�vel
	char cpf[40];
	//fim da cria��o da vari�vel
	
	printf ("Digite o n�mero de CPF cadastrado que deseja deletar: "); //comando para o usu�rio digitar o n�mero de cpf que deseja excluir do sistema
	scanf("%s",cpf); //comando "%s" para salvar na string
	
	remove(cpf); //comando para deletar o arquivo
	
	FILE *file;
	file = fopen (cpf,"r"); //comando "r" para realizar a leitura do arquivo
	
	if(file == NULL) //comando para quando ele n�o encontrar o arquivo, por n�o existir ou porqu� ele encontrou e j� deletou do sistema
	{
		printf("Esse usu�rio n�o se encontra no sistema! \n"); //mensagem para o usu�rio ap�s exclus�o do cadastro
		system("pause"); //comando para pausar a tela para que o usu�rio possa ler as informa��es
	}
	
	
}
//fim dos comandos para deletar os nomes

int main () //fun��o do menu principal - respons�vel pelo menu do usu�rio com as op��es dispon�veis
{ // inicio dos comandos do menu principal
	
	int opcao=0; //comando para definir a vari�vel
	int repeat=1; //comando para definir a vari�vel de repeti��o - retorno ao menu
	
	for(repeat=1;repeat=1;) //comando para retornar ao menu principal
	{
		system("cls"); //comando para a limpeza de tela ap�s a op��o selecionada pelo usu�rio

		setlocale(LC_ALL, "Portuguese"); //comando para ativar o idioma e ativar os acentos utilizados nas palavras em portugu�s
	
		printf ("### Controle de usu�rios da EBAC ###\n\n"); //inicio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n"); 
		printf ("Digite o n�mero da sua op��o: "); //fim do menu 
	
		scanf("%d", &opcao); //comando "%d" para armazenar a escolha do usu�rio
	
		system("cls"); //comando para a limpeza de tela do menu principal ap�s sele��o do usu�rio
		
		switch(opcao) //operador de repeti��o switch - inicio da sele��o do usu�rio (escolha do menu)
		{	
			case 1:
			registro(); //chamada da fun��o registro de nomes
			break;
			
			case 2:
			consulta(); //chamada da fun��o consulta de nomes
			break;
			
			case 3:
			deletar(); //chamada da fun��o deletar nomes
            break;
				
			default:
			printf ("Essa op��o n�o est� dispon�vel, selecione uma das op��es dispon�veis no menu\n\n"); //mensagem para usu�rio que escolha uma op��o indispon�vel 
			system("pause"); //esse carinha aqui pausa a tela
			break;
				
		}  //fim da sele��o do usu�rio
		
	}
}
//fim dos comandos do menu principal
