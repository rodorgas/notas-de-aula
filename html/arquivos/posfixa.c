
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* v;
    int topo;
    int max;
} pilha;

typedef pilha* Pilha;

int PilhaVazia(Pilha P) {
    if (P -> topo == 0) return 1;
    return 0;
}

void resize(Pilha P) {
    char* novo = malloc(2*(P -> max)*sizeof(char));
    for (int i = 0; i < (P -> max); i++) {
        novo[i] = P -> v[i];
    }
    P -> max = 2*(P -> max);
    free(P -> v);
    P -> v = novo;
}

void Empilha(Pilha P, char el) {
    if (P -> topo == P -> max) {
        resize(P);
    }
    P -> v[P -> topo] = el;
    (P -> topo)++;    
}

void Desempilha(Pilha P) {
    if (PilhaVazia(P)) {
        printf("Erro\n");
        return;
    }
    (P -> topo)--;
}

char TopoDaPilha(Pilha P) {
    if (PilhaVazia(P)){
        //printf("Erro\n");
        return 0;    
    }
    return (P -> v[P -> topo -1]);
}

Pilha CriaPilha(int max) {
    Pilha P = malloc(sizeof(pilha));
    P -> v = malloc(max*sizeof(char));
    P -> topo = 0;
    P -> max = max;
    return P;
}

void DestroiPilha(Pilha P) {
    free(P);
}

int casa(char c1, char c2) {
    if ((c1 == '(' && c2 == ')') ||  (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}')) return 1;
    return 0;
}

int operador(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return 1;
    return 0;
}

int prec(char c) {
    switch(c) {
        case '(': 
            return 0;
            break;
        case '+': 
            return 1;
            break;
        case '-': 
            return 1;
            break;
        case '*': 
            return 2;
            break;
        case '/': 
            return 2;
            break;
        default: return -1;
    }
}

void posfixa (char expr[]) {
    Pilha P = CriaPilha(100);
    char c;
    int n = strlen(expr);
    for(int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            Empilha(P, expr[i]);
        } else if (expr[i] == ')') {
            c = TopoDaPilha(P);
            while (c != '(') {
                printf("%c", c);
                Desempilha(P);
                c = TopoDaPilha(P);
            }
            Desempilha(P);
        } else if (operador(expr[i])) {
            if (PilhaVazia(P)) Empilha(P, expr[i]);
            else {
                c = TopoDaPilha(P);
                while (prec(c) >= prec(expr[i]) && !PilhaVazia(P)) {
                    printf("%c", c);
                    Desempilha(P);
                    if (!PilhaVazia(P)) c = TopoDaPilha(P);
                }
                Empilha(P, expr[i]);
            }
        } else {
            printf("%c", expr[i]);
        }
    }
    while (!PilhaVazia(P)) {
        printf("%c", TopoDaPilha(P));
        Desempilha(P);
    }
    printf("\n");
}


int main() {
    char expressao[] = "(A+B*C)+D*E/(F-G+H*I)-D";
    posfixa(expressao);
    return 0;
}
