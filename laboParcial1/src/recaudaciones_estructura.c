#include "recaudaciones_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaR(eRecaudaciones varGeneral[],int len,int * id)
{
	int funcionar=0;
	int i=0;
	int error;
	int auxEntero;
	float auxFloat;

	while(varGeneral[i].isEmpty==0)
	{
		i++;
	}
	if(varGeneral[i].isEmpty==1)
	{
		*id=*id+1;
		varGeneral[i].idRecaudaciones=*id;

		do
		{
			printf("Cargue id de contribuyente: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		varGeneral[i].idContribuyente = auxEntero;

		do
		{
			printf("Cargue numero de mes: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		varGeneral[i].mes = auxEntero;

		do
		{
			printf("Cargue tipo de Recaudacion [1]-ARBA [2]-IIBB [3]-GANANCIAS: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		do
		{
			printf("Cargue importe: ");
			error = cargarFloat(&auxFloat);
		}while(error);

		varGeneral[i].importe = auxFloat;


		varGeneral[i].estado=DEBE;
		varGeneral[i].isEmpty=0;
	}

	return funcionar;
}

int ABMLecturaR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	printf("\n************************************************************************************************\n");
	printf("   IdRec   | IdCont | Estado  |  Importe  |  Mes   |   Tipo  \n");
	printf("************************************************************************************************\n");

	for(int i=0;i<len;i++)
	{

		if(varGeneral[i].isEmpty==0)
		{
			mostrarEstructuraR(varGeneral,i);
			funcionar=1;
		}
	}
	printf("*************************************************************************************************\n");

	return funcionar;
}

int ABMBajaR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	int posicionACambiar;

	if(varGeneral != NULL)
		{
		posicionACambiar=buscarIdR(varGeneral,len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el id, reintente");
		}else{
			printf("   Id   | 4L | 4L  |  6L  |  6L   |   8L  |    8L    |   9L\n");
			if(validarIntencionUsuarioR(varGeneral, posicionACambiar, "ESTRUCTURA", "eliminar"))
			{
				varGeneral[posicionACambiar].isEmpty = 1;
			}
		}
	}
	return funcionar;
}

int ABMModificarR(eRecaudaciones varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4)
{
	int funcionar=0;
	int posicionACambiar;
	int elegir;
	char elegirchar;
	int flagError=1;
	if(varGeneral != NULL)
	{
		posicionACambiar = buscarIdR(varGeneral, len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el legajo, reintente");
		}else{
			printf("   Id   | 4L | 4L  |  6L  |  6L   |   8L  |    8L    |   9L\n");
			if(validarIntencionUsuarioR(varGeneral, posicionACambiar, "ESTRUCTURA", "modificar"))
			{

				printf("Desea modificar %s [1]-Refinanciar [2]-Saldar: ",deseoModificar);
				fflush(stdin);
				scanf("%d",&elegir);
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
						case 1:
							printf("Cambiar a %s: ",mensajeOpcion1);
							cargarCaracter(&elegirchar);
							validarSoN(elegirchar);
							if(elegirchar== 's')
							{
								varGeneral[posicionACambiar].estado=REFINANCIAR;
							}

							break;
						case 2:
							printf("Cambiar a %s: ",mensajeOpcion2);
							cargarCaracter(&elegirchar);
							validarSoN(elegirchar);
							if(elegirchar== 's')
							{
								varGeneral[posicionACambiar].estado=SALDADO;
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

int ABMinformesR()
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

int mostrarEstructuraR(eRecaudaciones varGeneral[],int i)
{
	int funcionar=0;
	printf(" %-5d    %-5d    %-5d      %-5f      %-5d      %-5d   \n",varGeneral[i].idRecaudaciones,varGeneral[i].idContribuyente,varGeneral[i].estado,varGeneral[i].importe,varGeneral[i].mes,varGeneral[i].tipo);
	return funcionar;
}

int buscarIdR(eRecaudaciones varGeneral[],int len)
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
				if(varGeneral[i].idRecaudaciones == id)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}
/*
int buscarDescripcionR(eRecaudaciones varGeneral[],int len)
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
				id = varGeneral[i].idRecaudaciones;
				break;
			}
		}
	}

	return id;
}
*/

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarIdR(eRecaudaciones varGeneral[],int len,int numero)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (varGeneral[i].idRecaudaciones==numero)
			{
				funcionar=1;
			}
		}
	}
	return funcionar;
}

int validarIntencionUsuarioR(eRecaudaciones varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varGeneral != NULL)
	{
		do
		{
			mostrarEstructuraR(varGeneral, posicionACambiar);
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

int inicializarisEmptyR(eRecaudaciones varGeneral[],int len)
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
int promediar(eRecaudaciones varGeneral[],int i,float * resultado)
{
	int funcionar=0;

	if(varGeneral != NULL)
	{
		*resultado = (varGeneral[i].valor1 + varGeneral[i].valor2)/2;
		funcionar=1;
	}

	return funcionar;
}

int multiplicar(eRecaudaciones varGeneral[],int i,int * resultado)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		*resultado = varGeneral[i].valor1 * varGeneral[i].valor2;
		funcionar=1;
	}
	return funcionar;
}
*/

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorIdR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
		int aux;
		if(varGeneral != NULL)
		{
			while(flagNoOrdenado)
			{
				flagNoOrdenado=0;
				for(int i=1; i<len;i++)
				{
					if(varGeneral[i].idRecaudaciones < varGeneral[i-1].idRecaudaciones)
					{
						aux=varGeneral[i].idRecaudaciones;
						varGeneral[i].idRecaudaciones=varGeneral[i-1].idRecaudaciones;
						varGeneral[i-1].idRecaudaciones=aux;

					}

			}
			funcionar=1;
		}
		}
	return funcionar;
}

/*
void hardCodearRecaudacion(eRecaudaciones recaudacion[], int len)
{
    int i;
    int estado[]= {DEBE,REFINANCIAR,SALDADO};
    char descripcionCarrera[][MAXCHAR]= {"Progra","Analisis"};
    for(i=0; i<2; i++)
    {
    	recaudacion[i].estado = estado[i];


    }


}
*/
