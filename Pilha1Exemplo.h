#pragma once

#define SAIR 0
#define EMPILHAR 1
#define DESEMPILHAR 2

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    char nome[50];
    Data nascimento;
}Pessoa;

typedef struct nodo {
    Pessoa p;
    struct nodo *proximo;
}Nodo_t;

int pilhaExemplo();

// Lê os dados do teclado e insere na estrutura Pessoa.
Pessoa lerPessoa();

Nodo_t* push(Nodo_t *topo);

Nodo_t* pop(Nodo_t** topo);

// Imprime os dados da Pessoa.
void imprimePessoa(Pessoa p);

// Substitui o caracter de escape '\n' do char *v para um '\0', feito para remover o '\n' de entradas em strings literais da linguagem C.
void retiraCaracterEscape(char* v);

// interface básica para interação
void menu(Nodo_t *topo);

// Função para imprimir a pilha completa.
void imprimirPilha(Nodo_t *topo);