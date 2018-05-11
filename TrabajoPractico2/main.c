#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANT 20


int main()
{
    char seguir = 's';
    int opcion = 0;

    EPersona persona [CANT];

    inicializarPersonas (persona, CANT);



    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        fflush(stdin);

        switch(opcion)
        {
            case 1:
                alta(persona, CANT);
                break;
            case 2:
                baja(persona, CANT);
                break;
            case 3:
                mostrarPersonas(persona, CANT);
                break;
            case 4:
                seguir = 'n';
                break;

            default:
                printf("\nOpcion Incorrecta, ingrese nuevamente opcion entre 1 y 5.\n\n");
                system("pause");
        }
    }

    return 0;
}
