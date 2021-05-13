#include <stdio.h>
#define cantidadEstructura 2

int main(void)
{

	estructuraGeneral varGeneral[cantidadEstructura];
	inicializarisEmpty(varGeneral,cantidadEstructura);
	menuABM(varGeneral, cantidadEstructura, "Estructura");

	return 0;
}
