//Implementar una función que invierta los elementos de un arreglo de enteros (Iterativa y recursiva). Tamaño del
//arreglo 1000000.
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
//Función para generar una lista con valores aleatorios
void crear(long long * &lista, long long tam){
	srand(time(NULL));
	lista=new long long [tam];
	for(long long i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
	cout<<"\n";
}
//Función para generar un archivo de texto plano con los datos aleatorios
void mostrar(long long *lista, long long tam){
	ofstream archivo;
	archivo.open("Lista.txt",ios::out);
	for(long long i=0;i<tam;i++){
		archivo<<lista[i]<<" ";
	}
	archivo.close();
}
//Función para sumar los valores de la lista de manera Iterativa
void invertir_Iterativa(long long *lista, long long tam){
    ofstream file;
	file.open("Lista_invertido.txt",ios::out);
	long long *listab;
	listab=new long long [tam];
	for(long long  j=0;j<tam;j++){
		listab[j]=lista[tam-(j+1)];
		file<<listab[j]<<" ";
	}
	file.close();
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	mostrar(lista,tam);
	cout<<"\nLISTA GUARDADA EN TXT \n";
	invertir_Iterativa(lista,tam);
	cout<<"\nLISTA INVERTIDAD EN TXT \n";
	cout<<endl;
	delete[]lista;

	return 0;
}
