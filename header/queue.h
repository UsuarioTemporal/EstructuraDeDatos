#include<iostream>
#include<stdlib.h>
using namespace std;
namespace Queue{
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL;
	};
	
	void push(Nodo *&primero,Nodo *&ultimo,int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		if(primero==NULL){
			primero=nuevo;
		}else{
			ultimo->siguiente=nuevo;
		}
		ultimo=nuevo;
		
	}
	bool isEmpty(Nodo *primero){
		return primero==NULL;
	}
	
	void pop(Nodo *&primero,Nodo *&ultimo){
		if(!isEmpty(primero)){
			Nodo *temporal=new Nodo;
			temporal=primero;
			int elemento=temporal->dato;
			if(ultimo==primero){
				delete ultimo;
				delete primero;
				ultimo=primero=NULL;
			}else{
				primero=primero->siguiente;
			}
			delete temporal;
			temporal=NULL;
		}else{
			cout<<"\nVacio "<<endl;
		}
	}
	
	void show(Nodo *primero){
		cout<<"\n";
		Nodo *recorrer=new Nodo;
		recorrer =primero;
		while(recorrer!=NULL){
			cout<<recorrer->dato;
			if(recorrer->siguiente!=NULL){
				cout<<" -- ";
			}
			recorrer=recorrer->siguiente;
		}
		cout<<"\n";
	}
	
}
