#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipos

void push(Nodo *&,int);
void show(Nodo *);
bool isEmpty(Nodo *);
void pop(Nodo *&);
void empty(Nodo *&);

//

Nodo *cima=NULL;
int main(){
	push(cima,3);
	push(cima,4);
	push(cima,4);
	push(cima,1);
	push(cima,2);
	push(cima,6);
	push(cima,7);
	push(cima,8);
	push(cima,9);
	push(cima,0);
	pop(cima);
	show(cima);
	empty(cima);
	show(cima);
	return 0; 
}
bool isEmpty(Nodo *cima){
	return cima==NULL;
}
void push(Nodo *&cima,int dato){
	Nodo *nuevo=new Nodo();
	nuevo->dato=dato;
	nuevo->siguiente=cima;
	cima=nuevo;
	
}

void show(Nodo *cima){
	cout<<"\n";
	if(!isEmpty(cima)){
		Nodo *recorrer=cima;
		while(recorrer!=NULL){
			cout<<"| "<<recorrer->dato<<" | "<<endl;
			recorrer=recorrer->siguiente;
		}
		cout<<"-----";
		delete recorrer;
	}else{
		cout<<"\nVacio";
	}
}

void pop(Nodo *&cima){
	if(!isEmpty(cima)){
		Nodo *temporal=new Nodo;
		temporal=cima;
		int n=temporal->dato;
		cima=cima->siguiente;
		cout<<"\nElemento sacado : "<<n;
		delete temporal;
	}else{
		cout<<"\nVacio ";
	}
}

void empty(Nodo *&cima){
	if(!isEmpty(cima)){
		while(!isEmpty(cima)){
			pop(cima);
		}
	}else{
		cout<<"\nVacio";
	}
}


