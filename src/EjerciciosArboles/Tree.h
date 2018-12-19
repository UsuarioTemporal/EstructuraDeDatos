#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


//La altura de del arbol es la altura de n odo raiz
//La altura de un nodo se cuenta desde la raiz hasta el nodo querido

//DIFERENCIAS ENTRE UN ARBOL ABB Y UN AVL 
// ES QUE UN ARBOL ABB SE CREA PARA IMPLEMENTAR UN
//MEJOR TIEMPO DE ACCESO A LOS DATOS EN LAS OPERACIONES DE 
//BUSQUEDA , ELIMINACION Y DERIVADOS
//eS RECOMENDABLE QUE LA ALTURA DEL ARBOL SEA LA MENOR POSIBLE


//Para eliminar un nodo es necesario saber quien es el padre  (IMPORTANTE)

	typedef struct Nodo{
		int dato;
		Nodo *hijoDere=NULL;
		Nodo *hijoIzqu=NULL;
		
				
		//Es opcional es uno de los metodos
		//Existen muchas formas de crear un arbol
		Nodo *padre=NULL;
	};
	int cantidad=0;
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
			cantidad++;
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
				cout<<"\nDato encontrado : "<<raiz->dato<<endl;
				return true;
			}else if(raiz->dato>dato){
				cout<<"\nPor la izquierda : "<<raiz->hijoIzqu->dato<<endl;
				return busqueda(raiz->hijoIzqu,dato);
			}else{
				cout<<"\nPor la derecha : "<<raiz->hijoDere->dato<<endl;
				return busqueda(raiz->hijoDere,dato);
			}
		}else{
			return false;
		}	
	}
	bool isExist(Nodo *raiz,int dato){
		if(!isEmpty(raiz)){
			if(raiz->dato==dato){
				return true;
			}else if(raiz->dato>dato){
				return isExist(raiz->hijoIzqu,dato);
			}else{
				return isExist(raiz->hijoDere,dato);
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
			if(raiz->dato==raiz->padre->hijoIzqu->dato){
				raiz->padre->hijoIzqu=nuevoNodo;
			}else if(raiz->dato==raiz->padre->hijoDere->dato){
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
		else{ //Nodo hoja
			reemplazar(raiz,NULL);
			destruirNodo(raiz);
		}
		
	}
	
	//Funcion principal
	void eliminar(Nodo *raiz,int dato){
		if(isEmpty(raiz)){
			return ;
		}else if(dato<raiz->dato){
			eliminar(raiz->hijoIzqu,dato);
		}else if(dato> raiz->hijoDere->dato){
			eliminar(raiz->hijoDere,dato);
		}else{
			cantidad--;
			eliminarNodo(raiz);
		}
	}
	
	
	
	int max(int a,int b){
	    return a<b ? b:a;
	}
	int profundidad(Nodo *raiz){
	   if (raiz != NULL){
	      // No Contabilizo los nodos Hoja
	      if ((raiz->hijoDere==NULL) && (raiz->hijoIzqu==NULL))
	         return 0;
	      else
	      // Cada vez que avanzo por un hijo aumento altura
	         return 1 + max(profundidad(raiz->hijoIzqu),profundidad(raiz->hijoDere));
	   }else
	      return 0;
	}

	
	void cantidadDeNodos(Nodo *raiz){
		if(!isEmpty(raiz)){
			cout<<"\nEl arbol tiene o es de tamaño "<<cantidad<<" nodos \n";
		}else{
			cout<<"\nEl arbol esta vacio\n";
		}
	}
	
	//menor valor 
	void encotrarMenor(Nodo *raiz){
		if(!isEmpty(raiz)){
			if(raiz->hijoIzqu!=NULL){
				encotrarMenor(raiz->hijoIzqu);
			}else{
				cout<<raiz->dato;
				return ;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	//mayor valor
	void encotrarMayor(Nodo *raiz){
		if(!isEmpty(raiz)){
			if(raiz->hijoDere!=NULL){
				encotrarMayor(raiz->hijoDere);
			}else{
				cout<<raiz->dato;
				return ;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	
	//recorrer por anchura
    //Analizando la solucion de este algoritmo y buscando informacion por internet la mejor opcion
    //es apoyarnos a otras estructuras para ir guardando la informacion para esto se utiliza un array
    
    string *niveles;
	void imprimirNivelRecursivo(Nodo *raiz, int nivel) {
        if (raiz != NULL) {
        	char buffer[10]; // 10 significa la cantidad maxima que puede soportar un entero
        	
			char *intStr = itoa(raiz->dato,buffer,10);
			string dato=string(intStr);
            niveles[nivel] = dato + " , " + niveles[nivel];
            imprimirNivelRecursivo(raiz->hijoDere, nivel + 1);
            imprimirNivelRecursivo(raiz->hijoIzqu, nivel + 1);
        }
    }
    void imprimirNivel(Nodo *raiz) {
    	int size=profundidad(raiz)+1;
        niveles=new string[size];
        for (int i = 0; i < size; i++) {
            niveles[i]={""};
        }
        imprimirNivelRecursivo(raiz, 0);
        cout<<endl;
        for (int i = 0; i < size; i++) {
            cout<<niveles[i]<<" En nivel: "<<i<<endl;
        }
        cout<<endl;
    }
	
	
	//mostrar solo hojas
	
	void mostrarHojas(Nodo *raiz){
		if(raiz!=NULL){
			if(raiz->hijoDere==NULL && raiz->hijoIzqu==NULL){
				cout<<raiz->dato<<" ";
			}
			mostrarHojas(raiz->hijoIzqu);
			mostrarHojas(raiz->hijoDere);
		}else{
			return;
		}
	}
	
	//mostrar solo padres
	void mostrarPadres(Nodo *raiz){
		if(raiz!=NULL){
			if(raiz->hijoDere!=NULL || raiz->hijoIzqu!=NULL){
				cout<<raiz->dato<<" ";
			}
			mostrarPadres(raiz->hijoIzqu);
			mostrarPadres(raiz->hijoDere);
		}else{
			return;
		}
	}
	
	
	//mostrar nodos de solo los niveles ingresaods
	void mostrarNodoDelNivel(Nodo *raiz,int nivel){
		int size=profundidad(raiz)+1;
        if(nivel>size || nivel<size){
        	cout<<"\nNivel no existe\n";
		}else{
			niveles=new string[size];
	        for (int i = 0; i < size; i++) {
	            niveles[i]={""};
	        }
	        imprimirNivelRecursivo(raiz, 0);
	        cout<<niveles[nivel]<<" En nivel: "<<nivel<<endl;
		}
	}
	
	//mostrar nivel de cierto nodo
	void encontrarNivel(Nodo *raiz, int nivel,int dato) {
        if (raiz != NULL) {
        	if(dato==raiz->dato){
        		cout<<"\nEl dato "<<dato<<" fue encontrado en el nivel "<<nivel<<"\n";
				return;
			}else{
	            encontrarNivel(raiz->hijoDere, nivel + 1,dato);
	            encontrarNivel(raiz->hijoIzqu, nivel + 1,dato);
			}
        	
        }
    }
	void mostrarNivelDe(Nodo *raiz,int dato){
		if(isExist(raiz,dato)){
        	encontrarNivel(raiz, 0,dato);
		}else{
			cout<<"\nAquel nodo no existe \n";
		}
	}
#endif
 
