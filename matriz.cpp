#include <stdio.h>
#include <string.h>
#include <iostream>
#define CLEAR "cls"
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;
using std::setprecision;
void imprimir(int f, int c, float *);
void pivote(int f, int c, float *, float *, float *, int j);
int definirMatriz();
int matrizInversa();
int creditos();
void titulo(string title);

int menu()
{

	int opc;
	system("color 3F");
	titulo("BIENVENIDO");
	cout << "1.SOLUCION DE ECUACIONES LINEALES POR GAUSS-JORDAN" << endl;
	cout << "2.CALCULAR MATRIZ INVERSA" << endl;
	cout << "3.CREDITOS" << endl;
	cout << "4.SALIR" << endl;
	cout << "\nOPCION: ";
	cin >> opc;
	system(CLEAR);
	switch (opc)
	{

	case 1:
		definirMatriz();
		break;
	case 2:
		matrizInversa();
		break;
	case 3:
		creditos();
		break;
	case 4:
		titulo("GRACIAS POR SU ATENCION");
		break;
	default:
		titulo("GRACIAS POR SU ATENCION");
		menu();
		break;
	}
}

int definirMatriz()
{

	// Definimos la matriz , solicitamos el numero de filas y columnas al usuario
	int f = 0, c = 0;
	titulo("SOLUCION DE ECUACIONES LINEALES POR GAUSS-JORDAN");
	printf("Ingresa el numero de filas: ");
	scanf("%i", &f);
	printf("\nIngresa el numero de columanas: ");
	scanf("%i", &c);
	// se le agrega 1 a las columnas para despues pedir los numeros independientes
	c++;
	// Creamos nuestra matriz de dos dimensiones
	float matriz[f][c];

	// con estos dos ciclos for , llenamos nuestra matriz
	// El primer ciclo son las columnas y el segundo para las filas
	// Esto para que podamos llenar el vector de terminos independientes
	printf("\nIntroduce los elementos que conforman la matriz:");
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < f; i++)
		{
			if (c - 1 == j) // se pregunta si columnas -1 es igual a j
			{
				printf("\nIngresa los valores del vector de terminos independentientes");
			}
			// llenamos la matriz y agregamos 1 a i y a j
			printf("\nIngresa el elemento en la posicion [%i,%i:] ", i + 1, j + 1);
			scanf("%f", &matriz[i][j]);
		}
	}
	system(CLEAR); // limpiamos la consola
	// Imprimimos la matriz inicial
	titulo("Matriz aumentada inicial:");
	// llamamos a nuestro metodo imprimir y le agregamos los parametros
	imprimir(f, c, &matriz[0][0]);
	cout << "\n";
	system("Pause");
	system(CLEAR);

	float aux = 0;
	float vecPivote[c];
	float vectAuxiliar[c];
	float n = 0;

	// Reduccion por guss-jordan
	// Recorremos la matriz para  reducir elementos a 0
	for (int j = 0; j < c - 1; j++)
	{
		// llamamos a nuestro al metodo pivote
		pivote(f, c, &matriz[0][0], &vecPivote[0], &vectAuxiliar[0], j);

		for (int i = 0; i < f; i++)
		{
			printf("\n(%d,%d)\n", i + 1, j + 1);

			if (i != j && j < c - 1) // decimos que cuando i es diferente de j , no estamos en la diagonal
			// entonces tenmos que redurcirlo a 0. Tambien si no nos encontramos en la columna de resultados
			{
				n = matriz[i][j]; // se asigna n al elemento que no esta en la diagonal principla
			}

			//
			for (int k = 0; k < c; k++)
			{
				// realizamos la siguiente operacion para hacer 0 a los elementos por debajo
				// de la diagonal
				matriz[i][k] = (-1 * n * vecPivote[k]) + matriz[i][k];
			}

			if (i == j)
			{
				// este for sirve para no se alteres la diagonal principal
				// regresa los valores a esa diagonal
				for (int l = 0; l < c; l++)
				{
					matriz[i][l] = vectAuxiliar[l];
					if (matriz[i][l] == -0)
					{
						matriz[i][l] = 0;
					}
				}
			} // llamamos a nuestro metodo impirmir, asignamos los parametros
			imprimir(f, c, &matriz[0][0]);
			cout << ("\n");
			system("pause");
		}
		// cout<<"Matriz escalonada";
		//	imprimir(f,c,&matriz[0][0]);

		// Se limpia la fila pivote para evitar arrastrar basura al igual que n
		n = 0;
		for (int k = 0; k < c; k++)
		{
			vecPivote[k] = 0;
		}
		// cout<<"Matriz escalonada";
		//	imprimir(f,c,&matriz[0][0]);
	}
	titulo("Matriz Escalonada:");
	imprimir(f, c, &matriz[0][0]);
	system("pause");
	system(CLEAR);
	menu();
}

void imprimir(int f, int c, float *matriz)
{
	printf("\n\n");
	int contar = 0;

	for (int i = 0; i < f * c; i++)
	{
		if (contar < c)
		{
			printf(" %f ", matriz[i]);
			contar++;
		}
		else
		{
			contar = 0;
			printf("\n");
			printf(" %f ", matriz[i]);
			contar++;
		}
	}
}

