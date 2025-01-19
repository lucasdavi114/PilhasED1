#include <stdio.h>
#include <stdlib.h>
#include "Fatorial.h"

typedef struct Nodo {
    fat_t numero;
    struct Nodo *proximo;
}Nodo_t;

struct Pilha_t {
    Nodo_t *topo;
    int tamanho;
};

PilhaPtr criaPilha() {
    PilhaPtr p;
    
    p = malloc(sizeof(struct Pilha_t));

    if(p) {
        p->tamanho = 0;
        p->topo = NULL;
    }else {
        printf("\nFalha ao criar a pilha!!\n");
    }
    return p;
}

void terminaPilha(PilhaPtr p) {
    Nodo_t *ptr;

    while(p->topo != NULL) {
        ptr = p->topo;
        p->topo = ptr->proximo;
        free(ptr);
    }
    free(p);
}

// Insere na pilha
int push (PilhaPtr p, fat_t numero) {
    Nodo_t *ptr;
    ptr = malloc(sizeof(Nodo_t));

    if(ptr == NULL)
        return 0;
    
    ptr->numero = numero;
    ptr->proximo = p->topo;
    p->topo = ptr;
    p->tamanho++;
    return 1;
}

// Remove topo da pilha.
int pop (PilhaPtr p, fat_t *numero) {
    Nodo_t *ptr;

    if(p->topo == NULL) {
        return 0;
    }

    ptr = p->topo;
    p->topo = ptr->proximo;
    *numero = ptr->numero;
    free(ptr);
    p->tamanho--;

    return 1;
}

void imprimirPilha(PilhaPtr p) {
    Nodo_t *ptr = p->topo;

    if(p->topo == NULL) {
        printf("\nPilha Vazia\n");
    }else {
        printf("\n\tPilha\n");
        while(ptr) {
            printf("\n\t%d\n", ptr->numero);
            ptr = ptr->proximo;
        }
        printf("\n\tFim da Pilha\n");
    }
}

fat_t calculaFat(int num) {
    PilhaPtr p;
    fat_t resultado = 1;
    p = criaPilha();
    while(num > 1) {
        push(p, num);
        num--;
    }
    imprimirPilha(p);
    while (pop(p, &num)) {
        resultado *= num;
    }
    terminaPilha(p);
    return resultado;
}