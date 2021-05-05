//6. Implemente una función que reciba un arreglo de cadenas y su tamaño y ordene lexicográficamente dicho arreglo.
//Tamaño del arreglo 1000000.
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Función que inicializa una lista con datos obtenidos de un archivo de texto plano
void crear(string * &lista, long long tam){
	ifstream archivo;
	archivo.open("D:\\Ficheros\\Texto.txt",ios::in);
	if(archivo.fail()){
		cout<<"texto no encontrado";
		exit(1);
	}
	for(int i=0;i<tam;i++){
		archivo>>*(lista+i);
	}
	archivo.close();

}
//Función que realiza el ordenamiento usando el algoritmo Quicksort
void Quicksort(string *lista, long long inicio,long long final){
    int centro, i = inicio, j = final;
	string pivot;
	centro = (inicio+final)/2;
	pivot = lista[centro];
	do{
		while (lista[i]<pivot) i++;
		while (lista[j]>pivot) j--;
		if(i<=j){
			string aux;
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;
			i++;
			j--;
		}
	}
	while(i<=j);
	if(inicio<j) Quicksort(lista, inicio, j);
	if(i<final) Quicksort(lista,i,final);
}
//Función que genera un archivo de texto plano con los datos ordenados
void mostrar(string *lista, long long tam){
	ofstream file;
	file.open("Texto_Ordenado_Lexicográficamente.txt",ios::out);
	for(long long i=0;i<tam;i++){
		file<<*(lista+i)<<" ";
	}
	file.close();
}
int main(){
	long long  tam=1000000;
    string *lista = new string[tam];
	crear(lista,tam);
	Quicksort(lista,0,tam-1);
	mostrar(lista,tam);
	cout<<"Generando texto ordenado \n";
	delete[]lista;
    return 0;
}
