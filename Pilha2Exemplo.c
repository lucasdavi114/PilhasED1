#include <stdio.h>
#include <stdlib.h>
#include "Pilha2Exemplo.h"

int main() {
    return pilhaExemplo();
}

int pilhaExemplo() {
    
    Pilha_t *pilha;

    pilha = criaPilha();
    if(pilha) {
        printf("\nPilha Criada!!\n");
    }
    menu(pilha);

    destruirPilha(pilha);
    
    printf("\nEncerrando Programa!!\n");

    return EXIT_SUCCESS;
}

void menu(Pilha_t *p) {
    int opcao;
    Pessoa pessoaRemovida;

    do{
        printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir pilha\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case EMPILHAR:
            push(p);
            break;
        case DESEMPILHAR:
            if(pop(p, &pessoaRemovida)) {
                imprimePessoas(pessoaRemovida);
            }else {
                printf("\nSem nó a remover!!\n");
            }
            break;
        case IMPRIMIR:
            imprimirPilha(p);
            break;
        case SAIR:
            break;
        default:
            printf("\nOpçao Invalida!!\n");
            break;
        }

    }while(opcao != SAIR);
}

Pilha_t* criaPilha() {
    Pilha_t *p;
    p = malloc(sizeof(Pilha_t));
    if (p == NULL) {
        printf("\nFalha ao criar a pilha!!\n");
    }else {
        p->topo = NULL;
        p->tamanho = 0;
    }

    return p;
}

// Lê os dados do teclado e insere na estrutura Pessoa.
Pessoa lerPessoa() {
    Pessoa p;
    
    printf("\nDigite o nome: ");
    setbuf(stdin, NULL);
    fgets(p.nome, 50, stdin);
    setbuf(stdin, NULL);
    retiraCaracterEscape(p.nome);
    printf("Entre com a data de nascimento do %s no formado d/m/ano: ", p.nome);
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
    printf("\nNome:%s\nData de Nascimento: %.2d/%.2d/%.2d\n", p.nome, p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);
}

void imprimirPilha(Pilha_t *p) {

    printf("\n-Pilha Tam: %d-\n", p->tamanho);
    Nodo_t *atual = p->topo;
    while (atual) {
        imprimePessoas(atual->p);
        atual = atual->proximo;
    }
    printf("\n-Fim Pilha\n");

}


int push(Pilha_t *p) {
    Nodo_t *novoNo = malloc(sizeof(Nodo_t));

    if(novoNo){
        novoNo->p = lerPessoa();
        printf("\nPessoa Criada!!\n");
        novoNo->proximo = p->topo;
        p->topo = novoNo;
        p->tamanho += 1;
        return 1;
    }else {
        printf("\nNão foi possível alocar memória!\n");
    }
    return 0;
}

// Desempilha a pilha recebe a pilha e um elemento do tipo nó que vai receber o endereço para 
// enviar o nó desempilhado, retorna 1 se desempilhou com sucesso 0 se não.
int pop(Pilha_t *p, Pessoa *elemento) {
    
    if(p->topo) {
        Nodo_t *no = p->topo;
        *elemento = no->p;
        p->topo = no->proximo;
        p->tamanho -= 1;
        free(no);
        return 1;
    }else {
        printf("\nPilha Vazia!!\n");
    }
    return 0;
}

void destruirPilha(Pilha_t *p) {
    Pessoa temp;
    while (pop(p, &temp)); // Remove todos os nós
    free(p); // Libera a estrutura da pilha
}