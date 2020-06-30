#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "Controller.h"
#include "validations.h"
#include "parser.h"
#include <ctype.h>
#include<string.h>

int controller_loadFromText(char* path, LinkedList* pListaBicicletas)
{
    int todoOk = -1;
    FILE* pFile;
    if(path != NULL && pListaBicicletas != NULL)
    {

        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_EmployeeFromText(pFile, pListaBicicletas) == 1)
            {
                todoOk = 1;
                printf("Bicicletas cargadas correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar las bicicletas.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int controller_ListarBicicletas(LinkedList* pListaBicicletas)
{
    int todoOk = -1;
    int tam = ll_len(pListaBicicletas);
    int flag = 0;
    eBicicleta* auxBici;

    if( pListaBicicletas != NULL)
    {
        todoOk = 1;
        printf("\n  Id                          Nombre                  Tipo                  Tiempo \n");
        printf("--------------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {
            auxBici = (eBicicleta*) ll_get(pListaBicicletas, i);
            if (  auxBici  != NULL )
            {
                mostrarBicicleta( auxBici );
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay bicicletas que mostrar\n");
        }
    }
    return todoOk;

}

//************************************************************************************************************************************/
int controller_guardarComoTexto(char* path, LinkedList* pListaBicicletas)
{
    FILE* f = fopen(path,"w") ;
    int tam =  ll_len(pListaBicicletas);
    eBicicleta* auxBicicleta;
    int todoOk = -1;

    if(f != NULL)
    {
        fprintf(f,"id_bike,nombre,tipo,tiempo\n");
        for (int i =0; i<tam; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(pListaBicicletas, i);
            if (auxBicicleta !=NULL)
            {
                fprintf(f, "%d,%s,%s,%d\n", auxBicicleta->id_bike, auxBicicleta->nombre, auxBicicleta-> tipo, auxBicicleta->tiempo);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}

//************************************************************************************************************************************/

int controller_sortBicicletas(LinkedList* pListaBicicletas)
{
    int ordenamiento = 1;
    int todoOk =-1;

    if( pListaBicicletas != NULL)
    {

       todoOk = ll_sort(pListaBicicletas, compararBicicletasPorTipoyTiempo, ordenamiento);

    }

    return todoOk;
}
