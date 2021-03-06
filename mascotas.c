#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


typedef struct
{
    int id;//PK
    char nombre[51];
    int edad;
    char sexo;
    char especie[10];//Especie es mas apropiado que "tipo" //{gato ,perro o raro}
    float peso;
    int isEmpty;
    int idRaza;//FK a eRaza
} eMascota;


typedef struct
{
    int id;//PK
    char descripcion[51];
    int idTamanio; //chico ,mediano o grande,
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
} ePais;

typedef struct
{
    int id;
    char  descripcion[10];
    int isEmpty;
} eTamanio;


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

void inicializarArrayTamanios(eTamanio *list, int tamTamanio)
{
    for(int i=0; i<tamTamanio; i++)
    {
        list[i].isEmpty=1;
    }
}



/** \brief hardcodea un array de eRaza
 * \param  puntero a array de eRaza
 * \param  cantidad derazas a hardcodear. MAXIMO 5
*/
void hardcodearRazas(eRaza *list, int tamHardcodeo, int*proximoIdRaza)
{
    //int ids[5]= {10,11,12,13,14};
    char descripciones[7][51]= {"siames", "doberman", "persa", "pastor belga", "NoAplica", "dogo arg", "pastor aleman"};
    int idTamanios[7] = {1,3,2,3,1,2,3};
    //char tamanios[7][10]= {"chico", "grande", "mediano", "grande", "NA", "mediano", "grande"}; //chico ,mediano o grande,
    int idPaisesDeOrigen[7]= {103, 101, 104, 102, 100, 100, 102};
    if(tamHardcodeo<6)
    {
        for(int i=0; i<tamHardcodeo; i++)
        {
            list[i].id= *proximoIdRaza;
            strcpy(list[i].descripcion, descripciones[i]);
            //strcpy(list[i].tamanio, tamanios[i]);
            list[i].idTamanio= idTamanios[i];
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
    char nombresPaises[6][51]= {"Argentina", "Alemania", "Belgica", "Tailandia", "Persia","No especificado"};
    char continentes[6][51]= {"Sudamerica", "Europa", "Europa", "Asia", "Asia", "N/A"};
    int codigosTelefonicos[6]= {54, 49, 32, 66, 98, 00};
    if(tamHardcodeo<= 6)
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
 * \param tamHardcodeo cuantos elementois se van a cargar. MAXIMO 7
 */
void hardcodearMascotas(eMascota* list, int tamHardcodeo, int*proximoId)
{
    char nombres[7][51]= {"Rufo", "Firulais", "Cata", "Anush", "Paul", "Tyson", "Negro"};
    int edades[7]= {3,5,7,2,1, 2, 5};
    char sexos[7]= {'m', 'm', 'f', 'f', 'm', 'm', 'm'};
    char especies[7][10]= {"perro", "perro", "gato", "gato", "perro", "perro", "perro"};
    float pesos[7] =  {20.6, 14.4, 3.5, 4.4, 14.3, 35.2, 22.8};
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
            list[i].peso = pesos[i];
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

void hardcodearTamanios(eTamanio* list, int tamHardcodeo, int*proximoIdTamanio)
{
    int ids[3] = {1,2,3};
    char descripciones[3][10]= {"chico", "mediano","grande"};
    if(tamHardcodeo<=3)
    {
        for(int i=0; i<tamHardcodeo; i++)
        {
            list[i].id = ids[i];
            strcpy(list[i].descripcion, descripciones[i]);
            list[i].isEmpty = 0;
        }
    }
    else
    {
        printf("\nError al hardcodear pesos");
        system("pause");
    }
}
/** \brief recibe un ID de raza y lo busca en un array de eRaza
 * \param id a buscar
 * \param list puntero a array de eRaza donde buscar la coincidencia
 * \param tamRaz tamanio del array de eRaza
 * \return retorna un elemento del tipo eRaza;
 */
eRaza buscarRaza(int idRaza, eRaza *list, int tamRaz)
{
    eRaza aux;
    int exito=0;

    for(int i=0; i<tamRaz; i++)
    {
        if(idRaza == list[i].id)
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
    }
    return aux;
}

ePais buscarPais(int idPais, ePais lista[], int tamPais)
{
    ePais aux;
    int exito=0;
    for(int i=0; i<tamPais; i++)
    {
        if(idPais == lista[i].id)
        {
            aux= lista[i];
            exito=1;
            break;
        }
    }
    if(!exito)
    {
        strcpy(aux.nombrePais, "Error 143, ID pais no hallado");
        system("pause");
        aux.id=-1;
        aux.isEmpty=1;
        aux.codigoTelefonico= -1;
    }
    return aux;
}

eTamanio buscarTamanio(int idTamanio, eTamanio listaTamanios[], int tamTamanios)
{
    eTamanio aux;
    int exito=0;
    for(int i=0; i<tamTamanios; i++)
    {
        if(idTamanio == listaTamanios[i].id)
        {
            aux= listaTamanios[i];
            exito=1;
            break;
        }
    }
    if(!exito)
    {
        strcpy(aux.descripcion, "Error 263");
        system("pause");
        aux.id=-1;
        aux.isEmpty=1;
    }
    return aux;
}


void mostrarMascota(eMascota x)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c   %.2fkg   %s ",x.id, x.nombre, x.edad, x.sexo, x.peso, x.especie);
    }
}

/** \brief recibe eMascota y eRaza, y los muestra*/
void mostrarMascotaConRazaYPais(eMascota x, eRaza razaRecibida, ePais paisRecibido)
{
    if(x.isEmpty==0)
    {
        printf("\n%d %8s  %d    %c  %8s  %.2f  %12s %10s   %10d ",x.id, x.nombre, x.edad, x.sexo, x.especie, x.peso, razaRecibida.descripcion, paisRecibido.nombrePais, paisRecibido.codigoTelefonico);
    }
}


/** \brief muestra array de eMascota recibido, con los datos del pais correspondiente */
void listarMascotas(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPais)
{
    eRaza auxRaza;
    ePais auxPais;
    printf("\nID   Nombre   Edad Sexo Especie Peso(kg)      Raza       PaisDeOrigen   CodigoTelefonico");

    for(int i=0; i<tamList; i++)
    {
        if(list[i].isEmpty==0)
        {
            auxRaza = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
            auxPais = buscarPais(auxRaza.idPaisDeOrigen, listaPaises, tamPais);
            mostrarMascotaConRazaYPais(list[i], auxRaza, auxPais);

        }

    }
}


void listarPaises(ePais *list, int tamPais)
{
    for(int i=0; i<tamPais; i++)
    {
        if(list[i].isEmpty ==0)
        {
            printf("\nPais: %10s Continente:%10s IdPais:%d", list[i].nombrePais, list[i].continente, list[i].id);
        }
    }
}

void listarTamanios(eTamanio *list, int tamTamanio)
{
    printf("\nID  Descripcion");
    for(int i=0; i<tamTamanio; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n%d  %s", list[i].id, list[i].descripcion);
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

int buscarIndiceRazaPorId(eRaza *list, int tamRaz, int idABuscar)
{
    int indice =-1;

    for(int i=0; i<tamRaz; i++)
    {
        if(idABuscar == list[i].id)
        {
            indice=i;
        }
    }
    return indice;
}

int buscarIndiceTamanioPorId(eTamanio *list, int tamTamanio, int idABuscar)
{
    int indice =-1;

    for(int i=0; i<tamTamanio; i++)
    {
        if(idABuscar == list[i].id)
        {
            indice=i;
        }
    }
    return indice;
}


/*
pedir el ingreso al usuario de un tama�o v�lido
y mostrar el listado de mascotas de este tama�o con sus pa�ses de origen,
peso y la suma total del peso entre estas mascotas.
*/
void listarPorTamanioYPeso(eMascota listaMascotas[], int tamList, eRaza listRazas[], int tamRaz, ePais listaPaises[], int tamPais, eTamanio listaTamanios[], int tamTamanios)
{
    int auxIdTamanio;//
    int auxIndiceTamanio;//
    float acumuladorPeso = 0;
    eTamanio auxTamanio;
    eRaza auxRaza;
    ePais auxPais;

    printf("\n****Funcion listar por Tamanio y peso");
    //muestro los tamanios y elijo uno
    listarTamanios(listaTamanios, tamTamanios);
    utn_getNumero(&auxIdTamanio, "\nIndique el id de tamanio: ", "\nError321", 1,3,3);
    auxIndiceTamanio = buscarIndiceTamanioPorId(listaTamanios, tamTamanios, auxIdTamanio);
    //si eligio un tamanio valido y se encontro el indice del mismo
    if(auxIdTamanio >= 1 && auxIdTamanio<=3 && auxIndiceTamanio!=-1)
    {
        //muesto tamanio elegido
        auxTamanio = listaTamanios[auxIndiceTamanio];
        printf("\nTamanio elegido: %s\n", auxTamanio.descripcion);
        //mi objeto elegido listaTamanios[auxIndiceTamanio]
        //recorro array de mascotas

        printf("\nID       Nombre  Especie   Peso(kg)   Descripcion    Pais de origen");
        for(int i=0; i<tamList; i++)
        {
            if(listaMascotas[i].isEmpty==0)
            {
                //si no esta vacia sigo
                //recuperar el tamanio a partir de la raza de la mascota
                //listaMascotas[i].idRaza--->raza -->tam raza if ==tamElegido SIGO
                auxRaza = buscarRaza(listaMascotas[i].idRaza, listRazas, tamRaz);
                if(auxRaza.idTamanio == auxTamanio.id)
                {
                    //recuperar pais de cada mascota para luego mostrarlo
                    auxPais = buscarPais(auxRaza.idPaisDeOrigen, listaPaises, tamPais);
                    //muestro la mascota cuyo tamanio de su raza coincide con el elegido
                    //y acumulador+=peso.mascota
                    //y mostrar con sus pa�ses de origen,
                    //peso y la suma total del peso entre estas mascotas.
                    //acumular peso
                    printf("\n%4d %10s %6s %9.2f %15s %15s", listaMascotas[i].id, listaMascotas[i].nombre, listaMascotas[i].especie, listaMascotas[i].peso, auxRaza.descripcion, auxPais.nombrePais);
                    acumuladorPeso += listaMascotas[i].peso;
                }
            }
        }
        printf("\nSumatoria de pesos(kg): %f", acumuladorPeso);
    }
    else
    {
        printf("\nError 418");
        system("pause");
    }
}

void listarRazas(eRaza *list, int tamRaz, ePais listaPaises[], int tamPais, eTamanio listaTamanios[], int tamTamanio)
{
    ePais auxPais;
    eTamanio auxTamanio;
    if(list!=NULL && tamRaz>0)
    {
        printf("\n***Listado de razas cargadas***");
        printf("\nID Descripcion PaisOrigen Tamanio");
        for(int i=0; i<tamRaz; i++)
        {
            if(list[i].isEmpty==0)//si hay un estructura de raza cargada busco su pais
            {
                auxPais = buscarPais(list[i].idPaisDeOrigen, listaPaises, tamPais);
                auxTamanio = buscarTamanio(list[i].idTamanio, listaTamanios, tamTamanio);
                printf("\n%d %10s %10s %10s", list[i].id, list[i].descripcion, auxPais.nombrePais, auxTamanio.descripcion);
            }

        }
    }
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
void bajaMascota(eMascota *list, int tamList, int minId, int maxId)
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


void mostrarUnaRazaConSusMascotas(eRaza x, eMascota listaMascotas[], int tamMascotas)
{
    int bandera =0;
    printf("\n***Se mostraran todos los %s", x.descripcion);

    for(int i=0; i<tamMascotas; i++)
    {
        if(listaMascotas[i].idRaza == x.id)
        {
            printf("\nMascota: %s Id:%d ", listaMascotas[i].nombre, listaMascotas[i].id);
            bandera =1;
        }
    }
    if(bandera ==0)
    {
        printf("\nNo se encontraron mascotas de esa raza\nPuede eliminarla sin problemas");
    }
}

void bajaRaza(eRaza *list, int tamRaz, int minId, int maxId, eMascota listaMascotas[], int tamMascotas)
{
    int idRazaBorrar;
    int indiceRazaBorrar;
    char confirma;

    printf("\n***Borrar raza***\n");

    //mostrar razas, luego elegir por ID
    for(int i=0; i<tamRaz; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\nRaza: %s Id:%d ", list[i].descripcion, list[i].id);
        }
    }

    utn_getNumero(&idRazaBorrar, "\nIngrese el Id de la raza que desea borrar: ", "\nError", minId, maxId,3 );

    indiceRazaBorrar = buscarIndiceRazaPorId(list, tamRaz, idRazaBorrar);

    if(indiceRazaBorrar != -1)
    {
        //muestro la raza, los elementois y la advertencia
        mostrarUnaRazaConSusMascotas(list[indiceRazaBorrar], listaMascotas, tamMascotas);
        printf("\n***ADVERTENCIA: si usted borra una raza, se borraran tambien las mascotas que a ella pertenecen\n");

        do
        {
            utn_getChar(&confirma, "\nConfirma dar de baja la raza? s/n: ", "\nError 360\n", 'n', 's', 3);
        }
        while(confirma!='s' && confirma!='n');

        if(confirma =='s')
        {
            list[indiceRazaBorrar].isEmpty = 1;
            //dar de baja las mascotas de esa raza
            for(int i=0; i<tamMascotas; i++)
            {
                if(listaMascotas[i].idRaza == list[indiceRazaBorrar].id)
                {
                    listaMascotas[i].isEmpty=1;
                }
            }
            printf("\nSe dieron de baja la raza y todos sus elementos****\n");
            system("pause");
        }
        else
        {
            printf("\nOperacion cancelada***");
            system("pause");
        }

    }
}


void bajaPais(ePais *list, int tamPais, int minId, int maxId)
{
    printf("\n***Por el momento no disponible.");
    system("pause");
}


/** \brief retorna el primer indicelibre en un array de eMascota
 *
 * \param *list puntero a array de eMascota
 * \param tamList tamanio del array
 * \return retorna el primer indice libre que encuentra or -1 si el array esta lleno
 *
 */

int buscarLugarEnMascotas(eMascota *list, int tamList)
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
void altaMascota(eMascota *list, int tamList, int* nextId, eRaza listaRaza[], int tamRaz, ePais listaPaises[], int tamPais, eTamanio listaTamanios, int tamTamanios, int primerIdRaza, int ultimoIdRaza)
{
    printf("\n***Alta de mascota***\n");
    eMascota auxMascota;
    int indiceLibre;
    indiceLibre = buscarLugarEnMascotas(list, tamList);

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
        int cargoEspecie = -1;
        do
        {
            utn_getTexto(auxMascota.especie, 10, "\nIndique uno de los siguientes: 'perro' , 'gato' o 'raro'\n", "\nERROR627\n");
        }
        while(strcmp(auxMascota.especie, "perro")!= 0 && strcmp(auxMascota.especie, "gato")!= 0 && strcmp(auxMascota.especie, "raro")!= 0);
        cargoEspecie = 0;
        int cargoPeso = utn_getNumeroFlotante(&auxMascota.peso, "\nIngrese peso: ", "\nError537", 0.1, 200, 3);
        int cargoRaza = -1;//DEBUG
        //int cargoRaza = utn_getNumero(&auxMascota.idRaza, "\nIngrese id de raza 10-13: ", "\nERROR\n", 10, 20, 3);
        if(cargoNombre==0 && cargoEdad==0 && cargoSexo==0 && cargoEspecie==0 && cargoPeso==0)
        {
            //muestro raza y q elija
            listarRazas(listaRaza, tamRaz, listaPaises, tamPais, &listaTamanios, tamTamanios);
            cargoRaza = utn_getNumero(&auxMascota.idRaza, "\nIndique la raza: ", "\nError544", primerIdRaza, ultimoIdRaza, 3 );
        }
        //si todo lo anterior esta bien
        if(cargoRaza==0)
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


int buscarLugarEnPaises(ePais *list, int tamPais)
{
    int retorno= -1;
    for(int i=0; i<tamPais; i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
void altaPais(ePais *list, int tamPais, int *nextId)
{
    printf("\n***Alta de pais***\n ");
    ePais auxPais;
    int indiceLibre = buscarLugarEnPaises(list, tamPais);

    if(indiceLibre!=-1)
    {
        int cargoNombre = utn_getTexto(auxPais.nombrePais, sizeof(auxPais.nombrePais), "\nIngrese nombre: ", "\nError\n");
        int cargoContinente = utn_getTexto(auxPais.continente, sizeof(auxPais.continente), "\nIngrese continente: ", "\nError\n");
        int cargoCodigoTelefonico = utn_getNumero (&auxPais.codigoTelefonico, "\nIngrese el prefijo telefonico: ", "\nError", 0, 300, 3);

        if(cargoNombre==0 && cargoContinente==0 && cargoCodigoTelefonico==0)
        {
            auxPais.id = *nextId;
            auxPais.isEmpty = 0;
            list[indiceLibre] = auxPais;
            *nextId = *nextId +1;
        }
    }
    else
    {
        printf("\n**NO hay lugar para cargar otro pais\n");
        system("pause");
    }
}

int menu()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion, "\n**Menu de opciones***\n1-Altas (mascotas, paises, razas)\n2-Bajas \n3-Modificaciones\n4-Listados\n5-Aplicar ordenamientos al listado\n9-SALIR\n", "\nERROR, ingrese una opcion valida\n", 1, 9,3);
    return opcion;
}


void listarRazasConSusMascotas(eRaza listaRazas[], int tamRaz, eMascota listaMascotas[], int tamMascotas, eTamanio listaTamanios[], int tamTamanio)
{
    eTamanio auxTamanio;
    if(listaRazas!= NULL && tamRaz>0 && listaMascotas != NULL && tamMascotas>0 && listaTamanios!= NULL && tamTamanio>0)
    {
        printf("\n***Se listara cada raza y las mascotas de cada una***");

        for(int i=0; i<tamRaz; i++)//recorro arrar de razas
        {
            //mostrarRazaConSusMascotas(eRaza x, eMascota listaMascotas[], int tamMascotas);
            if(listaRazas[i].isEmpty==0)//si hay una estructura eRaza la muestro
            {
                auxTamanio = buscarTamanio(listaRazas[i].idTamanio, listaTamanios, tamTamanio);
                printf("\n\n**Raza: %s IdRaza: %d Tamanio: %s ",  listaRazas[i].descripcion,listaRazas[i].id, auxTamanio.descripcion);
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
int buscarLugarEnRazas(eRaza *list, int tamRaz)
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

    for(i=0; i<tamPaises; i++)
    {
        if(listaPaises[i].isEmpty==0)//muestro todos los paises con isEmpty=0
        {
            printf("\n%d  Pais: %s", i, listaPaises[i].nombrePais);
            //retorno=0;
        }
    }//luego le pido al usuario que elija opcion


    utn_getNumero(&opcion, "\nElija un pais por numero : ", "\nERROR", 0, tamPaises,3);
    if(opcion >=0 && opcion<=tamPaises && listaPaises[opcion].isEmpty==0)
    {
        retorno = listaPaises[opcion].id;
    }

    return retorno;

}

//retorna el id de pais o -1 en caso de error
int elegirTamanio(ePais listaPaises[], int tamPaises)
{
    int retorno=-1;
    int opcion;
    int i;

    for(i=0; i<tamPaises; i++)
    {
        if(listaPaises[i].isEmpty==0)//muestro todos los paises con isEmpty=0
        {
            printf("\n%d  Pais: %s", i, listaPaises[i].nombrePais);
            //retorno=0;
        }
    }//luego le pido al usuario que elija opcion


    utn_getNumero(&opcion, "\nElija un pais por numero : ", "\nERROR", 0, tamPaises,3);
    if(opcion >=0 && opcion<=tamPaises && listaPaises[opcion].isEmpty==0)
    {
        retorno = listaPaises[opcion].id;
    }

    return retorno;

}


void altaRaza(eRaza *list, int tamRaz, int*nextId,ePais listaPaises[], int tamPaises, eTamanio listaTamanios[], int tamTamanio)
{
    printf("\n***Alta de raza***");
    eRaza auxRaza;

    int indiceLibre;
    indiceLibre=buscarLugarEnRazas(list, tamRaz);

    if(indiceLibre!=-1)//si hay lugar disponible
    {
        //cargo raza

        int cargoDescripcion = utn_getTexto(auxRaza.descripcion, sizeof(auxRaza.descripcion), "\nNombre de la raza: ", "\nERROR\n");
        int cargoTamanio = utn_getNumero(&auxRaza.idTamanio, "\nIndique n� tamanio:\n 1- Chico\n2- Mediano\n3- Grande\nIngrese una opcion:", "\nError728", 1,3,3);

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

    printf("\n\n***Funcion de ordenamiento por pais**");
    //system("pause");

    eRaza auxRazaI;
    eRaza auxRazaJ;

    eMascota mascotaAuxiliar;

    int auxIdPaisI;
    int auxIdPaisJ;

    ePais auxPaisI;
    ePais auxPaisJ;
    for(int i=0; i<tamList-1; i++)//para cada i
    {
        if(list[i].isEmpty==0)
        {
            for(int j=i+1; j<tamList; j++)//para cada j
            {
                if(list[j].isEmpty==0)
                {
                    //recupero la raza de cada elemento a comparar
                    auxRazaI = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
                    auxRazaJ = buscarRaza(list[j].idRaza, listaRazas, tamRaz);
                    //recupero el id de pais de cada elemento
                    auxIdPaisI = auxRazaI.idPaisDeOrigen;
                    auxIdPaisJ = auxRazaJ.idPaisDeOrigen;
                    //busco los paises y los guardo
                    auxPaisI = buscarPais(auxIdPaisI, listaPaises, tamPaises);
                    auxPaisJ = buscarPais(auxIdPaisJ, listaPaises, tamPaises);


                    if(strcmp(auxPaisI.nombrePais, auxPaisJ.nombrePais) > 0)
                    {
                        //swap
                        mascotaAuxiliar = list[i];
                        list[i] = list[j];
                        list[j] = mascotaAuxiliar;
                    }

                }
            }
        }
    }
    printf("\n***Se ordeno el listado de mascotas por pais de origen");
    system("pause");

}

void modificarMascota(eMascota *list, int tamList, eRaza listarRazas[], int tamRaz, int idMin, int idMax)
{
    int idAModificar;//el usuario ingresara el id, el sistema buscara el indice de �l
    int banderaId;
    int auxIndice;
    char confirma;
    eMascota auxMascota;
    printf("\n***Modificar Registro de mascota");
    banderaId = utn_getNumero(&idAModificar, "\nIngrese el ID de la mascota a modificar", "error\n", idMin, idMax, 3);
    if(banderaId==0) //es decir si obtuve un ID
    {
        auxIndice = buscarIndiceMascotaPorId(list, tamList, idAModificar);
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
                int cargoPeso = utn_getNumeroFlotante(&auxMascota.peso, "\nInglese el peso(kg): ", "\nError 745\n", 0.1, 500,3);

                if(cargoNombre==0 && cargoEdad==0 && cargoSexo==0 && cargoEspecie==0 && cargoRaza==0 && cargoPeso==0)
                {
                    auxMascota.isEmpty = 0;
                    auxMascota.id = idAModificar;
                    list[auxIndice] = auxMascota;

                    printf("\n***Se modifico correctamente el registro\n");
                    system("pause");
                }
            }

        }
        else
        {
            printf("\n***Error. No se pudo obtener id");
        }
    }
}

void mostrarPaisConMasMascotas(eMascota listaMascota[], int tamMascota,
                               eRaza listaRazas[], int tamRaz,
                               ePais listaPaises[], int tamPais)
{
    //"Argentina", "Alemania", "Belgica", "Tailandia", "Persia"
    int contadorArgentina =0;
    int contadorAlemania=0;
    int contadorBelgica=0;
    int contadorTailandia=0;
    int contadorPersia=0;
    eRaza auxRaza;

    //recorrer el array de emascota
    //de cada una recurerar pais de origen(habra que recuperar raza)
    //luego swichear el pais recibido por los contadores
    for(int i=0; i<tamMascota; i++)//voy a rrecorrer el array de mascotas
    {
        //e ir contando de cada pais;

        auxRaza = buscarRaza(listaMascota[i].idRaza, listaRazas, tamRaz);
        switch(auxRaza.idPaisDeOrigen)
        {
        case 100:
            contadorArgentina++;
            break;
        case 101:
            contadorAlemania++;
            break;
        case 102:
            contadorBelgica++;
            break;
        case 103:
            contadorTailandia++;
            break;
        case 104:
            contadorPersia++;
            break;
        }
    }
}

int retornarCodigoTelefonicoDePais(ePais *list, int tamPais, int idPais)
{
    int retorno=-1;
    for(int i=0; i<tamPais; i++)
    {
        if(idPais== list[i].id)
        {
            retorno= list[i].codigoTelefonico;
        }
    }
    return retorno;
}
//#-Opci�n del men� ordenar mascotas por el C�digo Telef�nico del pa�s, de mayor a menor.

/** \brief recibe un array de mascotas, uno de razas, otro de paises,
 ordena el array de mascotas por codigo telefonico del pais de cada mascota
 */
void ordenarPorCodigoTelefonico(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises)
{

    printf("\n\n***Funcion de ordenamiento por codigo telefonico de pais**");
    system("pause");

    eRaza auxRazaI;
    eRaza auxRazaJ;

    eMascota mascotaAuxiliar;

    int auxIdPaisI;
    int auxIdPaisJ;

    ePais auxPaisI;
    ePais auxPaisJ;
    for(int i=0; i<tamList-1; i++)//para cada i
    {
        if(list[i].isEmpty==0)
        {
            for(int j=i+1; j<tamList; j++)//para cada j
            {
                if(list[j].isEmpty==0)
                {
                    //recupero la raza de cada elemento a comparar
                    auxRazaI = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
                    auxRazaJ = buscarRaza(list[j].idRaza, listaRazas, tamRaz);
                    //recupero el id de pais de cada elemento
                    auxIdPaisI = auxRazaI.idPaisDeOrigen;
                    auxIdPaisJ = auxRazaJ.idPaisDeOrigen;
                    //busco los paises y los guardo
                    auxPaisI = buscarPais(auxIdPaisI, listaPaises, tamPaises);
                    auxPaisJ = buscarPais(auxIdPaisJ, listaPaises, tamPaises);


                    if(auxPaisI.codigoTelefonico > auxPaisJ.codigoTelefonico)
                    {
                        //swap
                        mascotaAuxiliar = list[i];
                        list[i] = list[j];
                        list[j] = mascotaAuxiliar;
                    }

                }
            }
        }
    }


}

/*#-Se debe mostrar el pa�s de origen que tenga m�s mascotas en nuestra
veterinaria. PENDIENTE*/
void informarPaisDeOrigenConMasMascotasEnNuestroListado(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises)

{
    eRaza auxRaza;
    ePais auxPais;
    int contadorAlemania=0;
    int contadorArgentina=0;
    int contadorBelgica=0;
    int contadorPersia=0;
    int contadorTailandia=0;
    int contadorPaisNoEspecificado=0;


    /*recorro vector mascotas, de c/u recupero pais y lo sumo a un contador  */
    for(int i=0; i<tamList; i++)
    {
        if(list[i].isEmpty==0)//si esta cargado
        {
            //recupero raza-->idPais-->
            //recupero pais
            auxRaza = buscarRaza(list[i].idRaza, listaRazas, tamRaz);
            auxPais = buscarPais(auxRaza.idPaisDeOrigen, listaPaises, tamPaises);

            //"Argentina", "Alemania", "Belgica", "Tailandia", "Persia"
            if(strcmp(auxPais.nombrePais, "Argentina")==0)
            {
                contadorArgentina++;
            }
            else if(strcmp(auxPais.nombrePais, "Alemania")==0)
            {
                contadorArgentina++;
            }
            else if(strcmp(auxPais.nombrePais, "Belgica")==0)
            {
                contadorBelgica++;
            }
            else if(strcmp(auxPais.nombrePais, "Tailandia")==0)
            {
                contadorTailandia++;
            }
            else if (strcmp(auxPais.nombrePais, "Persia")==0)
            {
                contadorPersia++;
            }
            else
            {
                contadorPaisNoEspecificado++;
            }
        }
    }
    // determino el maximo contador y lo muestro
    int arrayContadores[6] = { contadorAlemania, contadorArgentina, contadorBelgica, contadorPersia, contadorTailandia, contadorPaisNoEspecificado};
    char arrayPaisesDeLosContadores[6][10]= { {"Alemania"}, {"Argentina"}, {"Belgica"}, {"Persia"}, {"Tailandia"}, {"NoEspecifa"}};
    //buscarYMostrarPaisConMasMascotas
    int i;
    int maximoContador;
    char paisDelMaximoContador[10];

    maximoContador = arrayContadores[0];
    strcpy(paisDelMaximoContador, arrayPaisesDeLosContadores[0]);

    for (i = 1; i < 6; i++)
    {
        if (arrayContadores[i] > maximoContador)
        {
            maximoContador = arrayContadores[i];
            strcpy(paisDelMaximoContador, arrayPaisesDeLosContadores[i]);
        }
    }
    //return maximoContador;
    printf("\nEl pais con mas mascotas registradas es %s con %d mascotas", paisDelMaximoContador, maximoContador);
    system("pause");

}

/*
#-Opci�n Listar por TIPO y PESO:
Sabiendo que solo hay tres tipos de mascotas (tipo{gato ,perro o raro}),
informar el peso total de cada tipo, la cantidad de mascotas por tipo y el promedio de
peso por tipo.Estos tres datos en una tabla bien hecha.
*/
void listarPorTipoYPeso(eMascota listaMascotas[], int tamList, eRaza listRazas[], int tamRaz)
{
    system("cls");
    printf("\n***Funcion de listar por Tipo y Peso:\nSe contaran los individuos de cada especie, y se dara peso total y peso promedio de cada una\n");
    int contadorGatos = 0;
    float acumuladorPesoGatos = 0;
    float pesoPromedioGatos;

    int contadorPerros = 0;
    float acumuladorPesoPerros = 0;
    float pesoPromedioPerros;

    int contadorRaros = 0;
    float acumuladorPesoRaros = 0;
    float pesoPromedioRaros;
    //recorro listado de mascotas, acumulo peso y cuento individuos de cada especie/TIPO
    for(int i=0; i<tamList; i++)
    {
        if(listaMascotas[i].isEmpty==0)
        {
            if(strcmp(listaMascotas[i].especie, "gato")==0)
            {
                contadorGatos++;
                acumuladorPesoGatos += listaMascotas[i].peso;
            }
            if( strcmp(listaMascotas[i].especie, "perro")==0)
            {
                //fue perro
                contadorPerros++;
                acumuladorPesoPerros += listaMascotas[i].peso;
            }
            else
            {
                //fue raro
                contadorRaros++;
                acumuladorPesoRaros += listaMascotas[i].peso;
            }
        }
    }
    //saco promedios
    pesoPromedioGatos = acumuladorPesoGatos / contadorGatos;
    pesoPromedioPerros = acumuladorPesoPerros / contadorPerros;
    pesoPromedioRaros = acumuladorPesoRaros / contadorRaros;

    printf("\nTipo  CantidadIndividuos PesoTotal  PesoPromedio");
    printf("\n gato|         %d       |  %.2f    |    %.2f",  contadorGatos,acumuladorPesoGatos, pesoPromedioGatos);
    printf("\nperro|         %d       |  %.2f   |    %.2f",  contadorPerros,acumuladorPesoPerros, pesoPromedioPerros);
    printf("\n raro|         %d       |  %.2f    |    %.2f\n",  contadorRaros,acumuladorPesoRaros, pesoPromedioRaros);


}
