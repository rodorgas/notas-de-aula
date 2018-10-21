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

Anexo: `listaligada.c`_

.. _listaligada.c: ../_static/listaligada.c

Aplicação
=========
Representação de polinômios usando listas ligadas.

Considere um polinômio de coeficientes reais:

.. math::

    p(x) = a_0 + a_1 x + a_2 x^2 + \ldots + a_n x^n

Exemplo:

.. math::

    p(x) = 3.5 - 7x^{14} + 3.14x^{123} - 0.3x^{1279}

Como representar um polinômio no computador?

**Ideia 1:** usando um vetor colocando no índice :math:`i` o coeficiente do termo de grau :math:`i`.

Essa representação como desvantagem o desperdício de espaço caso o polinômio seja esparso, ou seja, ele tenha poucos coeficientes não nulos.

**Ideia 2:** lista ligada com os elementos não nulos do polinômio. Cada célula da lista ligada guarda o grau e o coeficiente não nulo do termo. Vamos considerar que os termos estão ordenados em ordem crescente de grau:

.. image:: resources/listaligada-polinomio.svg

.. code-block:: c

    typedef struct cel {
        float coef;
        int expo;
        struct cel *prox;
    } celula;
    typedef celula *polinomio;

    float avalia(polinomio p, float x) {
       /* devolve p(x) */
       float resultado = 0.0;
       polinomio ap = p;

       while (ap != NULL) {
          resultado += ap->coef * pow(x, ap->expo);
          ap = ap->prox;
       }

       return resultado;
    }

Se eu tenho um polinômio de grau máximo :math:`k`, :math:`m` termos não nulos, o número de somas é :math:`n` e o tempo para todos as operações de exponenciação é :math:`k`.

Na representação por vetor é proporcional ao grau máximo.

**Exercício:** soma de polinômios.

.. code-block:: c

    polinomio criacelula(float c, int e) {
        polinomio novo = malloc(sizeof(celula));
        novo->coef = c;
        novo->expo = e;
        novo->prox = NULL;
        return novo;
    }

    polinomio soma(polinomio p, polinomio q) {
        polinomio soma = NULL, ult = NULL, ap = p, aq = q, novo;
        while (ap != NULL && aq != NULL) {
            if (ap->expo < aq->expo) {
                novo = malloc(sizeof(celula));
                novo->coef = ap->coef;
                novo->expo = ap->expo;
                ap = ap->prox;
            }
            else if (ap->expo < ap->expo) {
                novo = criacelula(aq->coef, aq->expo);
                aq = aq->prox;
            }
            else {
                if (ap->coef + aq->coef != 0.0) {
                    // nunca vai dar zero devido a problemas de representacao.
                    // precisa estar em modulo epsilon.
                    novo = criacelula(ap->coef + aq->coef, ap->expo);
                    ap = ap->prox;
                    aq = aq->prox;
                }
            }

            if (novo != NULL)
                if (soma == NULL)
                    soma = ult = novo;
                else {
                    ult->prox = novo;
                    ult = novo;
                }
        }

        while (ap != NULL) {
            novo = criacelula(ap->coef, ap->expo);
            ap = ap->prox;
            if (soma == NULL)
                soma = ult = novo;
            else {
                ult->prox = novo;
                ult = novo;
            }
        }

        while (aq != NULL) {
            novo = criacelula(aq->coef, aq->expo);
            aq = aq->prox;
            if (soma == NULL)
                soma = ult = novo;
            else {
                ult->prox = novo;
                ult = novo;
            }
        }
    }
