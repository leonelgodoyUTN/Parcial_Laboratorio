#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
//el burbujeo no esta listo

typedef struct
{
    int id;//PK
    char nombre[51];
    int edad;
    char sexo;
    char especie[10];//Especie es mas apropiado que "tipo" //{gato ,perro o raro}
    int isEmpty;
    int idRaza;//FK a eRaza
} eMascota;


typedef struct
{
    int id;//PK
    char descripcion[51];
    char tamanio[10]; //chico ,mediano o grande,
    //char paisDeOrigen[51];
    int idPaisDeOrigen;//FK a pais
    int isEmpty;
} eRaza;

typedef struct
{
    int id;
    char nombrePais[51];
    char continente[51];
    int codigoTelefonico;
    int isEmpty;
}ePais;

void saludar()
{
    printf("\nHola Carolas!\n");
}

void inicializarArrayMascotas(eMascota *list, int tamList)
{
    for(int i=0; i<tamList; i++)
    {
        list[i].isEmpty = 1;
    }
}

void inicializarArrayRazas(eRaza *list, int tamRaz)
{
    for(int i=0; i<tamRaz; i++)
    {
        list[i].isEmpty = 1;
    }
}

void inicializarArrayPaises(ePais *list, int tamPais)
{
    for(int i=0; i<tamPais; i++)
    {
        list[i].isEmpty= 1;
    }
}



/** \brief hardcodea un array de eRaza
 * \param  puntero a array de eRaza
 * \param  cantidad derazas a hardcodear. MAXIMO 5
*/
void hardcodearRazas(eRaza *list, int tamHardcodeo, int*proximoIdRaza)
{
    //int ids[5]= {10,11,12,13,14};
    char descripciones[7][51]= {"siames", "doberman", "persa", "pastor belga", "OTRO", "dogo arg", "pastor aleman"};
    char tamanios[7][10]= {"chico", "grande", "mediano", "grande", "NA", "mediano", "grande"}; //chico ,mediano o grande,
    int idPaisesDeOrigen[7]= {103, 101, 104, 102, 100, 100, 102};
    if(tamHardcodeo<6)
    {
        for(int i=0; i<tamHardcodeo; i++)
        {
            list[i].id= *proximoIdRaza;
            strcpy(list[i].descripcion, descripciones[i]);
            strcpy(list[i].tamanio, tamanios[i]);
            list[i].idPaisDeOrigen = idPaisesDeOrigen[i];
            list[i].isEmpty=0;
            *proximoIdRaza= *proximoIdRaza+1;
        }
    }
    else
    {
        printf("\n***ERROR al hardcodear razas bro");
        system("pause");
    }

}

void hardcodearPaises(ePais* list, int tamHardcodeo, int*proximoIdPais)
{
    char nombresPaises[5][51]= {"Argentina", "Alemania", "Belgica", "Tailandia", "Persia"};
    char continentes[5][51]= {"Sudamerica", "Europa", "Europa", "Asia", "Asia"};
    int codigosTelefonicos[5]= {54, 49, 32, 66, 98};
    if(tamHardcodeo<= 5)
    {
         for(int i=0; i<tamHardcodeo; i++)
        {

            list[i].codigoTelefonico = codigosTelefonicos[i];
            strcpy(list[i].continente, continentes[i]);
            strcpy(list[i].nombrePais, nombresPaises[i]);
            list[i].id = *proximoIdPais;
            list[i].isEmpty=0;
            *proximoIdPais = *proximoIdPais+1;

        }
    }

}

/** \brief carga un array de eMascota hasta con 5 elementos
 * \param list puntero a array de eMascota
 * \param tamHardcodeo cuantos elementois se van a cargar. MAXIMO 5
 */
