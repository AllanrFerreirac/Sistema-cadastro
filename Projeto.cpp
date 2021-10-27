#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
struct projeto{
	int codigo;
	char titulo[100];
	char descricao[100];
	char responsavel[100]; 
	int status;
};
struct projeto projetos[200];
int opcao, i, sequencia=0;
bool achou;
const int A = 1, F = 2, C = 3;

void cadastrar_projeto(){
	bool cadastro = true;
	char continuar;
	do{
		system("cls");
		projetos[sequencia].codigo = sequencia + 1;
		printf("\nDigite o titulo do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].titulo);
		printf("\nDigite a descricao do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].descricao);
		printf("\nDigite o responsavel do projeto: ");
		fflush(stdin);
		gets(projetos[sequencia].responsavel);
		printf("\nDigite o status do projeto: 1 - A FAZER . 2 - FAZENDO . 3 - CONCLUIDO: ");
		fflush(stdin);
		scanf("%d",&projetos[sequencia].status);
		printf("\nCadastro realizado com sucesso.\nDeseja realizar um novo cadastro? S - sim . N - nao: ");
		fflush(stdin);
		scanf("%c",&continuar);
		if ((continuar == 'N') || (continuar == 'n')){
			cadastro = false;
		}
		sequencia ++;
	}while(cadastro == true);
}
copia1 (){
	printf("\nCodigo: %d ",projetos[i].codigo);
	printf("\nTitulo: %s ",projetos[i].titulo);
	printf("\nDescricao: %s ",projetos[i].descricao);
	printf("\nResponsavel: %s ",projetos[i].responsavel);
	printf("\nStatus: %d ",projetos[i].status);
	printf("\n-------------------------------------------------------------------------------------\n");
}
pro_nao (){
	if (achou == false){
		printf("\nProjeto não encontrado! \n");
	}
	system("pause");
}
void todos_projetos(){
	system("cls");
	if (projetos[0].codigo > 0){
		for ( i = 0; i < sequencia; i ++){
			copia1 ();
		}
	}else{
		printf("\nNenhum projeto cadastrado!");
	}
	system("pause");
}
void por_status(int s){
	system("cls");
	for (i = 0; i < sequencia; i ++){
		if (projetos[i].status == s){
			copia1 ();
			achou = true;
			break;	
		}else{
			achou = false;
		}
	}
	pro_nao ();
}
busca_codigo(){
	int busca = 0;
	system ("cls");
	printf("\nDigite o codigo de busca: ");
	scanf("%d",&busca);
	for (i = 0; i < sequencia; i ++){
		if (projetos[i].codigo == busca){
			copia1 ();
			achou = true;
			break;
		}else{
			achou = false;
		}
	}
	pro_nao ();
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	do{
		system("cls");
		opcao = 9;
		printf("\nDigite 1 para cadastrar projetos\nDigite 2 para imprimir todos os projetos\nDigite 3 para imprimir todos os projetos com status: A FAZER\nDigite 4 para imprimir todos os projetos com status: FAZENDO\nDigite 5 para imprimir todos os projetos com status: CONCLUÍDO\nDigite 6 para busca de projetos por código\nDigite 0 para sair da aplicação\n");
		printf("\nDigite a opção desejada: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				cadastrar_projeto();
			break;
			case 2:
				todos_projetos();
			break;
			case 3:
				por_status(A);
			break;
			case 4:
				por_status(F);
			break;
			case 5:
				por_status(C);
			break;
			case 6:
				busca_codigo();	
			break;
			case 0:
				printf ("\nSaindo da aplicação! ");
			break;
			default:
				printf("\nOpção inválida!");
				system("pause");							
		}
	}while(opcao != 0 );	
	return 0;
}


