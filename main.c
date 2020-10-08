/* Autor: Leonel Godoy

Soy un veterinario que necesita atender a las mascotas de sus clientes, para tener el
control vamos a tener un sistema ....el sistema debe realizar las siguientes
funcionalidades.(los datos deben ser hardcodeados).
******************************** 1era parte

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
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
#define TAMRAZAS 4
typedef struct
{
    int id;//PK
    char nombre[51];
    int edad;
    char sexo;
    char tipo; //{gato ,perro o raro}
    int isEmpty;
    int idRaza;//FK a eRaza
} eMascota;

typedef struct
{
    int id;//PK
    char descripcion[51];
    char tamanio; //chico ,mediano o grande,
    char paisDeOrigen[51];
} eRaza;

void inicializarArrayMascotas(eMascota *list, int tamList);
void hardcodearMascotas(eMascota* list, int tamList);
void mostrarListadoCompleto(eMascota* list, int tamList, eRaza listaRazas[], int tamRaz);
void mostrarMascota(eMascota, eRaza *list, int tamRaz);
void hardcodearRazas(eRaza *list, int tamList);

int main()
{
    eMascota listado[TAM];
    eRaza listadoRazas[TAMRAZAS];

    //inicializo el array de eMascota
    inicializarArrayMascotas(listado, TAM);
    //hardcodeo arrays de mascotas y de razas
    hardcodearMascotas(listado, TAM);
    hardcodearRazas(listadoRazas, TAMRAZAS);

    //muestro el listado
    mostrarListadoCompleto(listado, TAM, listadoRazas, TAMRAZAS);

    return 0;
}

void inicializarArrayMascotas(eMascota *list, int tamList)
{
    for(int i=0; i<tamList; i++)
    {
        list[i].isEmpty=1;
    }
}


void hardcodearMascotas(eMascota* list, int tamList)
{
    //datos a hardcodear
    char nombres[5][51]= {"Rufo", "Firulais", "Cata", "Anush", "Paul"};
    int edades[5]= {3,5,7,2};
    char sexos[5]= {'m', 'm', 'f', 'f', 'm'};
    char tipos[5]= {'p', 'p', 'c', 'c', 'p'};
    int isEmpty[5]= {0,0,0,0,0};
    int idRazas[5]= {11, 13, 10, 12, 13};

    for(int i=0; i<tamList; i++)
    {
        list[i].id = i+1000;
        strcpy(list[i].nombre, nombres[i]);
        list[i].edad = edades[i];
        list[i].sexo = sexos[i];
        list[i].tipo = tipos[i];
        list[i].idRaza = idRazas[i];
        list[i].isEmpty = isEmpty[i];
    }
}

void mostrarListadoCompleto(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz)
{
    printf("\nNombre   Edad Sexo Tipo       Raza   PaisDeOrigen");
    for(int i=0; i<tamList; i++)
    {
        if(list[i].isEmpty==0)
        {
            mostrarMascota(list[i], listaRazas, tamRaz);
        }
    }
}

void mostrarMascota(eMascota x, eRaza *list, int tamRaz)
{
    printf("\n%8s  %d    %c    %c   ", x.nombre, x.edad, x.sexo, x.tipo);
    for(int i=0; i<tamRaz; i++)
    {
        if(x.idRaza == list[i].id)
        {
            printf("%10s", list[i].descripcion);
            printf("    %10s", list[i].paisDeOrigen);
        }

    }
}

void hardcodearRazas(eRaza *list, int tamList)
{
    //datos a hardcodear
    int ids[4]= {10,11,12,13};
    char descripciones[4][51]= {"siames", "doberman", "persa", "pastor belga"};
    char tamanios[4]= {'c', 'g', 'm', 'g'}; //chico ,mediano o grande,
    char paisesDeOrigen[4][51]= {"Tailandia", "Alemania", "Persia", "Belgica"};

    for(int i=0; i<tamList; i++)
    {
        list[i].id= ids[i];
        strcpy(list[i].descripcion, descripciones[i]);
        list[i].tamanio = tamanios[i];
        strcpy(list[i].paisDeOrigen, paisesDeOrigen[i]);
    }
}
