#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include"Funcoes.h"


int main(){
	
  Lista* lista_passagem = NULL;
  Passagem* passagem = NULL;
  int menu;
  
  do{
	
  	printf("\n\t|-----------------------------------------|\n");
  	printf("\t| 1 - Realizar reserva                    |\n");
	printf("\t| 2 - Excluir reseva                      |\n");
	printf("\t| 3 - listar reservas                     |\n");
	printf("\t| 4 - Buscar reserva                      |\n");
	printf("\t| 5 - Cunsultar vagas disponiveis         |\n");
	printf("\t| 6 - Consultar quantidades de passageiro |\n");
	printf("\t| 7 - Sair                                |\n");
	printf("\t|-----------------------------------------|\n");   
	            
    printf("\n-> Informe a opcao que vc deseja ");
    scanf("%d",&menu);
    system("cls");

	switch(menu){
		case 1:
		  
          reserva_passagem();
		  //lista_passagem = ler_arquivo(lista_passagem);
          lista_passagem = inserir_passagem(lista_passagem,passagem);
		  
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
	    

	
  }while(menu != 7);

}



