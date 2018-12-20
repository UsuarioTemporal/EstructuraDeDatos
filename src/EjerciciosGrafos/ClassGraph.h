#ifndef CLASSGRAPH__H
#define CLASSGRAPH__H
#include<iostream>
#include<list>
#include<queue>
#include<stack>
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
		
		int getGradoEntrada(Vertice *vertice){
			int grad=0;
			Vertice *verticeAux=partida;
			Arista *arisAux;
			while(verticeAux!=NULL){
				arisAux=verticeAux->verticeAdyacente;
				while(arisAux!=NULL){
					if(arisAux->adyacente->etiqueta==vertice->etiqueta){
						grad++;
					}
					arisAux=arisAux->siguiente;
				}
				verticeAux=verticeAux->siguiente;
			}
			return grad;	
		}
		int getGradoSalida(Vertice *vertice){
			int grad=0;
			if(vertice->verticeAdyacente!=NULL){
				grad=1;
			}
			Arista *arisAux=vertice->verticeAdyacente;
			while(arisAux!=NULL){
				grad++;
				arisAux=arisAux->siguiente;
			}
			return grad;
		}
		void existeCamino(Vertice *origen,Vertice *destino){
			Arista *actual=origen->verticeAdyacente;
			bool bandera = false;
			if(actual==NULL){
				cout<<"\nEl vertice  no tiene aristas\n";
			}else if(actual->adyacente->etiqueta==destino->etiqueta){
				cout<<"\nSi tiene camino\n";
			}else{
				Arista *temporal=actual;
				while(actual->adyacente!=NULL){
					if(actual->adyacente->etiqueta==destino->etiqueta){
						bandera=true;
						cout<<"\nSi tiene camino\n";
						break;
					}else if(actual->adyacente->verticeAdyacente!=NULL){
						actual=actual->adyacente->verticeAdyacente;
					}else{
						actual=temporal->siguiente;
						if(actual==NULL){
							break;
						}
					}
				}
				if(!bandera){
					cout<<"\nLos vertices ingresados no estan conectados\n";
				}
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
					cout<<arisAux->adyacente->etiqueta<<":"<<arisAux->peso<<"-->";
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
			cout<<"\nInsertar origen : ";
			cin>>inicio;
			cout<<"Insertar destino : ";
			cin>>final;
			int peso;
			cout<<"Insertar peso : ";
			cin>>peso;
			Vertice *origen=getVertice(inicio);
			Vertice *destino=getVertice(final);
			if(origen!=NULL && destino!=NULL){
				
				insertEdge(getVertice(inicio),getVertice(final),peso);			
			}else{
				cout<<"\nLos vertices ingresados no existen\n";
			}
		}
		void deleteArista(){
			char inicio,final;
			cout<<"\nOrigen : ";
			cin>>inicio;
			cout<<"Deatino : ";
			cin>>final;
			Vertice *origen = getVertice(inicio);
			Vertice *destino = getVertice(final);
			if(origen!=NULL && destino!=NULL){
				eliminarArista(origen,destino);
			}else{
				cout<<"\nNo existen Nodos";
			}
			
		}
		void deleteVertice(){
			char vetice ;
			cin>>vetice;
			Vertice *ver=getVertice(vetice);
			if(ver!=NULL){
				
				eliminarVertice(ver);
			}else{
				cout<<"\nNo existe vertice\n";
			}
		}
		void recorridoAnchura(Vertice *origen){
			bool bandera,bandera2;
			Vertice *actual;
			queue<Vertice*> cola;
			list<Vertice*> lista;
			list<Vertice*>::iterator next;
			cola.push(origen);
			while(!cola.empty()){
				bandera=false;
				actual=cola.front();
				cola.pop();
				for(next=lista.begin();next!=lista.end();next++){
					if(*next==actual){
						bandera=true;
					}
				}
				if(!bandera){
					cout<<actual->etiqueta<<", ";
					lista.push_back(actual);
					Arista *aux=actual->verticeAdyacente;
					while(aux!=NULL){
						bandera2=false;
						for(next=lista.begin();next!=lista.end();next++){
							if(aux->adyacente==*next){
								bandera2=true;
							}
						}
						if(!bandera2){
							cola.push(aux->adyacente);
						}
						aux=aux->siguiente;
					}
				}
			}
		}
		void recorridoProfundidad(Vertice *origen){
			Vertice *actual;
			stack<Vertice*> pila;
			list<Vertice*> lista;
			bool bandera,bandera2;
			list<Vertice*>::iterator next;
			pila.push(origen);
			while(!pila.empty()){
				bandera=false;
				actual=pila.top();
				pila.pop();
				for(next=lista.begin();next!=lista.end();next++){
					if(*next==actual){
						bandera=true;
					}
				}
				if(!bandera){
					
					cout<<actual->etiqueta<<",";
					lista.push_back(actual);
					Arista *aux;
					aux=actual->verticeAdyacente;
					while(aux!=NULL){
						bandera2=false;
						for(next=lista.begin();next!=lista.end();next++){
							if(*next==aux->adyacente){
								bandera2=true;
							}
						}
						if(!bandera2){
							pila.push(aux->adyacente);
						}
						aux=aux->siguiente;
					}
				}
			}
		}
		
		void caminoEntre(char inicio,char final){
			Vertice *origen = getVertice(inicio);
			Vertice *destino=getVertice(final);
			if(origen!=NULL && destino!=NULL){
				existeCamino(origen,destino);
			}else{
				cout<<"\nNo existen los vertices ingresados\n";
			}
		}
		
		void getGrado(int grado,char etiqueta){
			Vertice *vertice = getVertice(etiqueta);
			if(vertice!=NULL){
				if(grado==0){ //grado general
				cout<<"El grado en general de "<<vertice->etiqueta<<" es "<<(getGradoEntrada(vertice)+getGradoSalida(vertice))<<endl;
				}else if(grado==1){//grado de entrada
					cout<<"El grado de entrada de "<<vertice->etiqueta<<" es "<<getGradoEntrada(vertice)<<endl;
				}else{//grado de salida
					cout<<"El grado de Salida de "<<vertice->etiqueta<<" es "<<getGradoSalida(vertice)<<endl;
				}
			}else{
				cout<<"\nLa etiqueta no existe\n";
			}
		}
};

#endif
