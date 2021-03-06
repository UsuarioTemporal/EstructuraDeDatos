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
Nodo *getNodo(char etiqueta,Nodo *grafo){ //funcion que me retorna el nodo buscado
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
void insertarArista(Nodo *grafo,Nodo *origen,Nodo *destino,int peso){
	if(getNodo(origen->etiqueta,grafo)!=NULL && getNodo(destino->etiqueta,grafo)!=NULL){
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
	}else if(getNodo(origen->etiqueta,grafo)==NULL){
		cout<<"\nEl vertice "<<destino->etiqueta<<" no existe en el grafo\n";
	}else if(getNodo(destino->etiqueta,grafo)==NULL){
		cout<<"\nEl vertice "<<destino->etiqueta<<" no existe en el grafo\n";
	}else{
		cout<<"\nLos vertices ingresados no existen\n";
	}
}

int getGradoEntrada(Nodo *vertice,Nodo *grafo){
	if(getNodo(vertice->etiqueta,grafo)){
		int grado=0;
		Nodo *verticeAux=grafo;
		Arista *aristaAux;
		while(verticeAux!=NULL){
			aristaAux=vertice->vertAdyacente;
			while(aristaAux!=NULL){
				if(aristaAux->destino->etiqueta==vertice->etiqueta){
					grado++;
				}
				aristaAux=aristaAux->siguiente;
			}
			verticeAux=verticeAux->siguiente;
		}
		return grado;
	}
	return 0;
}
int getGradoSalida(Nodo *vertice,Nodo *grafo){
	if(getNodo(vertice->etiqueta,grafo)){
		int grado=0;
		if(vertice->vertAdyacente!=NULL){
			grado=1;
		}
		Arista *arisAux=vertice->vertAdyacente;
		while(arisAux!=NULL){
			grado++;
			arisAux=arisAux->siguiente;
		}
		return grado;
	}
	return 0;
}
void listaAdyacencia(Nodo *grafo){
	if(!isEmpty(grafo)){
		Nodo *verticeAux=grafo;
		Arista *arisAux;
		while(verticeAux!=NULL){
			cout<<verticeAux->etiqueta<<"-->";
			arisAux=verticeAux->vertAdyacente;
			while(arisAux!=NULL){
				cout<<arisAux->destino->etiqueta<<":"<<arisAux->peso<<"-->";
				arisAux=arisAux->siguiente;
			}
			verticeAux=verticeAux->siguiente;
			cout<<"\n";
		}
	}else{
		cout<<"\nGrafo vacio\n";
	}
}
void existeCamino(Nodo *origen,Nodo *destino){
	Arista *actual=origen->vertAdyacente,*anterior;
	bool bandera = false;
	if(actual==NULL){
		cout<<"\nEl vertice  no tiene aristas\n";
	}else if(actual->destino==destino){
		origen->vertAdyacente=actual->siguiente;
		cout<<"\nSi tiene camino\n";
	}else{
		while(actual->destino!=NULL){
			if(actual->destino==destino){
				bandera=true;
				anterior->siguiente=actual->siguiente;
				cout<<"\nSi tiene camino\n";
				break;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(!bandera){
			cout<<"\nLos vertices ingresados no estan conectados\n";
		}
	}
}

void insertarAris(Nodo *grafo){
	char inicio;
	cout<<"\nIngrese la etiqueta inicio : ";
	cin>>inicio;
	cout<<"\nIngrese la etiqueta destino : ";
	char destino;
	cin>>destino;
	cout<<"\nIngrese el peso  : ";
	int peso;
	cin>>peso;
	insertarArista(grafo,getNodo(inicio,grafo),getNodo(destino,grafo),peso);
}
#endif 
