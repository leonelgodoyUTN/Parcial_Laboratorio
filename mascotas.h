#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;//PK
    char nombre[51];
    int edad;
    char sexo;
    char especie[10]; //{gato ,perro o raro}
    int isEmpty;
    int idRaza;//FK a eRaza
} eMascota;


typedef struct
{
    int id;//PK
    char descripcion[51];
    char tamanio[10]; //chico ,mediano o grande,
    int idPaisDeOrigen;//FK a pais
    int isEmpty;
} eRaza;

typedef struct
{
    int id;//PK
    char nombrePais[51];
    char continente[51];
    int codigoTelefonico;
    int isEmpty;
}ePais;

void saludar();
void inicializarArrayMascotas(eMascota *list, int tamList);
void inicializarArrayRazas(eRaza *list, int tamRaz);
void inicializarArrayPaises(ePais *list, int tamPais);

void hardcodearRazas(eRaza *list, int tamHardcodeo, int*proximoIdRaza);
void hardcodearMascotas(eMascota* list, int tamHardcodeo, int*proximoId);
void hardcodearPaises(ePais* list, int tamHardcodeo, int*proximoIdPais);

eRaza buscarRaza(int idRaza, eRaza *list, int tamRaz);
ePais buscarPais(int idPais, ePais lista[], int tamPais);

void mostrarMascota(eMascota x);
void mostrarMascotaConRazaYPais(eMascota x, eRaza razaRecibida, ePais paisRecibido);
void mostrarUnaRazaConSusMascotas(eRaza x, eMascota listaMascotas[], int tamMascotas);

void listarMascotas(eMascota* list, int tamList,eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPais);
void listarRazas(eRaza *list, int tamRaz, ePais listaPaises[], int tamPais);
void listarPaises(ePais *list, int tamPais);

int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar);
int buscarIndiceRazaPorId(eRaza *list, int tamRaz, int idABuscar);

void bajaMascota(eMascota *list, int tamList, int minId, int maxId);
void bajaRaza(eRaza *list, int tamRaz, int minId, int maxId, eMascota listaMascotas[], int tamMascotas);
void bajaPais(ePais *list, int tamPais, int minId, int maxId);


int buscarLugarEnMascotas(eMascota *list, int tamList);
int buscarLugarEnPaises(ePais *list, int tamPais);
int buscarLugarEnRazas(eRaza *list, int tamRaz);

void altaMascota(eMascota *list, int tamList, int* nextId);
void altaRaza(eRaza *list, int tamRaz, int*nextId,  ePais listaPaises[], int tamPaises);
void altaPais(ePais *list, int tamPais, int *nextid);

int menu();

void listarRazasConSusMascotas(eRaza listaRazas[], int tamRaz, eMascota listaMascotas[], int tamMascotas);

//void agregarRaza(eRaza *list, int tamRaz, int*nextId);

int elegirPais(ePais listaPaises[], int tamPaises);
//void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);
void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises);
void modificarMascota(eMascota *list, int tamList, eRaza listarRazas[], int tamRaz, int idMin, int idMax);
void mostrarPaisConMasMascotas(eMascota listaMascota[], int tamMascota, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPais);
void listarMascotasConRazaYDatosDelPais(eMascota listaMascotas[], int tamList,eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPais);

int retornarCodigoTelefonicoDePais(ePais *list, int tamPais, int idPais);
void ordenarPorCodigoTelefonico(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises);


#endif // MASCOTAS_H_INCLUDED
