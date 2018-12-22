#ifndef TREE_H
#define TREE_H
#include "Cliente.h"
#include "Nodo.h"
class Tree{
	private :
		
		Nodo<Cliente> *raiz;
		Nodo<Cliente> *getNodo(Cliente *cliente,Nodo<Cliente> *padre){
			Nodo<Cliente> *nuevo=new Nodo<Cliente>(cliente);
			nuevo->padre=padre;
			return nuevo;
		}
		
		void insertPrivado(Nodo<Cliente> *&raizPrivado,Cliente *cliente,Nodo<Cliente> *padre){
			if(raizPrivado!=NULL){
				if(cliente->getID()<raizPrivado->getDato()->getID()){
					insertPrivado(raizPrivado->hijoIzquierdo,cliente,raizPrivado);
				}else{
					insertPrivado(raizPrivado->hijoDerecho,cliente,raizPrivado);		
				}
			}else{
				Nodo<Cliente> *nuevo=getNodo(cliente,padre);
				raizPrivado=nuevo;
			}
		}
		
		void inOrdenPrivado(Nodo<Cliente> *raizPrivado){
			if(raizPrivado==NULL){
				return ;
			}else{
				inOrdenPrivado(raizPrivado->hijoIzquierdo);
				raizPrivado->getDato()->toString();
				inOrdenPrivado(raizPrivado->hijoDerecho);
			}
		}
		void destruir(Nodo<Cliente> *nodo){
			nodo->hijoDerecho=nodo->hijoIzquierdo=NULL;
			delete nodo;
		}
		void reemplazar(Nodo<Cliente> *raizPrivado,Nodo<Cliente> *nuevoNodo){
			if(raizPrivado->padre!=NULL){
				//raizPrivado->padre hay que asignarle su nuevo hijo
				if(raizPrivado->getDato()->getID()==raizPrivado->padre->hijoDerecho->getDato()->getID()){
					raizPrivado->padre->hijoDerecho=nuevoNodo;
				}else if(raizPrivado->getDato()->getID()==raizPrivado->padre->hijoIzquierdo->getDato()->getID()){
					raizPrivado->padre->hijoIzquierdo=nuevoNodo;
				}
			}
			if(nuevoNodo!=NULL){
				nuevoNodo->padre=raizPrivado->padre;
			}
		}
		Nodo<Cliente> *izquierdaPosible(Nodo<Cliente> *raizPrivado){
			if(raizPrivado==NULL){
				return NULL;
			}
			if(raizPrivado->hijoIzquierdo!=NULL){
				izquierdaPosible(raizPrivado->hijoIzquierdo);
			}else{
				return raizPrivado;
			}
		}
		void eliminarNodo(Nodo<Cliente> *raizPrivado){
			if(raizPrivado->hijoDerecho!=NULL && raizPrivado->hijoIzquierdo!=NULL){
				Nodo<Cliente> *menor=izquierdaPosible(raizPrivado->hijoDerecho);
				raizPrivado->setDato(menor->getDato());
				eliminarNodo(menor);
			}else if(raizPrivado->hijoIzquierdo!=NULL){
				//El hijo toma el lugar del padre
				reemplazar(raizPrivado,raizPrivado->hijoIzquierdo);
				destruir(raizPrivado);
				
			}else if(raizPrivado->hijoDerecho!=NULL){
				//El hijo toma el lugar del padre
				reemplazar(raizPrivado,raizPrivado->hijoDerecho);
				destruir(raizPrivado);
			}else{
				reemplazar(raizPrivado,NULL);
				destruir(raizPrivado);
			}
		}
		void eliminar(Nodo<Cliente> *raizPrivado,Cliente *cliente){
			if(cliente->getID()>raizPrivado->getDato()->getID()){
				eliminar(raizPrivado->hijoDerecho,cliente);
			}else if (cliente->getID()<raizPrivado->getDato()->getID()){
				eliminar(raizPrivado->hijoIzquierdo,cliente);
			}else{
				eliminarNodo(raizPrivado);
			}
		}
		
		Nodo<Cliente> *getNodoBusquedaBinaria(Nodo<Cliente> *raizPrivado,int id){
			if(raizPrivado->getDato()->getID()==id){
				return raizPrivado;
			}else if(raizPrivado->getDato()->getID()>id){
				return getNodoBusquedaBinaria(raizPrivado->hijoIzquierdo,id);
			}else{
				return getNodoBusquedaBinaria(raizPrivado->hijoDerecho,id);
			}
		}
		int suma=0;
		void gastosTotales(Nodo<Cliente> *raizPrivado){
			if(raizPrivado!=NULL){
				gastosTotales(raizPrivado->hijoIzquierdo);
				suma+=raizPrivado->getDato()->getGasto();
				gastosTotales(raizPrivado->hijoDerecho);
			}
		}
		
	public :
		int conteo;
		Tree(){
			conteo=0;
			raiz=NULL;
		}
		bool isEmpty(){
			return raiz==NULL;
		}
		
		void insert(Cliente *cliente,Nodo<Cliente> *padre){
			conteo++;
			insertPrivado(raiz,cliente,padre);
		}
		
		//Recorrido en Inorden
		void inOrden(){
			cout<<"\n#ID\tNombre Cliente\tGasto total\n";
			cout<<"---------------------------------------\n";
			inOrdenPrivado(raiz);
		}
		
		void eliminarCliente(Cliente *cliente){
			conteo++;
			eliminar(raiz,cliente);
		}
		Nodo<Cliente> *get(int id){
			return getNodoBusquedaBinaria(raiz,id);
		}
		
		void ganancia(Vendedor *&vendedor){
			suma=0;
			gastosTotales(raiz);
			vendedor->setGanacia(suma);
		}
		void obtenerPilaProductos(int id){
			Cliente *cli = getNodoBusquedaBinaria(raiz,id)->getDato();
			cout<<"\n#ID : "<<cli->getID();
			cout<<"\nNombre : "<<cli->getNombre();
			cout<<"\n----------------\n\n";
			cli->getPilaProductos()->showPila();
		}
};
#endif
