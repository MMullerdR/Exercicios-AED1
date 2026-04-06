/*Faca um programa que leia dois vetores de 10 elementos. Crie um vetor que seja a
interseccao entre os 2 vetores anteriores, ou seja, que contem apenas os numeros que
estao em ambos os vetores. Nao deve conter numeros repetidos.*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int vet1[10]; 
    int vet2[10];
    int vets[10];
    int cont = 0;

    for ( int i = 0; i < 10; i++ ) {
        scanf("%d", &vet1[i]);
    }

    for ( int i = 0; i < 10; i++ ) {
        scanf("%d", &vet2[i]);
    }

    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ){
            if( vet1[i] == vet2[j] ) {
                vets[cont] = vet1[i];
                cont++;
            }
        }
    }

    for (int i = 0; i < cont; i++) {
        printf("%d\n", vets[i]);
    }

    return 0;
}