void hardcodearMascotas(eMascota* list, int tamHardcodeo, int*proximoId)
{
    char nombres[7][51]= {"Rufo", "Firulais", "Cata", "Anush", "Paul", "Tyson", "Negro"};
    int edades[7]= {3,5,7,2,1, 2, 5};
    char sexos[7]= {'m', 'm', 'f', 'f', 'm', 'm', 'm'};
    char especies[7][10]= {"perro", "perro", "gato", "gato", "perro", "perro", "perro"};
    int idRazas[7]= {11, 13, 10, 12, 13, 15, 16};
    if(tamHardcodeo<=7)
    {
        for(int i=0; i<tamHardcodeo; i++)
        {
            list[i].id = *proximoId;
            strcpy(list[i].nombre, nombres[i]);
            list[i].edad = edades[i];
            list[i].sexo = sexos[i];
            strcpy(list[i].especie, especies[i]);
            list[i].idRaza = idRazas[i];
            list[i].isEmpty = 0;
            *proximoId = *proximoId+1;
        }
    }
    else
    {
        printf("\n***Error al hardcodear Mascotas\n");
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
        strcpy(aux.descripcion, "Error 143");
        aux.id=-1;
        aux.isEmpty=1;
        aux.idPaisDeOrigen= -1;
        strcpy(aux.tamanio, "Error 143");
    }
    return aux;
}

ePais buscarPais(int id, ePais lista[], int tamPais)
{
    ePais aux;
    int exito=0;
    for(int i=0; i<tamPais; i++)
    {
        if(id == lista[i].id)
        {
            aux= lista[i];
            exito=1;
            break;
        }
    }
    if(!exito)
    {
        strcpy(aux.nombrePais, "Error 143");
        aux.id=-1;
        aux.isEmpty=1;
        aux.codigoTelefonico= -1;
    }
    return aux;
}


void mostrarMascota(eMascota x)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c    %s ",x.id, x.nombre, x.edad, x.sexo, x.especie);
    }
}

/** \brief recibe eMascota y eRaza, y los muestra*/
void mostrarMascotaConRazaYPais(eMascota x, eRaza razaRecibida)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c    %s  %15s ",x.id, x.nombre, x.edad, x.sexo, x.especie, razaRecibida.descripcion);
    }
}


/** \brief muestra array de eMascota recibido */
void mostrarListadoCompleto(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz)
{
    eRaza aux;
    printf("\nID   Nombre   Edad Sexo Especie       Raza       PaisDeOrigen");

    for(int i=0; i<tamList; i++)
    {
        if(list[i].isEmpty==0)
        {
            aux = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
            mostrarMascotaConRazaYPais(list[i], aux);

        }

    }
}

int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar)
{
    int indice =-1;

    for(int i=0; i<tamList; i++)
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
    if(indiceABorrar==-1)//es decir si el ID no fue valido
    {
        printf("\nNo se encontro el id de mascota...");
        system("pause");
    }
    else    //si el ID si fue valido...
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

/** \brief retorna el primer indicelibre en un array de eMascota
 *
 * \param *list puntero a array de eMascota
 * \param tamList tamanio del array
 * \return retorna el primer indice libre que encuentra or -1 si el array esta lleno
 *
 */

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
    eMascota auxMascota;

    //printf("\nIndice libre en i:%d", indiceLibre);
    // *nextId= *nextId+1;
    // printf("\nnextId: %d", *nextId);*
    //list[indiceLibre].id = *nextId;
    //printf("\nnextId: %d", *nextId);
    //printf("\nlist[indiceLibre].id:%d", list[indiceLibre].id);
    if(indiceLibre==-1)//es decir, si no hay lugar disponible en el array
    {
        printf("\n**SISTEMA COMPLETO");
        system("pause");
    }
    else//pido los datos
    {

        int cargoNombre = utn_getTexto(auxMascota.nombre, 51, "\ningrese nombre: ", "\nERROR\n");
        int cargoEdad = utn_getNumero(&auxMascota.edad, "\ningrese edad: ", "\nERROR\n", 0, 99, 3);
        int cargoSexo = utn_getChar(&auxMascota.sexo, "\nindique sexo m/f: ", "\nERROR", 'f', 'm', 3);
        int cargoEspecie = utn_getTexto(auxMascota.especie, 10, "\nIndique uno de los siguientes: 'perro' , 'gato' o 'raro'\n", "\nERROR\n");
        int cargoRaza = utn_getNumero(&auxMascota.idRaza, "\nIngrese id de raza 10-13: ", "\nERROR\n", 10, 20, 3);


        if(cargoNombre==0 && cargoEdad==0 && cargoSexo==0 && cargoEspecie==0 && cargoRaza==0)
        {
            list[indiceLibre] = auxMascota;
            list[indiceLibre].isEmpty = 0;
            list[indiceLibre].id = *nextId;
            *nextId=*nextId+1;
        }
        else
        {
            printf("\n***Hubo error a la hora de cargar algun dato\n");
            system("pause");
        }
    }
}

