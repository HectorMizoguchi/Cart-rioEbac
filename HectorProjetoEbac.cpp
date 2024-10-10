#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das strings

/*int teste() // teste de função
{
	printf("Funcionou o teste pedro");
	system("pause");
}*/

int registro()//função responsavel por cadastrar os usuários do sistema.
{
	//inicio da criação de variáveis/strings
	/*printf("Você escolheu o registro de nomes!\n");
	system("pause");*/
	char arquivo[40];//criar um arquivo para poder registrar os valores a baixo.
	char cpf[40];//variavel para armazenar o cpf
	char nome[40];// variavel para armazenar o nome
	char sobreNome[40];// variavel para armazenar o sobrenome
	char cargo[40];// variavel para armazenar o cargo.
	//final da criação das variáveis

	printf("Digita o CPF a ser cadastrado: ");//coletando informação dos usuários
	scanf("%s", cpf);//Armazena uma string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings.
	
	FILE *file; //FILE - Procure nas bibliotecas uma estrutura que seja file *file- porque vc vai criar um arquivo ou seja CRIA O ARQUIVO
	file = fopen(arquivo, "w");//fopen abra arquivo, arquivo "w" e escreva 
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" = atualizar a informação
	fprintf(file, ", ");//Salva o valor da variavel
	fclose(file);//fecha o file aberto
	
	printf("Digite o nome a ser cadastrado: ");//coleta a informação do usuário
	scanf("%s", nome);//%s armazena a string nome
	
	file = fopen(arquivo, "a");// fopen abre o file, "a" = atualizar a informação
	fprintf(file, nome);//Salva o valor da variavel
	fclose(file);//fecha o file que foi aberto anteriormente
	
	file = fopen(arquivo, "a");// "a" = atualizar a informação
	fprintf(file, ", ");//salva o valor na variavel
	fclose(file);//fecha o file aberto anteriormente
	
	printf("Digite o sobre nome a ser cadastrado: ");//coletando a informação do usuário
	scanf("%s", sobreNome);//%s armazena a string sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo file e o "a" é para atualizar o file
	fprintf(file, sobreNome);//Atualizando o sobreNome
	fclose(file);//Fecha o file aberto acima
	
	file = fopen(arquivo, "a");// "a" = atualizar a informação
	fprintf(file, ", ");//salva o valor na varialvel
	fclose(file);//fecha o file aberto acima
	
	printf("Digite o cargo do cadastrado: ");//Coletando a infomação do usuário
	scanf("%s", cargo);//armazenando a string coletada
	
	file = fopen(arquivo, "a");//abre o arquivo file e o "a" é para atualiza-lo
	fprintf(file, cargo);//salva a atualização feita
	fclose(file);//fecha o arquivo salvo acima
	
	system("pause");//pausa o sistema para o usuário visualizar o processo
}

int consulta()//consulta de usuário cadastrado
{
	/*printf("Você escolheu o consultar nomes!\n");
	system("pause");*/// pausa o sistema para o usuário visualizar o processo
	
	setlocale(LC_ALL,"portuguese");//localiza o texto para o portugues brasil

	char cpf[40];// variavel do cpf
	char conteudo[100];//variavel criada para mostrar na tela as infomações salvas no arquivo do usuário pq se não o sistema só vai ler e não vai mostrar
	
	printf("Digite o cpf a ser consultado: ");//coletando a informação do usuário para buscar o arquivo
	scanf("%s", cpf);//salva a string para buscar o arquivo
	
	FILE *file; //Procure nas bibliotecas uma estrutura que seja file
	file = fopen(cpf, "r"); // oque é o arquivo,abre o arquivo o arquivo é o cpf com o arquivo salvo abre o aquivo para leitura "r" r de read
	
	if(file == NULL)//criada uma condição para informara o usuário se existe o cpf ou não. se file ser = a nulo mostrar uma condição se nao outra
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");//mostra ao usuário o texto escrito entre parênteses
	}
	
	while(fgets(conteudo, 200, file) != NULL)//laço de repetição, função para salvar as letrinhas dentro. enquanto (fgets, ou seja vai buscar no arquivo)o conteudo, de até 200, dentro do arquivo(file), for diferente de nulo(!=NULL)	mostre ao usuário
	{
		printf("\nEssas são as informações do usuário: ");//texto para informar o usuário da informação a seguir 
		printf("%s", conteudo);//Mostra em string(texto) dentro de conteudo e salva
		printf("\n\n");//pulando linhar para melhorar a experiência do usuário
	} 
	
	system("pause");// pausa o sistema para o usuário ver as infomações
}

