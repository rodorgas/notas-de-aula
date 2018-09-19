# Pilha

acessos, inserções e remoções são feitas em uma das extremidades (topo)

Operadores: empilha, desempilha, pila vazia, topo da pilha, cria, destroi.

```C
typedef struct {
    TipodaPilha *v;
    int topo;
    int max;
} pilha;

typedef pilha* Pilha;
```

## Notação posfixa

$(A + B * C) + D * E / (F - G + H * I) - D$

**Problema:** Dada uma expressão aritmética com `+`, `-`, `*`, `(` e `)`, imprima a expressão correspondente na notação posfixa.

```C
int operador (char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int prec(char c) {
    switch(c) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }
}

void posfixa(char expr[]) {
    Pilha p = CriaPilha(100);
    int i;
    for (i=0; expr[i] != '\0'; i++) {
        if (expr[i] == '(')
            Empilha(P, expr[i]);
        else if (expr[i] == ')') {
            c = TopoDaPilha(P);
            while (c != '(') {
                printf("%c", c);
                Desempilha(P);
                c = TopoDaPilha(P);
            }
            Desempilha(P);
        }
        else if (operador(expr[i])) {
            if (PilhaVazia(P)) Empilha(P, expr[i]);
            else {
                c = TopoDaPilha(P);
                while (prec(c) >= prec(expr[i]) && !PilhaVazia(P)) {
                    printf("%c", c);
                    Desempilha(P));
                    if (!PilhaVazia(P)) c = TopoDaPilha(P);
                }
                Empilha(P, expr[i]);
            }
        }
        else
            printf("%c", expr[i]);

    }
    while (!PilhaVazia(P)) {
        printf("%c", TopoDaPilha(P));
        Desempilha(P);
    }

    printf("\n"));
}

int main() {
    char expr[] = "(A+B*C)+D*E/(F-G+H*I)-D";
    posfixa(expr);
    return 0;
}
```

Anexos:

- [postfix.c](resources/postfix.c)
- [queue.c](resources/queue.c)
- [stack.c](resources/stack.c)

---

Quinta, 16 de agosto
