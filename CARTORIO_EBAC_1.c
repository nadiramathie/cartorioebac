#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca respons�vel por dar vida �s strings>> string='corda', cria uma conex�o, amarra as coisas

int registro()
{
			char arquivo [40];//o valor de CPF tem que ser o mesmo do arquivo para que o nome do arquivo armazenado seja o mesmo do CPF, lembrando que o tamanho da string � a mesma
			char cpf[40];//aqui a gente criou uma string de tamanho de 40 caract�res para ser digitada quando formos colocar o CPF como registro
			char nome[40];
			char sobrenome[40];
			char cargo[40];
			printf("Digite o CPF a ser cadastrado: ");
			scanf("%s", cpf);
				
			strcpy(arquivo,cpf);//bora criar o arquivo, primeiro colocando a vari�vel. Como observado o valor do CPF e do arquivo t�m que ser iguais, ent�o � s� usar o strgcpy para pegar a mesma info
			
			FILE *file; //Enfim, a cria��o do arquivo. O sistema vai procurar chamar uma estrutura FILE e da� acessar um arquivo de fato
			file = fopen(arquivo,"w");//aqui o arquivo ser� aberto ou criado de fato, por isso � preciso de "w" para escrever o arquivo na pasta que o .C est�  salvo
			fprintf(file,cpf); //esse � um printf s� que dentro do arquivo, ent�o vai ser escrito e salvo dentro do arquivo a vari�vel "CPF"
			fclose(file);//aqui o arquivo � fechado, ou melhor, est� conclu�da a etapa de cria��o de um arquivo e o salvar da vari�vel
			
			file = fopen(arquivo,"a");	//como o computador n�o entende vari�vel, temos que separar por v�rgula. Para isso temos que armazenar dentro do arquivo a separa��o. Primeiro abrimos o arquivo e da� atualizamos com "a", caso fosse o "w" criaria outro, mas n�o � o que queremos.
			fprintf(file,",");//pediu para colocar l� dentro a v�rgula
			fclose(file);
			
			printf("Digite o nome a ser cadastrado: ");
			scanf("%s",nome);//buscando e salvado na vari�vel nome o que foi digitado
			
			file = fopen(arquivo,"a");
			fprintf(file,nome);
			fclose(file);
			
			file = fopen(arquivo,"a");
			fprintf(file,","); // somente a v�rgula que precisa ser colocada entre aspas, pois a string j� vai ser puxada "automaticamente" pelo fprint do file sem a necessidade de impress�o de nova informa��o
			fclose(file);
			
			printf("Digite o sobrenome a ser cadastrado: ");
			scanf("%s",sobrenome);
			
			file = fopen(arquivo,"a");
			fprintf(file,sobrenome);
			fclose(file);
			
			file = fopen(arquivo,"a");
			fprintf(file,",");
			fclose(file);
			
			printf("Digite o cargo a ser cadastrado: ");
			scanf("%s",cargo);
			
			file = fopen(arquivo,"a");
			fprintf(file,cargo);
			fclose(file);
			
			system("pause");
		
			
}


int consulta()
{
			setlocale(LC_ALL,"Portuguese");
			
			char cpf[40];//o sistema n�o sabe nessa fun��o qual que � a vari�vel cpf dentro da string, ent�o tem que definir de novo as coisas e criar o conte�do
			char conteudo[200];
			
			printf("Digite o CPF a ser consultado: ");
			scanf("%s",cpf);
			
			FILE*file;
			file = fopen(cpf,"r");//"r"= read/ler, como � consulta, apenas tem que ler o arquivo e achar a informa��o
			
			if(file == NULL)//nesse momento, antes de tudo, tem que ter uma valida��o caso ele n�o ache o CPF
			{
				printf("N�o foi poss�vel localizar o arquivo do CPF.\n");
			}
			
			while (fgets(conteudo, 200, file) != NULL);//Precisa salvar essa string at� acabar as letras da string, logo precisa de repeti��o. No caso o fgets vai pegar na vari�vel "conte�do" 200 vezes (tamanho m�ximo do conte�do) dentro do arquivo, CASO SEJA DIFERENTE != � nulo
			{
				printf("\nEssas s�o as informa��es do usu�rio:");
				printf("%s",conteudo);
				printf("\n\n");
			}
			
			system ("pause");
}

int deletar()
{
			char cpf[40];
			
			printf("Digite o CPF a ser deletado: ");
			scanf("%s",cpf);
			
			remove(cpf);
			
			FILE*file;
			file = fopen(cpf,"r");
			
			if(file == NULL)
			
			{
					printf("N�o se encontra no sistema o arquivo do CPF.\n");
					system("pause");
			}
}

int main ()
	{
	
	int opcao=0; //Definiu a vari�vel que aloca a caracter�stica de n�mero a ser apertado, assim o computador entende que um n�mero foi teclado como "op��o"
	int laco=1;
	
	for(laco=1;laco=1;)//Essa coisinha faz voltar para o come�o depois que tudo � feitinho
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese");//Define o idioma e seus caract�res especiais
		
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do Sistema\n");
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao);//Aqui � o espa�o que armazena a escolha do usu�rio que foi optada ao ele clicar
		
		system("cls"); //deleta a tela e mostra a outra
		
		
		switch(opcao)
		{
			case 1:
			registro();//aqui sim chamou a fun��o
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;

			case 4:
			printf("Obrigado por usar o sistema");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n");// fim da sele��o de op��es
			system("pause");
			break;		
		
		
		}
		
		printf("Esse Software � de livre uso dos funcion�rios da EBAC\n");
	}
}
