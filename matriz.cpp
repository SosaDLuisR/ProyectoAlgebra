#include<stdio.h>
#include<string.h>
#include<iostream>
#define CLEAR "cls"
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void imprimir(int f, int c, float * );
void pivote(int f, int c, float *, float*,float*,int j);
int definirMatriz();


int menu();

	system("color 3F");
	titulo("SOLUCION DE ECUACIONES LINEALES POR GAUSS-JORDAN");
cout<<"1.SOLUCION DE ECUACIONES LINEALES POR GAUSS-JORDAN"<<endl;
cout<<"2.CALCULAR "<<endl;
cout<<"3.Instrucciones"<<endl;
cout<<"4.Salir"<<endl;
cout<<"\nOpcion: ";
cin>>opc;
system(CLEAR);


void titulo(string title)
{
	int i;
	int val;
	
	val = title.length() ;
	
	val = val + 20;
	
	
	for(i=0; i<= val; i++)
	{
		cout << "*";
	}
	
	cout << "\n \n";
	
	for(i=0; i<= val; i++)
	{
		cout << " ";
		if(i==4 )
		{
			cout << title;
		}
		
		cout << " ";
		
	}
	
	cout << "\n";
	
	for(i=0; i<= val; i++)
	{
		cout << "*";
	}
	
	cout << "\n \n \n";
	
}

int menu(){
	system("color 0a");
	titulo("BIENVENIDO AL PROGRAMA");
	titulo("Solucion de ecuaciones con guss-jordan");
}


int definirMatriz(){

	// Definicion de la matriz
	int f = 0, c = 0;
	
	printf("Ingresa el numero de filas: ");
	scanf("%i",&f);
	printf("\nIngresa el numero de columanas: ");
	scanf("%i",&c);
	c++;
	float matriz[f][c];
	
	printf("\nIntroduce los elementos que conforman la matriz:");
	for(int j=0; j<c;j++)
	{
		for(int i = 0; i<f; i++)
		{
			if (c - 1 == j)
			{
				printf("\nIngresa los valores del vector de terminos independentientes");
			}
			printf("\nIngresa el valor de la posicion [%i,%i:] ",i+1,j+1);
			scanf("%f",&matriz[i][j]);
		}
	}
	//Matriz Inicial
	printf("MATRIZ AUMENTADA INICIAL ES: \n");
	imprimir(f,c,&matriz[0][0]);
	printf("\n");
	
	//Metodo de gauss-jordan
	
	float aux = 0;
	float vecPivote[c];
	float vectAuxiliar[c];
	float n = 0;
    

        for(int j =0; j<c-1;j++)
	    {
	    	// Se necesita la posicion j, el vector pivote
	    	pivote(f, c,&matriz[0][0], &vecPivote[0], &vectAuxiliar[0], j);
	    	
		    for(int i = 0; i<f; i++)
	        {
	        	printf("\n(%d,%d)\n",i+1,j+1);
			 //Cuando i sea diferente de j se asigna el valor n, y se restringe para evitar que tome el valor de columna de resultados
			 if (i != j && j < c-1)
	         {
	         	n = matriz[i][j];
	         	
	         }
	         
	     
		 // Opera sobre toda la fila sin importar que esta contenga ya un pivote
	        for(int k = 0; k < c; k++)
			{
				matriz[i][k] = (-1*n*vecPivote[k]) + matriz[i][k];
				
			}
			 
			 if(i == j )
			 {
			 	// Para evitar que se altere la fila pivote se realizan las siguientes asignaciones.
				for(int l = 0; l < c; l++)
				{
					matriz[i][l] = vectAuxiliar[l];
					if(matriz[i][l] == -0)
					{
						matriz[i][l] = 0;
					}
					
				}		
			 }
	         imprimir(f,c,&matriz[0][0]);			
	    	}
	    	
	    	// Se limpia la fila pivote para evitar arrastrar basura al igual que n 
	    	n = 0;		
	        for(int k = 0; k < c; k++)
	    	{
	    	     vecPivote[k] = 0;
			}
	    	
	
	}			
	  
}

void imprimir(int f, int c, float * matriz)
{
	printf("\n\n");
	int contar = 0;
	   
	for(int i = 0; i<f*c; i++)
	{
		if(contar < c)
		{
			printf(" %f ",matriz[i]);
			contar++;
		}
		else
		{
			contar = 0;
			printf("\n");
			printf(" %f ",matriz[i]);
			contar++;
		}
		
	}
}


void pivote(int f, int c, float *matriz, float *vecPivote, float *vectAuxiliar, int j)
{
	float aux = 0;
	float matrizT[f][c];
	int sumi = 0;
	//Copiamos los datos de la MatrizA  a una matriz temporal porque al enviarla como apuntador esta se convierte en un vector.
	
	for (int  i =  0; i < f; i++)
	{
		for( int k = 0; k < c; k++)
		{
			matrizT[i][k] = matriz[sumi];
			sumi ++;
		}
	}
	
	//Una vez copiados los datos en una matriz temporal operamos para obtener el pivote y su fila asociada

		for(int i = 0; i<f;i++)
		{
			if(i == j )
			 {
			 	// Suponemos que el pivote esta en la posicion (i,j) y lo calculamos dividiendo el numero en esa posicion entre si mismo.
					aux = matrizT[i][j];
					printf("Pivote: %f\n",aux);
				// En la matriz temporal realizamos la divicion de toda la fila donde se encuentra el pivote y la guardamos en la matriz temporal y en dos vectores que usaremos mas tarde.	
					for(int l = 0; l < c; l++)
					{
						matrizT[i][l] = matrizT[i][l] /aux;
						vecPivote[l] = matrizT[i][l];
						vectAuxiliar[l] = matrizT[i][l];
						
					}		
			 }
		}

		
	//Luego pasamos los datos de la matriz temporal a nuestra matriz de trabajo MA.
	sumi = 0;
	
	for (int  i =  0; i < f; i++)
	{
		for( int k = 0; k < c; k++)
		{
			matriz[sumi] = matrizT[i][k];
			sumi++;
		}
	}
}
main()
{ 	
	 
}
	
