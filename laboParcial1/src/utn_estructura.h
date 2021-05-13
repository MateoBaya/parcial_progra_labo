#ifndef UTN_ESTRUCTURA_H_
#define UTN_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"


typedef struct
{
	int idGeneral;
	char caracter;
	int valor1;
	int valor2;
	char descripcion[MAXCHAR];
	int isEmpty;
}estructuraGeneral;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(estructuraGeneral varGeneral[],int len,int * id);

int ABMLectura(estructuraGeneral varGeneral[],int len);

int ABMBaja(estructuraGeneral varAlumno[],int len);

int ABMModificar(estructuraGeneral varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4);

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructura(estructuraGeneral varGeneral[],int i);

int buscarId(estructuraGeneral varGeneral[],int len);

int buscarDescripcion(estructuraGeneral varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(estructuraGeneral varGeneral[],int len,int numero);

int validarIntencionUsuario(estructuraGeneral varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmpty(estructuraGeneral varGeneral[],int len);

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorId(estructuraGeneral varGeneral[],int len);

#endif /* UTN_ESTRUCTURA_H_ */
