#include<iostream>
using namespace std;
namespace Tree{
	typedef struct Nodo{
		int dato;
		Nodo *hijoDere=NULL;
		Nodo *hijoIzqu=NULL;
	};
	Nodo *createNodo(int dato){
		Nodo *nuevoNodo=new Nodo;
		nuevoNodo->dato=dato;
		return nuevoNodo;
	}
	bool isEmpty(Nodo *raiz){
		return raiz==NULL;
	}
	void show(Nodo *raiz){
		if(!isEmpty(raiz)){
			
		}else{
			return ;
		}
	}
	void insertar(Nodo *&raiz,int dato){
		if(isEmpty(raiz)){
			Nodo *nuevo=createNodo(dato);
			raiz=nuevo;
		}else{
			int valorRaiz=raiz->dato;
			if(dato<valorRaiz){
				insertar(raiz->hijoIzqu,dato);
			}else{
				insertar(raiz->hijoDere,dato);
			}
		}
	}
} 
