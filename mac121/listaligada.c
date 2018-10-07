#include<stdlib.h>
#include<stdio.h>

typedef int TipoDaLista;

struct celula {
    TipoDaLista info;
    struct celula *prox;
};
typedef struct celula *apontador;

void imprimeLista(apontador inicio) {
    apontador p = inicio;
    while (p != NULL) {
        printf("%d\n", p->info);
        p = p->prox;
    }

    // alternativamente:
    /*
     * for (p = inicio; p != NULL; p = p->prox)
     *      printf("%d", p->info);
     */
}

apontador buscaRec(apontador inicio, int x) {
    if (inicio == NULL) return NULL;
    if (inicio->info == x) return inicio;
    return buscaRec(inicio->prox, x);
}

apontador busca(apontador inicio, int x) {
    apontador p;
    for (p = inicio; p != NULL && p->info != x; p = p->prox)
        return p;
}

apontador insereNoInicio(apontador inicio, int x) {
    apontador novo = malloc(sizeof(struct celula));
    novo->info = x;
    novo->prox = inicio;
    return novo;
}
// chamada: inicio = insereNoInicio(inicio, x);

apontador removePrimeiro(apontador inicio) {
    /* inicio == NULL não faz nada */
    apontador p = inicio;
    if (inicio != NULL) {
        p = inicio->prox;
        free(inicio);
    }
    return p;
}

apontador insereNoFim(apontador inicio, int x) {
    apontador p, novo;
    for (p = inicio; p != NULL && p->prox != NULL; p = p->prox);
    novo = malloc(sizeof(struct celula));
    novo->info = x; novo->prox = NULL;

    if (p == NULL)
        return novo;

    p->prox = novo;
    return inicio;
}

apontador insereNoFimRec(apontador inicio, int x) {
    apontador novo;
    if (inicio == NULL) {
        novo = malloc(sizeof(struct celula));
        novo->info = x;
        novo->prox = NULL;
        return novo;
    }
    inicio->prox = insereNoFimRec(inicio->prox, x);
    return inicio;
}

apontador insereOrdenado(apontador inicio, int x) {
    apontador p, ant, novo;
    for (ant = NULL, p = inicio;
            p != NULL && p->info < x;
            ant = p, p = p->prox);
    novo = malloc(sizeof(struct celula));
    if (ant == NULL) {
        novo->prox = inicio;
        return novo;
    }
    ant->prox = novo;
    novo->prox = p;
    return inicio;
}

int main() {
    apontador lista = NULL;
    insereNoFim(lista, 1);
    insereNoFim(lista, 5);
    imprimeLista(lista);
    removePrimeiro(lista);
    removePrimeiro(lista);

    free(lista);

    return 0;
}
