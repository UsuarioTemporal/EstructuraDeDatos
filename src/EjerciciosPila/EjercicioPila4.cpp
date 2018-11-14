#include<iostream>
#include "Pila.h"
/*Todos los métodos que me piden en el ejercicio estan en Pila.h*/
using namespace std;
int factorial(int);
Pila pilaFactorial=Pila();
int main(){
	int numero;
	cout<<"\nIngrese el numero de factoriales que agregaran secuencialmente: ";cin>>numero;
	factorial(numero);
	pilaFactorial.show();
	// si se ingresa 5 entonces debe mostrar lo siguiente
	/*
		5!
		4!
		3!
		2!
		1!
	*/
}
int factorial(int numero){
	if(numero==0){
		return 1;
	}
	int recursivo=factorial(numero-1)*numero;
	pilaFactorial.push(recursivo);
	return recursivo;
}
