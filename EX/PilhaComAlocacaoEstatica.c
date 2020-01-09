#include <stdio.h>
#include <stdlib.h>
#include <Ctype.h>

/*
-----======-----CRIA UMA PILHA EM ALOCAÇÃO ESTÁTICA (COM TESTES)-----======-----
*/

typedef struct pilha{
    int topo;
    char item[10];
} PILHA;

//REFERENCIA DE FUNCOES PARA MAIN 
void create(PILHA *pilha);
void destroy(PILHA *pilha);
int isfull(PILHA *pilha);
int isempty(PILHA *pilha);
void push(PILHA *pilha, char x);
char pop(PILHA *pilha);
int ispalindromo(char *str);
void inverte(char *str);

int main(void){

    // EXERCÍCIO A
    PILHA pilha;
    create(&pilha);
    push(&pilha, 'B');
    push(&pilha, 'r');
    push(&pilha, 'a');
    push(&pilha, 's');
    push(&pilha, 'i');
    push(&pilha, 'l');
    printf("Pilha vazia? %d\n", isempty(&pilha));
    printf("Pilha cheia? %d\n", isfull(&pilha));
    printf("Item do topo: %c\n", pop(&pilha));
    destroy(&pilha);

    // EXERCÍCIO B
    char a[10];
    printf("\nDigite uma palavra: ");
    gets(a);
    printf("Eh palindromo: %d\n", ispalindromo(a));
    
    // EXERCÍCIO C
    char c[10];
    printf("\nDigite uma palavra: ");
    gets(c);
    inverte(c);
    printf("Palavra invertida: %s", c);
    
    return 0;
}

//CRIA PILHA
void create(PILHA *pilha){
    pilha->topo = -1;
}

//DESTROI PILHA
void destroy(PILHA *pilha){
    pilha->topo = -1;
}

//VERIFICA PILHA CHEIA
int isfull(PILHA *pilha){
    return pilha->topo == 9;
}

//VERIFICA PILHA VAZIA
int isempty(PILHA *pilha){
    return pilha->topo == -1;
}

//INSERE (PUSH) ELEMENTO NA PILHA
void push(PILHA *pilha, char x){
    if (isfull(pilha)){
        puts("Overflow");
        abort();
    }
    pilha->topo++;
    pilha->item[pilha->topo] = x;
}

//REMOVE (POP) ELEMENTO DA PILHA
char pop(PILHA *pilha){
    char aux;
    if (isempty(pilha)){
        puts("Underflow");
        abort();
    }
    aux = pilha->item[pilha->topo];
    pilha->topo--;
    return aux;
}

//RETORNA VALOR DO TOPO DA PILHA
char top(PILHA *pilha){
    if (isempty(pilha)){
        printf("Underflow\n");
        abort();
    }
    return pilha->item[pilha->topo];
}

//FUNCAO PALINDROMO
int ispalindromo(char *str){
    PILHA pilha;
    create(&pilha);
    int indice;
    for(indice = 0; str[indice] != '\0'; indice++)
        push(&pilha, str[indice]);
    for(indice = 0; !isempty(&pilha); indice++)
        if (tolower(str[indice]) != tolower(pop(&pilha))) 
            return 0;
    return 1;
}

//FUNCAO INVERTE PILHA
void inverte(char *str){
    PILHA pilha;
    create(&pilha);
    int indice, aux = 0;
    for (indice = 0; str[indice] != '\0'; indice++){
        if (str[indice] == 32){
            while (!isempty(&pilha)){
                str[aux++] = pop(&pilha);
            }
            indice++, aux++;            
        }
        push(&pilha, str[indice]);
    }
    while(!isempty(&pilha)){
        str[aux++] = pop(&pilha);
    }    
}
