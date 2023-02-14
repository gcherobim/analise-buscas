/**
 * Guilherme de Oliveira Cherobim
 * NUSP 8531139
**/

// estrutura de nó utilizada na lista encadeada, guarda um valor 
// inteiro e um ponteiro para o próximo nó
typedef struct no NO;
struct no {
    int chave;
    NO* proximo;
};