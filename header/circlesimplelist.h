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
	
	bool isEmpty(Nodo *ultimo){
		return ultimo==NULL;
	}
	
	void insert(Nodo *&ultimo,int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		if(ultimo!=NULL){
			nuevo->siguiente=ultimo->siguiente ;
			ultimo->siguiente=nuevo;
			
		}
		ultimo=nuevo;
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
				Nodo *actual=new Nodo;
				if(ultimo->siguiente==ultimo){
					delete ultimo;
				}else{
					Nodo *anterior=ultimo;
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
				delete actual;
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
