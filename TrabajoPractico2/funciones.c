#include <stdio.h>
#include <stdlib.h>
#include <string.h> //incluyo la biblioteca string para realizar las funciones correspondientes para copiar los datos d elos vectores.
#include "funciones.h"
#include "validaciones.h" //inbcluyo la biblioteca validaciones.h para realizar las validaciones correspondientes.

void inicializarPersonas(EPersona persona[], int CANT) // funcion para inicializar las personas que ingresa el usuario.
{
    int i;

    for(i=0; i < CANT; i++)
        {
            persona[i].estado = 1;
        }
}


int buscarLibre(EPersona persona[], int CANT) //funcion para buscar espacio libre para dar alta.
{
    int indice = -1;
    int i;

    for(i=0; i < CANT; i++)
    {
        if(persona[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarpersona (EPersona persona[], int CANT, int dni) //funcion para buscar persona en el programa, para asi saber si ya fue cargado.
{
    int indice = -1;
    int i;

    for(i=0; i < CANT; i++)
    {
        if(persona[i].estado == 0 && persona[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarPersona (EPersona persona) // funcion para mostrar persona cargada en el programa.
{
    printf("  %d     %s     %d  \n", persona.dni, persona.nombre, persona.edad);
}


void mostrarPersonas(EPersona persona[], int CANT) //funcion para mostrar la lista de personas en el programa.
{

    system("cls");

    printf("---Lista de personas---\n\n");
    printf("  DNI  Nombre  Edad  \n\n");

    fflush(stdin);

    EPersona aux; //Declaro un vector aux para poder realizar el ordenamiento alfabetico.
    int i;
    int j;
    int flag = 0;

    for(i=1; i < CANT; i++)
    {

        for(j = CANT-1; j >= i; j--)
          {
             if(strcmp(persona[j-1].nombre, persona[j].nombre) > 0) //Realizo este metodo para ordenarlos por nombre alfabetico a las personas cargadas en el programa.
                {
                  aux = persona[j];
                  persona[j] = persona[j-1];
                  persona[j-1] = aux;
                  flag = 1;

                }

                fflush(stdin);
         }

         if (flag == 0)
            {
                break;
            }

    }


    for(i=0; i < CANT; i++)
        {
            if(persona[i].estado == 0)
            {
                mostrarPersona(persona[i]);
                fflush(stdin);
            }


        }

    printf("\n");

}




void alta(EPersona persona[], int CANT) // funcion para dar de alta en el programa.
{
    EPersona nuevaPersona; //decalro el vector nuevapersona como auxiliar para agregar nuevas personas la programa.
    int edad;
    char nombre [50];
    int estado;
    int dni;
    int indice;
    char auxdni[10];    // declaro estos 3 vectrores auxiliares para realizar las validaciones correspondientes.
    char auxNombre[50];
    char auxEdad[120];


    system("cls");
    printf("---Alta persona---\n\n");

    indice = buscarLibre(persona, CANT);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a personas nuevos.\n\n");
    }

    else
    {
        printf("Ingrese dni: ");
        scanf("%s", auxdni);

            while ( (esNumero(auxdni) == 0)) //validacion para que el usuario solo ingrese numeros en el dni.
            {
                printf("Error! DNI Incorrecto, ingrese solo numeros!\n");
                printf("Ingrese DNI: ");
                scanf("%s", auxdni); //lo cargo directamente en el axiliar para luego asignarlo a la var dni.
                fflush(stdin);
            }


        dni = atoi(auxdni); //con la funcion atoi convierto el vecto auxdni en un entero y lo asigno a dni.

        estado = buscarpersona(persona, CANT, dni);

        if(estado != -1)
            {
                printf("\nEl dni %d ya esta dado de alta en el sistema.\n", dni);
                mostrarPersona (persona[estado]);

                printf("\n");
            }

        else
            {
                   nuevaPersona.estado = 0;
                   nuevaPersona.dni = dni; //al vector nuevapersona le asigno el valor dni para cargar los demas datos.

                   printf("Ingrese nombre: ");
                   fflush(stdin);
                   gets(nuevaPersona.nombre); //el usuario ingresa el dato nombre y guardo con la funcion gets en nuevapersona.nombre.
                   strcpy( auxNombre, nuevaPersona.nombre); //luego copio los datos de nuevapersona.nombre a mi auxnombre para validarlos.


                   while ( esSoloLetras(auxNombre) == 0 ) //validacion para que le usuario solo ingrese letras en el nombre.
                   {
                       printf("Error!! Ingrese nombre, solo letras!\n");
                       printf("Ingrese nombre: ");
                       scanf("%s", auxNombre); //vuelvo a cargar el vector auxnombre validado.
                       fflush(stdin);

                   }

                   strcpy( nuevaPersona.nombre, auxNombre); // al estra validado el ingreso copio auxnombre a mi vector nuevapersona.nombre.

                   printf("Ingrese edad: ");
                   scanf("%s", auxEdad);
                   fflush(stdin);


                   while ( esNumero(auxEdad) == 0 ) //validacion de la edad al igual qu el dni solo numeros.
                   {
                       printf("Error!! Edad incorrecta, ingrese numeros!!\n");
                       printf("Ingrese edad : ");
                       fflush(stdin);
                       scanf("%s", auxEdad);
                   }

                   edad = atoi(auxEdad);
                   nuevaPersona.edad = edad;



                   persona[indice] = nuevaPersona;

                   printf("\nAlta exitosa!!!\n\n");

           }

    }

}



void baja(EPersona persona[], int CANT) // funcion para dar de baja una persona en el programa.
{
    char confirma;
    int estado;
    int dni;
    char auxdni[10]; //auxiliar para validar el dni en la funcion baja.

    system("cls");
    printf("---Baja Persona---\n\n");

    printf("Ingrese dni: ");
    scanf("%s", auxdni);


        while ( (esNumero(auxdni) == 0)) //validacion del dni en la funcion baja.
            {
                printf("Error! DNI Incorrecto, ingrese solo numeros!\n");
                printf("Ingrese DNI: ");
                scanf("%s", auxdni);
                fflush(stdin);
            }


        dni = atoi(auxdni);

    estado = buscarpersona(persona, CANT, dni);

        if(estado == -1) //realizo este condicional por si el usuario ingresa un dni que no esta en el programa.
        {
            printf("\nEl dni %d no se encuentra en el sistema!!\n\n", dni);
        }

        else
        {
            mostrarPersona (persona[estado]);

            do {

                printf("\nConfirma baja? [s|n]: "); //si ingresa un dni que esta ne le programa se le pregunta si esra seguro.
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);

                }while(confirma != 's' && confirma != 'n');

            if (confirma == 's') //Si confirma se cambia el estado y se lo da de baja.
                {
                    persona[estado].estado = 1;
                    printf("\nSe ha realizado la baja!!\n\n");
                }

            else
            {
                printf("\nSe ha cancelado la baja!\n\n");
            }

        }

}
