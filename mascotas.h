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
    char tamanio; //chico ,mediano o grande,
    char paisDeOrigen[51];
} eRaza;


void inicializarArrayMascotas(eMascota *list, int tamList);
void hardcodearMascotas(eMascota* list, int tamHardcodeo);
void hardcodearRazas(eRaza *list, int cantidad);
eRaza buscarRaza(int id, eRaza *list, int tamRaz);
void mostrarMascota(eMascota x);
void mostrarMascotaConRaza(eMascota x, eRaza razaRecibida);
void mostrarListadoCompleto(eMascota* list, int tamList, eRaza listaRazas[], int tamRaz);
void borrarMascotaDelListado(eMascota *list, int tamList);
int buscarIndiceMascotaPorId(eMascota *list, int tamList, int idABuscar);
void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);


int buscarLugar(eMascota *list, int tamList);
void cargarMascota(eMascota *list, int tamList, int* nextId);
int menu();
#endif // MASCOTAS_H_INCLUDED
