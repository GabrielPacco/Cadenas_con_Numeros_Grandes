//4. Implemente una funci�n que reciba una cadena y retorne su tama�o. (Iterativa y recursiva)
#include <bits/stdc++.h>
using namespace std;

/* Funci�n para calcular la longitud con Recursivdidad*/
int tam_Recursivo(char* str)
{
    // si llegamos al final de la cadena
    if (*str == '\0')
        return 0;
    else
        return 1 + tam_Recursivo(str + 1);
}
/* Funci�n para calcular la longitud con Iteraciones*/
int tam_Iterando(char* str){
    int contador;
    while(str[contador] != '\0'){
        contador++;
    }

    return contador;
 }
int main()
{
    char str[] = "Hola amigo estamos descubriendo la ciencia ";
    cout << "\nLongitud_con_Recursividad: "<<tam_Recursivo(str);

    cout<<"\n\nTamanio: "<<tam_Iterando(str);
    cout<<"\n";
    return 0;
}
