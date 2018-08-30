# Estrutura:

Quinta, 9 de agosto

```
// definições globais

#include <stdio.h>
#define PI 3.14159

// protótipo das funções

int mdc(int, int);

int main {
    return(0);
}
```

# Variáveis
Uma variável em um programa é uma parte da memória reservada para armazenar um valor. As variáveis tem tipos. Em C os tipos não são fortes.

1. int
ex.: int num, soma;
Os número inteiros são armazenados em 2 bytes "em copmlemento de dois", podendo assumir valores entre:
-2^15 <= num <= 2^15 - 1 = 32767

    1.1 unsigned int: 0 <= x <= 2^16 - 1
    1.1 long int: usa 4 bytes

2. float
Uma variável deste tipo armazena um "número real". Usamos o ponto flutuante.
```
Ex. 1234.5678: .12345678 * 10^4
              |----------|-----|
              |----------|-----|
```

3. double
Tem o dobro da precisão de float. Para leitura e impressão usamos:
%f:  float
%lf: double

## Tipagem
C não tem tipos fortes:
Exemplo:
```
int n;
float x;

n = 7;
x= n / 2;
```

## Imprimindo valores
```
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
