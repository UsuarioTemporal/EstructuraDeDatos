#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
namespace CircleSimpleList{
	struct Nodo{
		int dato;
		Nodo *siguiente=this;
	};
	int conteo=0;
	bool isEmpty(Nodo *ultimo){
		return ultimo==NULL;
	}
	void contar(Nodo *ultimo){
		if(isEmpty(ultimo)){
			cout<<"\nVacio\n";
		}else{
			cout<<"\nNumero de elementos : "<<conteo<<endl;
		}
	}
	/// :| 
	void insertToEnd(Nodo *&ultimo,int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		conteo++;
		if(ultimo!=NULL){
			nuevo->siguiente=ultimo->siguiente ;
			ultimo->siguiente=nuevo;
		}
		ultimo=nuevo;
	}	
	void insertToStart(Nodo *&ultimo,int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		conteo++;
		if(isEmpty(ultimo)){
			ultimo=nuevo;
		}else{
			Nodo *inicio=new Nodo;
			inicio=ultimo->siguiente;
			ultimo->siguiente=nuevo;
			nuevo->siguiente=inicio;
		}
	}
	void deleteToStart(Nodo *&ultimo){
		if(!isEmpty(ultimo)){
			conteo--;
			if(ultimo==ultimo->siguiente){
				ultimo=NULL;
			}else{
				Nodo *inicio=new Nodo;
				inicio=ultimo->siguiente;
				ultimo->siguiente=inicio->siguiente;
				inicio=NULL;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	void deleteToEnd(Nodo *&ultimo){
		if(!isEmpty(ultimo)){
			conteo--;
			if(ultimo==ultimo->siguiente){
				ultimo=NULL;
			}else{
				Nodo *recorrer=new Nodo;
				Nodo *posterior=new Nodo;
				recorrer=ultimo->siguiente;
				posterior=recorrer->siguiente;
				while(recorrer->siguiente !=ultimo){
					recorrer=recorrer->siguiente;
					posterior=posterior->siguiente;
				}
				recorrer->siguiente =ultimo->siguiente;
				ultimo=recorrer;
				posterior=NULL;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void insertToEndOrToStartOf(Nodo *&ultimo,int datoFijo,int opcion,int dato){
		if(!isEmpty(ultimo)){
			if(find(ultimo,datoFijo)){
				conteo++;
				Nodo *recorrer=new Nodo;
				Nodo *nuevo=new Nodo;
				if(opcion==1){ //antes
					if(ultimo->siguiente->dato==datoFijo){
						insertToStart(ultimo,dato);
					}else{
						nuevo->dato=dato;
						recorrer=ultimo->siguiente;
						while(recorrer->siguiente->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->siguiente=recorrer->siguiente;
						recorrer->siguiente =nuevo;
					}
				}else{ //despues
					if(ultimo->dato==datoFijo){
						insertToEnd(ultimo,dato);
					}else{
						nuevo->dato=dato;
						recorrer=ultimo->siguiente;
						while(recorrer->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->siguiente=recorrer->siguiente;
						recorrer->siguiente=nuevo;
					}
				}
			}else{
				cout<<"\nNo existe el dato fijo\n";
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	
	bool find(Nodo *ultimo,int dato){
		Nodo *actual=new Nodo;
		actual=ultimo;
		bool encontrado=false;
		while(actual->siguiente!=ultimo && !encontrado){
			encontrado=(dato==actual->dato);
			if(!encontrado){
				actual=actual->siguiente;
			}
		}
		return actual->dato==dato;
	}
	
	void deleteEspecific(Nodo *&ultimo,int dato){
		if(!isEmpty(ultimo)){
			if(find(ultimo,dato)){
				conteo--;
				Nodo *actual=new Nodo;
				if(ultimo->siguiente==ultimo){
					ultimo=NULL;
				}else{
					Nodo *anterior=new Nodo;
					anterior=ultimo;
					actual=ultimo->siguiente;
					while(actual->dato!=dato){
						actual=actual->siguiente;
						anterior=anterior->siguiente;
					}
					if(actual==ultimo){
						ultimo=anterior;
						ultimo->siguiente=actual->siguiente;				
					}else{
						anterior->siguiente=actual->siguiente;
					}
				}
				actual=NULL;
			}else{
				cout<<"\nNo existe\n";
			}
		}else{
			cout<<"\nVacio\n" ;
		}
	}
	
	void show(Nodo *ultimo){
		Nodo *recorrer=new Nodo;
		recorrer=ultimo->siguiente;
		string cadena="-->";
		do{
			char buffer[10];
			char *str=itoa(recorrer->dato,buffer,10);
			string dato=string(str);
			cadena+="["+dato+"]-->";
			recorrer=recorrer->siguiente;
			
		}while(recorrer!=ultimo->siguiente);
		cout<<"\n"<<cadena<<"\n";
	}
}
