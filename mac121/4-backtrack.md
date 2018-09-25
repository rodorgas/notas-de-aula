# Backtrack

## Problema das n Rainhas
**Problema:** Dado `n>0`, imprima, se existir, uma solução para o problema das `n` rainhas.

Exemplos:

- `n=4`
```
|      |  x   |      |      |
|      |      |      | x    |
|  x   |      |      |      |
|      |      | x    |      |
```
- n=3: Não tem solução



A estratégia que usaremos será backtrack: tentativa e erro implementada numa pilha. Usamos a pilha para guardar as decisões tomadas (em que coluna cada rainha foi colocada) e, quando não conseguimos colocar uma rainha no tabuleiro voltamos à última decisão tomada e tentamos mudá-la.



```C
void nRainhas(int n) {
    Pilha pos = CriaPilha(n);
    int **tab, i, j, atual, col, temsol = 1;

    tab = malloc(n*sizeof(int *));
    for (i=0; i<n; i++)) {
        tab[i] = malloc(n*sizeof(int));
        for (j=0; j<n;j++) tab[i][j] = 0;
    }

    atual = 0; col = 0;;
    while (atual < n && temsol == 1) {
        ok = 0;
        while (atual.mov < 9 && ok == 0) {
            if (PodePular(tab, n, atual))
                ok = 1;
            else {
                atual.mov++;
            }
            if (ok == 1) {
                Empilha(pos, atual);
                atual++;
                tab[atual.linha][atual.col] = pulos;
                atual = proxima(atual);
            }
            else { //backtrack
                pulos--;
                if (PilhaVazia(pos))
                    temsol = 0;
                else {
                    atual = TopoDaPilha(pos);
                    Desempilha(pos);
                    atual.mov++;
                    tab[atual.linha][atual.col] = 0;
                }
            }
        }

        if (temsol == 1)
            imprimeMatriz(tab, n, m);
        else
            printf("Não tem solução\n");

        DestroiPilha(pos);
        for (i = 0; i < n; i++)
            free(tab[i]);
        free(tab);
    }
}
```


## Problema do Pulo do Cavalo

É possível que um cavalo saia da posição (0,0) num tabuleiro nxn e visite todas as posições do tabuleiro com n^2 pulo?

É possível para n=1 e todo n≥5

```C
typedef struct {
    int linha;
    int col;
    int mov;
} PuloDoCavalo;

void puloDoCavalo(int n) {
    Pilha pos = CriaPilha(n);
    int **tab, i, j, pulos, temsol = 1;
    PuloDoCavalo atual;

    tab = malloc(n*sizeof(int *));
    for (i=0; i<n; i++)) {
        tab[i] = malloc(n*sizeof(int));
        for (j=0; j<n;j++) tab[i][j] = 0;
    }

    pulos = 0; atual.linha = 0; atual.col = 0; atual.mov = 1;
    while (pulos < n*n && temsol == 1) {
        ok = 0;
        while (atual.mov < 9 && ok == 0) {
            if (PodePular(tab, n, atual))
                ok = 1;
            else
                atual.mov++;
            if (ok == 1) {
                Empilha(pos, atual);
                tab[atual.linha][atual.col] = pulos;
                atual = proxima(atual);
            }
            else { //backtrack
                pulos--;
                if (PilhaVazia(pos))
                    temsol = 0;
                else {
                    atual = TopoDaPilha(pos);
                    Desempilha(pos);
                    tab[atual][col] = 0;
                    col++;
                }
            }
        }

        if (temsol == 1)
            imprimeMatriz(tab, n, m);
        else
            printf("Não tem solução\n");

        DestroiPilha(pos);
        for (i = 0; i < n; i++)
            free(tab[i]);
        free(tab);
    }
}
```



Queijo do ratinho no labirinto

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

---

Terça, 21 de agosto

Quinta, 23 de agosto
