#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* v;
    int topo;
    int max;
} pilha;

typedef pilha *Pilha;

int PilhaVazia(Pilha P) {
   return P->topo == 0;
}

void resize(Pilha P) {
    char *novo = malloc(2*(P->max)*sizeof(char));

    for (int i = 0; i < (P -> max); i++)
        novo[i] = P->v[i];

    P->max = 2*(P->max);
    free(P->v);
    P->v = novo;
}

void Empilha(Pilha P, char d) {
    if (P->topo == P->max)
        resize(P);

    P->v[P->topo] = d;
    (P->topo)++;
}

void Desempilha(Pilha P) {
    if (PilhaVazia(P)) {
        printf("Erro!\n");
        return;
    }
    (P->topo)--;
}

char TopoDaPilha(Pilha P) {
    if (PilhaVazia(P)) {
        printf("Erro!\n");
        return 0;
    }
    return (P->v[P->topo - 1]);
}

Pilha CriaPilha(int max) {
    Pilha P = malloc(sizeof(pilha));
    P -> v = malloc(max*sizeof(char));
    P->topo = 0;
    P -> max = max;
    return P;
}

void DestroiPilha(Pilha P) {
    free(P);
}

int casa(char c1, char c2) {
    if ((c1 == '(' && c2 == ')') ||
        (c1 == '[' && c2 == ']') ||
        (c1 == '{' && c2 == '}'))
        // casou
        return 1;
    return 0;
}

int bemFormada(char seq[]) {
    int ok = 1, i;
    Pilha P = CriaPilha(1000);
    for (i=0; seq[i] != '\0'; i++)
        if (seq[i] == '(' || seq[i] == '[' || seq[i] == '{')
            Empilha(P, seq[i]);
        else {
            if (PilhaVazia(P)) ok = 0;
            else {
                char c = TopoDaPilha(P);
                if (casa(c, seq[i]))
                    Desempilha(P);
                else
                    ok = 0;
            }
        }
    ok = (ok && PilhaVazia(P));
    DestroiPilha(P);
    return ok;
}

int main() {
    char invalido[] = "[(])";
    char valido[] = "([]{})";

    int result;
    result = bemFormada(invalido);
    printf("%s %sé bem formada\n", invalido, result ? "" : "não ");

    result = bemFormada(valido);
    printf("%s %sé bem formada\n", valido, result ? "" : "não ");
}
