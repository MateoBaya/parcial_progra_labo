#include <stdio.h>
#include "contribuyente_menu.h"
#include "utn_general.h"
#define cantidadContribuyentes 50
#define cantidadRecaudacion 50
#define ARBA 1
#define IIBB 2
#define GANANCIAS 3
#define DEBE 1
#define REFINANCIAR 2
#define SALDADO 3

int main(void)
{
	setbuf(stdout,NULL);
	int elegir;
	int error;
	eContribuyentes contribuyentes[cantidadContribuyentes];
	inicializarisEmpty(contribuyentes,cantidadContribuyentes);

	do
	{
		printf("[1]-ABM CONTRIBUYENTES, [2]-ABM RECAUDACION, [3]-SALIR\n");
		error = cargarNumero(&elegir);

		if(error == 0)
		{
			switch(elegir)
			{
			case 1:
					menuABM(contribuyentes, cantidadContribuyentes, "Contribuyentes");
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				printf("Ese numero no estaba dentro de rango");
				break;
			}
		}
	}while(elegir!=3);

	return 0;
}
