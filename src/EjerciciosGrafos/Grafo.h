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
Nodo *getNodo(char etiqueta){
	
}
void insertNode(char etiqueta,Nodo *&grafo){
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
void insertEdge(Nodo *&grafo,Nodo *&origen,Nodo *&destino,int peso){
	if(getNodo(origen->etiqueta) && getNodo(destino->etiqueta)){
		
	}else if(getNodo(origen->etiqueta)){
		cout<<"\nEl vertice "<<destino->etiqueta<<" no existe en el grafo\n";
	}else if(getNodo(destino->etiqueta)){
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
