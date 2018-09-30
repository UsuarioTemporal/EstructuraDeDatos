#include<iostream>
#include<stdlib.h>
using namespace std;
namespace Stack{
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL;	
	};
	void push(Nodo *&cima,int dato){
		Nodo *nuevo=new Nodo();
		nuevo->dato=dato;
		nuevo->siguiente=cima;
		cima=nuevo;
	}
	bool isEmpty(Nodo *cima){
		return cima==NULL;
	}
	
	void pop(Nodo *&cima){
		if(!isEmpty(cima)){
			Nodo *temporal=new Nodo;
			temporal=cima;
			int elemento=temporal->dato;
			cima=cima->siguiente;
			cout<<"\nElemento eliminado "<<elemento<<endl;
			delete temporal;
			temporal=NULL;
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	
	void empty(Nodo *&cima){
		cout<<"\n";
		if(!isEmpty(cima)){
			while(!isEmpty(cima)){
				pop(cima);
			}
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	
	void show(Nodo *cima){
		if(!isEmpty(cima)){
			Nodo *recorrer=cima;
			while(recorrer!=NULL){
				cout<<" | "<<recorrer->dato<<" | "<<endl;
				recorrer=recorrer->siguiente;
			}
			cout<<endl;
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	
}
