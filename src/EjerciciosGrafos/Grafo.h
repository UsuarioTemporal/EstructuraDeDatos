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

void insertNode(Nodo *&grafo){
	Nodo *nuevo=new Nodo;
	conteo++;
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
void insertEdge(Nodo *origen,Nodo *destino,int peso){
	Arista *nuevo=new Arista;
	nuevo->peso=peso;
	Arista *aux=origen->vertAdyacente;
	if(aux==NULL){
		origen->vertAdyacente=nuevo;
		nuevo->destino=destino
	}else{
		
	}
}

#endif 
