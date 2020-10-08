#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void hardcodearMascotas(eMascota* list)
{
    int tamList=5;
    char nombres[5][51]= {"Rufo", "Firulais", "Cata", "Anush", "Paul"};
    int edades[5]= {3,5,7,2,1};
    char sexos[5]= {'m', 'm', 'f', 'f', 'm'};
    char tipos[5][10]= {"perro", "perro", "gato", "gato", "perro"};
    int idRazas[5]= {11, 13, 10, 12, 13};

    for(int i=0; i<tamList; i++)
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

void hardcodearRazas(eRaza *list, int tamList)
{
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


eRaza buscarRaza(int id, eRaza *list, int tamRaz)
{
    eRaza aux;
    for(int i=0; i<tamRaz; i++)
    {
        if(id == list[i].id)
        {
            aux= list[i];
            break;
        }
    }
    return aux;
}

void mostrarMascotaConRaza(eMascota x, eRaza razaRecibida)
{
    if(x.isEmpty==0)
    {
        printf("\n%8s  %d    %c    %s  %10s  %10s", x.nombre, x.edad, x.sexo, x.tipo, razaRecibida.descripcion, razaRecibida.paisDeOrigen);
    }
}

void mostrarListadoCompleto(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz)
{
    eRaza aux;
    printf("\nNombre   Edad Sexo Tipo       Raza   PaisDeOrigen");

    for(int i=0; i<tamList; i++)
    {
        aux = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
        mostrarMascotaConRaza(list[i], aux);
    }
}


//fuera de uso, version vieja
/*
void mostrarMascota(eMascota x, eRaza *list, int tamRaz)
{
    if(x.isEmpty==0) //lo muestro
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

}*/


/** \brief hace la baja logica de una mascota por ID
 *
 * \param *list listado de mascotas
 * \param tamList tamanio
 * \param id id de la mascota a eliminar
 * \return 0 si se realizo con exito la baja, -1 si no
 *
 */

int borrarMascotaDelListado(eMascota *list, int tamList, int id)
{
    for(int i=0; i<tamList; i++)
    {
        if(id == list[i].id)
        {
            list[i].isEmpty=1;
            return 0;
        }
    }
    return -1;
}

void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz)
{
    eMascota aux;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    for(int i=0;i<tamList-1;i++)
    {
        auxRazaI = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
        for(int j=i+1; j<tamList;j++)
        {
            auxRazaJ= buscarRaza(list[j].idRaza, listaRazas, tamRaz);

            if(strcmp(auxRazaI.descripcion, auxRazaJ.descripcion)>0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }

}

void cargarMascota(eMascota *list, int tamList)
{

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

