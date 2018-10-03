#include<stdio.h>


void ascende(float v[], int n, int i) {
    int pai, filho;
    filho = i; pai = (i-1)/2;

    while (filho > 0) {
        if (v[pai] > v[filho])
            break;
        troca(v, pai, filho);
        filho = pai;
        pai = (pai - 1)/2;
    }
}

int main() {


    return 0;
}
