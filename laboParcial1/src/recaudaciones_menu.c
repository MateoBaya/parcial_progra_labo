#include <stdio.h>

#include "recaudaciones_estructura.h"
#include "utn_general.h"

int menuRecaudaciones(eRecaudaciones varGeneral[],int len,char texto[],int * legajo)
{
	int eleccionUsuario;
	int funcionar;
	int error;

	if(varGeneral != NULL && texto != NULL)
	{
		do
		{
			printf("\n///////////////////////////////////////////\n");
			printf("///    %-13s                    ///\n",texto);
			printf("///      [1]-ALTA                       ///\n");
			printf("///      [2]-LECTURA                    ///\n");
			printf("///      [3]-MODIFICAR                  ///\n");
			printf("///      [4]-SALIR                      ///\n");
			printf("///                                     ///\n");
			printf("///////////////////////////////////////////\n");

			fflush(stdin);
			do{
			error = cargarNumero(&eleccionUsuario);
			}while(error!=0);
			switch(eleccionUsuario)
			{
			case 1:
				ABMAltaR(varGeneral,len,&*legajo);
				funcionar=1;
				break;
			case 2:
				ABMLecturaR(varGeneral, len);
				funcionar=1;
				break;
			case 3:
				ABMModificarR(varGeneral, len, "ESTRUCTURA", "DESCRIPCION", "CARACTER", "VALOR1", "VALOR2");
				funcionar=1;
				break;
			case 4:
				funcionar=1;
				break;
			case 5:

				break;
			default:
				printf("Reingrese, no eligio una opcion valida\n");
				break;
			}
		}while(eleccionUsuario!=4);
	}
	return funcionar;
}
