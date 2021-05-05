//1. Implementar una función reciba un arreglo de enteros y su tamaño y retorne la suma de los elementos de un arreglo.
//Tamaño del arreglo 1000000. (Iterativa y recursiva).
#include<iostream>
#include <time.h>
using namespace std;

//Función para generar una lista de tamaño 1000000 con enteros aleatorios
void crear(long long * &lista, long long tam){
	srand(time(NULL));
	lista=new long long [tam];
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
}
//Suma con interaciones usando bucle for
long long suma_iterativa(long long *lista,long long tam){
	long long sum=0;
	for(long long j=0;j<tam;j++){
		sum+=lista[j];
	}
	return sum;
}
//Función que Suma de elementos con Recursividad
long long suma_recursiva(long long *lista, long long inicio,long long final){
	if(inicio>final)return 0;
	if(inicio==final) return lista[final];
	long long primpart=suma_recursiva(lista,inicio+1,((inicio+1)+final)/2);
	long long segpart=suma_recursiva(lista,(((inicio+1)+final)/2)+1,final);
	return lista[inicio]+primpart+segpart;
}

int main(){
	long long  *lista, tam=1000000; //Inicializar valores
	crear(lista,tam);

	cout<<"Suma Iterativa: "<<suma_iterativa(lista,tam)<<"\n";
	cout<<"Suma Recursiva: "<<suma_recursiva(lista,0,tam-1)<<"\n";

	delete[]lista;
	return 0;
}
