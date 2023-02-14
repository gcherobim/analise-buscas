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

    int* inteiros = (int *) malloc(sizeof(int) * n);

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

// função para a ordenação dos elementos do vetor por particionamento 
// de Lomuto
void sort(int entradas[], int inicio, int fim) {
    if (inicio >= fim)
    {
        return;
    }
        
    int meio = inicio + (fim - inicio) / 2;
    int pivo = entradas[meio];
    int i, j;
    i = j =0;

    entradas[meio] = entradas[fim];
    entradas[fim] = pivo;

    for (; j < fim; j++)
    {
        if (entradas[j] < pivo)
        {
            int aux = entradas[j];
            entradas[j] = entradas[i];
            entradas[i] = aux;
            i++;
        }
        
    }
    
    entradas[fim] = entradas[i];
    entradas[i] = pivo;

    sort(entradas, inicio, i - 1);
    sort(entradas, i + 1, fim);
    
}

// função que realiza a busca sequencial na tabela de índices, 
// comparando as chaves com os intervalos compreendidos entre dois 
// índices consecutivos
int busca_indice(int chave, int indices[], int tam) {
    for (int i = 0; i < tam; i++)
    {
        if (indices[i] <= chave && chave <= indices[i + 1])
        {
            return i;
        }
        
    }

    // retorna tam-1 se não estiver em nenhum dos outros intervalos,
    // pois não tem elemento seguinte para comparar
    return tam - 1;
    
}

// função para a busca sequencial em um intervalo específico do vetor
bool busca_sequencial(int chave, int entradas[], int comeco, int fim) {
    for (int i = comeco; i < fim + 1; i++)
    {
        if (entradas[i] == chave)
        {
            return TRUE;
        }
        
    }

    return FALSE;
    
}

int main(int argc, char const *argv[])
{
    const int N = 50000;
    const int index_size = 10000;
    unsigned encontrados = 0;

    int* entradas = ler_inteiros("inteiros_entrada.txt", N);
    int* consultas = ler_inteiros("inteiros_busca.txt", N);
    
    // ordenar entrada
    sort(entradas, 0, N);
    
    

    // criar tabela de indice
    int tam = N / index_size;
    int indices[tam];
    for (int i = 0; i < tam; i++)
    {
        indices[i] = entradas[i * index_size];
    }
    
    

    // realizar consultas na tabela de indices 
    inicia_tempo();
    for (int i = 0; i < N; i++) {
        // buscar o elemento consultas[i] na entrada
        int comeco = busca_indice(consultas[i], indices, tam) * index_size;
        if (busca_sequencial(consultas[i], entradas, comeco, comeco + index_size) == TRUE)
        {
            encontrados += 1;
        }
        
    }
    double tempo_busca = finaliza_tempo();

    printf("Tempo de busca    :\t%fs\n", tempo_busca);
    printf("Itens encontrados :\t%d\n", encontrados);

    return 0;
}
