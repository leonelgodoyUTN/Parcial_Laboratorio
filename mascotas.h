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

eRaza buscarRaza(int id, eRaza *list, int tamRaz);
ePais buscarPais(int id, ePais lista[], int tamPais);
void mostrarMascota(eMascota x);
void mostrarMascotaConRazaYPais(eMascota x, eRaza razaRecibida);

void mostrarListadoCompleto(eMascota* list, int tamList, eRaza listaRazas[], int tamRaz);
int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar);
void borrarMascotaDelListado(eMascota *list, int tamList, int minId, int maxId);
int buscarLugar(eMascota *list, int tamList);
void cargarMascota(eMascota *list, int tamList, int* nextId);
int menu();
void listarRazas(eRaza *list, int tamRaz, ePais listaPaises[], int tamPais);
void listarRazasConSusMascotas(eRaza listaRazas[], int tamRaz, eMascota listaMascotas[], int tamMascotas);
int buscarLugarLibreRaza(eRaza *list, int tamRaz);
//void agregarRaza(eRaza *list, int tamRaz, int*nextId);
void agregarRaza(eRaza *list, int tamRaz, int*nextId,ePais listaPaises[], int tamPaises);
int elegirPais(ePais listaPaises[], int tamPaises);
//void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);
void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz, ePais listaPaises[], int tamPaises);
void modificarMascota(eMascota *list, int tamList, eRaza listarRazas[], int tamRaz, int idMin, int idMax);
void mostrarPaisConMasMascotas(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);

#endif // MASCOTAS_H_INCLUDED
