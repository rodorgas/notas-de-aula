# Recursão

Quinta, 30 de agosto

Uma função recursiva é aquela que inclui no seu copro uma chamada a ela mesma.

Exemplos: idem a aula anterior



**Exercício:** Dado n > 0, devolver a soma dos dígitos de n.

Ex: 21340071 -> 18

```C
int somaDigitos(int n) {
    /* n > 0 */
    if (n < 10) return n;
    return ((n % 10) + somaDigito(n/10));
}
```

**Exercício:** Faça uma função que reecbe um vetor com n>0 números inteiros e devolve a média desses números.

```C
float media(int v[], int n) {
    if (n == 1)
        return v[0];

    return (media(v, n-1)*(n-1) + v[n-1])/n;
}
// chamada: media(vetor, 0, n)
```

Simulação:

```
n = 4: 12, 7, -3, 5

+----------------------+
|    4                 |
+--------------------+ |
|    3               | |
+------------------+ | |
|    2             | | |
+---------------+  | | |
|    1          |  | | |
+---------------+  | | |
|     -> 12*1|7    | | |
+------------------+ | |
|  ->  9,5*2|(|3)    | |
+--------------------+ |
| -> 16/3*3|5/4        |
+----------------------+
 -> 5.25

```



# Hanoi

Na torre A são dados n discos de diâmetros diferentes que devem ser movidos para a torre C podendo usar B como auxiliar.

As regras para movimentar os discos são:

1. São pode mover 1 disco por vez.
2. Não pode colocar um disco maior sobre um menor.

n=3 → 7 movimentos

```
 1
 2
 3
+---------+
 A  B  C

 2                 1
 3       1         2  3
+---------+   +--------+

 3   2   1     1   2  3
+---------+   +--------+         1
     1                2          2
 3   1         1      3          3
+---------+   +--------+   +------+
```

```
    XX
   X  X
  X  n X
 X      X
+-------------------+
    A     B      C

         XX
        X  X
       X n-1X
   n  X      X
+-------------------+

         XX
        X  X
       X n-1X
      X      X   n
+-------------------+


               XX
              X  X
             X n-1X
            XXXXXXXX
           X    n   X
+-------------------+
```

```C
void hanoi(int n, char origem, char aux, char destino) {
    /* n>= 0 */
    if (n > 0) {
        hanoi(n-1, origem, destino, aux);
        printf("Mova o disco %d de %c para %c\n", n, origem, destino);
        hanoi(n-1, aux, origem, destino);
    }
}
```

Simulação:

```
+------------------------+
| 3 A B C                |
+--------------------v-+ |
| 2 A C B              | |
+------------------v-+ | |
| 1 A B C            | | |
+---------------v-+  | | |
| 0 A C B         |  | | |
+-----------------+  | | |
+---------------l-+  | | |
| 0 B A C         |  | | |
+-----------------+  | | |
|--------------------+ | |
+------------------l-+ | |
| 1 C A B            | | |
+--------------v-+   | | |
| 0              |   | | |
+----------------+   | | |
+--------------l-+   | | |
| 0              |   | | |
+----------------+   | | |
|--------------------+ | |
+----------------------+ |
|                        |
+----------------------+ |
| 2 B A C              | |
+------------------v-+ | |
| 1 B C A            | | |
+----------------v-+ | | |
| 0                | | | |
+------------------+ | | |
+----------------l-+ | | |
| 0                | | | |
+------------------+ | | |
+--------------------+ | |
|                      | |
+------------------l-+ | |
| 1 A B C            | | |
+--------v-+         | | |
| 0        |         | | |
+--------l-+         | | |
| 0        |         | | |
+----------+         | | |
|--------------------+ | |
+----------------------+ |
|                        |
+------------------------+
```

Podemos mover os n discos com $2^n-1$ movimentos.

**Prova:**
$$
n = 0 \\
2^n - 1 + 1 + 2^{n-1}-1 \\
2\cdot 2^n - 1
$$

## Curvas de Hilbert

```
                         <---+
      <-+
                      +---<----+    +   +
   +------+           | A      |  D |   |
+  |                  |        +----+   v
|  |                  +-----+
v  |                        |
   +------>           +---<-+  +----+   +
                      | A      |  B |   |
     +-->             |        |    |   v
     H1               +--------+    v

                         +--->
                         H2
```

Para desenha uma curva de Hilber de profundidade  fazemos 4 cópias de figuras de profundidade n-1:

Se denotarmos por:

```
+-----+   +-----+   <----+   ^     +
|         |     |        |   |     |
|  A      |  B  |     C  |   |  D  |
|         |     |        |   |     |
+----->   +     v   +----+   +-----+
```


- **A**: D ← A ↓ A → B
- **B**: C ↑ B → B ↓ A
- **C**: B → C ↑ C ← D
- **D**: A ↓ D ← D ↑ C

Curvas deste tipo são chamadas de fractais, e tem a propriedade de que:

> O todo tem a mesma estrutura que cada pequena parte.

Estes padrões ficaram na moda na década de 80 depois do livre _The fractal geometry of nature._ (B. B. Maldelbrot).

