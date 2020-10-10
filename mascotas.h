#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

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
    char tamanio[10]; //chico ,mediano o grande,
    char paisDeOrigen[51];
    int isEmpty;
} eRaza;


void inicializarArrayMascotas(eMascota *list, int tamList);
void inicializarArrayRazas(eRaza *list, int tamRaz);
void hardcodearMascotas(eMascota* list, int tamHardcodeo, int*proximoId);
void hardcodearRazas(eRaza *list, int cantidad, int*proximoIdRaza);
eRaza buscarRaza(int id, eRaza *list, int tamRaz);
void mostrarMascota(eMascota x);
void mostrarMascotaConRaza(eMascota x, eRaza razaRecibida);
void mostrarListadoCompleto(eMascota* list, int tamList, eRaza listaRazas[], int tamRaz);
void borrarMascotaDelListado(eMascota *list, int tamList, int minId, int maxId);
int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar);
void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);
int buscarLugar(eMascota *list, int tamList);
void cargarMascota(eMascota *list, int tamList, int* nextId);
int menu();
void listarRazas(eRaza *list, int tamRaz);
void listarRazasConSusMascotas(eRaza listaRazas[], int tamRaz, eMascota listaMascotas[], int tamMascotas);
void agregarRaza(eRaza *list, int tamRaz, int*nextId);
int buscarLugarLibreRaza(eRaza *list, int tamRaz);
#endif // MASCOTAS_H_INCLUDED
