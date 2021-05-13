#include <stdio.h>

#include "utn_estructura.h"
#include "utn_general.h"
#include "utn_menu.h"

int main(void)
{
	setbuf(stdout,NULL);
	char respuesta[MAXCHAR];
	cargarTexto(respuesta);

	//printf("%s\n",respuesta);

	if(validarMAIL(respuesta, MAXCHAR))
	{
		printf("mail: %s\n",respuesta);
	}

	/*
	estructuraGeneral varGeneral[2];
	inicializarisEmpty(varGeneral,2);
	menuABM(varGeneral, 2, "UTN");*/
	return 0;
}
