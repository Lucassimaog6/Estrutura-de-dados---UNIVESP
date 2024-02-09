#include <stdio.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX+1];
    int numeroElementos;
} LISTA;

void inicializarLista(LISTA* l) {
    l->numeroElementos = 0;
}

int tamanhoLista(LISTA* l) {
    return l->numeroElementos;
}

void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \n");
    for (i=0; i < l->numeroElementos; i++) {
        printf(" %i", l->A[i].chave);
    }
    printf("\n");
}

int buscaBinaria(LISTA* l, TIPOCHAVE chave) {
    int esquerda, meio, direita;
    esquerda = 0;
    direita = l->numeroElementos-1;
    while (esquerda <= direita) {
        meio = ((esquerda + direita) / 2);
        if (l->A[meio].chave == chave) return meio;
        else {
            if (l->A[meio].chave < chave) esquerda = meio + 1;
            else direita = meio - 1;
        }
    }
    return -1;
}

bool inserirElementoOrdenado(LISTA* l, REGISTRO reg) {
    if (l->numeroElementos >= MAX) return 0;
    int pos = l->numeroElementos;
    while (pos > 0 && l->A[pos-1].chave > reg.chave) {
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->numeroElementos++;
}

bool excluirElemento(LISTA* l, TIPOCHAVE chave) {
    int pos, j;
    pos = buscaBinaria(l, chave);
    if (pos == -1) return 0;
    for (j = pos; j < l->numeroElementos; j++) {
        l->A[j] = l->A[j+1];
    }
    l->numeroElementos--;
    return 1;
    
}

void reinicializarLista(LISTA* l) {
    l->numeroElementos = 0;
}