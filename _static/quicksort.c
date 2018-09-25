void troca(float v[], int ini, int fim) {
    int temp = v[ini];
    v[ini] = v[fim];
    v[fim] = temp;
}

int separa(float v[], int ini, int fim) {
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

    return p;
}

void Quicksort(float v[], int ini, int fim) {
    int pivo;
    if (fim - ini >= 2) {
        pivo = separa(v, ini, fim);
        Quicksort(v, ini, pivo);
        Quicksort(v, pivo+1, fim);
    }
}

int main() {
    float v[12] = {12, 25, 10, 39, 14, 23, 37, 40, 45, 72, 42, 61};

    Quicksort(v, 0, 11);

    int i;
    for (i=0; i < 12; i++) {
        printf("%1.0f ", v[i]);
    }
    printf("\n");
}
