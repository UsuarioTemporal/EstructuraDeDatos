#include<iostream>
#include "Pila.h"
/*Todos los métodos que me piden en el ejercicio estan en Pila.h*/
using namespace std;
Pila *pilaTorreA=new Pila();
Pila *pilaTorreB=new Pila();
Pila *pilaTorreC=new Pila();
int conteo=0;
int factorial(int);
void torresHanoi(int ,char ,char ,char ,Pila *,Pila *,Pila *);
int llenandoPrimeraTorre(int);
int main(){
	int discos;
	cout<<"\nIngrese la cantidad de discos :  ";cin>>discos;
	llenandoPrimeraTorre(discos);
	torresHanoi(discos,'A','B','C',pilaTorreA,pilaTorreB,pilaTorreC);
}

int llenandoPrimeraTorre(int numero){
	pilaTorreA->push(numero);
	if(numero>1){
		return llenandoPrimeraTorre(numero-1);
	}
	return 1;
}
void torresHanoi(int discos,char A,char B,char C,Pila *torreA,Pila *torreB,Pila *torreC){
	if(discos==1){
		int cima=torreA->pop();
		cout<<++conteo<<". Moviendo "<<cima<<" de la pila "<<A<<" hacia la pila "<<C<<endl;
		torreC->push(cima);
	}else{
		torresHanoi(discos-1,A,C,B,torreA,torreC,torreB);
		int cima = torreA->pop();
    	cout<<++conteo<<". Moviendo "<<cima<<" de la pila "<<A<<" hacia la pila "<<C<<endl;
    	torreC->push(cima);
    	torresHanoi(discos-1,B,A,C,torreB,torreA,torreC);
	}
}
