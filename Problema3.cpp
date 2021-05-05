//3. Implementar una función que ordene los elementos de un arreglo: ascendente. Tamaño del arreglo 1000000.
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

//Función que genera un archivo de texto plano con valores aleatorios del 1 - 10
void crear(long long * &lista, long long tam){
	ofstream archivo;
	archivo.open("Lista_Original_Aleatoria.txt",ios::out);
	srand(time(NULL));
	lista=new long long [tam];
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
		archivo<<lista[i]<<" ";
	}
	archivo.close();
}
//Función que genera un archivo de texto plano con los valores ordenados ascendentemente
void mostrar(long long *lista, long long tam){
	ofstream file;
	file.open("Lista_Ordenada.txt",ios::out);
	for(long long i=0;i<tam;i++){
		file<<lista[i]<<" ";
	}
	file.close();
}
//Función para ordenar los valores de la lista aleatoria
//utilizando el algoritmo de ordenamiento Quicksort
void quicksort(long long *lista,long long izq, long long der ){
    long long  i, j, x , aux;
    i = izq;
    j = der;
    x = lista[ (izq + der) /2 ];
        do{
            while( (lista[i] < x) && (j <= der) ){
                i++;
            }
            while( (x < lista[j]) && (j > izq) ){
                j--;
            }
            if( i <= j ){
                aux = lista[i]; lista[i] = lista[j]; lista[j] = aux;
                i++;  j--;
            }
        }while( i <= j );
        if( izq < j )
            quicksort( lista, izq, j );
        if( i < der )
            quicksort( lista, i, der );
}

int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	cout<<"\n\nGenerando archivo de texto plano con valores aleatorios"<<endl;
	quicksort(lista,0,tam-1);
	mostrar(lista,tam);
	cout<<"\nGenerando un nuevo archivo con los valores ordenados ascendentemente"<<endl;
	delete[]lista;

	return 0;
}
