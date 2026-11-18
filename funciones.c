#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num;
    int val;
    do
    {
        val = scanf("%f",&num);
        while ((getchar())!='\n');
        if (num < a || num > b || val != 1)
        {
            printf("Error: el valor ingresado es incorrecto\n");
        }
    } while (num < a || num > b || val != 1);
    return num;
}

void leerCadena(char *cadena, int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

/*
    Modificar para que a través de la misma función
    se pueda ingresar n libros, sin que sobreescriba los
    libros ya ingresados
*/
void registrarLibro(Libro *libros, int *cont){
    printf("Ingrese el libro %d\n",*cont);
    libros[*cont].id = *cont;
    printf("Titulo: ");
    leerCadena(libros[*cont].titulo,100);
    printf("Autor: ");
    leerCadena(libros[*cont].autor,50);
    printf("Anio: ");
    libros[*cont].anio = validarFloatRango(2000,2026);
    libros[*cont].estado = 0;
    (*cont)++;
}

void mostrarLibro(Libro *libros, int m, int cont){
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = m; i < cont; i++)
    {
        if (libros[i].estado != 3){
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",libros[i].id,
                                            libros[i].titulo,
                                            libros[i].autor,
                                            libros[i].anio,
                                            (libros[i].estado==0 ? "Disponible" : "Prestado"));
        }
    }
}

int buscarLibro(Libro *libros, int cont){
    printf("Seleccione el metodo de busqueda 1.Id/2.Titulo: ");
    int opc = validarFloatRango(1,2);
    int indice = -1;
    switch (opc)
    {
    case 1:
        printf("Ingrese el id del libro (0-%d): ",cont-1);
        indice = validarFloatRango(0,cont-1);
        mostrarLibro(libros,indice,indice+1);
        break;
    case 2:
        printf("Ingrese el titulo del libro: ");
        char titulo[100];
        leerCadena(titulo,100);
        for (int i = 0; i < cont; i++)
        {
            if(strcasecmp(libros[i].titulo,titulo)==0){
                indice = i;
                mostrarLibro(libros,indice,indice+1);
                break;
            }
        }
    default:
        break;
    }

    return indice;
}

void cambiarEstado(Libro *libros, int cont){
    int posicion = buscarLibro(libros,cont);
    if (posicion != -1)
    {
        printf("Seleccione 1.Prestar/2.Devolver: ");
        int opc = validarFloatRango(1,2);
        switch (opc)
        {
        case 1:
            if (libros[posicion].estado == 0 && libros[posicion].estado != 3)
            {
                libros[posicion].estado = 1;
                printf("Libro prestado\n");
            }else{
                printf("Error: El libro ya esta prestado\n");
            }
            break;
        case 2:
             if (libros[posicion].estado == 1 && libros[posicion].estado != 3)
            {
                libros[posicion].estado = 0;
                printf("Libro Devuelto\n");
            }else{
                printf("Error: El libro no se puede devolver, no esta prestado\n");
            }
            break;
        
        default:
            break;
        }
    }else{
        printf("Error: No se encuentra el libro\n");
    }
}

void borrarLibro(Libro *libros, int cont){
    int posicion = buscarLibro(libros,cont);
    if (posicion != -1)
    {
        printf("Desea borrar el libro 1.Si/2.No: ");
        int opc = validarFloatRango(1,2);
        if (opc == 1)
        {
            libros[posicion].estado = 3;
            printf("Libro borrado\n");
        }
    }
}

