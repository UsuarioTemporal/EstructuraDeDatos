#include<iostream>
using namespace std;
//Para eliminar un nodo es necesario saber quien es el padre  (IMPORTANTE)
namespace Tree{
	typedef struct Nodo{
		int dato;
		Nodo *hijoDere=NULL;
		Nodo *hijoIzqu=NULL;
		
		//Es opcional es uno de los metodos
		//Existen muchas formas de crear un arbol
		Nodo *padre=NULL;
	};
	Nodo *createNodo(int dato,Nodo *padre){
		Nodo *nuevoNodo=new Nodo;
		nuevoNodo->dato=dato;
		nuevoNodo->padre=padre;
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
	void insertar(Nodo *&raiz,int dato,Nodo *padre){
		if(isEmpty(raiz)){
			Nodo *nuevo=createNodo(dato,padre);
			raiz=nuevo;
		}else{
			int valorRaiz=raiz->dato;
			if(dato<valorRaiz){
				insertar(raiz->hijoIzqu,dato,raiz);
			}else{
				insertar(raiz->hijoDere,dato,raiz);
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
	
	void preOrden(Nodo *raiz){
		if(isEmpty(raiz)){
			return ;
		}else{
			cout<<raiz->dato<<" ";
			preOrden(raiz->hijoIzqu);
			preOrden(raiz->hijoDere);	
		}
	}
	
	void inOrden(Nodo *raiz){
		if(isEmpty(raiz)){
			return ;
		}else{
			inOrden(raiz->hijoIzqu);
			cout<<raiz->dato<<" ";
			inOrden(raiz->hijoDere);

		}
	}
	
	void posOrden(Nodo *raiz){
		if(isEmpty(raiz)){
			return ;
		}else{
			posOrden(raiz->hijoDere);
			cout<<raiz->dato<<" ";
			posOrden(raiz->hijoIzqu);
		}
	}
	
	void eliminar(Nodo *raiz,int dato){
		if(isEmpty(raiz)){
			return ;
		}else if(dato<raiz->dato){
			eliminar(raiz->hijoIzqu,dato);
		}else if(dato>raiz->hijoDere){
			eliminar(raiz->hijoDere,dato);
		}else{
			eliminarNodo(raiz);
		}
	}
	
	void eliminarNodo(Nodo *&raiz){
		//Borrar Un Nodo siempre y cuando tenga dos subarboles hijos
		
	}
} 
