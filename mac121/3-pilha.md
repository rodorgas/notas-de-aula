# Pilha

**Problema:** Dada uma sequência com `(, [, {, }, ], )`determinar se a sequência é bem formada).

Uma pilha é uma estrutura de dados em que o último elemento que entra será o primeiro a sair. Ela tem uma única extremidade, chamada topo, em que inserções e remoções são feitas:

Exemplo:

- `[(])` não é bem formada
- `([]{})` é bem formada

Funções:

- Empilha: insere um elemento no topo
- Desempilha: remove o elemento do topo
- Pilha vazia: verifica se está vazia
- Topo da pilha: devolve o eleento do topo

 `P->` é idêntico a `(*P)`.

## Implementação

1. ```c
   #define MAX 1000

   // implementação com vetor estático
   typedef struct {
       char v[MAX];
       int topo;
   } pilha
   typedef pilha *Pilha;

   int PilhaVazia(pilha P) {
      return P.topo == 0;
   }
   void Empilha(Pilha P, char d) {
       if (P->topo == MAX) {
           printf("Deu ruim!\n");
           return;
       }
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
       return (P->v[P->topo -1])
   }

   // vetor dinâmico
   Pilha CriaPilha() {
       Pilha P = malloc(sizeof(pilha));
       P->topo = 0;
   }
   void DestroiPilha(Pilha P) {
       free(P);
   }
   void resize(Pilha p) {
       char *novo = malloc(2 * P->max**sizeof(char));
       for (int i=0; i<P->max; i++) novo[i] = P->v[i];
       P->max = 2*P->max;
       free(P->v);
       P->v=novo;
   }
   ```

   ```C
   int bemFormada(char seq[]) {
       int ok = 1, i;
       Pilha P = CriaPilha(1000);
       for (i=0; seq[i] != '\0'; i++)
        if (seq[i] = '(' || seq[i] == '[' || seq[i] == '{')
            Empilha(P, seq[i]);
        else {
               if (PilhaVazia(P)) ok = 0;
            else {
                   c = TopoDaPilha(P);
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
   }

   int casa(char c1, char c2) {
       if ((c1 == '(' && c2 == ')') ||
           (c1 == '[' && c2 == ']') ||
           (c1 == '{' && c2 == '}'))
           // casou
           return 1;
       return 0
   }
   ```

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

---

Terça, 14 de agosto
