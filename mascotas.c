#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "utn.c"
typedef struct
{
    int id;//PK
    char nombre[51];
    int edad;
    char sexo;
    char tipo[10]; //{gato ,perro o raro}
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


void inicializarArrayMascotas(eMascota *list, int tamList)
{
    for(int i=0; i<tamList; i++)
    {
        list[i].isEmpty=1;
    }
}

/** \brief carga un array de eMascota hasta con 5 elementos
 * \param list puntero a array de eMascota
 * \param tamHardcodeo cuantos elementois se van a cargar. MAXIMO 5
 */
void hardcodearMascotas(eMascota* list, int tamHardcodeo)
{
    char nombres[5][51]= {"Rufo", "Firulais", "Cata", "Anush", "Paul"};
    int edades[5]= {3,5,7,2,1};
    char sexos[5]= {'m', 'm', 'f', 'f', 'm'};
    char tipos[5][10]= {"perro", "perro", "gato", "gato", "perro"};
    int idRazas[5]= {11, 13, 10, 12, 13};
    if(tamHardcodeo<=5)
    {
        for(int i=0; i<tamHardcodeo; i++)
        {
            list[i].id = i+1000;
            strcpy(list[i].nombre, nombres[i]);
            list[i].edad = edades[i];
            list[i].sexo = sexos[i];
            strcpy(list[i].tipo, tipos[i]);
            list[i].idRaza = idRazas[i];
            list[i].isEmpty = 0;
        }
    }
    else
    {
        printf("\n***Error al hardcodear Mascotas\n");
        system("pause");
    }

}

/** \brief hardcodea un array de eRaza
 * \param  puntero a array de eRaza
 * \param  cantidad derazas a hardcodear. MAXIMO 5
*/
void hardcodearRazas(eRaza *list, int cantidad)
{
    int ids[5]= {10,11,12,13,14};
    char descripciones[5][51]= {"siames", "doberman", "persa", "pastor belga", "OTRO"};
    char tamanios[5]= {'c', 'g', 'm', 'g', 'x'}; //chico ,mediano o grande,
    char paisesDeOrigen[5][51]= {"Tailandia", "Alemania", "Persia", "Belgica", "N/A"};
    if(cantidad<6)
    {
        for(int i=0; i<cantidad; i++)
        {
            list[i].id= ids[i];
            strcpy(list[i].descripcion, descripciones[i]);
            list[i].tamanio = tamanios[i];
            strcpy(list[i].paisDeOrigen, paisesDeOrigen[i]);
        }
    }
    else
    {
        printf("\n***ERROR al hardcodear razas bro");
        system("pause");
    }

}

/** \brief recibe un ID de raza y lo busca en un array de eRaza
 * \param id a buscar
 * \param list puntero a array de eRaza donde buscar la coincidencia
 * \param tamRaz tamanio del array de eRaza
 * \return retorna un elemento del tipo eRaza;
 */
eRaza buscarRaza(int id, eRaza *list, int tamRaz)
{
    eRaza aux;
    int exito=0;

    for(int i=0; i<tamRaz; i++)
    {
        if(id == list[i].id)
        {
            aux= list[i];
            exito=1;
            break;
        }
    }
    if(!exito)
    {
        printf("\n***Error al buscar raza;");
        system("pause");
    }
    return aux;
}

/** \brief recibe eMascota y eRaza, y los muestra*/
void mostrarMascotaConRaza(eMascota x, eRaza razaRecibida)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c    %s  %15s  %10s",x.id, x.nombre, x.edad, x.sexo, x.tipo, razaRecibida.descripcion, razaRecibida.paisDeOrigen);
    }
}

/** \brief muestra array de eMascota recibido */
void mostrarListadoCompleto(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz)
{
    eRaza aux;
    printf("\nID   Nombre   Edad Sexo Tipo          Raza       PaisDeOrigen");

    for(int i=0; i<tamList; i++)
    {
        aux = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
        mostrarMascotaConRaza(list[i], aux);
    }
}


void mostrarMascota(eMascota x)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c    %s ",x.id, x.nombre, x.edad, x.sexo, x.tipo);
    }
}
int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar)
{
    int indice =-1;

    for(int i=0;i<tamList;i++)
    {
        if(idABuscar == list[i].id)
        {
            indice=i;
        }
    }
    return indice;
}



/** \brief Hace la baja logica de una mascota (campo isEmpty=1).
recibe un array de eMascota, solicita ingreso del id a dar de baja,
lo busca en el array y muestra el elemento, pide confirmacion y luego baja logica.
 *
 * \param list eMascota*
 * \param tamList int
 * \return int
 *
 */
