#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Funciones.h"

#define MAX 1001

int initEmployees(eEmployee list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};
int findEmpty(eEmployee list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findEmployee(eEmployee list[],int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewEmployee(eEmployee aEmployee)
{

    printf(" ID:%d - Nombre:%s -  Apellido:%s-  Salario:%.2f-  Sector:%d ", aEmployee.id, aEmployee.name, aEmployee.lastName, aEmployee.salary, aEmployee.sector);
};

void viewEmployees(eEmployee list[], int len)
{

    system("cls");
    printf(" ID NAME LASTNAME SALARY SECTOR \n\n");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewEmployee(list[i]);
        }
    }
    system("pause");
};
int addEmployee(eEmployee list[], int len)

{
    eEmployee newEployee;

    int index;
    char auxName[31];
    char auxLastName[31];
    char auxSalary[10];
    char auxSector[10];
    int ret;

    int nombre=0,apellido=0,salario=0,sector=0;

    if(list != NULL && MAX > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("*** ALTA EMPLEADO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Empleado Nuevo, su ID es : %d \n",index);
            newEployee.id = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ", auxName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ", auxLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n\n",auxName,auxLastName);
            if(salario == 0)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ", auxSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n\n",auxName,auxLastName);
                    salario=1;
                };
                salario=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxSalary);
            if(sector == 0)
            {
                while(!funcion_getStringNumeros("Ingrese Sector: ", auxSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxSalary);
                    sector=1;
                };
                sector=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Sector %s \n\n",auxName,auxLastName,auxSalary,auxSector);
            while((nombre == 1) && (apellido == 1) && (salario == 1) && (sector == 1) )
            {
                strcpy(newEployee.name,auxName);
                strcpy(newEployee.lastName,auxLastName);
                newEployee.sector = atoi(auxSector);
                newEployee.salary = atof(auxSalary);
                list[index] = newEployee ;
                system("cls");
                printf("\n\n********NUEVO EMPLEADO, BIENVENIDO*********\n\n");
                viewEmployee(list[index]);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};

int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- INFORMAR \n");
    printf(" 5- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
}
