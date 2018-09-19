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
} PuloDoCavalo

void nRainhas(int n) {
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

---

Terça, 21 de agosto de 2018
