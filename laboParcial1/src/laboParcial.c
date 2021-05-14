#include <stdio.h>
#include "contribuyente_menu.h"
#include "recaudaciones_estructura.h"
#include "recaudaciones_menu.h"
#include "utn_general.h"
#define cantidadContribuyentes 50
#define cantidadRecaudacion 50


int main(void)
{
	setbuf(stdout,NULL);
	int elegir;
	int error;
	eContribuyentes contribuyentes[cantidadContribuyentes];
	eRecaudaciones recaudaciones[cantidadRecaudacion];
	inicializarisEmptyC(contribuyentes,cantidadContribuyentes);
	inicializarisEmptyR(recaudaciones, cantidadRecaudacion);
	int legajoRecaudaciones=100;
	int legajoContribuyente=1000;



	do
	{
		printf("[1]-ABM CONTRIBUYENTES, [2]-ABM RECAUDACION, [3]-SALIR\n");
		error = cargarNumero(&elegir);

		if(error == 0)
		{
			switch(elegir)
			{
			case 1:
				menuContribuyente(contribuyentes, cantidadContribuyentes, "Contribuyentes",&legajoContribuyente);
				break;
			case 2:
				menuRecaudaciones(recaudaciones, cantidadRecaudacion, "Recaudaciones",&legajoRecaudaciones);
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
