#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include "bicicleta.h"
#include "controller.h"

int main()
{
    srand (time(NULL));
    char confirm ='n';
    char seguir = 's';
    char archivo[20];
    int posicionesAsignadas = -1;
    LinkedList* listaBicicletas = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar: ");
            scanf("%s", archivo);
            controller_loadFromText(archivo, listaBicicletas);
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaBicicletas))
            {
                controller_ListarBicicletas(listaBicicletas);
            }
            else
            {
                printf("La lista de bicicletas esta vacia. Debe cargar al menos una bicicleta primero.\n");
            }
            system("pause");
            break;
        case 3:

            if( !ll_isEmpty(listaBicicletas))
            {
                listaBicicletas = ll_map(listaBicicletas, cambiarTiempo);
                posicionesAsignadas = 1;
                controller_ListarBicicletas(listaBicicletas);
            }
            else
            {
                printf("No se pudo asignar nuevos tiempos ya que la lista esta vacia, debe cargarla desde un archivo primero.\n");
            }
            system("pause");
            break;
        case 4:
            filtrarPorTipos(listaBicicletas);
            break;
        case 5:
            if(posicionesAsignadas == 1 &&  !ll_isEmpty(listaBicicletas))
            {
                if (controller_sortBicicletas(listaBicicletas) != -1)
                {
                    controller_ListarBicicletas(listaBicicletas);
                }
            }else{
                printf("No se pudo asignar posiciones ya que la lista esta vacia o no se asignaron tiempos, debe cargarla desde un archivo primero y asignarle nuevos tiempos.\n");
            }

            system("pause");
            break;
        case 6:
            if( posicionesAsignadas == 1 &&  !ll_isEmpty(listaBicicletas))
            {
                controller_guardarComoTexto("bicisOrdenadas.csv", listaBicicletas);
                printf(" Se han guardado las bicicletas ordenadas por posiciones en el archivo bicisOrdenadas.csv\n");
            }
            else
            {
                printf("No se pudo guardar el archivo de posiciones ya que la lista esta vacia o no se asignaron tiempos, debe cargarla desde un archivo primero y asignarle nuevos tiempos primero.\n");
            }
            system("pause");
            break;
        case 7:
            printf("Esta seguro que desea salir? [s/n] : ");
            fflush(stdin);
            scanf("%c", &confirm);
            if (confirm == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');
    ll_deleteLinkedList(listaBicicletas);
    return 0;
}

