/* Autor: Leonel Godoy
    1B
8/10/2020
**Parcial Laboratorio I-  1era parte

#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ​pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica
las 5 mascotas están formadas por los siguientes datos:
a- 2 gatos
b- 3 perros
c- los demás datos de estas 5 mascotas deben ser hardcodeados por el alumno.
1-Se debe mostrar un listado de mascotas con sus razas y países de origen .
*el harcodeo debe estar en funciones separadas .
*la función de listar mascota debe estar modularizada, ósea debe llamar a otras
funciones y no realizar dos for.

******************************** 2da parte
#Borrado lógico de una mascota del listado
#-Se debe mostrar un listado de mascotas ordenadas por país de origen.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#define TAM 10
#define TAMRAZAS 4

int main()
{
    eMascota listado[TAM];
    eRaza listadoRazas[TAMRAZAS];

    //inicializo el array de eMascota
    inicializarArrayMascotas(listado, TAM);
    //hardcodeo arrays de mascotas y de razas
    hardcodearMascotas(listado, TAM);
    hardcodearRazas(listadoRazas, TAMRAZAS);

    //muestro el listado original
    mostrarListadoCompleto(listado, TAM, listadoRazas, TAMRAZAS);

    /*    printf("\n***Se borrara una mascota para probar funcion de borrado\n");
    borrarMascotaDelListado(listado, TAM, listado[0].id);
    system("pause");
    printf("\n***Nuevo listado");
    mostrarListadoCompleto(listado, TAM, listadoRazas, TAMRAZAS);
    */

    printf("\n***Se aplicara un ordenamiento de burbujeo***");
    system("pause");
    ordenarPorPais(listado, TAM, listadoRazas, TAMRAZAS);
    printf("\n***Ordenado***");
    mostrarListadoCompleto(listado, TAM, listadoRazas, TAMRAZAS);


    return 0;
}
