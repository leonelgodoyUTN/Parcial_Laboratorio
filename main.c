/* Autor: Leonel Godoy
    1B
8/10/2020
**Parcial Laboratorio I-  1era parte
PENDIENTES:

///////////////////////////

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

se deben modificar las estructuras y las funcionalidades,                       DONE
no se pueden tener campos de la versión anterior en las estructuras.
debemos tener hardcodeado los datos de las 7 mascotas
incluyendo los países y la relación con la raza y el atributo peso

#Opción del menú Alta de RAZA:
dar de alta una raza, mostrando el listado de países disponibles.                   DONE

#-Opción del menú Listar mascota con la raza y los datos del pais (nombrePais,       DONE
CodigoTelefonico)

#-Opción del menú ordenar mascotas por el Código Telefónico del país, de mayor      DONE
a menor.

********************************6ta parte
#-Opción Listar por TAMAÑO y PESO:                                                  DONE
-Sabiendo que solo hay tres tamaños(tamaño{chico ,mediano o grande}),pedir
el ingreso al usuario de un tamaño válido y mostrar el listado de mascotas de este
tamaño con sus países de origen peso y la suma total del peso entre estas mascotas.

******************************** 7ma parte
#Opción borrar RAZA:
borrado en cascada de una raza, al borrar una raza , se borran todas las
mascotas de esa raza                                                                    DONE


#-Opción Listar por TIPO y PESO:                        DONE
Sabiendo que solo hay tres tipos de mascotas (tipo{gato ,perro o raro}),
informar el peso total de cada tipo, la cantidad de mascotas por tipo y el promedio de
peso por tipo.Estos tres datos en una tabla bien hecha.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "mascotas.h"

#define primerIdMascotas 1000
#define MAXMASCOTAS 10  //espacio total para nuestro array de mascotas
#define HARDMASCOTAS 5 //las mascotas que voy a hardcodear

#define primerIdRazas 10
#define MAXRAZAS 20     //espacio total para nuestro array de razas
#define HARDRAZAS 5 //las razas que voy a hardcodear

#define primerIdPaises 100
#define MAXPAISES 20
#define HARDPAISES 5

#define primerIdTamanios 1
#define MAXTAMANIOS 3
#define HARDTAMANIOS 3

int main()
{
    //los primeros ids estan en #define's
    int proximoId= primerIdMascotas;
    int proximoIdRaza= primerIdRazas;
    int proximoIdPais= primerIdPaises;
    int proximoIdTamanio = primerIdTamanios;

    //declaro mis arrays de mascota, razas, paises
    eMascota listadoMascotas[MAXMASCOTAS];
    eRaza listadoRazas[MAXRAZAS];
    ePais listadoPaises[MAXPAISES];
    eTamanio listadoTamanios[MAXTAMANIOS];

    //saludar();
    //inicializo arrays pòniendo el campo isEmpty = 1 en todos los lugares disponibles
    inicializarArrayRazas(listadoRazas, MAXRAZAS);
    inicializarArrayMascotas(listadoMascotas, MAXMASCOTAS);
    inicializarArrayPaises(listadoPaises, MAXPAISES);
    inicializarArrayTamanios(listadoTamanios, MAXTAMANIOS);

    //hardcodeos para comenzar a trabajar
    hardcodearRazas(listadoRazas, HARDRAZAS, &proximoIdRaza);
    hardcodearMascotas(listadoMascotas, HARDMASCOTAS, &proximoId);
    hardcodearPaises(listadoPaises, HARDPAISES, &proximoIdPais);
    hardcodearTamanios(listadoTamanios, HARDTAMANIOS, &proximoIdTamanio);

    int salir=0;
    char confirma;
    int opcion;
    char subOpcion;
    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1://ALTAS
            utn_getChar(&subOpcion, "\na. alta mascota\nb. alta raza\nc. alta pais\nd. Cancelar\nIndique opcion: ", "\nERROR\n", 'a', 'd', 3);
            switch(subOpcion)
            {
            case 'a':
                altaMascota(listadoMascotas, MAXMASCOTAS, &proximoId, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES, listadoTamanios, MAXTAMANIOS, primerIdRazas, primerIdRazas+HARDRAZAS);
                break;
            case 'b':
                altaRaza(listadoRazas, MAXRAZAS, &proximoIdRaza, listadoPaises, MAXPAISES, listadoTamanios, MAXTAMANIOS);
                break;
            case 'c':
                //altaPais
                altaPais(listadoPaises, MAXPAISES, &proximoIdPais);
                break;
            }

            break;



        case 2://BAJAS

            utn_getChar(&subOpcion, "\na. baja mascota\nb. baja raza\nc. baja pais\nd. Cancelar\nIndique opcion: ", "\nERROR\n", 'a', 'd', 3);
            switch(subOpcion)
            {
            case 'a':
                bajaMascota(listadoMascotas, MAXMASCOTAS, primerIdMascotas, primerIdMascotas + HARDMASCOTAS );
                break;
            case 'b':
                bajaRaza(listadoRazas, MAXRAZAS, primerIdRazas, primerIdRazas + HARDRAZAS, listadoMascotas, MAXMASCOTAS);
                break;
            case 'c':
                bajaPais(listadoPaises, MAXPAISES, primerIdPaises, primerIdPaises + HARDPAISES);
                break;
            }
            break;



        case 3: //MODIFICACIONES
            utn_getChar(&subOpcion, "\na. modif mascota\nb. modif raza -no disp-\nc. modif pais -no disp-\nd. Cancelar\nIndique opcion: ", "\nERROR\n", 'a', 'd', 3);
            switch(subOpcion)
            {
            case 'a':
                modificarMascota(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, 1000, proximoId);
                break;
            case 'b':
                printf("\nFuncion aun no programada***\n");
                system("pause");
                break;
            case 'c':
                printf("\nFuncion aun no programada***\n");
                system("pause");
                break;
            }
            break;


        case 4:// LISTADOS
            system("cls");
            printf("\n***Submenu de listados");
            utn_getChar(&subOpcion, "\na. Listar mascotas\nb. Listar razas\nc. Listar paises\nd.Listar mascotas de un determinado tamanio\ne.Listar por Tipo(especie) Y peso\nf. Menu aterior\nIndique opcion: ", "\nERROR\n", 'a', 'f', 3);
            switch(subOpcion)
            {
            case 'a':
                listarMascotas(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXMASCOTAS, listadoPaises, MAXPAISES);
                break;
            case 'b':
                listarRazas(listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES, listadoTamanios, MAXTAMANIOS);
                break;
            case 'c':
                listarPaises(listadoPaises, MAXPAISES);
                break;
            case 'd':
                listarPorTamanioYPeso(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES, listadoTamanios, MAXTAMANIOS);
                break;
            case 'e':
                listarPorTipoYPeso(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS);
                break;
            }
            system("pause");
            break;


        case 5:
            system("cls");
            printf("\n***Submenu de Ordenamientos");
            utn_getChar(&subOpcion, "\na.ordenar mascotas por pais\nb.ordenar por el codigo telefono del pais de origen de cada mascota\nc.Menu aterior\nIndique opcion: ", "\nERROR\n", 'a', 'd', 3);
            switch(subOpcion)
            {
            case 'a':
                printf("\nNo funciona");
                ordenarPorPais(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES);
                break;
            case 'b':

                ordenarPorCodigoTelefonico(listadoMascotas, MAXMASCOTAS, listadoRazas, MAXRAZAS, listadoPaises, MAXPAISES);
                break;
            }
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

