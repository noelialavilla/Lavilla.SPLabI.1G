#include "LinkedList.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[30];
    char tipo[20];
    int tiempo;
}eBicicleta;


#endif // BICICLETA_H_INCLUDED

int menu();
/** \brief muestra opciones y devuelve la elegida por el usuario
 *
 * \return opcion elegida por el usuario
 *
 */

eBicicleta* nuevaBicicleta();
/** \brief constructor de eBicicleta
 *
 * \return un puntero a una eBicicleta
 *
 */

eBicicleta* nuevaBicicletaParam(char* id_bikeStr, char* nombre, char* tipo, char* tiempoStr);
/** \brief constructor de eBicicleta con atributos pasados por parametro
 *
 * \param char id de la bicicleta a crear
 * \param char nombre de la bicicleta a crear
 * \param char tipo de la bicicleta a crear
 * \param char tiempo de la bicicleta a crear
 * \return
 *
 */
int bicicleta_setId_bike(eBicicleta* this, int id_bike);
/** \brief recibe por parametro el valor del id que le asignara a la bicicleta recibida
 *
 * \param eBicicleta* puntero a la eBicicleta a modificar
 * \param int id_bike que se le asignara a la eBicicleta recibida
 * \return 1 si pudo asignarla, -1 si no
 *
 */

int bicicleta_setNombre(eBicicleta* this, char* nombre);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int bicicleta_setTipo(eBicicleta* this, char* tipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int bicicleta_setTiempo(eBicicleta* this, int tiempo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int bicicleta_getTiempo(eBicicleta* this, int* tiempo);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

int bicicleta_getTipo(eBicicleta* this, char* tipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void borrarBici(eBicicleta* this );
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int mostrarBicicleta(eBicicleta* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void* cambiarTiempo(void* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int elegirTipo();
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

void filtrarPorTipos(LinkedList* this);
  /** \brief
   *
   * \param
   * \param
   * \return
   *
   */

   int esTipoBMX(void* this);
   /** \brief
    *
    * \param
    * \param
    * \return
    *
    */

int esTipoPlayera(void* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int esTipoPaseo(void* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int esTipoMtb(void* this);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

int compararBicicletasPorTipoyTiempo(void* biciA,void* biciB);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
