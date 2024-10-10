#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das strings

/*int teste() // teste de fun��o
{
	printf("Funcionou o teste pedro");
	system("pause");
}*/

int registro()//fun��o responsavel por cadastrar os usu�rios do sistema.
{
	//inicio da cria��o de vari�veis/strings
	/*printf("Voc� escolheu o registro de nomes!\n");
	system("pause");*/
	char arquivo[40];//criar um arquivo para poder registrar os valores a baixo.
	char cpf[40];//variavel para armazenar o cpf
	char nome[40];// variavel para armazenar o nome
	char sobreNome[40];// variavel para armazenar o sobrenome
	char cargo[40];// variavel para armazenar o cargo.
	//final da cria��o das vari�veis

	printf("Digita o CPF a ser cadastrado: ");//coletando informa��o dos usu�rios
	scanf("%s", cpf);//Armazena uma string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings.
	
	FILE *file; //FILE - Procure nas bibliotecas uma estrutura que seja file *file- porque vc vai criar um arquivo ou seja CRIA O ARQUIVO
	file = fopen(arquivo, "w");//fopen abra arquivo, arquivo "w" e escreva 
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" = atualizar a informa��o
	fprintf(file, ", ");//Salva o valor da variavel
	fclose(file);//fecha o file aberto
	
	printf("Digite o nome a ser cadastrado: ");//coleta a informa��o do usu�rio
	scanf("%s", nome);//%s armazena a string nome
	
	file = fopen(arquivo, "a");// fopen abre o file, "a" = atualizar a informa��o
	fprintf(file, nome);//Salva o valor da variavel
	fclose(file);//fecha o file que foi aberto anteriormente
	
	file = fopen(arquivo, "a");// "a" = atualizar a informa��o
	fprintf(file, ", ");//salva o valor na variavel
	fclose(file);//fecha o file aberto anteriormente
	
	printf("Digite o sobre nome a ser cadastrado: ");//coletando a informa��o do usu�rio
	scanf("%s", sobreNome);//%s armazena a string sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo file e o "a" � para atualizar o file
	fprintf(file, sobreNome);//Atualizando o sobreNome
	fclose(file);//Fecha o file aberto acima
	
	file = fopen(arquivo, "a");// "a" = atualizar a informa��o
	fprintf(file, ", ");//salva o valor na varialvel
	fclose(file);//fecha o file aberto acima
	
	printf("Digite o cargo do cadastrado: ");//Coletando a infoma��o do usu�rio
	scanf("%s", cargo);//armazenando a string coletada
	
	file = fopen(arquivo, "a");//abre o arquivo file e o "a" � para atualiza-lo
	fprintf(file, cargo);//salva a atualiza��o feita
	fclose(file);//fecha o arquivo salvo acima
	
	system("pause");//pausa o sistema para o usu�rio visualizar o processo
}

int consulta()//consulta de usu�rio cadastrado
{
	/*printf("Voc� escolheu o consultar nomes!\n");
	system("pause");*/// pausa o sistema para o usu�rio visualizar o processo
	
	setlocale(LC_ALL,"portuguese");//localiza o texto para o portugues brasil

	char cpf[40];// variavel do cpf
	char conteudo[100];//variavel criada para mostrar na tela as infoma��es salvas no arquivo do usu�rio pq se n�o o sistema s� vai ler e n�o vai mostrar
	
	printf("Digite o cpf a ser consultado: ");//coletando a informa��o do usu�rio para buscar o arquivo
	scanf("%s", cpf);//salva a string para buscar o arquivo
	
	FILE *file; //Procure nas bibliotecas uma estrutura que seja file
	file = fopen(cpf, "r"); // oque � o arquivo,abre o arquivo o arquivo � o cpf com o arquivo salvo abre o aquivo para leitura "r" r de read
	
	if(file == NULL)//criada uma condi��o para informara o usu�rio se existe o cpf ou n�o. se file ser = a nulo mostrar uma condi��o se nao outra
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//mostra ao usu�rio o texto escrito entre par�nteses
	}
	
	while(fgets(conteudo, 200, file) != NULL)//la�o de repeti��o, fun��o para salvar as letrinhas dentro. enquanto (fgets, ou seja vai buscar no arquivo)o conteudo, de at� 200, dentro do arquivo(file), for diferente de nulo(!=NULL)	mostre ao usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//texto para informar o usu�rio da informa��o a seguir 
		printf("%s", conteudo);//Mostra em string(texto) dentro de conteudo e salva
		printf("\n\n");//pulando linhar para melhorar a experi�ncia do usu�rio
	} 
	
	system("pause");// pausa o sistema para o usu�rio ver as infoma��es
}

