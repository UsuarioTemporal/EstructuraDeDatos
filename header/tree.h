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
	void show(Nodo *raiz,int contador){
		if(!isEmpty(raiz)){
			show(raiz->hijoDere,contador+1);
			for(int i=0;i<contador;i++){
				cout<<"  ";
			}
			cout<<raiz->dato<<endl;
			show(raiz->hijoIzqu,contador+1);
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
	bool busqueda(Nodo *raiz,int dato){
		if(!isEmpty(raiz)){
			if(raiz->dato==dato){
				return true;
			}else if(raiz->dato>dato){
				return busqueda(raiz->hijoIzqu,dato);
			}else{
				return busqueda(raiz->hijoDere,dato);
			}
		}else{
			return false;
		}	
	}
} 
