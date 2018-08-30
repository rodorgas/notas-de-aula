# Filas

Terça, 28 de agosto

Problema: do ratinho, agora com filas

![implementacao](/Users/rodrigoorem/Desktop/implementacao.png)

Ideia: a partir da posicao do rato vamos numerando os vizinhos e colando numa fila. Dijkstra

```C
typedef posicao TipoDaFila;
int caminhoMinimo(int **lab, int m, int n, posicao rato, posicao queijo) {
    Fila F = CriaFila(m + n);
    posicao atual = rato;
    int dir, temsol = 1;
    lab[atual.linha][atual.col] = 1;
    insere(F, atual);
    
    while (!FilaVazia(F) && 
           (atual.linha != queijo.linha || atual.col != queijo.col)) {
        atual = PrimeiroDaFila(F);
        for (dir = 0; dir < 4; dir++)
            if (PodeIr(lab, m, n, atual, dir)) {
                prox = anda(atual, dir);
                insere(F, prox);
                lab[prox.linha][prox.col] = lab[atual.linha][atual.col] + 1;
            }
    }
    
    if (atual.linha == queijo.linha && atual.col = queijo.col)
        imprimeMatriz(lab, m, n);
    else {
        printf("Não tem caminho\n");
        temsol = 0;
    }
    
    destroiFila(F);
    return temsol;
}
```

# Recursão

Dizemos que uma função é recursiva se em sua definição a própria função é usada.

Exemplos:
$$
n! =
\begin{cases}
1, &n = 0 \\
n(n-1)!, &n > 0
\end{cases}
$$

$$
2^n = \begin{cases}
1, &n=0 \\
2*2^{n-1}, &n>0
\end{cases}
$$

$$
F(n) = \begin{cases}
1, &n=1 \text{ ou } n=2 \\
F(n-1) + F(n-2), &n>2
\end{cases}
$$

Em computação dizemos que uma função é recursiva se dentro do corpo da função temos uma chamada para ela própria.

Recursão de calda: só tem uma chamada recursiva no fim.

Exemplo:

```C
int fatorial (int n) {
    if (n == 0) return 1;
    return n*fatorial(n-1));
}

int expo2(int n) {
    if (n == 0)
        return 1;
    return (2* expo2(n-1));
}
```

Ex faça uma função recursiva que recebe um vetor com n elementos inteiros e devolve o maior

```C
int maximo(int v[], int n) {
    if (n == 1) return v[0];
    int max = maximo (v, n-1);
    if (max > v[n-1])
        return (max)
    return v[n-1];
}
```

Faça uma função recursiva que recebe um inteiro d>0 e calcula a soma dos dígitos de d.

Ex: d=2751438 -> 30

```C

```

