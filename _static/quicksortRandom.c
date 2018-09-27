#include<stdio.h>
#include<stdlib.h>

void troca(float v[], int ini, int fim) {
    int temp = v[ini];
    v[ini] = v[fim];
    v[fim] = temp;
}

int separaSedgewick(float v[], int ini, int fim) {
    int p = ini, q = fim - 1;
    float pivo = v[ini];
    while (p < q) {
        while (v[q] > pivo)
            q--;
        if (q > p)
            troca(v, p, q);
        while (p < q && v[p] <= pivo)
            p++;
        if (p < q)
            troca(v, p, q);
    }
}


int separaAleatorio(float v[], int ini, int fim) {
    int r = random(ini, fim);  // sorteia índice [ini, fim-1]
    troca(v, r, fim - 1);
    return separaSedgewick(v, ini, fim);
}

void quickSortAleatorizado(float v[], int ini, int fim) {
    int pivo;
    if (fim - ini > 1) {
        pivo = separaAleatorio(v, ini, fim);
        quickSortAleatorizado(v, ini, pivo);
        quickSortAleatorizado(v, pivo + 1, fim);
    }
}

int main() {
    float v[12] = {12, 25, 10, 39, 14, 23, 37, 40, 45, 72, 42, 61};

    quickSortAleatorizado(v, 0, 11);

    int i;
    for (i=0; i < 12; i++) {
        printf("%1.0f ", v[i]);
    }
    printf("\n");
}
