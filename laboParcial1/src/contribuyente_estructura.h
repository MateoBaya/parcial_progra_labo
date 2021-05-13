#ifndef CONTRIBUYENTE_ESTRUCTURA_H_
#define CONTRIBUYENTE_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"



typedef struct
{
	int idGeneral;
	char CUIL[MAXCHAR];
	char nombre[MAXCHAR];
	char apellido[MAXCHAR];
	int isEmpty;
}eContribuyentes;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(eContribuyentes varGeneral[],int len,int * id);

int ABMLectura(eContribuyentes varGeneral[],int len);

int ABMBaja(eContribuyentes varAlumno[],int len);

int ABMModificar(eContribuyentes varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3);

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructura(eContribuyentes varGeneral[],int i);

int buscarId(eContribuyentes varGeneral[],int len);

int buscarDescripcion(eContribuyentes varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(eContribuyentes varGeneral[],int len,int numero);

int validarIntencionUsuario(eContribuyentes varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmpty(eContribuyentes varGeneral[],int len);

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorId(eContribuyentes varGeneral[],int len);

#endif /* CONTRIBUYENTE_ESTRUCTURA_H_ */
