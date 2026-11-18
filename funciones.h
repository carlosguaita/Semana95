typedef struct
{
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    int estado;
}Libro;

float validarFloatRango(float a, float b);
void leerCadena(char *cadena, int n);
void registrarLibro(Libro *libros, int *cont);
void mostrarLibro(Libro *libros, int m, int cont);
int buscarLibro(Libro *libros, int cont);
void cambiarEstado(Libro *libros, int cont);
void borrarLibro(Libro *libros, int cont);