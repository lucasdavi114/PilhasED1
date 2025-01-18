#pragma once

#define SAIR 0
#define EMPILHAR 1
#define DESEMPILHAR 2
#define IMPRIMIR 3

typedef int chave_t;

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

typedef struct {
    Nodo_t *topo;
    int tamanho;
}Pilha_t;

int pilhaExemplo();

Pilha_t* criaPilha();

// Lê os dados do teclado e insere na estrutura Pessoa.
Pessoa lerPessoa();

// Função para adicionar elemento na pilha.
int push(Pilha_t *p);

// Função para remover elemento da pilha.
int pop(Pilha_t *p, Pessoa *elemento);

// Imprime os dados da Pessoa.
void imprimePessoas(Pessoa p);

// Substitui o caracter de escape '\n' do char *v para um '\0', feito para remover o '\n' de entradas em strings literais da linguagem C.
void retiraCaracterEscape(char* v);

// interface básica para interação
void menu(Pilha_t *p);

// Função para imprimir a pilha completa.
void imprimirPilha(Pilha_t *p);

void destruirPilha(Pilha_t *p);