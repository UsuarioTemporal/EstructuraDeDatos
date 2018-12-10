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
		
		
		void eliminarArista(Vertice *origen,Vertice *destino){
			Arista *actual=origen->verticeAdyacente,*anterior;
			bool bandera = false;
			if(actual==NULL){
				cout<<"\nEl vertice  no tiene aristas\n";
			}else if(actual->adyacente==destino){
				origen->verticeAdyacente=actual->siguiente;
				delete(actual);
			}else{
				while(actual->adyacente!=NULL){
					if(actual->adyacente==destino){
						bandera=true;
						anterior->siguiente=actual->siguiente;
						delete(actual);
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
		
		void eliminarVertice(Vertice *vertice){
			Vertice *actual=partida,*anterior;
			Arista *aux;
			while(actual!=NULL){
				aux=actual->verticeAdyacente;
				while(aux!=NULL){
					if(aux->adyacente==vertice){
						eliminarArista(actual,aux->adyacente);
						break;
					}
					aux=aux->siguiente;
				}
				actual=actual->siguiente;
			}
			actual=partida;
			if(partida==vertice){
				partida=partida->siguiente;
				delete(actual);
			}else{
				while(actual!=vertice){
					anterior=actual;
					actual=actual->siguiente;
				}
				anterior->siguiente=actual->siguiente;
				delete(actual);
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
		void deleteArista(){
			char inicio,final;
			cin>>inicio>>final;
			eliminarArista(getVertice(inicio),getVertice(final));
		}
		void deleteVertice(){
			char vetice ;
			cin>>vetice;
			eliminarVertice(getVertice(vetice));
		}
		
};

#endif
