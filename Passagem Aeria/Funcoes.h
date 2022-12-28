#include <stdio.h>
#include <stdlib.h>
#include "Prototipos.h"


 struct Passagem{
	char nome[50];
	char origem[50];
	char destino[50];
	int numero_aviao;
	
};

 struct Lista{
	Passagem* infor;
	struct Lista* prox;
	
};

void menu(){

	 printf("\t1 - Realizar reserva\n\t2 - Excluir reseva\n\t3 - listar reservas\n\t4 - Buscar reserva\n");
	 printf("\t5 - Cunsultar vagas disponiveis\n\t6 - Consultar quantidades de passageiro\n\t7 - Sair\n");
}


Passagem* reserva_passagem(void){
	
	Passagem* passagem = (Passagem*)malloc(sizeof(Passagem));
	printf("-> Informe Seu Nome ");
	scanf("%s",passagem->nome);
	fflush(stdin);
	printf("\n");
	

	printf("-> Informe a origem ");
	gets(passagem->origem);
	fflush(stdin);
	printf("\n");
	
	printf("-> Informe o Destino ");
	gets(passagem->destino);
	fflush(stdin);
	printf("\n");
	
	printf("-> Informe o numero do aviao ");
	scanf(" %d",&passagem->numero_aviao);
	fflush(stdin);
	printf("\n");
	
	FILE* arquivo = fopen("entradapassagem.txt", "a");
	if(arquivo == NULL){
		printf("Erro ao abir o arquivo: ");
		exit(1);
	}
	
	fprintf(arquivo, "%s\t%s\t%s\t%d\t\n", passagem->nome,passagem->origem,passagem->destino,passagem->numero_aviao);
	fclose(arquivo);
	
	return passagem;
}

Lista* list_retira(Lista* l){
	FILE* arquivo;
	FILE* arquivomodificado;
	//Lista* ant;
	//Lista* p = l;
	char nome[50];
	

	arquivo = fopen("entradapassagem.txt", "rb");
	arquivomodificado = fopen("entradapassagems.txt", "ab");

	if(arquivo == NULL || arquivomodificado == NULL){
		printf("Problema em abrir o arquivo: ");
	}else{
		fflush(stdin);
		printf("\nInforme o nome do passageiro a ser removido: ");
	    gets(nome);

		while(fread(l, sizeof(Lista), 1, arquivo) == 1){
			if(strcmp(nome, l->infor) != 0){
				fwrite(l, sizeof(Lista), 1, arquivomodificado);
			}

		}

	}
     fclose(arquivo);
	 fclose(arquivomodificado);
	 remove("entradapassagem.txt");
	 rename("entradapassagems.txt", "entradapassagem.txt");
	 printf("Nome Excluido!\n");
	 getch();
	
	
	/*printf("\nInforme o nome do passageiro a ser removido: ");
	scanf("%s",nome);
	fflush(stdin);
		
	while(strcmp(p->infor->nome,nome)!=0){
		if(p==NULL)
		return l;
		ant = p;
		p = p->prox;

		
	}
	
	if(ant==NULL){
		l = p->prox;
		
	}else{
		ant->prox = p->prox;
	}
	
	printf("==== Nome removido com sucesso ====\n\n");
	free(p);
	return l;*/
	return arquivomodificado;
}

Lista* inserir_passagem(Lista* lista_passagem,Passagem * nome){
	Lista* new_passagem = (Lista*)malloc(sizeof(Lista));
	new_passagem->infor = nome;
	new_passagem->prox = lista_passagem;
	return new_passagem;
}

void list_listar(Lista* lista_passagem){
	Lista* cont;

	for(cont=lista_passagem; cont!=NULL; cont=cont->prox){
		printf("----passagem----\n");
		
	     exibe_passagem(cont->infor);
		
		printf("------------------\n");
	}

}

void exibe_passagem(Passagem* lista_passagem){
	printf("Nome: %s\nOrigem: %s\nDestino: %s\\nNumero do Aviao: %d\n\n",lista_passagem->nome,lista_passagem->origem,lista_passagem->destino,lista_passagem->numero_aviao);
}

Lista * list_busca(Lista* lista_passagem){

	char nome_buscado[50];

	printf("\nInforme o nome que voce deseja buscar? ");
	scanf("%s",nome_buscado);
	
	Lista* aux;

	/*while(aux && aux->infor->nome != EOF){
		aux = aux->prox;
		if(aux){
            aux = lista_passagem ;
		   	printf("\n%s Elemento encontrado \n",nome_buscado);				 
		}
		else{
			printf("\n%s Elemento nao encontrado\n",nome_buscado);
		}
        return aux;
	}*/
	
    
	for(aux=lista_passagem; aux!=NULL; aux=aux->prox){
		
	  if(strcmp(aux->infor->nome, nome_buscado)==NULL){
			printf("O nome %s foi encontrado!\n\n", nome_buscado);	
			
		}
		
		return aux;
	}
	
	printf("O nome buscado nao foi encontrado!\n\n");
	printf("------------------\n");

	   return NULL;
}	

/*Lista* ler_arquivo(Lista* lista_passagem){
	int n;
	char linha[100];

	FILE* arquivo = fopen("entradapassagem.txt", "r");
	if(arquivo == NULL){
		printf("Erro ao abir o arquivo: ");
		exit(1);
	}

	while(fgets(linha,100,arquivo) != NULL){
	  fscanf(arquivo, "%s\t%s\t%s\t%s\t%d\t\n",lista_passagem->infor->nome,lista_passagem->infor->origem,lista_passagem->infor->destino,&lista_passagem->infor->numero_aviao);
	  n++;
	}
	return lista_passagem;
}*/


void quantidade(Lista* lista_passagem){
	Lista * i;
	int conta = 0;
	
	for(i = lista_passagem; i != NULL; i = i->prox){
		conta++;
	}
	
	printf("======== QUANTIDADE DE PASSAGEIRO ========\n");
	printf("\n\t existe %d passageiro!\n\n",conta);
	printf("========================================\n\n");
}

void quant_vagas(Lista* lista_passagem){
	Lista * i;
	int pass = 100;
	
	for(i = lista_passagem; i != NULL; i = i->prox){
		pass--;
	}
	
	printf("========== QUANTIDADE DE VAGAS ==========\n");
	printf("\n\t existe %d Vagas!\n\n",pass);
	printf("=======================================\n\n");
}
 
 