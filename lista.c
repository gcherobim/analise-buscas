/**
 * Guilherme de Oliveira Cherobim
 * NUSP 8531139
**/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// função para criar a lista vazia, com tamanho zero
LISTA *criar() {
    LISTA *lista = (LISTA*)malloc(sizeof(LISTA));

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    return lista;
}

// função para destruir a lista a partir de seu inicio
void destruir(LISTA* lista) {
    while (lista->inicio != NULL)
    {
        NO* aux = lista->inicio;
        lista->inicio = aux->proximo;
        free(aux);
        lista->tamanho--;
    }
    
}

// função para inserir um novo nó ao fim da lista
void inserir(LISTA* lista, int chave) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (lista->inicio == NULL)
    {
        novo->chave = chave;
        lista->inicio = novo;
        novo->proximo = NULL;
    } else {
        lista->fim->proximo = novo;
        novo->chave = chave;
        novo->proximo = NULL;
    }

    lista->fim = novo;
    lista->tamanho++;
    
}

// função que realiza a busca de um valor na lista, retorna TRUE se 
// encontrado
bool busca(LISTA* lista, int chave) {
    NO* no;
    if (lista != NULL)
    {
        no = lista->inicio;
        while (no != NULL)
        {
            if (no->chave == chave)
            {
                return TRUE;
            }
            no = no->proximo;
            
        }
        
    }
    return FALSE;
    
}