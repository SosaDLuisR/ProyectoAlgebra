#include <stdio.h>
int main()
{
	int f,c,i,j,A[10][10];
	/*f = fila
	c= columna
	i= fila dentro de la matriz
	j= columna dentro de la matriz
	A[10][10] = es la dimension del arreglo*/
	printf("\n\nSolucion de una matriz por metodo de Gauss-Jordan");
	printf("\nDamos por hecho que sabes que es una matriz aumentada");
	printf("\nAhora te solicitaremos los datos para que los ingreses, gracias :)");
	printf("\n\nCuantas filas tendra la matriz? ");
	scanf("%i",&f);
	printf("\nCuantas columnas tendra la matriz? ");
	scanf("%i",&c);
	printf("\n\nIntroduce los elementos que conforman la matriz\n");
	for(i=1;i<=c;i=i+1) {
		for(j=1;j<=f;j=j+1) {
			printf("\nDame un elemento para A[%i][%i]: \t",i,j);
			scanf("%i",&A[i][j]);
		}
	}
	//*fin captura de matriz*//
	printf("\nLa matriz que ingresaste es: \n\n");
	for(i=1;i<=c;i=i+1)	{
		for(j=1;j<=f;j=j+1)	{
			printf("\t%i",A[i][j]);
		}
		printf("\n");
	}
	//*fin impresion de matriz*//
	printf("\nAhora procederemos a escalonar la parte inferior a la diagonal principal");
	if
	printf("\n\n");
}
