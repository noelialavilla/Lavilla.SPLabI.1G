#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicleta.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//************************************************************************************************************************************/
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if (this != NULL)
    {
        this -> size = 0;
        this-> pFirstNode = NULL;
    }

    return this;
}

//************************************************************************************************************************************/
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = this -> size;
    }
    return returnAux;
}

//************************************************************************************************************************************/
 /** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;
    if( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        nodo = this ->pFirstNode;

        while ( nodeIndex > 0)
        {
            nodo = nodo ->pNextNode;
            nodeIndex --;
        }

//    for (int i = nodeIndex; i> 0; i--)
//    {
//        nodo = nodo->pNextNode;
//    }
    }
    return nodo;
}

//************************************************************************************************************************************/
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

//************************************************************************************************************************************/
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    /*
       - 1 Crear un nuevo nodo
       -2  Hacer que el campo pElement del nodo apunte al elemento (pEleement)
        3- Agregar el vagon en el indice pasadoi por paramtro (nodeIndex)
    */
    Node* nuevoNodo;
    Node* nodoAnterior ;
    int returnAux = -1;

    if ( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if (nuevoNodo != NULL)
        {
            nuevoNodo ->pElement = pElement;
            if (nodeIndex == 0 )
            {
                nuevoNodo ->pNextNode = this ->pFirstNode;
                //nuevoNodo ->pNextNode =  getNode(this, 0);
                this -> pFirstNode = nuevoNodo;

            }
            else
            {
                nodoAnterior = getNode(this, nodeIndex -1);
                nuevoNodo ->pNextNode = nodoAnterior ->pNextNode;
                nodoAnterior ->pNextNode = nuevoNodo;

            }
            this-> size++;
            returnAux =0;
        }

    }

    return returnAux;
}

//************************************************************************************************************************************/
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

//************************************************************************************************************************************/
int ll_add(LinkedList* this, void* pElement)
{
    /*   int returnAux = -1;
       if (this != NULL)
       {
           //returnAux = addNode(this,  ll_len(this), pElement);
           if (addNode(this,  ll_len(this), pElement) == 0)
           {
               returnAux = 0;
           }
       }*/


    return addNode(this,  ll_len(this), pElement);
}

//************************************************************************************************************************************/
void* ll_get(LinkedList* this, int index)
{
    Node* nodoAux;
    void* returnAux = NULL;
    if ( this != NULL && index >= 0 && index < ll_len(this))
    {
        nodoAux =  getNode(this, index);
        if (nodoAux != NULL)
        {
            returnAux = nodoAux ->pElement;
        }
    }
    return returnAux;
}

//************************************************************************************************************************************/

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
    if ( this != NULL && index >= 0 && index < ll_len(this))
    {
        nodoAux = getNode(this, index);
        if (nodoAux != NULL)
        {
            nodoAux ->pElement = pElement;
            returnAux = 0;
        }

    }
    return returnAux;
}

//************************************************************************************************************************************/
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAux;
    Node* nodoAnt;

    if ( this != NULL && index >= 0 && index < ll_len(this))
    {
        nodoAux = getNode(this, index);
        if (nodoAux != NULL)
        {
            if (index == 0)
            {
                this -> pFirstNode = nodoAux->pNextNode;
                this->size --;
                free(nodoAux);
                returnAux = 0;
            }
            else
            {
                nodoAnt = getNode(this, index -1);
                if ( nodoAnt != NULL )
                {
                    nodoAnt ->pNextNode = nodoAux ->pNextNode;
                    this->size --;
                    free(nodoAux);
                    returnAux = 0;
                }
            }
        }
    }
    return returnAux;
}


//************************************************************************************************************************************/

//int ll_clear(LinkedList* this)
//{
//    int returnAux = -1;
//    int tam;
//    if (this != NULL)
//    {
//        tam = ll_len(this);
//        for (int i = tam; i >= 0; i--)
//        {
//            ll_remove(this, i);
//        }
//        returnAux = 0;
//    }
//
//    return returnAux;
//}
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {

        while ( ll_len(this))
        {
            ll_remove(this, 0);
            returnAux = 0;
        }
    }

    return returnAux;
}

//************************************************************************************************************************************/
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if ( ll_clear (this) == 0)
    {
        free(this);
        returnAux =0;
    }

    return returnAux;
}

//************************************************************************************************************************************/
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if (this != NULL)
    {
        tam = ll_len(this);
        for (int i = 0; i< tam; i++)
        {
            if (ll_get(this, i)  == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

//************************************************************************************************************************************/
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if ( this != NULL)
    {
        //   if (ll_len(this) == 0)
        returnAux = 0;
        if(this->pFirstNode == NULL)
        {
            returnAux = 1;
        }

    }

    return returnAux;
}

//************************************************************************************************************************************/
int ll_push(LinkedList* this, int index, void* pElement)
{

    return addNode(this, index, pElement);
}

//************************************************************************************************************************************/
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this, index);
    if (ll_remove(this, index) == -1)
    {
        returnAux = NULL;
    }

    return returnAux;
}

//************************************************************************************************************************************/

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux =0;
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

//************************************************************************************************************************************/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;
    void* elementAux;
    if (this != NULL && this2 != NULL)
    {
        returnAux= 1;
        tam =  ll_len(this2);
        for (int i = 0; i < tam; i++)
        {
            elementAux = ll_get(this2, i);
            if(ll_contains(this, elementAux) == 0)
            {
                returnAux =0;
                break;
            }
        }
    }

    return returnAux;
}

//************************************************************************************************************************************/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if (this != NULL && from >=0 && from <= ll_len(this) &&  to >=from && to <= ll_len(this) )
    {
        cloneArray = ll_newLinkedList();
        for(int i = from; i < to; i++ )
        {
            ll_add(cloneArray, ll_get(this, i));
        }
    }
    return cloneArray;
}

//************************************************************************************************************************************/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    cloneArray = ll_subList(this, 0, ll_len(this));

    return cloneArray;
}

//************************************************************************************************************************************/
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pElement1;
    void* pElement2;

    int tam;
    if (this != NULL && pFunc != NULL &&(order == 0 || order == 1))
    {
        tam = ll_len(this);
        for(int i = 0; i < tam - 1; i++)
        {
            for (int j= i+1;  j< tam;  j++)
            {
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, j);

                if ((pFunc(pElement1, pElement2) > 0 && order == 1) || (pFunc(pElement1, pElement2) <0 && order == 0))
                {
                    ll_set(this, i, pElement2);
                    ll_set(this, j, pElement1);
                }
            }
        }
        returnAux = 0;

    }
    return returnAux;

}

//************************************************************************************************************************************/
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    void* auxElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
        listaFiltrada = ll_newLinkedList();
        if(listaFiltrada !=NULL)
        {
            for (int i = 0; i< ll_len(this); i++)
            {
                auxElement =ll_get(this, i);

                if (pFunc(auxElement) == 1 )
                {
                    ll_add(listaFiltrada, auxElement);
                }

            }
        }

    }
    return listaFiltrada;
}
//************************************************************************************************************************************/

LinkedList* ll_map(LinkedList* this , void* (*pFunc)(void*)){
	void* auxElement = NULL;
	int tam;
	LinkedList* nuevaListaBicis = NULL;

	if( this != NULL && pFunc != NULL){
		nuevaListaBicis = ll_newLinkedList();
		tam = ll_len(this);

		for (int i = 0; i < tam; i++) {
			auxElement = ll_get(this, i);
			auxElement = pFunc(auxElement);
			if(auxElement != NULL){

               ll_add(nuevaListaBicis, auxElement);
			}
		}
	}

return nuevaListaBicis;
}
