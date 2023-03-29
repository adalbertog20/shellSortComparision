#include <stdio.h>
#include <time.h>
#include "sort.h"

#define MAX_NUMEROS 1000

int main(int argc, char const *argv[])
{
    int numeros[MAX_NUMEROS];
    clock_t start_t, end_t;
    double total_t;
    double sum = 0;
    int n = 0;

    if(argc != 2) {
        printf("Uso: %s archivo\n", argv[0]);
        return 1;
    }
    
    FILE *archive;
    FILE *datos;
    datos = fopen(argv[1], "r");
    if(datos == NULL) {
        printf("no se pudo abrir el archivo");
        return 1;
    }

    while(fscanf(datos, "%d", &numeros[n]) == 1 && n < MAX_NUMEROS) {
        n++;
    }
    archive = fopen("time.txt", "w");
    if(archive == NULL) {
        printf("No se pudo abrir archivo");
        return 1;
    }

    fprintf(archive, "------------ PRIMERA IMPLEMENTACION ------------\n");
    for (int i = 0; i < 1000; i++)
    {       
        start_t = clock();
        shellSortPrimera(numeros, 1000);
        end_t = clock();
        total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
        fprintf(archive, "ejecucion: %d = %lf\n", (i + 1), total_t);
        sum += total_t;
    }
    fprintf(archive, "------------ FIN DE LA PRIMERA IMPLEMENTACION ------------\n");

    printf("Promedio de tiempo de ejecucion de la primera implementacion: %f\n", (double)(sum / 1000));

    fprintf(archive, "------------ SEGUNDA IMPLEMENTACION ------------\n");
    for (int i = 0; i < 1000; i++)
    {       
        start_t = clock();
        shellSortSegunda(numeros, 1000);
        end_t = clock();
        total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
        fprintf(archive, "ejecucion: %d = %lf\n", (i + 1), total_t);
        sum += total_t;
    }
    fprintf(archive, "------------ FIN DE LA SEGUNDA IMPLEMENTACION ------------\n");

    printf("Promedio de tiempo de ejecucion de la segunda implementacion: %f\n", (double)(sum / 1000));

    fclose(archive);
    fclose(datos);
    return(0);
}
 