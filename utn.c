/** Biblioteca de ingreso de datos
 * Leonel Godoy, 2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//usada por getInt() y getFloat()
/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado
 *          en cadena un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio en memoria donde se copiara la cadena obtenida
 * \param longitud define el tamanio de la cadena
 * \return retorna 0 (exito) si se obtiene la cadena y -1 (error) si no
 *
 */
int myGets(char* cadena, int longitud)
{fflush(stdin);
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin )==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
    /*
    otra version
    fflush(stdin);
    fgets(cadena, longitud, stdin);
    cadena[strlen(cadena)-1] = '\0';
    return 0;
    */
}


//usada por getInt() y getFloat()
/** \brief Verifica si la cadena ingresada es numerica. NO ACEPTA FLOAT
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0(falso) si no lo es
 */
static int esNumerica(char* cadena)
{
    int i=0;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i] < '0' || cadena[i]>'9')
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char* str)
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

//utiliza myGets() y esNumerica()
//es usada por utn_getNumero()
/** \brief verifica si la cadena ingresada es numerica
 * \param pResultado puntero al espacio de memoria donde se deja el resultado de la funcion
 * \return Retorna 0 (exito) si se obtiene un numero entero y -1(error) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado= atoi(buffer);
            retorno=0;
        }
    }
    return retorno;
}



/**< chequear si es necesario una funcion esNumericaFlotante */
//es usada por utn_getNumeroConDecimales
//llama a myGets() y esNumericoFlotante()
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumericoFlotante(buffer))
        {
            *pResultado= atof(buffer);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de meoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado al solicitar el dato
 * \param mensajeError Mensaje que se muestra al fallar la carga
 * \param minimo Numero maximo a ser aceptado
 * \param minimo Numero minimo a ser aceptado
 * \param reintentos Numero de reintentos disponibles
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
//esta funcion utiliza getInt()
int utn_getNumero(int* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo,
                  int reintentos)
{
    int bufferInt;
    int retorno=-1;

    while(reintentos>0)
    {
        reintentos--;
        printf("%s", mensaje);

        //llamado a getInt()
        if(getInt(&bufferInt)==0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno =0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}



//llama a getFloat()
/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
* \param pResultado puntero al espacio de meoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado al solicitar el dato
* \param mensajeError Mensaje que se muestra al fallar la carga
* \param minimo Numero maximo a ser aceptado
* \param minimo Numero minimo a ser aceptado
* \param reintentos Numero de reintentos disponibles
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int utn_getNumeroFlotante(float* pResultado,
                          char* mensaje,
                          char* mensajeError,
                          float minimo,
                          float maximo,
                          int reintentos)
{
    float bufferFloat;
    int retorno=-1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s", mensaje);

        //llamado a getFloat()
        if(getFloat(&bufferFloat)==0)//
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno =0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}


//lama a myGets()
/**
 * \brief
 * \param
 * \return
*
*/
int utn_getTexto(char* pTexto,int tamBuffer, char* mensaje, char* mensajeError)
{
    int retorno=-1;
    char buffer[tamBuffer];
    if(pTexto != NULL && tamBuffer>0)
    {
        printf("\n%s", mensaje);
        if(myGets(buffer,sizeof(buffer))==0)
        {
            //pTexto = buffer;//que boludo...
            strcpy(pTexto, buffer);
            retorno = 1;
        }
    }
    return retorno;
}


/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}



/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerica(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}


int utn_getChar(char* pResultado,
                char* mensaje,
                char* mensajeError,
                char minimo,
                char maximo,
                int reintentos)
{
    char bufferChar;
    int retorno=-1;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
    {
        while(reintentos>0)
        {
            reintentos--;
            printf("%s", mensaje);
            scanf("%c",&bufferChar);
                if(bufferChar >= minimo && bufferChar <= maximo)
                {
                    *pResultado = bufferChar;
                    retorno =0;
                    break;
                }

            printf("%s",mensajeError);
        }
    }

    return retorno;
}