int deletar()
{
	/*printf("Voc� escolheu deletar de nomes!\n");
	system("pause");*/
	char cpf[40];//criar o cpf string
	
	printf("\nDigite Qual o cpf do usu�rio a ser deletado: ");//pedindo para o usu�rio irformar o cpf do a ser deletado.
	scanf("%s", cpf);//salva o valor na vari�vel cpf
	
	FILE *file;	//valida��o para retornar para o usu�rio se tem o n�o o cpf a ser deletado. Acessa a fun��o file na biblioteca, que parametro, parametro arquivo(puxar os arquivos). 
	file = fopen(cpf, "r");//abre a pasta(FILE) e procura nos arquivos, abre o arquivo com nome cpf, e o leia-o("r").Tenta abrir o arquivo para leitura
	
	if(file == NULL)//Abre uma condi��o para informar o usu�rio, se n�o encontra o arquivo, ent�o se o ser nulo.
	{//Se o arquivo for nulo
		printf("O usu�rio n�o se encontra no sistema!.\n");//mostra ao usu�rio que n�o no sistema
		system("pause");// pausa o sistema para melhor visualiza��o do usu�rio
	}
	else//se o aquivo existir
	{
		fclose(file);//Fecha o arquivo para poder ser deletado
		remove(cpf);// Remove o arquivo
		
		printf("Usu�rio foi deletado!.\n");// mostra ao usu�rio que o arquivo foi deletado
		system("pause");// pausa o sistema para melhor visualiza��o do usu�rio
	}
	
}


int main()//Int main sempre vai ser executada primeiro, int main � a fun��o principal do projeto, o "()" mostra que isso � uma fun��o
{// as chaves � tudo que est� dentro da int main
	int opcao=0;// Variavel criada para o sistema entender qual a op��o que o us�rio quer que o sistema mostre para o usu�rio.
	int laco=1;// variavel criada para fazer o for laco funcionar.
	//la�o criado para o sistema n�o fechar o sistema quando o usu�rio terminar uma das a��es das op��es.
	for(laco=1;laco=1;)//for(laco=1;laco=1; loco++)Enquanto la�o ser = 1 repita at� la�o ser = 1 *Macete para sempre repetir o la�o* ele pode repetir at� um numero ex: enquanto lo�o ser = 1 repita at� la�o ser = 10.
	{
		system("cls");//limpa a tela
		setlocale(LC_ALL,"portuguese"); //Define a linguagem 
		
		printf("###cart�rio da EBAC###\n\n"); // inicio do menu, printf � responsavel por trazer oque est� escrito dentro dos par�nteses para o usu�rio ler. tudo que est� entre aspas � texto
		printf("Escolha a op��o desejada do menu\n\n");//informando o usu�rio de que vai haver um menu.
		printf("\t1 - Registrar nomes\n");//\t � para criar um espa�o antes de mostrar oque ta escrito.
		printf("\t2 - Consultar nomes\n");//mosntrar as op��es de escolhas para usu�rio poder administrar os usu�rios
		printf("\t3 - Deletar nomes\n");//Deletar usu�rio cadastrado.
		printf("\t4 - Sair do Sistema\n");//Comando para sair do sistema.
		printf("Op��es: ");//mostrar ao usu�rio que ele deve escolher uma das op��es � acima.
		
		scanf("%d", &opcao); //armazena a escolha do usu�rio "%d � um tipo inteiro"
		system("cls");//limpa a tela
		
		switch(opcao)//Switch Case
		{
			case 1:
				/*printf("Voc� escolheu o registro de nomes!\n");
				system("pause");*/
				registro();//busca a fun��o registro
				break;//serve para o programa parar de rodar o switch case.
			
			case 2:
				/*printf("Voc� escolheu o consultar nomes!\n");
				system("pause");*/
				consulta();//puxa e mostra a fun��o consulta
				break;//serve para o programa parar de rodar o switch case.
				
			case 3:
				/*printf("Voc� escolheu deletar de nomes!\n");
				system("pause");*/
				deletar();//puxa e mostra a fun��o deletar
				break;//serve para o programa parar de rodar o switch case.
				
			case 4:
				printf("Obrigado por usar o sistema!\n\nPressione enter para continuar!");//Menssagem para mostrar ao us�ario que a comando foi executado.
				return 0;
				break;
			/*case 4: // testando fun��o
				teste();
				break;*/
			
			default:
				system("pause");//pausa o sistema para melhor experiencia do usu�rio
				break;//serve para o programa parar de rodar o switch case.
	
		
		/*if(opcao == 1) //inicio da sele��o
		{
			printf("Voc� escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao == 2)
		{
			printf("Voc� escolheu o consultar nomes!\n");
			system("pause");
		}
		if(opcao == 3)
		{
			printf("Voc� escolheu deletar de nomes!\n");
			system("pause");
		}
		if(opcao == 4)
		{
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
		}//fim da sele��o
		*/
	}
}
}
