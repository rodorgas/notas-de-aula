==============
Listas Ligadas
==============
Uma lista ligada armazena elementos de forma que vizinhos possam estar localizados em posições não adjacentes na memória:

Em uma lista ligada:

.. image:: resources/listaligada.svg

A ordem dos elementos na lista é dada através de apontadores. O primeiro elemento da lista é apontado pelo **início**. Cada célula da lista tem o seguinte aspecto:

.. image:: resources/listaligada-aspecto.svg

.. code-block:: c

    struct celula {
        TipoDaLista info;
        struct celula *prox;
    }
    typedef struct celula *apontador;

Implementação
=============
Faça uma função que recebe uma lista ligada com números inteiros apontada por início e imprime os números.

.. code-block:: c

    void imprimeLista(apontador inicio) {
        apontador p = inicio;
        while (p != NULL) {
            printf("%d", p->info);
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
        for (p = inicio; p != NULL && p->info != x; p = p->prox);
            return p;
    }

    apontador insereNoInicio(apontador inicio, int x) {
        apontador novo = malloc(sizeof(struct celula));
        novo->info = x;
        novo->prox = inicio;
        return novo;
    }
    // chamada: inicio = insereNoInicio(inicio, x);

    // alternativamente, passando ponteiro:
    apontador insereNoInicio(apontador *inicio, int x) {
        apontador novo = malloc(sizeof(struct celular));
        novo->info = x;
        novo->prox = *inicio;
        *inicio = novo;
    }
    // chamada: insereNoInicio(&inicio, x);

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
        apontador p;
        for (p = inicio; p != NULL || p->prox != NULL; p = p->prox);
        novo = malloc(sizeof(struct celula));
        novo->info = x; novo->prox = NULL:
    }
