/**
 * Guilherme de Oliveira Cherobim
 * NUSP 8531139
**/

#include "no.h"

typedef unsigned char bool;
#define TRUE  1
#define FALSE 0

// estrutura da lista encadeada utilizada no bucket, contém um ponteiro
// para o primeiro nó da lista, outro para o último e seu tamanho;
typedef struct lista LISTA;
struct lista
{
    NO* inicio;
    NO* fim;
    int tamanho;
};

LISTA *criar();
void destruir(LISTA* lista);
void inserir(LISTA* lista, int chave);
bool busca(LISTA* lista, int chave);