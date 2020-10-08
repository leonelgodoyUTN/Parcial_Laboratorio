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
void hardcodearMascotas(eMascota* list);
void hardcodearRazas(eRaza *list, int tamList);

void mostrarListadoCompleto(eMascota* list, int tamList, eRaza listaRazas[], int tamRaz);
//void mostrarMascota(eMascota, eRaza *list, int tamRaz);//fuera de uso, version vieja
void mostrarMascotaConRaza(eMascota x, eRaza razaRecibida);
eRaza buscarRaza(int id, eRaza *list, int tamRaz);

void ordenarPorPais(eMascota *list, int tamList, eRaza listaRazas[], int tamRaz);

int borrarMascotaDelListado(eMascota *list, int tamList, int id);
int buscarLugar(eMascota *list, int tamList);

#endif // MASCOTAS_H_INCLUDED
