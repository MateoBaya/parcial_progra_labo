#include "utn_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(estructuraGeneral varGeneral[],int len,int * id)
{
	int funcionar=0;
	int i=0;
	int error;
	int auxEntero;
	char auxChar;
	char auxTexto[MAXCHAR];

	while(varGeneral[i].isEmpty==0)
	{
		i++;
	}
	if(varGeneral[i].isEmpty==1)
	{
		*id=*id+1;
		varGeneral[i].idGeneral=*id;

		do
		{
			printf("Cargue VALOR1: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		varGeneral[i].valor1 = auxEntero;

		do
		{
			printf("Cargue VALOR2: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		varGeneral[i].valor2 = auxEntero;

		do
		{
			error=cargarCaracter(&auxChar);
		}while(error);
		varGeneral[i].caracter=auxChar;

		do
		{
			error=cargarTexto(auxTexto);
		}while(error==0);
		strcpy(varGeneral[i].descripcion,auxTexto);

		varGeneral[i].isEmpty=0;
	}

	return funcionar;
}

int ABMLectura(estructuraGeneral varGeneral[],int len)
{
	int funcionar=0;
	printf("\n************************************************************************************************\n");
	printf("   Id   | 4L | 4L  |  6L  |  6L   |   8L  |    8L    |   9L\n");
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

int ABMBaja(estructuraGeneral varGeneral[],int len)
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
			printf("   Id   | 4L | 4L  |  6L  |  6L   |   8L  |    8L    |   9L\n");
			if(validarIntencionUsuario(varGeneral, posicionACambiar, "ESTRUCTURA", "eliminar"))
			{
				varGeneral[posicionACambiar].isEmpty = 1;
			}
		}
	}
	return funcionar;
}

int ABMModificar(estructuraGeneral varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4)
{
	int funcionar=0;
	int posicionACambiar;
	char elegir;
	int flagError=1;
	int auxEntero;
	char auxTexto[MAXCHAR];
	if(varGeneral != NULL)
	{
		posicionACambiar = buscarId(varGeneral, len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el legajo, reintente");
		}else{
			printf("   Id   | 4L | 4L  |  6L  |  6L   |   8L  |    8L    |   9L\n");
			if(validarIntencionUsuario(varGeneral, posicionACambiar, "ESTRUCTURA", "modificar"))
			{

				printf("Desea modificar %s: ",deseoModificar);
				fflush(stdin);
				scanf("%c",&elegir);
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
						case 'd':
							printf("Ingrese un %s nuevo: ",mensajeOpcion1);
							cargarTexto(auxTexto);
							if (auxTexto==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].descripcion,auxTexto);
							}
							break;
						case 'X':
							printf("Ingrese un %s nuevo: ",mensajeOpcion2);
							cargarCaracter(&varGeneral[posicionACambiar].caracter);
							break;
						case 'Y':
							printf("Ingrese un %s nuevo: ",mensajeOpcion3);
							auxEntero=cargarNumero(&auxEntero);
							if (auxEntero)
							{
								printf("ERROR. No escribio un numero, reintente.");
							}else
							{
								varGeneral[posicionACambiar].valor1 = auxEntero;
							}
							break;
						case 'Z':
							printf("Ingrese un %s nuevo: ",mensajeOpcion4);
							auxEntero=cargarNumero(&auxEntero);
							if (auxEntero)
							{
								printf("ERROR. No escribio un numero, reintente.");
							}else
							{
								varGeneral[posicionACambiar].valor2 = auxEntero;
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
	int funcionar;
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
		pritf("Valor fuera de rango");
	}
	}while(decidir!=3);

	return funcionar;
}

///////////////////////////////////BUSQUEDA_INFORMACION////////////////////////////////////////////////

int mostrarEstructura(estructuraGeneral varGeneral[],int i)
{
	int funcionar=0;
	printf(/*" %-5d     %-5c  %-5d    %-5d       %-5d      %-10f      %-15s    %-5d\n"*/"%-5d\n",varGeneral[i].idGeneral);
	return funcionar;
}

int buscarId(estructuraGeneral varGeneral[],int len)
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

int buscarDescripcion(estructuraGeneral varGeneral[],int len)
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
			if(strcmp(auxString,varGeneral[i].descripcion)==0)
			{
				id = varGeneral[i].idGeneral;
				break;
			}
		}
	}

	return id;
}

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(estructuraGeneral varGeneral[],int len,int numero)
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

int validarIntencionUsuario(estructuraGeneral varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
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

int inicializarisEmpty(estructuraGeneral varGeneral[],int len)
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

int promediar(estructuraGeneral varGeneral[],int i,float * resultado)
{
	int funcionar=0;

	if(varGeneral != NULL)
	{
		*resultado = (varGeneral[i].valor1 + varGeneral[i].valor2)/2;
		funcionar=1;
	}

	return funcionar;
}

int multiplicar(estructuraGeneral varGeneral[],int i,int * resultado)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		*resultado = varGeneral[i].valor1 * varGeneral[i].valor2;
		funcionar=1;
	}
	return funcionar;
}

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorId(estructuraGeneral varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
		int aux;
		char auxChar;
		float auxFloat;
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

						auxChar=varGeneral[i].caracter;
						varGeneral[i].caracter=varGeneral[i-1].caracter;
						varGeneral[i-1].caracter=auxChar;

						aux=varGeneral[i].valor1;
						varGeneral[i].valor1=varGeneral[i-1].valor1;
						varGeneral[i-1].valor1=aux;

						aux=varGeneral[i].valor2;
						varGeneral[i].valor2=varGeneral[i-1].valor2;
						varGeneral[i-1].valor2=aux;


						strcpy(auxArrayTexto,varGeneral[i].descripcion);
						strcpy(varGeneral[i].descripcion,varGeneral[i-1].descripcion);
						strcpy(varGeneral[i-1].descripcion,auxArrayTexto);

					}

			}
			funcionar=1;
		}
		}
	return funcionar;
}