int menu()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion, "\n**Menu de opciones***\n1-Cargar mascota\n2-Borrar mascota\n3-Modificar mascota\n4-Listado completo\n5-Ordenar por pais de origen\n6-Listar razas con sus mascotoas\n7-Agregar raza\n9-SALIR\n", "\nERROR, ingrese una opcion valida\n", 1, 9,3);
    return opcion;
}


void listarRazas(eRaza *list, int tamRaz, ePais listaPaises[], int tamPais)
{
    ePais auxPais;
    if(list!=NULL && tamRaz>0)
    {
        printf("\n***Listado de razas cargadas");
        printf("\nID Descripcion PaisOrigen Tamanio");
        for(int i=0; i<tamRaz; i++)
        {
            if(list[i].isEmpty==0)//si hay un estructura de raza cargada busco su pais
            {
                auxPais = buscarPais(list[i].idPaisDeOrigen, listaPaises, tamPais);
                printf("\n%d %s %s %s", list[i].id, list[i].descripcion, auxPais.nombrePais, list[i].tamanio);
            }

        }
    }
    printf("\n***fin de informe\n");
    system("pause");
}



void listarRazasConSusMascotas(eRaza listaRazas[], int tamRaz, eMascota listaMascotas[], int tamMascotas)
{

    if(listaRazas!= NULL && tamRaz>0 && listaMascotas != NULL && tamMascotas>0)
    {
        printf("\n***Se listara cada raza y las mascotas de cada una***");

        for(int i=0; i<tamRaz; i++)//recorro arrar de razas
        {
            if(listaRazas[i].isEmpty==0)//si hay una estructura eRaza la muestro
            {

                printf("\n\n**Raza: %s IdRaza: %d Tamanio: %s ",  listaRazas[i].descripcion,listaRazas[i].id, listaRazas[i].tamanio);
                //debo mostrar todos los eMascotas cuyo idconcuerde
                for(int j=0; j<tamMascotas; j++)//para eso recorrere listaMascotas
                {
                    if(listaMascotas[j].idRaza == listaRazas[i].id)
                    {

                        mostrarMascota(listaMascotas[j]);
                    }
                }
            }
        }
    }
    system("pause");
}

/** \brief busca un lugar libre en un array de eRaza
 * \param puntero a lista
 * \param  tamanio del array
 * \return -1 error o el primer indice libre que encuentre
 */
