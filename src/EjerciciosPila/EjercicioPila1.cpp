#include<iostream>
#include "Pila.h"
#include<stdlib.h>
#include<time.h>
/*Todos los métodos que me piden en el ejercicio estan en Pila.h*/
using namespace std;
Pila *original=new Pila();
Pila *auxiliar=new Pila();
int main(){
	srand(time(NULL));
	int numero;
	/*Rellenare de numeros aleatorios*/
	for(int i=0;i<10;i++){
		original->push(0+rand()%(9+1));
	}
	cout<<"\nPila original\n";
	original->show();
	cout<<"\nIngrese el numero a eliminar de la pila : ";
	cin>>numero;
	original->eliminadoBuscado(auxiliar,numero);
	cout<<"\nPila original\n";
	original->show();
	cout<<"\nPila auxiliar\n";
	auxiliar->show();
}
