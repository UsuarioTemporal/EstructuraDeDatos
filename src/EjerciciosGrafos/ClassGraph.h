#ifndef CLASSGRAPH__H
#define CLASSGRAPH__H
#include<iostream>
using namespace std;

class Vertice{ //nodo
	public:
		Vertice *siguiente =NULL;
		Arista *verticeAdyacente =NULL; //conexion
		char etiqueta ;
		friend class Grafo;
};
class Arista{
	public :
		Arista *siguiente = NULL;
		Vertice *adyacente =NULL;
		int peso;
		friend class Grafo;
};
class Grafo{
	private :
		int conteo=0;
		void insertEdge(Vertice *origen,Vertice *destino,int peso){
			
		}
	public :
		Vertice *partida;
		Grafo(){
			partida=NULL;
		}
		bool isEmpty(){
			return partida==NULL;
		}
		Vertice *getVertice(char etiqueta){
			Vertice *aux=partida;
			while(aux!=NULL){
				if(aux->etiqueta==etiqueta){
					return aux;
				}
				aux=aux->siguiente;
			}
			return NULL;
		}
		void insertarVertice(char etiqueta){
			Vertice *nuevo=new Vertice;
			nuevo->etiqueta=etiqueta;
			conteo++;
			if(isEmpty()){
				partida=nuevo;
			}
		}
		
		
};

#endif
