#include <stdio.h>
#include <stdlib.h>

/*
	CRIE UMA FILA CIRCULAR E TESTE
*/

typedef struct fila{
    char vet[7];
    int front;
    int rear;
} FILA;

int next(int n);
void create(FILA *f);
void destroy(FILA *f);
int isfull(FILA *f);
int isempty(FILA *f);
void store(FILA *f, char x);
char retrieve(FILA *f);
void incluir(char paciente, int prioridade);
char retirar(void);

FILA f, f1, f2, f3;

int main(void)
{
    // EXERCÍCIO A
    create(&f);
    printf("Fila vazia: %d\n", isempty(&f));
    store(&f, 'a');
    store(&f, 'b');
    store(&f, 'c');
    store(&f, 'd');
    store(&f, 'e');
    store(&f, 'f');
    printf("Fila cheia: %d\n", isfull(&f));
    destroy(&f);

    // EXERCÍCIO B
    create(&f1);
    create(&f2);
    create(&f3);
    incluir('A', 1);
    incluir('C', 3);
    incluir('B', 1);
    incluir('D', 2);
    incluir('E', 1);
    printf("%c",retirar());
    printf("%c",retirar());
    printf("%c",retirar());
    printf("%c",retirar());
    printf("%c",retirar());

    return 0;
}

int next(int n)
{
    return (n + 1) % 7;
}

void create(FILA *f)
{
    f->rear = f->front = 0;
}

void destroy(FILA *f)
{
    f->rear = f->front;
}

int isfull(FILA *f)
{
    if (next(f->rear) == f->front)
        return 1;
    else
        return 0;
}

int isempty(FILA *f)
{
    if (f->rear == f->front)
        return 1;
    else
        return 0;
}

void store(FILA *f, char x)
{
    if (isfull(f))
    {
        puts("Overflow\n");
        abort();
    }
    f->vet[f->rear] = x;
    f->rear = next(f->rear);
}

char retrieve(FILA *f)
{
    char aux;
    if (isempty(f))
    {
        puts("Underflow\n");
        abort();
    }
    aux = f->vet[f->front];
    f->front = next(f->front);
    return aux;
}

// inclui um paciente na fila de acordo com sua prioridade
void incluir(char paciente, int prioridade)
{
    if (prioridade == 1)
        store(&f1, paciente);
    else if (prioridade == 2)
        store(&f2, paciente);
    else
        store(&f3, paciente);
}

// retira um paciente por vez da fila, dando prioridade para  fila 1
char retirar(void)
{
    if (!isempty(&f1)){
        printf("\nPaciente da fila 1: ");
        retrieve(&f1);
    }
    else if (!isempty(&f2)){
        printf("\nPaciente da fila 2: ");
        retrieve(&f2);
    }  
    else{
        printf("\nPaciente da fila 3: ");
        retrieve(&f3);
    }
}
