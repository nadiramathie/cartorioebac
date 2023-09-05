#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsável por dar vida às strings>> string='corda', cria uma conexão, amarra as coisas

int registro()
{
			char arquivo [40];//o valor de CPF tem que ser o mesmo do arquivo para que o nome do arquivo armazenado seja o mesmo do CPF, lembrando que o tamanho da string é a mesma
			char cpf[40];//aqui a gente criou uma string de tamanho de 40 caractéres para ser digitada quando formos colocar o CPF como registro
			char nome[40];
			char sobrenome[40];
			char cargo[40];
			printf("Digite o CPF a ser cadastrado: ");
			scanf("%s", cpf);
				
			strcpy(arquivo,cpf);//bora criar o arquivo, primeiro colocando a variável. Como observado o valor do CPF e do arquivo têm que ser iguais, então é só usar o strgcpy para pegar a mesma info
			
			FILE *file; //Enfim, a criação do arquivo. O sistema vai procurar chamar uma estrutura FILE e daí acessar um arquivo de fato
			file = fopen(arquivo,"w");//aqui o arquivo será aberto ou criado de fato, por isso é preciso de "w" para escrever o arquivo na pasta que o .C está  salvo
			fprintf(file,cpf); //esse é um printf só que dentro do arquivo, então vai ser escrito e salvo dentro do arquivo a variável "CPF"
			fclose(file);//aqui o arquivo é fechado, ou melhor, está concluída a etapa de criação de um arquivo e o salvar da variável
			
			file = fopen(arquivo,"a");	//como o computador não entende variável, temos que separar por vírgula. Para isso temos que armazenar dentro do arquivo a separação. Primeiro abrimos o arquivo e daí atualizamos com "a", caso fosse o "w" criaria outro, mas não é o que queremos.
			fprintf(file,",");//pediu para colocar lá dentro a vírgula
			fclose(file);
			
			printf("Digite o nome a ser cadastrado: ");
			scanf("%s",nome);//buscando e salvado na variável nome o que foi digitado
			
			file = fopen(arquivo,"a");
			fprintf(file,nome);
			fclose(file);
			
			file = fopen(arquivo,"a");
			fprintf(file,","); // somente a vírgula que precisa ser colocada entre aspas, pois a string já vai ser puxada "automaticamente" pelo fprint do file sem a necessidade de impressão de nova informação
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
			
			char cpf[40];//o sistema não sabe nessa função qual que é a variável cpf dentro da string, então tem que definir de novo as coisas e criar o conteúdo
			char conteudo[200];
			
			printf("Digite o CPF a ser consultado: ");
			scanf("%s",cpf);
			
			FILE*file;
			file = fopen(cpf,"r");//"r"= read/ler, como é consulta, apenas tem que ler o arquivo e achar a informação
			
			if(file == NULL)//nesse momento, antes de tudo, tem que ter uma validação caso ele não ache o CPF
			{
				printf("Não foi possível localizar o arquivo do CPF.\n");
			}
			
			while (fgets(conteudo, 200, file) != NULL);//Precisa salvar essa string até acabar as letras da string, logo precisa de repetição. No caso o fgets vai pegar na variável "conteúdo" 200 vezes (tamanho máximo do conteúdo) dentro do arquivo, CASO SEJA DIFERENTE != é nulo
			{
				printf("\nEssas são as informações do usuário:");
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
					printf("Não se encontra no sistema o arquivo do CPF.\n");
					system("pause");
			}
}

int main ()
	{
	
	int opcao=0; //Definiu a variável que aloca a característica de número a ser apertado, assim o computador entende que um número foi teclado como "opção"
	int laco=1;
	
	for(laco=1;laco=1;)//Essa coisinha faz voltar para o começo depois que tudo é feitinho
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese");//Define o idioma e seus caractéres especiais
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do Sistema\n");
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao);//Aqui é o espaço que armazena a escolha do usuário que foi optada ao ele clicar
		
		system("cls"); //deleta a tela e mostra a outra
		
		
		switch(opcao)
		{
			case 1:
			registro();//aqui sim chamou a função
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
			printf("Essa opção não está disponível.\n");// fim da seleção de opções
			system("pause");
			break;		
		
		
		}
		
		printf("Esse Software é de livre uso dos funcionários da EBAC\n");
	}
}
