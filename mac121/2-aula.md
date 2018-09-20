# A Linguagem C

## Tipos Estruturados

1. Vetores e matrizes alocados estaticamente
2. `structs`: uma variável capaz de armazenar vários camposd e diferentes tipos.

Exemplo:

```C
struct {
    char nome[50];
    int nusp;
    float nota;
} aluno;

...

aluno.nota = aluno.nota - 0.5;
scanf("%d", &(aluno.nusp));
```



Em C é permitido definir novos tipos usando o `typedef`:

```C
typedef struct {
    double x;
    double y;
} ponto;
ponto p;
p.x = 3;
p.y = 5;
```

## Ponteiros

C permite manipular o endereço da memória em que as variáveis estão armazenadas.

Exemplos:

```C
int a;
int *p;
int *q;
a = 10;
p = &a;
scanf("%d", p);
printf("%d", *p);  // o valor apontado por p
```

```C
int v[5], *pv;
pv = &(v[2]);
*pv = 7;
*(pv - 1) = -4;
// ...
x = 1.3; y = 4.9;
troca(&x, &y);
```

Ponteiros têm dois usos principais:

1. Passagem de parâmetros

   ```C
   void troca(float a, float b) {
       float aux;
       aux = *a;
       *a = *b;
       *b = aux;
   }
   ```

2. Vetores e matrizes são ponteiros

   ```C
   int v[10];
   // v[5] é igual a *(v + 5)
   ```

Podemos usar isso para fazer alocação dinâmica de vetores e matrizes:

```C
int n;
float *v;
scanf("%d", &n);
v = malloc(n * sizeof(float));
```

```C
typedef struct {
    double r;
    double im;
} complexo;

complexo *vc;  // vetor complexo

vc = malloc(m * sizeof(complexo));

// ...
// Quando a memória não é mais necessária, deve ser liberada

free(vc);
for (int i = 0; i < m; i++)
    free(mat[i]);
free(mat);
```

```C
// matriz
int **mat;
mat = malloc(m * sizeof(int *));
for (i = 0; i < n; i++)
    mat[i] = malloc(n * sizeof(int));
mat[4][7] = 10;
```



## Declarações

```C
// definições globais

#include <stdio.h>
#define PI 3.14159

// protótipo das funções

int mdc(int, int);

int main {
    return(0);
}
```

## Variáveis
Uma variável em um programa é uma parte da memória reservada para armazenar um valor. As variáveis tem tipos. Em C os tipos não são fortes.

1. `int`
ex.: `int num, soma;`
Os número inteiros são armazenados em 2 bytes "em copmlemento de dois", podendo assumir valores entre:
-2^15 <= num <= 2^15 - 1 = 32767

    1.1 `unsigned int`: 0 <= x <= 2^16 - 1
    1.1 `long int`: usa 4 bytes

2. `float`
Uma variável deste tipo armazena um "número real". Usamos o ponto flutuante.
```
Ex. 1234.5678: .12345678 * 10^4
              |----------|-----|
              |----------|-----|
```

3. `double`
Tem o dobro da precisão de float. Para leitura e impressão usamos:
`%f`:  float
`%lf`: double

## Tipos de dados
C não tem tipos fortes:
Exemplo:

```C
int n;
float x;

n = 7;
x= n / 2;
```

## Imprimindo valores
```C
// _ representa espaço

float x = 3.14159;
printf("%3.1f", x);  // 3.1
// ponto conta como vírgula
printf("%5.1f", x);   // __3.1
printf("%10.4f", x);  // ____3.1416

int m = 1234;
printf("%7d", m);   // ___1234
printf("%05d", m);  // 01234
printf("%2d", m);   // 1234
```

----

Terça, 7 de agosto

Quinta, 9 de agosto