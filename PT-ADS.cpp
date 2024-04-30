#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int emparejar_policias_ladrones(char arr[], int n, int K) {
    int *posiciones_policias = (int *)malloc(n * sizeof(int));
    int *posiciones_ladrones = (int *)malloc(n * sizeof(int));
    int emparejamientos_exitosos = 0;
    int poli_size = 0, ladron_size = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') {
            posiciones_policias[poli_size] = i;
            poli_size++;
        } else if (arr[i] == 'T') {
            posiciones_ladrones[ladron_size] = i;
            ladron_size++;
        }
    }

    int i = 0, j = 0;
    while (i < poli_size && j < ladron_size) {
        if (abs(posiciones_policias[i] - posiciones_ladrones[j]) <= K) {
            emparejamientos_exitosos++;
            i++;
            j++;
        } else if (posiciones_policias[i] < posiciones_ladrones[j]) {
            i++;
        } else {
            j++;
        }
    }

    free(posiciones_policias);
    free(posiciones_ladrones);

    return emparejamientos_exitosos;
}

int main() {
    char arr1[] = {'P', 'T', 'P', 'T', 'P', 'T', 'P', 'T', 'P', 'T'};
    int K1 = 1;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Ejemplo 1 - Numero de emparejamientos exitosos: %d\n", emparejar_policias_ladrones(arr1, n1, K1));

    char arr2[] = {'T', 'T', 'T', 'P', 'T', 'T', 'T', 'P', 'T', 'P'};
    int K2 = 2;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Ejemplo 2 - Numero de emparejamientos exitosos: %d\n", emparejar_policias_ladrones(arr2, n2, K2));

    char arr3[] = {'T', 'P', 'T', 'T', 'P', 'T', 'T', 'P', 'P', 'T'};
    int K3 = 3;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Ejemplo 3 - Numero de emparejamientos exitosos: %d\n", emparejar_policias_ladrones(arr3, n3, K3));

    return 0;
}

