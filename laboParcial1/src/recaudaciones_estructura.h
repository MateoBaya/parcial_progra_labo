#ifndef RECAUDACIONES_ESTRUCTURA_H_
#define RECAUDACIONES_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"

#define ARBA 1
#define IIBB 2
#define GANANCIAS 3
#define DEBE 1
#define REFINANCIAR 2
#define SALDADO 3

typedef struct
{
	int idRecaudaciones;
	int idContribuyente;
	int mes;
	int tipo;
	float importe;
	int estado;
	int isEmpty;
}eRecaudaciones;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaR(eRecaudaciones varGeneral[],int len,int * id);

int ABMLecturaR(eRecaudaciones varGeneral[],int len);

int ABMBajaR(eRecaudaciones varAlumno[],int len);

int ABMModificarR(eRecaudaciones varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4);

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructuraR(eRecaudaciones varGeneral[],int i);

int buscarIdR(eRecaudaciones varGeneral[],int len);

int buscarDescripcionR(eRecaudaciones varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarIdR(eRecaudaciones varGeneral[],int len,int numero);

int validarIntencionUsuarioR(eRecaudaciones varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmptyR(eRecaudaciones varGeneral[],int len);

void hardCodearRecaudacionR(eRecaudaciones recaudacion[], int len);

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorIdR(eRecaudaciones varGeneral[],int len);

#endif /* RECAUDACIONES_ESTRUCTURA_H_ */
