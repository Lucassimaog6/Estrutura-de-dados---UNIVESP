#include <stdio.h>
#include <malloc.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* proximo;
}ELEMENTO;

typedef ELEMENTO* PONTEIRO;

typedef struct {
    PONTEIRO inicio;
} LISTA;

void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

int tamanhoLista(LISTA* l) {
    PONTEIRO end = l->inicio;
    int tamanho = 0;
    while (end != NULL) {
        tamanho++;
        end = end->proximo;
    }
    return tamanho;
}

void exibirLista(LISTA* l) {
    PONTEIRO end = l->inicio;
    printf("Lista: \n");
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->proximo;
    }
    printf("\n");
}

PONTEIRO buscaSequencialAux(LISTA* l, TIPOCHAVE chave, PONTEIRO* anterior) {
    *anterior = NULL;
    PONTEIRO atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave < chave)) {
        *anterior = atual;
        atual = atual->proximo;
    }
    if ((atual != NULL) && (atual->reg.chave == chave)) return atual;
    return NULL;
}

int buscaSequencialOrdenada(LISTA* l, TIPOCHAVE chave) {
    PONTEIRO pos = l->inicio;
    while (pos != NULL && pos->reg.chave < chave) pos = pos->proximo;
    if (pos != NULL && pos->reg.chave == chave) return pos;
    return NULL ;    
}

bool inserirElementoOrdenado(LISTA* l, REGISTRO reg) {
    TIPOCHAVE chave = reg.chave;
    PONTEIRO anterior, i;
    i = buscaSequencialAux(l, chave, &anterior);
    if (i != NULL) return 0;
    i = (PONTEIRO) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if (anterior == NULL) {
        i->proximo = l->inicio;
        l->inicio = i;
    } else {
        i->proximo = anterior->proximo;
        anterior->proximo = i;
    }
    return 1;
}

bool excluirElemento(LISTA* l, TIPOCHAVE chave) {
    PONTEIRO anterior, i;
    i = buscaSequencialAux(l, chave, &anterior);
    if (i == NULL) return 0;
    if (anterior == NULL) l->inicio = i->proximo;
    else anterior->proximo = i->proximo;
    free(i);
    return 1;
}

void reinicializarLista(LISTA* l) {
    PONTEIRO end = l->inicio;
    while (end != NULL) {
        PONTEIRO tmp = end;
        end = end->proximo;
        free(tmp);
    }
    l->inicio = NULL;
}