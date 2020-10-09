//#ifndef UTN_H_INCLUDED
//#define UTN_H_INCLUDED
int myGets(char* cadena, int longitud);
int esNumericoFlotante(char* str);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int esNumericoFlotante(char* str);
int esSoloLetras(char *str);
int esAlfaNumerico(char *str);
int esTelefono(char *str);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void cleanStdin(void);

int utn_getNumero(int* pResultado,
                  char* mensaje,
                  char* mensjaeError,
                  int minimo,
                  int maximo,
                  int reintentos);//esta funcion utiliza getInt()



int utn_getNumeroFlotante(float* pResultado,
                              char* mensaje,
                              char* mensajeError,
                              float minimo,
                              float maximo,
                              int reintentos);

int utn_getChar(char* pResultado,
                char* mensaje,
                char* mensajeError,
                char minimo,
                char maximo,
                int reintentos);

int utn_getTexto(char* pTexto,int tamBuffer, char* mensaje, char* mensajeError);


//#endif // UTN_H_INCLUDED
