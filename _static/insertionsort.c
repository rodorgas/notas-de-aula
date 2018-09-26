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
        for (j = 1; j <= n-i; j++) {
            /* Invariante: Para todo j, sei que imax contém o
             * índice do maior número até o j-ésimo elemento.
             */
            printf("i: %d ", j);
            printf("j: %d\n", j);
            if (v[j] > v[imax])
                imax = j;
        }
        troca(v, n-i, imax);
    }
}

int main() {
    float v[12] = {12, 25, 10, 39, 14, 23, 37, 40, 45, 72, 42, 61};

    selecao(v, 12);

    int i;
    for (i=0; i < 12; i++) {
        printf("%1.0f ", v[i]);
    }
    printf("\n");
}
