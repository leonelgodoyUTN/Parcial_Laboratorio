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

******************************** 2da parte DONE
#Borrado lógico de una mascota del listado
#-Se debe mostrar un listado de mascotas ordenadas por país de origen.

******************************** 3era parte
#-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de
razas disponibles, teniendo en cuenta que ya tengo 5 mascotas cargadas y que el
máximo es 10
#-Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa
raza
******************************** 4ta parte
#Modificación de una mascotas(todo menos el id).
#Menú de opciones
#-Alta de RAZA (20 razas maximo)
#-Se debe mostrar el país de origen que tenga más mascotas en nuestra
veterinaria.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "utn.h"
#define TAM 10 //tamanio maximo del array de mascotas
#define TAMHARDCODEO 5//cantidad de mascotas a hardcodear
#define TAMRAZAS 10//tamanio maximo del array de razas
#define HARDRAZAS 5//hardcodeo de razas


int main()
{
    int proximoId= 1000;
    int proximoIdRaza=10;
    eMascota listado[TAM];
    eRaza listadoRazas[TAMRAZAS];

    //inicializo el array de eMascota
    inicializarArrayMascotas(listado, TAM);
    inicializarArrayRazas(listadoRazas, TAMRAZAS);
    //hardcodeo arrays de mascotas y de razas
    hardcodearRazas(listadoRazas, HARDRAZAS, &proximoIdRaza);
    hardcodearMascotas(listado, TAMHARDCODEO, &proximoId);


    int salir=0;
    char confirma;
    do
    {
        switch(menu())
        {
        case 1:
            cargarMascota(listado, TAM, &proximoId);
            break;
        case 2:
            borrarMascotaDelListado(listado, TAM, 1000, 1000+TAM);
            break;
        case 3:
            //modificar
            break;
        case 4:
            mostrarListadoCompleto(listado, TAM, listadoRazas, TAMRAZAS);
            break;
        case 5:
            ordenarPorPais(listado, TAM, listadoRazas, TAMRAZAS);
            break;
        case 6:
            listarRazas(listadoRazas, TAMRAZAS);
            break;
        case 7:
            agregarRaza(listadoRazas, TAMRAZAS, &proximoIdRaza);
            break;

        case 9:
            printf("\nConfirma salir del programa? s/n: ");
            myGets(&confirma, 1);
            if(confirma=='s')
            {
                salir =1;
            }

        }
    }
    while(salir==0);


    return 0;
}
