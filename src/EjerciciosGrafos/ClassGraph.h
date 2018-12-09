#ifndef CLASSGRAPH__H
#define CLASSGRAPH__H
#include<iostream>
using namespace std;
class Arista; // prototipo
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
		Vertice *partida;
		int conteo=0;
		void insertEdge(Vertice *origen,Vertice *destino,int peso){
			Arista *nueva=new Arista;
			nueva->peso=peso;
			Arista *aux=origen->verticeAdyacente;
			if(aux==NULL){
				origen->verticeAdyacente=nueva;
				nueva->adyacente=destino;
			}else{
				while(aux->siguiente!=NULL){
					aux=aux->siguiente;
				}
				aux->siguiente=nueva;
				nueva->adyacente=destino;
			}
		}
	public :
		
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
			}else{
				Vertice *aux=partida;
				while(aux->siguiente!=NULL){
					aux=aux->siguiente;
				}
				aux->siguiente=nuevo;
				
			}
		}
		
		void listaAdyacencia(){
			Vertice *verticeAux=partida;
			Arista *arisAux;
			while(verticeAux!=NULL){
				cout<<verticeAux->etiqueta<<"-->";
				arisAux=verticeAux->verticeAdyacente;
				while(arisAux!=NULL){
					cout<<arisAux->adyacente->etiqueta<<"-->";
					arisAux=arisAux->siguiente;
				}
				verticeAux=verticeAux->siguiente;
				cout<<"\n";
			}
		}
		
		void anular(){
			Vertice *aux;
			while(partida!=NULL){
				aux=partida;
				partida=partida->siguiente;
				delete(aux);
			}
		}
		
		void insertArtista(){
			char inicio;
			char final ;
			cin>>inicio;
			cin>>final;
			int peso;
			cin>>peso;
			insertEdge(getVertice(inicio),getVertice(final),peso);			
		}
};

#endif
