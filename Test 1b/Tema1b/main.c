//
//  main.c
//  Tema 1b
//
//  Created by Inga Curjos on 11/11/2020.
//
// Inmultire 2 matrici cu variabile dinamice.
// Variabilele nu sunt globale.
// Afisarea matricii frumos.

#include <stdio.h>
#include <stdlib.h>

void inmultire(int **m1, int **m2, int **m3, int linie, int coloana, int lungime);
void afisare(int **m1, int linie, int coloana);
void citire(int **m1, int linie, int coloana);
int **alocare(int lin, int col);
int citesteLinCol(void);

int citesteLinCol(){
    int n;
    scanf("%d", &n);
    while(n <= 0){
        printf("Eroare! Introduceti un numar mai mare decat 0: ");
        scanf("%d", &n);
    }
    return n;
}
int **alocare(int lin, int col) {
    int **d;
    
    d = (int **) malloc(lin*sizeof(int *));
    for (int i = 0; i < lin; i++) {
        d[i] = (int *) malloc(col*sizeof(int));
    }
    return d;
}

void citire(int **m1, int linie, int coloana) {
    for (int i = 0; i < linie; i++) {
        for (int j = 0; j < coloana; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }
}

void afisare(int **m1, int linie, int coloana) {
    for (int i = 0; i < linie; i++) {
        for (int j = 0; j < coloana; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void inmultire(int **m1, int **m2, int **m3, int linie, int coloana, int lungime) {
    
    for (int i = 0; i < linie; i++) {
        for (int j = 0; j < coloana; j++) {
            m3[i][j]=0;
            for (int k = 0; k < lungime; k++)
            m3[i][j] += m1[i][k] * m2[k][j];
        }
    }
    
}

int main() {
    int lin1, col1, lin2, col2;
    int **m1, **m2, **m3;
    
    printf("Linii Matrice 1: ");
    lin1 = citesteLinCol();
    printf("Coloane Matrice 1: ");
    col1 = citesteLinCol();
    printf("Linii Matrice 2: ");
    lin2 = citesteLinCol();
    
    while (lin2 != col1) {
        printf("Invalid! Reintroduceti: ");
        scanf("%d", &lin2);
    }
    
    printf("Coloane Matrice 2: ");
    scanf("%d", &col2);
    
    m1 = alocare(lin1, col1);
    m2 = alocare(lin2, col2);
    
    
    printf("\nIntroduceti elementele Matricii 1:\n");
    citire(m1, lin1, col1);
    printf("\nMatricea 1 este:\n");
    afisare(m1, lin1, col1);
    printf("\nIntroduceti elementele Matricii 2:\n");
    citire(m2, lin2, col2);
    printf("\nMatricea 2 este:\n");
    afisare(m2, lin2, col2);
    
    m3 = alocare(lin1, col2);
    inmultire(m1, m2, m3, lin1, col2, col1);
    printf("\nMatricea rezultat este:\n");
    afisare(m3, lin1, col2);
    
    printf("\n");
    
    return 0;
}