int deletar()
{
	/*printf("Você escolheu deletar de nomes!\n");
	system("pause");*/
	char cpf[40];//criar o cpf string
	
	printf("\nDigite Qual o cpf do usuário a ser deletado: ");//pedindo para o usuário irformar o cpf do a ser deletado.
	scanf("%s", cpf);//salva o valor na variável cpf
	
	FILE *file;	//validação para retornar para o usuário se tem o não o cpf a ser deletado. Acessa a função file na biblioteca, que parametro, parametro arquivo(puxar os arquivos). 
	file = fopen(cpf, "r");//abre a pasta(FILE) e procura nos arquivos, abre o arquivo com nome cpf, e o leia-o("r").Tenta abrir o arquivo para leitura
	
	if(file == NULL)//Abre uma condição para informar o usuário, se não encontra o arquivo, então se o ser nulo.
	{//Se o arquivo for nulo
		printf("O usuário não se encontra no sistema!.\n");//mostra ao usuário que não no sistema
		system("pause");// pausa o sistema para melhor visualização do usuário
	}
	else//se o aquivo existir
	{
		fclose(file);//Fecha o arquivo para poder ser deletado
		remove(cpf);// Remove o arquivo
		
		printf("Usuário foi deletado!.\n");// mostra ao usuário que o arquivo foi deletado
		system("pause");// pausa o sistema para melhor visualização do usuãrio
	}
	
}


int main()//Int main sempre vai ser executada primeiro, int main é a função principal do projeto, o "()" mostra que isso é uma função
{// as chaves é tudo que está dentro da int main
	int opcao=0;// Variavel criada para o sistema entender qual a opção que o usário quer que o sistema mostre para o usuário.
	int laco=1;// variavel criada para fazer o for laco funcionar.
	//laço criado para o sistema não fechar o sistema quando o usuário terminar uma das ações das opções.
	for(laco=1;laco=1;)//for(laco=1;laco=1; loco++)Enquanto laço ser = 1 repita até laço ser = 1 *Macete para sempre repetir o laço* ele pode repetir até um numero ex: enquanto loço ser = 1 repita até laço ser = 10.
	{
		system("cls");//limpa a tela
		setlocale(LC_ALL,"portuguese"); //Define a linguagem 
		
		printf("###cartório da EBAC###\n\n"); // inicio do menu, printf é responsavel por trazer oque está escrito dentro dos parênteses para o usuário ler. tudo que está entre aspas é texto
		printf("Escolha a opção desejada do menu\n\n");//informando o usuário de que vai haver um menu.
		printf("\t1 - Registrar nomes\n");//\t é para criar um espaço antes de mostrar oque ta escrito.
		printf("\t2 - Consultar nomes\n");//mosntrar as opções de escolhas para usuário poder administrar os usuários
		printf("\t3 - Deletar nomes\n");//Deletar usuário cadastrado.
		printf("\t4 - Sair do Sistema\n");//Comando para sair do sistema.
		printf("Opções: ");//mostrar ao usuário que ele deve escolher uma das opções à acima.
		
		scanf("%d", &opcao); //armazena a escolha do usuário "%d é um tipo inteiro"
		system("cls");//limpa a tela
		
		switch(opcao)//Switch Case
		{
			case 1:
				/*printf("Você escolheu o registro de nomes!\n");
				system("pause");*/
				registro();//busca a função registro
				break;//serve para o programa parar de rodar o switch case.
			
			case 2:
				/*printf("Você escolheu o consultar nomes!\n");
				system("pause");*/
				consulta();//puxa e mostra a função consulta
				break;//serve para o programa parar de rodar o switch case.
				
			case 3:
				/*printf("Você escolheu deletar de nomes!\n");
				system("pause");*/
				deletar();//puxa e mostra a função deletar
				break;//serve para o programa parar de rodar o switch case.
				
			case 4:
				printf("Obrigado por usar o sistema!\n\nPressione enter para continuar!");//Menssagem para mostrar ao usúario que a comando foi executado.
				return 0;
				break;
			/*case 4: // testando função
				teste();
				break;*/
			
			default:
				system("pause");//pausa o sistema para melhor experiencia do usuário
				break;//serve para o programa parar de rodar o switch case.
	
		
		/*if(opcao == 1) //inicio da seleção
		{
			printf("Você escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao == 2)
		{
			printf("Você escolheu o consultar nomes!\n");
			system("pause");
		}
		if(opcao == 3)
		{
			printf("Você escolheu deletar de nomes!\n");
			system("pause");
		}
		if(opcao == 4)
		{
			printf("Essa opção não está disponivel\n");
			system("pause");
		}//fim da seleção
		*/
	}
}
}
