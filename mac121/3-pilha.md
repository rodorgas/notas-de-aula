# Pilha

Uma pilha é uma estrutura de dados em que o último elemento que entra será o primeiro a sair. Ela tem uma única extremidade, chamada topo, em que inserções e remoções são feitas.

Funções:

- **Empilha**: insere um elemento no topo
- **Desempilha**: remove o elemento do topo
- **Pilha vazia**: verifica se está vazia
- **Topo da pilha**: devolve o eleento do topo

 `P->` é idêntico a `(*P)`.

## Implementação

```c
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
```

## Sequências bem formadas

**Problema:** Dada uma sequência com `(, [, {, }, ], )`determinar se a sequência é bem formada).

Exemplo:

- `[(])` não é bem formada
- `([]{})` é bem formada

```C
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
```

Anexo: [bemformada.c](../_static/bemformada.c)

## Análise Assintótica

Dizemos que:

$$
f(n)=O(g(n))
$$
se existem $c, n_0 > 0$ tais que:
$$
f(n) \le c\cdot g(n) \quad \forall n \ge n_0
$$

Ex.:
- $f(n) = 1000000n$ é $O(n)$
- $f(n) = n^2 + 10000n$ é $O(n^2)$
- $f(n) = n + 1$



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

Anexos [postfix.c](../_static/postfix.c), [stack.c](../_static/stack.c)

------

Terça, 14 de agosto

Quinta, 16 de agosto