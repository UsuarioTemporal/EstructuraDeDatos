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
	void destruirNodo(Nodo *nodo){
		nodo->hijoIzqu=NULL;
		nodo->hijoDere=NULL;
		delete nodo;
	}
	//Esta funcion te retornara el nodo mas ala izquierda
	Nodo *encontrarNodoIzquierda(Nodo *nodoEncontrar){
		if(isEmpty(nodoEncontrar)){
			return NULL;
		}
		if(nodoEncontrar->hijoIzqu!=NULL){
			return encontrarNodoIzquierda(nodoEncontrar->hijoIzqu);
		}else{
			return nodoEncontrar;
		}
	}
	
	void reemplazar(Nodo *raiz,Nodo *nuevoNodo){
		if(raiz->padre!=NULL){
			//raiz->padre hay que asignarle su nuevo hijo
			if(raiz->dato=raiz->padre->hijoIzqu->dato){
				raiz->padre->hijoIzqu=nuevoNodo;
			}else if(raiz->dato=raiz->padre->hijoDere->dato){
				raiz->padre->hijoDere=nuevoNodo;
			}
		}
		if(nuevoNodo!=NULL){ //si el nuevo nodo existe
			//Procedemos a asignarle su nuevo padre
			nuevoNodo->padre=raiz->padre;
		}
	}
	void eliminarNodo(Nodo *&raiz){
		//Borrar Un Nodo siempre y cuando tenga dos subarboles hijos
		//Luego se hara que se ira a la derecha , luego te iras
		//a la mas izquierda posible
		if(raiz->hijoDere!=NULL && raiz->hijoIzqu!=NULL){
			Nodo *menor=encontrarNodoIzquierda(raiz->hijoDere);
			raiz->dato=menor->dato;
			eliminarNodo(menor);
		}
		
		
		//Imaginemos que solo tenga un solo hijo 
		//Puede ser derecho o izquierdo pero solo uno 
		else if(raiz->hijoIzqu!=NULL){
			//El hijo toma el lugar del padre
			  reemplazar(raiz,raiz->hijoIzqu);
			  destruirNodo(raiz);
		}
		
		else if(raiz->hijoDere!=NULL){
			//El hijo toma el lugar del padre
			  reemplazar(raiz,raiz->hijoDere);
			  destruirNodo(raiz);
		}
		
		
	}
} 
