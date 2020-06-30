#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
/** \brief Crea y retorna un nuevo LinkedList. Es el constructor, ya que en él daremos valores iniciales a
 *                   las variables y asignaremos las funciones a sus punteros.
 *
 * \return  un nuevo LinkedList
 *
 */

int ll_len(LinkedList* this);
/** \brief Retorna el tamaño del LinkedList. Verificando que el puntero this sea distinto de NULL.
 *
 * \param this LinkedList* Puntero a la lista
 * \return  Si la verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
 *
 */


Node* test_getNode(LinkedList* this, int nodeIndex);
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_add(LinkedList* this, void* pElement);
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index);
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

int ll_set(LinkedList* this, int index,void* pElement);
/** \brief Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
  *                  sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
 *                   falla la función retorna (-1) y si tiene éxito (0).
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_remove(LinkedList* this,int index);
/** \brief Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
*                   sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
*                   falla la función retorna (-1) y si tiene éxito (0).
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_clear(LinkedList* this);
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_deleteLinkedList(LinkedList* this);
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_indexOf(LinkedList* this, void* pElement);
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si no hay ningun nodo que apunte a ese elemento
                        (indice del elemento) Si funciono correctamente
 *
 */

int ll_isEmpty(LinkedList* this);
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */

int ll_push(LinkedList* this, int index, void* pElement);
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

void* ll_pop(LinkedList* this,int index);
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

int ll_contains(LinkedList* this, void* pElement);
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/

int ll_containsAll(LinkedList* this,LinkedList* this2);
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/

LinkedList* ll_subList(LinkedList* this,int from,int to);
/** \brief Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
*                   sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
*                   del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
*                   array.
*
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/

LinkedList* ll_clone(LinkedList* this);
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

 LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));
 /** \brief   Se iteran todos los elementos de la lista y se pasan a la funcion pFunc la cual devuelve 1 si el item se agrega a la lista
 *                     o 0 si no debe agregarse. Se genera una nueva lsita resultado, agregando a la misma los items correspondientes y la devolvera.
 *
 *
* \param LinkedList* lista
* \param puntero a funcion
  * \return LinkedList* lista filtrada
  *
  */


LinkedList* ll_map(LinkedList* this , void* (*pFunc)(void*));
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


