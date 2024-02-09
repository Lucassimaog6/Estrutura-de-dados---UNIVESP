#include <stdio.h>

#define MAX 50

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

int buscaSentinela(LISTA* l, TIPOCHAVE chave) {
    int i = 0;
    l->A[l->numeroElementos].chave = chave;
    while (l->A[i].chave != chave) i++;
    if (i == l->numeroElementos) return -1;
    else return i;
    return i;    
}

bool inserirElemento(LISTA* l, REGISTRO reg, int i) {
    int j;
    if ((l->numeroElementos == MAX) || (i < 0) || (i > l->numeroElementos)) {
        return false;
    }
    for (j = l->numeroElementos; j > i; j--) {
        l->A[j] = l->A[j-1];
    }
    l->A[i] = reg;
    l->numeroElementos++;
    return true;

}

bool excluirElemento(LISTA* l, TIPOCHAVE chave) {
    int pos, j;
    pos = buscaSequencial(l, chave);
    if (pos == -1) return false;
    for (j = pos; j < l->numeroElementos; j++) {
        l->A[j] = l->A[j+1];
    }
    l->numeroElementos--;
    return true;
    
}

void reinicializarLista(LISTA* l) {
    l->numeroElementos = 0;
}