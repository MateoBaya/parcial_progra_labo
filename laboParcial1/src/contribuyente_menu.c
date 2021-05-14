#include <stdio.h>

#include "contribuyente_estructura.h"
#include "utn_general.h"

int menuContribuyente(eContribuyentes varGeneral[],int len,char texto[],int * legajo)
{
	int eleccionUsuario;
	int funcionar;
	int error;

	if(varGeneral != NULL && texto != NULL)
	{
		do
		{
			printf("\n///////////////////////////////////////////\n");
			printf("///    %-13s                   ///\n",texto);
			printf("///      [1]-ALTA                       ///\n");
			printf("///      [2]-BAJA                       ///\n");
			printf("///      [3]-LECTURA                    ///\n");
			printf("///      [4]-MODIFICAR                  ///\n");
			printf("///      [5]-SALIR                      ///\n");
			printf("///                                     ///\n");
			printf("///////////////////////////////////////////\n");

			fflush(stdin);
			do{
			error = cargarNumero(&eleccionUsuario);
			}while(error!=0);
			switch(eleccionUsuario)
			{
			case 1:
				ABMAltaC(varGeneral,len,&*legajo);
				funcionar=1;
				break;
			case 2:
				ABMBajaC(varGeneral,len);
				funcionar=1;
				break;
			case 3:
				ABMLecturaC(varGeneral, len);
				funcionar=1;
				break;
			case 4:
				ABMModificarC(varGeneral, len, "contribuyentes", "CUIL", "nombre", "apellido");
				funcionar=1;
				break;
			case 5:

				break;
			default:
				printf("Reingrese, no eligio una opcion valida\n");
				break;
			}
		}while(eleccionUsuario!=5);
	}
	return funcionar;
}
