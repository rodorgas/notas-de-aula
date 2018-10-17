#include<stdio.h>

void troca(int v[], int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void bubblesort(int v[], int n) {
    int i, j, trocou;

    for (i = 1; i < n; i++) {
        trocou = 0;
        for (j = 0; j < n-i; j++) {
            if (v[j+1] < v[j]) {
                troca(v, j, j+1);
                trocou = 1;
            }
        }

        if (!trocou) break;
    }
}

void print(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
   int v[12] = {12, 25, 10, 39, 14, 23, 37, 40, 45, 72, 42, 61};
   print(v, 12);

   bubblesort(v, 12);

   print(v, 12);
}
