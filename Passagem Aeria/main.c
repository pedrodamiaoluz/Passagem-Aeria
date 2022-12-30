#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include "Funcoes.h"


int main(){

	Lista *lista_passagem = NULL;
	Passagem *passagem = NULL;
	int opcao;

	do{

    	menu();
        //sleep(1);

    	printf("\n-> Informe a opcao que vc deseja ");
		scanf("%d", &opcao);
		system("cls");

	switch (opcao){

		case 1:

			reserva_passagem();
			// lista_passagem = ler_arquivo(lista_passagem);
			lista_passagem = inserir_passagem(lista_passagem, passagem);

		break;

		case 2:

			lista_passagem = list_retira(lista_passagem);

		break;

		case 3:

			list_listar(lista_passagem);

        break;

		case 4:

			lista_passagem = list_busca(lista_passagem);

		break;

		case 5:

			quant_vagas(lista_passagem);

		break;

		case 6:

			quantidade(lista_passagem);

		break;

		case 7:

			printf("Obrigado por ter usado o sistema de passagem aerias.\n");

		break;

		default:

			printf("Este programa possui um bug.\n");

		return 0;
		}

	} while (opcao != 7);
}
