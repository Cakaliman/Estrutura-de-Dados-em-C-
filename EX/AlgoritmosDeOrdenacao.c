#include <stdio.h>
#include <stdlib.h>
#define NEW_LINE putchar('\n')

/* 
----------========---------EXIBE AS ALTERAÇÕES QUE OCORREM DURANTE A EXECUÇÃO DOS ALGORITMOS DE ORDENAÇÃO EM ALOCAÇÃO ESTÁTICA----------========---------
*/

//REFERENCIA DE FUNCOES PARA MAIN
int particao(int v[], int ini, int fim);
void merge(int v[], int ini, int meio, int fim);
void exibe(int v[], int n);
void bsort(int v[], int n);
void ssort(int v[], int n);
void isort(int v[], int n);
void msort(int v[], int ini, int fim, int n);
void qqsort(int v[], int ini, int fim, int n);

int main(void)
{

    puts("Bubble Sort:");
    int bs[] = {5, 3, 4, 1, 2};
    bsort(bs, 5);

    NEW_LINE;

    puts("Selection Sort:");
    int ss[] = {5, 3, 4, 1, 2};
    ssort(ss, 5);

    NEW_LINE;

    puts("Inserton Sort:");
    int is[] = {5, 3, 4, 1, 2};
    isort(is, 5);

    NEW_LINE;

    puts("Merge Sort:");
    int ms[] = {5, 2, 7, 1, 8, 6, 4, 3};
    msort(ms, 0, 7, 8);

    NEW_LINE;

    puts("Quick Sort:");
    int qs[] = {5, 3, 4, 1, 2};
    qqsort(qs, 0, 4, 5);

    return 0;
}

//BUBBLE SORT
void bsort(int v[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                exibe(v, n);
            }
        }
    }
}

//SELECTION SORT
void ssort(int v[], int n)
{
    int aux, i, j, menor;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[j] < v[menor])  menor = j;
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        exibe(v, n);
    }
}

//INSERTION SORT
void isort(int v[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = v[i];
        for (j = i - 1; j >= 0 && x < v[j]; j--)
            v[j + 1] = v[j];
        v[j + 1] = x;
        exibe(v, n);
    }
}

//MERGE SORT (RECURSIVO)
void msort(int v[], int ini, int fim, int n)
{
    if (ini < fim)
    {
        int meio = (ini + fim) / 2;
        msort(v, ini, meio, n);
        msort(v, meio + 1, fim, n);
        merge(v, ini, meio, fim);
        exibe(v, n);
    }
}

//QUICK SORT (RECURSIVO)
void qqsort(int v[], int ini, int fim, int n)
{
    if (ini < fim)
    {
        int pivo = particao(v, ini, fim);
        exibe(v, n);
        qqsort(v, ini, pivo - 1, n);
        qqsort(v, pivo + 1, fim, n);
    }
}

//FUNCAO PARTICAO
int particao(int v[], int ini, int fim)
{
    int pivo = v[ini], esq = ini + 1, dir = fim, aux;
    while (esq <= dir)
    {
        while (esq <= dir && v[esq] <= pivo) esq++;
        while (v[dir] > pivo)                dir--;
        if (esq < dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
            esq++;
            dir--;
        }
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;
}

//MERGE SORT
void merge(int v[], int ini, int meio, int fim)
{
    int i = ini, j = meio + 1, k = 0, *aux;
    aux = malloc(sizeof(int) * (fim - ini + 1));
    if (aux == NULL)
        abort();
    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= meio)
        aux[k++] = v[i++];
    while (j <= fim)
        aux[k++] = v[j++];
    for (i = ini, j = 0; i <= fim; i++, j++)
        v[i] = aux[j];
    free(aux);
}

void exibe(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++) printf("%d ", v[i]);
    putchar('\n');
}