void borrarMascotaDelListado(eMascota *list, int tamList, int minId, int maxId)
{

    printf("\n**Funcion Borrar Marcota\n");
    int idABorrar;
    utn_getNumero(&idABorrar, "\nIngrese el id de la mascota a borrar: ",
                              "\nERROR ", minId, maxId, 3);
    int indiceABorrar;
    indiceABorrar = buscarIndiceMascotaPorId(list, tamList, idABorrar);

    char confirmacion;
    if(indiceABorrar==-1)
    {
        printf("\nNo se encontro el id de mascota...");
        system("pause");
    }
    else
    {
        mostrarMascota(list[indiceABorrar]);
        printf("\n***Confirma la baja? s/n: ");
        scanf("%c",&confirmacion);
        if(confirmacion=='s')
        {
            list[indiceABorrar].isEmpty=1; //AQUI se ha borrado;
            printf("\nSe ha dado de baja el registro****\n");
            system("pause");
        }
    }

}

void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz)
{
    eMascota aux;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    for(int i=0; i<tamList-1; i++)
    {
        auxRazaI = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
        for(int j=i+1; j<tamList; j++)
        {
            auxRazaJ= buscarRaza(list[j].idRaza, listaRazas, tamRaz);

            if(strcmp(auxRazaI.paisDeOrigen, auxRazaJ.paisDeOrigen)>0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }

}


int buscarLugar(eMascota *list, int tamList)
{
    int indice = -1;

    for(int i=0; i<tamList; i++)
    {
        if(list[i].isEmpty==1)
        {
            return i;
        }
    }
    return indice;
}
//Importante diferenciar entre ID e indice. Ambos son unicos, pero el id ES primaryKey y NO es la posicion en el array
void cargarMascota(eMascota *list, int tamList, int* nextId)
{
    int indiceLibre;
    indiceLibre = buscarLugar(list, tamList);
    //printf("\nIndice libre en i:%d", indiceLibre);
    // *nextId= *nextId+1;
    // printf("\nnextId: %d", *nextId);*
    //list[indiceLibre].id = *nextId;
    //printf("\nnextId: %d", *nextId);
    //printf("\nlist[indiceLibre].id:%d", list[indiceLibre].id);
    if(indiceLibre!=-1)
    {

        utn_getTexto(list[indiceLibre].nombre, 51, "\ningrese nombre: ", "\nERROR\n");

        utn_getNumero(&list[indiceLibre].edad, "\ningrese edad: ", "\nERROR\n", 0, 99, 3);

        utn_getChar(&list[indiceLibre].sexo, "\nindique sexo m/f: ", "\nERROR", 'f', 'm', 3);

        utn_getTexto(list[indiceLibre].tipo, 10, "\nIndique uno de los siguientes: 'perro' , 'gato' o 'raro'\n", "\nERROR\n");

        list[indiceLibre].isEmpty = 0;


        list[indiceLibre].id = *nextId;

        // int idRaza
        if( strcmp(list[indiceLibre].tipo, "perro")==0 || strcmp(list[indiceLibre].tipo, "gato")==0)
        {
            utn_getNumero(&list[indiceLibre].idRaza, "\nIngrese id de raza 10-13: ", "\nERROR\n", 10, 13, 3);
        }


        *nextId=*nextId+1;
    }


}
/*void cargarMascota(eMascota *list, int tamList, int* nextId)
{
    int indiceLibre;
    indiceLibre = buscarLugar(list, tamList);

    if(indiceLibre!=-1)
    {
        list[indiceLibre].id = nextId;
        utn_getTexto(list[indiceLibre].nombre, 51, "\ningrese nombre: ", "\nERROR\n", 3);
        fflush(stdin);
        utn_getNumero(&list[indiceLibre].edad, "\ningrese edad: ", "\nERROR\n", 0, 99, 3);
        utn_getChar(&list[indiceLibre].sexo, "\nindique sexo m/f: ", "\nERROR\n", 'f', 'm', 3);
        utn_getTexto(list[indiceLibre].tipo, 10, "\nIndique uno de los siguientes: 'perro' , 'gato' o 'raro'\n", "\nERROR\n", 3);
        list[indiceLibre].isEmpty = 0;
        // int idRaza
        utn_getNumero(&list[indiceLibre].idRaza, "\nIngrese id de raza 10-13: ", "\nERROR\n", 10, 13, 3);
        *nextId++;
    }
}*/

int menu()
{
    int opcion;
    int respuesta;

    do
    {
        respuesta= utn_getNumero(&opcion, "\n**Menu de opciones***\n\n1-Alta\n2-Baja\n3-Modificar registro\n4-Listar\n5-Ordenar por nombre\n6-Ordenar por ID\n9-SALIR\n", "\nERROR, ingrese una opcion valida\n", 1, 9,3);
        if(!respuesta)
        {
            switch(opcion)
            {
            case 1:
                printf("\nEntro al case 1");

                break;

            case 2:
                printf("\nEntro al case 2");
                break;
                //etc

            }
        }
    }
    while(opcion != 9); //OPCION SALIDA


    return 0;
}
