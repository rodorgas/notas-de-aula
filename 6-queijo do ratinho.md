Quinta, 23 de agosto

## Pilhas

- Posfixa
- Backtrack
  - n rainhas
  - passeio do cavalo
  - queijo do ratinho no labirinto

queijo do ratinho no labirinto

```
+---------------------------------------+
|R/1| 2 | 3 |///|///|///|///|   |///|   |
+---------------------------------------+
|///|///| 4 |   |   |   |   |   |   |   |
+---------------------------------------+
|13 |   | 5 |///|   |///|   |   |///|   |
+---------------------------------------+
|12 |///| 6 |   |   |///|///|   |///|   |
+---------------------------------------+
|11 |///| 7 |///|   |///|   |   |///|   |
+---------------------------------------+
|10 | 9 | 8 | 9 |   |///|   |///|///| Q |
|---------------------------------------+
```



## DFS

**Ideia**: em cada passo até encontrar uma solução ou decidir que não existe, escolhe uma alternativa e empilha a decisão . Se não houver alternativa possível desempilha a última e tenta modificar.

```C
typedef struct {
    int linha;
    int col;
} posicao;

int PodeAndar(int** lab, int m, int n, posicao p, int d) {
    switch (d):
    	case 1:
    		if (p.linha != m - 1 && lab[p.linha+1][p.col] == 0)
            	return 1;
    		break;
    	case 2:
    		
}

int caminho(int **lab, int m, int n, posicao rato, posicao queijo) {
    Pilha P = CriaPilha(m*n);
    posicao atual = rato;
    int passos = 0, temsol = 1, dir = 1, ok = 0;

    while (atual.linha != queijo.linha
           || atual.col != queijo.col) {
        ok = 0;
        while (dir <= 4 && ok == 0)
            if (PodeAndar(lab, m, n, atual, dir))
                ok = 1;
            else
                dir++;

        if (ok == 1) {
            passos++;
            lab[atual.linha][atual.coluna] = passos;
            atual = anda(atual, dir);
            Empilha(P.dir); dir = 0;
        }
        else { /* backtrack */
            if (PilhaVazia(P))
                temsol = 0;
            else {
                dir = TopoDaPilha(P);
                Desempilha(P);
                passos--;
                atual = andar(atual, (dir+2)%4);
                dir++;
            }
        }
    }

    if (temsol == 1)
        imprimeMatriz(lab, m, n);
    else
        printf("Não tem sol");
    DestroiPilha(P);
    return (temsol);
}
```


## Fila

Uma fila é uma estrura em que as inserções são feitas em uma das extremidade (fim) e as remoções são feitas na outra extremidade (começo). Com isso, o primeiro elemento a entrar vai ser o primeiro a sair da fila.

- **Insere**: insere um elemento no fim da fila;
- **Remove**: remove o elemento do começo da fila;
- **PrimeiroDaFila**: devolve o primeiro;
- **FilaVazia**: devolve se está vazia ou não.

```
+---+---+---+---+---+---+---+---+ max
|---|---|---|---|   |   |   |   |
+---+---+---+---+---+---+---+---+
                  ^fim     (não é bom)

+---+---+---+---+---+---+---+---+ max
|   |   |---|---|---|---|   |   |
+---+---+---+---+---+---+---+---+
         ^ início
                          ^ fim

                  v inicio
+---+---+---+---+---+---+---+---+ max
|---|   |   |---|---|---|---|---|
+---+---+---+---+---+---+---+---+
     ^ fim   ^ não é usada
                          ^ fim

inicio == fim               --> vazia
inicio == (fim + 1) % tam   --> cheia
```

 ```C
typedef TipoDaFila ...;
typedef struct {
    TipoDaFila *v;
    int max;
    int inicio;
    int fim;
} fila;

typedef fila *Fila;

Fila CriaFila(int tam) {
    Fila F = malloc(sizeof(fila));
    F->inicio = F->fim = 0;
    F->max = tam;
    F->v = malloc(tam * sizeof(TipoDaDila));
    return F;
}

void insere(Fila F, TipoDaFila x) {
    if ((F->fim + 1) %F->max == F->inicio)
        resize(F);
    F->v[F->fim] = x;
    F->fim = (F->fim + 1) % F->max;
}

int FilaVazia(Fila F) {
    return (F->inicio == F->fim);
}

void remove(Fila F) {
    if (FilaVazia(F))
        printf("Erro!");
    else
        F->inicio = (F->inicio + 1) % F->max;
}

TipoDaFila PrimeiroDaFila(Fila F) {
    if (FilaVazia(F)) {
        printf("Erro");
        return ???
    }
   
    return F->v[F->inicio]);
}
 ```

