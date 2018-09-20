# Ordenação

.. include:: ../README.txt

**Problema geral:** Dado um vetor com `n >= 0` elementos, rearranje os elementos do vetor de forma que fiquem em ordem crescente: `v[0] <= v[1] <= ... <= v[n-1]`

## Ordenação por seleção

```
44  75  12 27 *95* 15   3   73  19     maior: 95
44 *75* 12 27  19  15   3   73 [95]    maior: 75
44 *73* 12 27  19  15   3  [75  95]    maior: 73
...
Com n-1 passos, o vetor está ordenado
( )[                              ]
```

**Ideia:** Em cada passo encontra o maior do pedaço do vetor que estamos considerando e troca com o último. Em `n-1` passos o vetor está ordenado.

```C
void troca(float v[], int i, int j) {
    float aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selecao(float v[], int n) {
    int i, imax, j;
    for (i = 1; i <= n-1; i++) {
        /* Invariante: Para todo i, sei que os i-1 maiores
         * números estão ordenados à direita.
         */
        imax = 0;
        for (j = 1; i <= n-i; j++) {
            /* Invariante: Para todo j, sei que imax contém o
             * índice do maior número até o j-ésimo elemento.
             */
            if (v[j] > v[imax])
                imax = j;
        }
        troca(v, n-i, imax);
    }
}
```

Para analisar um loop em um algoritmo ou verificar sua **corretude**, utiliza-se técnicas como **invariantes** de loop: aquilo que está correto em todas as iterações.

### Complexidade

Número de comparações:
$$
n-1 + n-2 + ... + 1 = \dfrac{n(n-1)}{2}
$$
**Pior caso**

Comparações: $O(n^2)$
Trocas: $O(n)$.

**Ideia:** e se em cada iteração achássemos o máximo e o mínimo e trocássemos os dois?

```
 i-1            i-1
+------------------+
| <= |        | <= |
+------------------+
```

Temos n/2 iterações.

Trocas: <=2 por iteração: $O(n)$.



### Recursivo

```C
void selecaoRec(flat v[], int n) {
    int i, imax;
    if (n > 1) {
        imax = 0;
        for (i = 1; i < n; i++)
            if (v[i] > v[imax])
                imax = 1;
        troca(v, imax, n-1);
    }
    selecaoRec(v, n-1);
}
```



## Bubble sort

```
  44      44                 44  12                  12
- 75  12  12                 12  44  27              27
- 12  75  27                 27      44              44
- 27      75                 75          15          15
  95      95  15             15          75   3      3
  15      15  95  3           3              75  73  73
   3       3     93  73  73  73                  75  19
  73      73         95  19  19                      75
  19      19                 95                      95
```

**Ideia:** em cada iteração percorra o vetor comparando elementos vizinhos e trocando-os se estão na ordem errada. Quando não tiver mais elementos invertidos, o vetor estará ordenado. Sabemos que em cada iteração, um elemento vai pro lugar.

```C
void bubble(float v[], int n) {
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 0; j < n-i; j++)
            if (v[j+1] < v[j]) {
                troca(v, j, j+1);
                trocou = 1;
            }
}
```

### Complexidade

|                            | Comparações                         | Trocas   |
| -------------------------- | ----------------------------------- | -------- |
| Melhor<br>(vetor ordenado) | $O(n)$                              | $0$      |
| Pior<br>(ordem inversa)    | $\dfrac{n(n-1)}{2} \implies O(n^2)$ | $O(n^2)$ |

### Recursivo

```C
void bubbleRec(float v[], int n) {
    int i, troca = 0;
    if (n > 1) {
        for (i = 0; i < n-1; i++) {
            if (v[i+1] < v[i]) {
                troca(v, i, i+1);
                trocou = 1;
            }
        }
        if (trocou)
            bubbleRec(v, n-1);
    }
}
```



## Insertion sort

John Mauchly, 1946

**Ideia:** em cada iteração o vetor está dividido numa parte ordenada com $i$ elementos e o resto está bagunçado.

Vamos deslocando os elementos até encontrar um menor. O primeiro da parte bagunçada é inserido nessa posição.

## Links

- [Sorting algorithms](https://www.programming-algorithms.net/article/39344/Bubble-sort)
- [Gifs de ordenação](../ordenacao-gifs.html)
