#include <stdio.h>
#include <stdlib.h>
#include "Pilha1Exemplo.h"

int main() {
    return pilhaExemplo();
}

// Lê os dados do teclado e insere na estrutura Pessoa.
Pessoa lerPessoa() {
    Pessoa p;

    printf("\nDigite o nome: ");
    setbuf(stdin, NULL);
    fgets(p.nome, 50, stdin);
    setbuf(stdin, NULL);
    retiraCaracterEscape(p.nome);
    printf("\nEntre com a data de nascimento do %s no formado d/m/ano: ", p.nome);
    scanf("%d/%d/%d", &p.nascimento.dia, &p.nascimento.mes, &p.nascimento.ano);


    return p;
}

void retiraCaracterEscape(char* v) {
    int t;
    for(int indice = 0; indice < 50; indice++) {
        if (v[indice] == '\n') {
            t = indice;
            break;
        }
    }
    if(v[t] == '\n') {
        v[t] = '\0';
    }
}

// Imprime os dados da Pessoa.
void imprimePessoas(Pessoa p) {
    printf("\nNome:%s\nData de Nascimento: %d/%d/%d\n", p.nome, p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);
}

void imprimirPilha(Nodo_t *topo) {

}

void menu(Nodo_t *topo) {
    int opcao;
    Nodo_t *remover;

    do{
        printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir pilha\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case EMPILHAR:
            topo = push(topo);
            break;
        case DESEMPILHAR:
            remover = pop(&topo);
            if(remover) {
                imprimePessoas(remover->p);
            }else {
                printf("\nSem nó a remover!!\n");
            }
            break;
        case SAIR:
            printf("\nEncerrando Programa!!\n");
            break;
        default:
            printf("\nOpçao Invalida!!\n");
            break;
        }

    }while(opcao != SAIR);
}

int pilhaExemplo() {
    
    Nodo_t *topo = NULL;
    
    menu(topo);

    return EXIT_SUCCESS;
}

Nodo_t* push(Nodo_t *topo) {
    Nodo_t *novoNo = malloc(sizeof(Nodo_t));

    if(novoNo){
        novoNo->p = lerPessoa();
        novoNo->proximo = topo;
    }else {
        printf("\nNão foi possível alocar memória!\n");
    }

    return novoNo;
}

Nodo_t* pop(Nodo_t** topo) {
    if(*topo != NULL) {
        Nodo_t* remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else {
        printf("\nPilha Vazia!!\n");
    }
    return NULL;
}

