#ifndef COLA_H
#define COLA_H
#include "Producto.h"
class Cola{
	private :
		Nodo<Producto> *primero,*ultimo;
	public :
		Cola(){
			primero=ultimo=NULL;
		}
		
		void insert(Producto *producto){
			Nodo<Producto> *nuevo=new Nodo<Producto>(producto);
			if(primero==NULL){
				primero=ultimo=nuevo;
			}else{
				ultimo->siguiente=nuevo;
				ultimo=nuevo;
			}
		}
		
		void pop(){
			if(primero!=NULL){
				if(primero==ultimo){
					primero=ultimo=NULL;
				}else{
					primero=primero->siguiente;
				}
			}
		}
		
		void clear(Cliente *&cliente){
			if(primero!=NULL){
				while(primero!=NULL){
					cliente->getPilaProductos()->push(primero->getDato());
					cliente->setGasto(primero->getDato()->getCantidad() * primero->getDato()->getPrecioU());
					pop();
				}
			}
		}
};
#endif
