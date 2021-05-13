#include "contribuyente_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(eContribuyentes varContribuyente[],int len,int * id)
{
	int funciona=0;
	int i=0;
	int error;
	char auxTexto[MAXCHAR];

		if(varContribuyente != NULL)
		{

			while(varContribuyente[i].isEmpty==0)
			{
				i++;
			}
			if(varContribuyente[i].isEmpty==1)
			{
				*id=*id+1;
				varContribuyente[i].idGeneral=*id;

				printf("Cargue el CUIL: ");
				do
				{
					error=cargarTexto(auxTexto);
				}while(error == 0);
				strcpy(varContribuyente[i].CUIL,auxTexto);

				printf("Cargue el nombre: ");
				do
				{
					error=cargarTexto(auxTexto);
				}while(error==0);
				strcpy(varContribuyente[i].nombre,auxTexto);

				printf("Cargue el apellido: ");
				do
				{
					error=cargarTexto(auxTexto);
				}while(error==0);
				strcpy(varContribuyente[i].apellido,auxTexto);

				varContribuyente[i].isEmpty=0;
			}
	}

	return funciona;
}

int ABMLectura(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	printf("\n************************************************************************************************\n");
	printf("   Id   |    CUIL    |     Nombre    |    Apellido   \n");
	printf("************************************************************************************************\n");

	for(int i=0;i<len;i++)
	{

		if(varGeneral[i].isEmpty==0)
		{
			mostrarEstructura(varGeneral,i);
			funcionar=1;
		}
	}
	printf("*************************************************************************************************\n");

	return funcionar;
}

int ABMBaja(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	int posicionACambiar;

	if(varGeneral != NULL)
		{
		posicionACambiar=buscarId(varGeneral,len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el id, reintente");
		}else{
			printf("   Id   |    CUIL    |     Nombre    |    Apellido   \n");
			if(validarIntencionUsuario(varGeneral, posicionACambiar, "ESTRUCTURA", "eliminar"))
			{
				varGeneral[posicionACambiar].isEmpty = 1;
			}
		}
	}
	return funcionar;
}

int ABMModificar(eContribuyentes varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3)
{
	int funcionar=0;
	int posicionACambiar;
	char elegir;
	int flagError=1;
	char auxTexto[MAXCHAR];
	if(varGeneral != NULL)
	{
		posicionACambiar = buscarId(varGeneral, len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el legajo, reintente");
		}else{
			printf("   Id   |    CUIL    |     Nombre    |    Apellido   \n");
			if(validarIntencionUsuario(varGeneral, posicionACambiar, "ESTRUCTURA", "modificar"))
			{

				printf("Desea modificar %s, [c]-CUIL, [n]-Nombre, [a]-Apellido: ",deseoModificar);
				cargarCaracter(&elegir);
				do
				{
					if(flagError)
					{
						flagError=0;
					}else
					{
						printf("ERROR. Escribio un caracter incorrecto, reintente.");
					}
					switch(elegir)
					{
						case 'c':
							printf("Ingrese un %s nuevo: ",mensajeOpcion1);
							cargarTexto(auxTexto);
							if (auxTexto==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].CUIL,auxTexto);
							}
							break;
						case 'n':
							printf("Ingrese un %s nuevo: ",mensajeOpcion2);
							cargarTexto(auxTexto);
							if (auxTexto==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].nombre,auxTexto);
							}

							break;
						case 'a':
							printf("Ingrese un %s nuevo: ",mensajeOpcion3);
							cargarTexto(auxTexto);
							if (auxTexto==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].apellido,auxTexto);
							}
							break;
						default:
							elegir='0';
							break;
					}
				}while(elegir == '0');
			}
		}
	}

	return funcionar;
}

int ABMinformes()
{
	int funcionar=0;
	int decidir;

	do
	{
	printf("[1]-Ordenamiento por ***, [2]-Muestro ***, [3]-Salir");
	cargarNumero(&decidir);
	if(valorConRango(decidir, 1, 3))
	{
		switch(decidir)
		{
		case 1:
			break;
		case 2:
			break;
		}
	}else
	{
		printf("Valor fuera de rango");
	}
	}while(decidir!=3);

	return funcionar;
}

///////////////////////////////////BUSQUEDA_INFORMACION////////////////////////////////////////////////

int mostrarEstructura(eContribuyentes varGeneral[],int i)
{
	int funcionar=0;
	printf("  %-5d     %-15s  %-10s   %-10s   \n",varGeneral[i].idGeneral,varGeneral[i].CUIL,varGeneral[i].nombre,varGeneral[i].apellido);
	return funcionar;
}

int buscarId(eContribuyentes varGeneral[],int len)
{
	int posicion=-1;
	int i;
	int id;
	if(varGeneral != NULL)
	{
		printf("Id a buscar: ");
		scanf("%d",&id);
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idGeneral == id)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int buscarDescripcion(eContribuyentes varGeneral[],int len)
{
	int id=-1;
	int i;
	char auxString[MAXCHAR];
	printf("Escriba descripcion: ");
	scanf("%s",auxString);
	for(i=0;i<len;i++)
	{
		if(varGeneral[i].isEmpty==0)
		{
			if(strcmp(auxString,varGeneral[i].nombre)==0)
			{
				id = varGeneral[i].idGeneral;
				break;
			}
		}
	}

	return id;
}

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(eContribuyentes varGeneral[],int len,int numero)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (varGeneral[i].idGeneral==numero)
			{
				funcionar=1;
			}
		}
	}
	return funcionar;
}

int validarIntencionUsuario(eContribuyentes varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varGeneral != NULL)
	{
		do
		{
			mostrarEstructura(varGeneral, posicionACambiar);
			printf("\nSeguro que quiere %s este %s s/n: ",textoAValidar,mensaje);
			cargarCaracter(&decidir);
			sinError=validarSoN(decidir);
			if(sinError)
			{
				funcionar = 1;
			}
		}while(sinError==0);
	}
	return funcionar;
}

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmpty(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			varGeneral[i].isEmpty=1;
		}
		funcionar =1;
	}

	return funcionar;
}
/*
int promediar(eContribuyentes varGeneral[],int i,float * resultado)
{
	int funcionar=0;

	if(varGeneral != NULL)
	{
		*resultado = (varGeneral[i].CUIL + varGeneral[i].valor2)/2;
		funcionar=1;
	}

	return funcionar;
}
*/
/*
int multiplicar(eContribuyentes varGeneral[],int i,int * resultado)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		*resultado = varGeneral[i].CUIL * varGeneral[i].valor2;
		funcionar=1;
	}
	return funcionar;
}
*/

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorId(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
		int aux;
		char auxArrayTexto[MAXCHAR];
		if(varGeneral != NULL)
		{
			while(flagNoOrdenado)
			{
				flagNoOrdenado=0;
				for(int i=1; i<len;i++)
				{
					if(varGeneral[i].idGeneral < varGeneral[i-1].idGeneral)
					{
						aux=varGeneral[i].idGeneral;
						varGeneral[i].idGeneral=varGeneral[i-1].idGeneral;
						varGeneral[i-1].idGeneral=aux;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[i-1].nombre);
						strcpy(varGeneral[i-1].nombre,auxArrayTexto);

					}

			}
			funcionar=1;
		}
		}
	return funcionar;
}
