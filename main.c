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
#Borrado lógico de una mascota del listado DONE
#-Se debe mostrar un listado de mascotas ordenadas por país de origen. DONE

******************************** 3era parte
#-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de
razas disponibles, teniendo en cuenta que ya tengo 5 mascotas cargadas y que el
máximo es 10 DONE
#-Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa
raza DONE
******************************** 4ta parte
#Modificación de una mascotas(todo menos el id).    DONE
#Menú de opciones   DONE
#-Alta de RAZA (20 razas   maximo) DONE
#-Se debe mostrar el país de origen que tenga más mascotas en nuestra
veterinaria. PENDIENTE

******************************** 5ta parte
excluyente :

#Menú de opciones,con todas las opciones pedidas en las partes anteriores
Se nos agregaron dos mascotas más , un dogo argentino y un pastor alemán,
debemos hardcodear las nuevas razas. DONE

Vamos a tener que realizar la estructura pais,
con:(nombreDePais,continente,CodigoTelefonico)argentina =54 , alemania= 49,
belgica =32, tailandia=66,persia=98. DONE

se deben modificar las estructuras y las funcionalidades, DONE
no se pueden tener campos de la versión anterior en las estructuras.
debemos tener hardcodeado los datos de las 7 mascotas
incluyendo los países y la relación con la raza y el atributo peso

#Opción del menú Alta de RAZA:
dar de alta una raza, mostrando el listado de países disponibles. DONE

#-Opción del menú Listar mascota con la raza y los datos del pais (nombrePais,
CodigoTelefonico) DONE

#-Opción del menú ordenar mascotas por el Código Telefónico del país, de mayor
a menor.

********************************6ta parte
#-Opción Listar por TAMAÑO y PESO:
-Sabiendo que solo hay tres tamaños(tamaño{chico ,mediano o grande}),pedir
el ingreso al usuario de un tamaño válido y mostrar el listado de mascotas de este
tamaño con sus países de origen peso y la suma total del peso entre estas mascotas.

******************************** 7ma parte
#Opción borrar RAZA:
borrado en cascada de una raza, al borrar una raza , se borran todas las
mascotas de esa raza
#-Opción Listar por TIPO y PESO:
Sabiendo que solo hay tres tipos de mascotas (tipo{gato ,perro o raro}),
informar el peso total de cada tipo, la cantidad de mascotas por tipo y el promedio de
peso por tipo.Estos tres datos en una tabla bien hecha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "mascotas.h"
#define MAXMASCOTAS 10  //espacio total para nuestro array de mascotas
#define HARDMASCOTAS 5 //las mascotas que voy a hardcodear
#define MAXRAZAS 20     //espacio total para nuestro array de razas
#define HARDRAZAS 5 //las razas que voy a hardcodear
#define MAXPAISES 20
#define HARDPAISES 5

int main()
{
    /*
    eMascota listaDeMascotas[MAXMASCOTAS];
    eRaza listaDeRazas[MAXRAZAS];
    listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica
    */

    int proximoId= 1000;//los primeros ids son elegidos arbitrariamente
    int proximoIdRaza=10;
    int proximoIdPais=100;

    //declaro mis arrays de mascota y razas
    eMascota listadoMascotas[MAXMASCOTAS];
    eRaza listadoRazas[MAXRAZAS];
    ePais listadoPaises[MAXPAISES];

    //saludar();
    //inicializo ambos arrays pòniendo el campo isEmpty = 1 en todos los lugares disponibles
    inicializarArrayRazas(listadoRazas, MAXRAZAS);
    inicializarArrayMascotas(listadoMascotas, MAXMASCOTAS);
    inicializarArrayPaises(listadoPaises, MAXPAISES);
    //precargo algunas razas y mascotas para comenzar a trabajar
    hardcodearRazas(listadoRazas, HARDRAZAS, &proximoIdRaza);
    hardcodearMascotas(listadoMascotas, HARDMASCOTAS, &proximoId);
    hardcodearPaises(listadoPaises, HARDPAISES, &proximoIdPais);

    int salir=0;
    char confirma;
    int opcion;
    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1:
            cargarMascota(listadoMascotas, MAXMASCOTAS, &proximoId);
            break;
        case 2:
            borrarMascotaDelListado(listadoMascotas, MAXMASCOTAS, 1000, 1000+MAXMASCOTAS);
            break;
        case 3:
            modificarMascota(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, 1000, proximoId);
            break;
        case 4:
            mostrarListadoCompleto(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES);
            system("pause");
            break;
        case 5:

            ordenarPorPais(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES);
            break;
        case 6:
            //printf("\nDEBUG");
            //system("pause");
            listarRazasConSusMascotas(listadoRazas, MAXRAZAS, listadoMascotas, MAXMASCOTAS);
            break;
        case 7:
            //printf("\nproximo id raza %d", proximoIdRaza);system("pause");
            agregarRaza(listadoRazas, MAXRAZAS, &proximoIdRaza, listadoPaises, MAXPAISES);
            //printf("\nproximo id raza %d", proximoIdRaza);system("pause");
            break;

        case 8:
            //mostrarPaisConMasMascotas
            mostrarPaisConMasMascotas(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES);
            break;

        case 9:
            printf("\nConfirma salir del programa? s/n: ");

            myGets(&confirma, 2);

            if(confirma=='s')
            {
                salir =1;
            }

        }
    }
    while(salir==0);


    return 0;
}

