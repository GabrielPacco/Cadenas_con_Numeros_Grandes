//5. Implemente una función que reciba dos cadenas a y b; dicha función debe concatenar la cadena a a la cadena b.
//(asuma que la cadena b tiene el tamaño suficiente para contener los elementos de a).
#include <iostream>
using namespace std;

void concatenar(char *strA,char *strB){
	int tam=0;
	for(; *(strB+tam)!='\0';tam++);
	int ind=0;
	while(*(strA+ind)!='\0'){
		*(strB+tam+ind)=*(strA+ind);
		ind++;
	}
	*(strB+tam+ind)='\0';
}
int main(){
	char strA[100]="Hola amigo";
	char strB[100]="Me llamo Gabriel ";
	cout<<"\ncadena a: "<<strA;
	cout<<"\ncadena b: "<<strB;
	concatenar(strA,strB);

	cout<<"\n\nB: "<<strB<<endl;

	return 0;
}
