#include <stdio.h>

#define MAX_PROCESOS 4
#define MAX_BLOQUES 5

typedef struct {
    char nombre[20];
    int tamano;
} Proceso;

typedef struct {
    int tamano;
    int ocupado;
} BloqueMemoria;

void best_fit(Proceso procesos[], BloqueMemoria bloques[], int num_procesos, int num_bloques) {
    printf("\nAlgoritmo Best Fit:\n");
    
    for (int i = 0; i < num_procesos; i++) {
        Proceso proceso = procesos[i];
        int mejor_bloque = -1;
        int mejor_espacio_libre = 2147483647; 
        
        for (int j = 0; j < num_bloques; j++) {
            if (!bloques[j].ocupado && proceso.tamano <= bloques[j].tamano) {
                int espacio_libre = bloques[j].tamano - proceso.tamano;
                
                if (espacio_libre < mejor_espacio_libre) {
                    mejor_espacio_libre = espacio_libre;
                    mejor_bloque = j;
                }
            }
        }
        
        if (mejor_bloque != -1) {
            bloques[mejor_bloque].tamano -= proceso.tamano;
            bloques[mejor_bloque].ocupado = 1;
            printf("%s asignado a Bloque %d\n", proceso.nombre, mejor_bloque + 1);
        } else {
            printf("%s no asignado\n", proceso.nombre);
        }
    }
}
void first_fit(Proceso procesos[], BloqueMemoria bloques[], int num_procesos, int num_bloques) {
    printf("\nAlgoritmo First Fit:\n");
    
    for (int i = 0; i < num_procesos; i++) {
        Proceso proceso = procesos[i];
        int asignado = 0;
        
        for (int j = 0; j < num_bloques; j++) {
            if (!bloques[j].ocupado && proceso.tamano <= bloques[j].tamano) {

                bloques[j].tamano -= proceso.tamano;
                bloques[j].ocupado = 1;
                printf("%s asignado a Bloque %d\n", proceso.nombre, j + 1);
                asignado = 1;
                break;
            }
        }
        if (!asignado) {
            printf("%s no asignado\n", proceso.nombre);
        }
    }
}

int main() {
    Proceso procesos[MAX_PROCESOS] = {
        {"Proceso 1", 212},
        {"Proceso 2", 417},
        {"Proceso 3", 112},
        {"Proceso 4", 426}
    };

    BloqueMemoria bloques_memoria[MAX_BLOQUES] = {
        {100, 0},
        {500, 0},
        {200, 0},
        {300, 0},
        {600, 0}
    };

    best_fit(procesos, bloques_memoria, MAX_PROCESOS, MAX_BLOQUES);

    for (int i = 0; i < MAX_BLOQUES; i++) {
        switch (i) {
            case 0: bloques_memoria[i].tamano = 100; break;
            case 1: bloques_memoria[i].tamano = 500; break;
            case 2: bloques_memoria[i].tamano = 200; break;
            case 3: bloques_memoria[i].tamano = 300; break;
            case 4: bloques_memoria[i].tamano = 600; break;
        }
        bloques_memoria[i].ocupado = 0;
    }

    first_fit(procesos, bloques_memoria, MAX_PROCESOS, MAX_BLOQUES);

    return 0;
}

