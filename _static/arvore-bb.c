#include<stdio.h>

typedef struct no {
  TipoDaArvore info;
  struct no *pai;
  struct no *esq;
  struct no *dir;
} No;

typedef No *apontador;

apontador buscaRec(apontador raiz, TipoDaArvore x) {
    /* Devolve um apontador para o no que contem x ou NULL se x nao esta
     * na arvore.
     * Complexidade: O(altura)
     */
    if (raiz == NULL || raiz->info == x)
        return raiz;

    if (raiz->info > x)
        return buscaRec(raiz->esq, x);
    else
        return buscaRec(raiz->dir, x);
}

apontador busca(apontador raiz, TipoDaArvore x) {
    // versao iterativa
    apontador p = raiz;

    while (p != NULL && p->info != x) {
        if (p->info > x)
            p = p->esq;
        else
            p = p->dir;
    }

    return p;
}

apontador minimoRec(apontador raiz) {
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;

    return minimoRec(raiz->esq);
}

apontador minimo(apontador raiz) {
    apontador p = raiz;
    while (p != NULL || p->esq != NULL)
        p = p->esq;

    return p;
    }
}

apontador insereRec(apontador raiz, TipoDaArvore x) {
    /* Devolve um apontador para a raiz da arvore com x incluido.
     */
    if (raiz == NULL) {
        raiz = malloc(sizeof(celula));
        raiz->info = x;
        raiz->dir = raiz->esq = NULL;
    }

    if (raiz->info > x) {
        raiz->esq = insere(raiz->esq, x);
        raiz->esq->pai = raiz;
    }
    else if (raiz->info < x) {
        raiz->dir = insere(raiz->dir, x);
        raiz->dir->pai = raiz;
    }

    return raiz;
}

apontador insere(apontador raiz, TipoDaArvore x) {
    apontador p, q, novo;
    p = raiz; q = NULL;

    while (p != NULL && p->info != x) {
        q = p;
        if (p->info > x)
            p = p->esq;
        else
            p = p->dir;
    }

    if (p == NULL) {
        novo = malloc(sizeof(celula));
        novo->info = x;
        novo->esq = novo->dir = NULL;
        novo->pai = q;

        if (q == NULL)
            raiz = novo;
        else if (q->info < x)
            q->dir = novo;
        else
            q->esq = novo;
    }

    return raiz;
}

apontador remove(apontador raiz, TipoDaArvore x) {
    /* Complexidade: O(altura)
     */
    apontador aux;

    if (raiz != NULL)
        if (raiz->info > x)
            raiz->esq = remove(raiz->esq, x);
        else if (raiz->info < x)
            raiz->dir = remove(raiz->dir, x);
        else
            if (raiz->dir == NULL) {
                aux = raiz;
                raiz = raiz->esq;
                if (raiz != NULL)
                    raiz->pai = aux->pai;
                free(aux);
            }
            else if (raiz->esq == NULL) {
                aux = raiz;
                raiz = raiz->dir;
                raiz->pai = aux->pai;
                free(aux);
            }
            else {
                // tem os dois filhos
                aux = maximo(raiz->esq);
                raiz->info = aux->info;
                raiz->esq = remove(raiz->esq, aux->info);
            }

    return raiz;
}

int main() {
    apontador raiz = NULL;
    int i, n, x;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", x);
        raiz = insere(raiz, x);
    }

    // imprime arvore na ordem
    in_ordem(raiz);
}
