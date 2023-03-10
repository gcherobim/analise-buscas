/**
 * Guilherme de Oliveira Cherobim
 * NUSP 8531139
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição das variaveis que controlam a medição de tempo
clock_t _ini, _fim;

// Definição do tipo booleano
unsigned char typedef bool;
#define TRUE  1
#define FALSE 0

int* ler_inteiros(const char * arquivo, const int n)
{
    FILE* f = fopen(arquivo, "r");

    int * inteiros = (int *) malloc(sizeof(int) * n);

    for (int i = 0; !feof(f); i++)
        fscanf(f, "%d\n", &inteiros[i]);

    fclose(f);

    return inteiros;
}

void inicia_tempo()
{
    srand(time(NULL));
    _ini = clock();
}

double finaliza_tempo()
{
    _fim = clock();
    return ((double) (_fim - _ini)) / CLOCKS_PER_SEC;
}

// função auxiliar de mover_para_frente, recebe o parâmetro fim 
// referente à posição do elemento encontrado e o troca de lugar com 
// o elemento anterior até chegar em 0
void move_para_frente(int fim, int entradas[]) {
    int aux = entradas[fim];
    
    for (int i = fim; i > 0; i--)
    {
        entradas[i] = entradas[i-1];
    }

    entradas[0] = aux;
    
}

// função que realiza a busca com o método de mover para frente
bool mover_para_frente(int chave, int entradas[], int N) {
    for (int i = 0; i < N; i++)
    {
        if (entradas[i] == chave)
        {
            if (i != 0)
            {
                move_para_frente(i, entradas);
            }

            return TRUE;
            
        }
        
    }

    return FALSE;
    
}

int main(int argc, char const *argv[])
{
    const int N = 50000;
    unsigned encontrados = 0;

    int* entradas = ler_inteiros("inteiros_entrada.txt", N);
    int* consultas = ler_inteiros("inteiros_busca.txt", N);

    // realiza busca sequencia com realocação
    inicia_tempo();
    for (int i = 0; i < N; i++) {
        // buscar o elemento consultas[i] na entrada
        if (mover_para_frente(consultas[i], entradas, N) == TRUE)
        {
            encontrados += 1;
        }
    }
    double tempo_busca = finaliza_tempo();

    printf("Tempo de busca    :\t%fs\n", tempo_busca);
    printf("Itens encontrados :\t%d\n", encontrados);

    return 0;
}
