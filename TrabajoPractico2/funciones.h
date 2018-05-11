#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int edad;
    char nombre [50];
    int estado;
    int dni;


}EPersona;

void alta(EPersona[], int CANT);
void inicializarPersonas(EPersona persona[], int dni);
void baja(EPersona[], int CANT);
int buscarpersona(EPersona[], int dni, int CANT);
int buscarLIbre(EPersona[], int dni);
void mostrarPersona (EPersona);
void mostrarPersonas(EPersona persona[], int CANT);
void imprimirGrafico (EPersona persona[], int CANT);


#endif // FUNCIONES_H_INCLUDED

/** Realizo los prototipos de las funciones que voy a declarar y desarrolar en funciones.c.
 * Segun corresponda las declaro con void para que no retorne nada o con int si necesito que devuelva un entero.
 * Utilizo los parametros EPersona, el vector persona y el entero CANT segun corresponde en las funciones.
 */
