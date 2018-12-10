#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
using namespace std;
struct Arista{
	struct Nodo *destino=NULL;
	struct Arista *siguiente=NULL;
	int peso;
};
struct Nodo{
	char etiqueta;
	struct Arista *vertAdyacente=NULL;
	struct Nodo *siguiente=NULL;
	
};
int conteo=0;
bool isEmpty(Nodo *grafo){
	return grafo==NULL;
}
Nodo *getNodo(char etiqueta,Nodo *&grafo){ //funcion que me retorna el nodo buscado
	Nodo *aux=grafo;
	while(aux!=NULL){
		if(aux->etiqueta==etiqueta){
			return aux;
		}
		aux=aux->siguiente;
	}
	return NULL;
}
void insertarNodo(char etiqueta,Nodo *&grafo){
	Nodo *nuevo=new Nodo;
	conteo++;
	nuevo->etiqueta=etiqueta;
	if(isEmpty(grafo)){
		grafo=nuevo;
	}else{
		Nodo *aux=grafo;
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
	}
}
void insertarArista(Nodo *&grafo,Nodo *&origen,Nodo *&destino,int peso){
	if(getNodo(origen->etiqueta,grafo) && getNodo(destino->etiqueta,grafo)){
		Arista *nueva=new Arista;
		nueva->peso=peso;
		Arista *aux=origen->vertAdyacente;
		if(aux==NULL){
			origen->vertAdyacente=nueva;
			nueva->destino=destino;
		}else{
			while(aux->siguiente!=NULL){
				aux=aux->siguiente;
			}
			aux->siguiente=nueva;
			nueva->destino=destino;
		}
	}else if(getNodo(origen->etiqueta,grafo)){
		cout<<"\nEl vertice "<<destino->etiqueta<<" no existe en el grafo\n";
	}else if(getNodo(destino->etiqueta,grafo)){
		cout<<"\nEl vertice "<<origen->etiqueta<<" no existe en el grafo\n";
	}else{
		cout<<"\nLos vertices ingresados no existen\n";
	}
}

int getGradoEntrada(){
	
}
int getGradoSalida(){
	
}
#endif 