int buscarLugarLibreRaza(eRaza *list, int tamRaz)
{
    int indice=-1;

    for(int i=0; i<tamRaz; i++)
    {
        if(list[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

//retorna el id de pais o -1 en caso de error
int elegirPais(ePais listaPaises[], int tamPaises)
{
    int retorno=-1;
    int opcion;
    int i;
    printf("\nElija un pais por numero");
    for(i=0; i<tamPaises;i++)
    {
        if(listaPaises[i].isEmpty==0)//muestro todos los paises con isEmpty=0
        {
            printf("\n%d  Pais: %s", i, listaPaises[i].nombrePais);
            //retorno=0;
        }
    }//luego le pido al usuario que elija opcion
    system("pause");
    printf("\nOpcion: ");
    utn_getNumero(&opcion, "\nElija un pais por numero : ", "\nERROR", 0, i,3);
    if(opcion >=0 && opcion<=i)
    {
        retorno = listaPaises[opcion].id;
    }

    return retorno;

}

void agregarRaza(eRaza *list, int tamRaz, int*nextId,ePais listaPaises[], int tamPaises)
{
    eRaza auxRaza;

    int indiceLibre;
    indiceLibre=buscarLugarLibreRaza(list, tamRaz);

    if(indiceLibre!=-1)//si hay lugar disponible
    {
        //cargo raza

        int cargoDescripcion = utn_getTexto(auxRaza.descripcion, sizeof(auxRaza.descripcion), "\nNombre de la raza: ", "\nERROR\n");
        int cargoTamanio = utn_getTexto(auxRaza.tamanio, sizeof(auxRaza.tamanio), "\nIndique tamanio de esta raza (chico, mediano, grande, N/A):\n", "\nERROR\n");
        auxRaza.idPaisDeOrigen = elegirPais(listaPaises, tamPaises);

        //si todo lo anterior fue bien, el sistema hace lo ultimo:
        //copiar el auxiliar al array, y ponerle campos id y isEmpty
        if(cargoDescripcion == 0 && cargoTamanio == 0 && auxRaza.idPaisDeOrigen!=-1)
        {
            auxRaza.id = *nextId;
            auxRaza.isEmpty=0;
            list[indiceLibre]=auxRaza;
            *nextId= *nextId+1;

            printf("\n**Se realizo la carga de la nueva raza");
            system("pause");
        }
    }
    else
    {
        printf("\n***No hay lugar para cargar mas razas\n");
        system("pause");
    }
}


/** \brief recibe un array de mascotas y uno de razas,  ordena el array de mascotas por pais de origen(alfabeticamente)
 * \param puntero a array de eMascotas
 * \param tamanio array mascotas
 * \param array de eRazas
 * \param tamanio array razas
 */
void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises)
{
    eMascota aux;
    ePais auxPaisI;
    ePais auxPaisJ;

    for(int i=0; i<tamList-1; i++)
    {
       // auxRazaI = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
        auxPaisI = buscarPais(list[i].idRaza, listaPaises, tamPaises);

        for(int j=i+1; j<tamList; j++)
        {
           // auxRazaJ= buscarRaza(list[j].idRaza, listaRazas, tamRaz);
           auxPaisJ= buscarPais(list[j].idRaza, listaPaises, tamPaises);

            if(strcmp(auxPaisI.nombrePais, auxPaisJ.nombrePais)>0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }
    printf("\n\n***Se ordenaron las mascotas por pais de origen alfabeticamente**");
    system("pause");
    /*
    eMascota aux;
    eRaza auxRazaI;
    eRaza auxRazaJ;
    ePais auxPaisI;
    ePais auxPaisJ;

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
    printf("\n\n***Se ordenaron las mascotas por pais de origen alfabeticamente**");
    system("pause");*/
}

void modificarMascota(eMascota *list, int tamList, eRaza listarRazas[], int tamRaz, int idMin, int idMax)
{
    int auxId;//el usuario ingresara el id, el sistema buscara el indice de él
    int banderaId;
    int auxIndice;
    char confirma;
    eMascota auxMascota;
    printf("\n***Modificar Registro de mascota");
    banderaId = utn_getNumero(&auxId, "\nIngrese el ID de la mascota a modificar", "error\n", idMin, idMax, 3);
    if(banderaId==0) //es decir si obtuve un ID
    {
        //muestro
        auxIndice = buscarIndiceMascotaPorId(list, tamList, auxId);
        if(auxIndice!= -1)
        {
            mostrarMascota(list[auxIndice]);

            utn_getChar(&confirma, "\nEs este el registro a modificar? s/n :", "\nerror\n", 'n', 's', 3);
            if(confirma=='s')
            {
                printf("\nSe pediran los nuevos datos\n");

                int cargoNombre = utn_getTexto(auxMascota.nombre, 51, "\ningrese nombre: ", "\nERROR\n");
                int cargoEdad = utn_getNumero(&auxMascota.edad, "\ningrese edad: ", "\nERROR\n", 0, 99, 3);
                int cargoSexo = utn_getChar(&auxMascota.sexo, "\nindique sexo m/f: ", "\nERROR", 'f', 'm', 3);
                int cargoEspecie = utn_getTexto(auxMascota.especie, 10, "\nIndique uno de los siguientes: 'perro' , 'gato' o 'raro'\n", "\nERROR\n");
                int cargoRaza = utn_getNumero(&auxMascota.idRaza, "\nIngrese id de raza 10-13: ", "\nERROR\n", 10, 20, 3);


                if(cargoNombre==0 && cargoEdad==0 && cargoSexo==0 && cargoEspecie==0 && cargoRaza==0)
                {
                    list[auxIndice] = auxMascota;
                    list[auxIndice].isEmpty = 0;
                    //list[auxIndice].id = *nextId;
                    //*nextId=*nextId+1;
                }
            }

        }
        else
        {
            printf("\n***Error. No se pudo obtener id");
        }
    }
}
