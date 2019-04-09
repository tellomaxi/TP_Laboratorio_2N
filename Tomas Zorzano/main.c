#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "Funciones.h"

#define MAX 1001


int funcion_opciones();

int main()
{
    char seguir='s';
    eEmployee employee[MAX];
    initEmployees(employee,MAX);
    int flagSinAlta=0;

    do
    {

        switch (funcion_opciones())
        {
        case 1:
            addEmployee(employee, MAX);
            flagSinAlta++;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Saliendo...");
            exit(-1);
            break;
        default:
            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
            system("pause");
            break;

        }
        printf("\n\n Desea continuar? \n\n");
        scanf("%c",&seguir);
        system("cls");
        fflush(stdin);


    }
    while (seguir == 's' || seguir == 'S');

    printf("\n\n Saliendo...\n\n");

}
