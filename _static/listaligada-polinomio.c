#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
