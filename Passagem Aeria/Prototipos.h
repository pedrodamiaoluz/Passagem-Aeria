//#ifndef PASSAGEM_H
//#define PASSAGEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passagem Passagem;
typedef struct Lista Lista;

Lista* lista_cria;

void menu();

Passagem* reserva_passagem(void);

Lista* list_retira(Lista*lt);

Lista* inserir_passagem(Lista* lista_passagem,Passagem * nome);

void exibe_passagem(Passagem* lista_passagem);

void list_listar(Lista* lista_passagem);

Lista* list_busca(Lista* lista_passagem);

Lista* ler_arquivo(Lista* lista_passagem);

void quantidade(Lista *lista_passagem);

void quant_vagas(Lista *lista_passagem);