void pivote(int f, int c, float *matriz, float *vecPivote, float *vectAuxiliar, int j)
{
	float aux = 0;
	float matrizT[f][c]; // creamos un matriz Temporal que apunte a la matriz principal para poder manipularla
	int sumi = 0;

	// Este doble ciclo for nos aydua a copiar los datos de nuestra matriz original o a la matrizt
	// para poder pivotear
	for (int i = 0; i < f; i++)
	{
		for (int k = 0; k < c; k++)
		{
			matrizT[i][k] = matriz[sumi];
			sumi++;
		}
	}

	for (int i = 0; i < f; i++)
	{
		if (i == j)
		{

			aux = matrizT[i][j]; // le asignamos a aux los valores ... aux sera nuestro pivote

			// creamos un ciclo for que recorra toda la fila
			for (int k = 0; k < c; k++)
			{
				matrizT[i][k] = matrizT[i][k] / aux; // dividimos toda la fila entre el pivote
				// creamos dos vectores y les damos los valores de la matriz temporal
				vecPivote[k] = matrizT[i][k];
				vectAuxiliar[k] = matrizT[i][k];
			}
		}
	}

	// Agregamos los valores de la matriz Temporal a la matriz original
	sumi = 0;

	for (int i = 0; i < f; i++)
	{
		for (int k = 0; k < c; k++)
		{
			matriz[sumi] = matrizT[i][k];
			sumi++;
		}
	}
}
// Este metodo es para crear titulos llamativos
void titulo(string title)
{
	int i;
	int val;

	val = title.length();

	val = val + 20;

	for (i = 0; i <= val; i++)
	{
		cout << "*";
	}

	cout << "\n \n";

	for (i = 0; i <= val; i++)
	{
		cout << " ";
		if (i == 4)
		{
			cout << title;
		}

		cout << " ";
	}

	cout << "\n";

	for (i = 0; i <= val; i++)
	{
		cout << "*";
	}

	cout << "\n \n \n";
}
int creditos()
{
	system("color 3F");
	titulo("ALGEBRA lINEAL");
	string profesor = "Gerardo Gonzalez Hernandez";
	string nombre1 = "-Luis Ruben Sosa Delgadillo";
	string nombre2 = "-Ezequiel Olivera Reyes";
	string nombre3 = "-Jorge �ngel Jim�nez Sandoval";
	string nombre4 = "-Josu� Hern�ndez Rosas";
	string nombre5 = "-Giovanna Daiana Escutia Silva";

	cout << "Profesor: " << profesor << "\n";
	cout << "Integrantes: \n"
		 << nombre1 << "\n"
		 << nombre2 << "\n"
		 << nombre3 << "\n"
		 << nombre4 << "\n"
		 << nombre5;
}
COORD coord = {0, 0};
// El metodo gotoxy nos ayuda a colocarnos en una posicion determinada en nuestra consola
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
matrizInversa()
{
	titulo("CALCULADORA DE MATRIZ INVERSA");
	int i, j, k, n;
	cout << "Introduzca el orden de la matriz nxn: ";
	cin >> n;

	float A[n][n], I[n][n], aux, pivote;
	// Estos dos ciclos nos ayuda a construir nuestra matriz, el primero es para las filas
	// El segundo ciclo es para las columnas
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			gotoxy(j * 5, i + 10); // 5 espacios entre cada elemento de nuestra matriz y 10 espacios hacia abajo
			cin >> A[i][j];		   // Guardamos los datos en nuestra matriz A

			// Decimos que todos los elementos de la matriz Identidad se hagan 0
			// excepto la diagonal principal , en la diagonal la hace 1
			I[i][j] = 0;
			if (i == j) // Estamos en la diagonal principal ya que el elemento i es igual al elemento j
				I[i][j] = 1;
		}

	// recorremos la matriz construida
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			// imprimimos la matriz identidad 20 espacios hacia la izquierda de nuestro cursor
			gotoxy(20 + j * 5, i + 10);
			cout << I[i][j];
		}

	// Reducimos renglones
	for (i = 0; i < n; i++)
	{
		pivote = A[i][i]; // Este pivote nos ayuda a convertir a 1 la diagonal principal

		// Ciclo nos ayuda a movernos en la fila de la matriz
		for (k = 0; k < n; k++)
		{ // convertimos el pivote a 1 y dividimos a toda la fila
			A[i][k] = A[i][k] / pivote;
			// Aplicamos lo mismo en la matriz identidad
			I[i][k] = I[i][k] / pivote;
		}
		// Este ciclo nos permite convertir a 0 los elementos que esten por arriba o abajo de la diagonal
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{				   // no estamos en la diagonal
				aux = A[j][i]; // El aux es el numero que quiero convertir a 0
				for (k = 0; k < n; k++)
				{ // ciclo para aplicar el proceso en todo la fial

					// operacion para reducir a 0 los elemetos
					A[j][k] = A[j][k] - aux * A[i][k];
					I[j][k] = I[j][k] - aux * I[i][k];
				}
			}
		}
	}
	printf("\n\nLa matriz inversa es:");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			gotoxy(j * 5, i + 17);
			cout << A[i][j];

			gotoxy(25 + j * 9, i + 17);
			// redondeamos a dos decimales el resultado de la matriz
			cout << setprecision(2) << I[i][j];
		}
	cout << "\n\nPresione una tecla para regresar al menu" << endl;
	cout << "\n";
	system("pause");
	system(CLEAR);
	menu();
}

main()
{
	menu();
}
