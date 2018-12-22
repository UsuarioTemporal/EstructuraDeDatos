#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Nodo.h"
#include "Producto.h"
#include <sstream>
#include <windows.h>
#include <string>
class ListaDobleProductos{
	private :
		
		Nodo<Producto> *inicio;
		Nodo<Producto> *final;
		
	public :
		int conteo;
		ListaDobleProductos(){
			conteo=0;
			inicio=final=NULL;
		}
		bool isEmpty(){
			return inicio==NULL;
		}
		void insert(Producto *dato){
			conteo++;
			Nodo<Producto> *nuevo=new Nodo<Producto>(dato);
			if(inicio==NULL){
				inicio=final=nuevo;
			}else{
				final->siguiente=nuevo;
				final=nuevo;
			}
		}
		void show(){
			cout<<"#ID\t\tNOMBRE\t\t\t\tCANTIDAD\tPRECIO UNITARIO\n";
			cout<<"------------------------------------------------------------------------------\n";
			Nodo<Producto> *recorrer=inicio;
			while(recorrer!=NULL){
				Producto *pro=recorrer->getDato();
				pro->toString();
				recorrer=recorrer->siguiente;
			}
		}
		Nodo<Producto> *get(int id){
			if(id>conteo){
				cout<<"\nNo exite producto con ese ID\n";
				return NULL;
			}else if(id==1){
				return inicio;
			}else if(id==conteo){
				return final;
			}else{
				Nodo<Producto> *recorrer=NULL;
				recorrer=inicio;
				for(int i=1;i<id;i++){
					recorrer=recorrer->siguiente;	
				}
				return recorrer;
			}
		}
		Nodo<Producto> *retroceder(Nodo<Producto> *supuestoP,int lugar){
			for(int i=1;i<=lugar;i++){
				supuestoP=supuestoP->siguiente;
			}
			return supuestoP;
		}
		void shellSort(){
		    int saltos = conteo / 2;
		    while (saltos > 0) {
				Nodo<Producto> *q=retroceder(inicio,saltos);
		        Nodo<Producto> *p= inicio;
		        int posicionQ=saltos;
		        while (q != NULL) {
					Nodo<Producto> *supuestoQ=q;
					Nodo<Producto> *supuestoP=p;
					int supuestaPosicionQ=posicionQ;
					do{
						if (supuestoP->getDato()->getPrecioU() > supuestoQ->getDato()->getPrecioU()) {
				            Producto *aux = supuestoP->getDato();
				            supuestoP->setDato(supuestoQ->getDato());
				            supuestoQ->setDato(aux);
			            }
			            int supuestaPosicionP=supuestaPosicionQ-saltos;
			            if(supuestaPosicionP>=saltos && supuestoP!=inicio){
			                supuestoQ=supuestoP;
			                supuestoP=retroceder(inicio,supuestaPosicionP-saltos);
			                supuestaPosicionQ-=saltos;
						}else{
							break;
						}
					}while(supuestoP->getDato()->getPrecioU() > supuestoQ->getDato()->getPrecioU());
			        p = p->siguiente;
			        q = q->siguiente;
			        posicionQ++;
		        }
		        saltos/= 2;
			}	        
		}
		void butbujaCantidades(Nodo<Producto> *&inicio,Nodo<Producto> *final){
			if(!isEmpty()){
				for(Nodo<Producto> *primero=inicio;primero->siguiente!=NULL;primero=primero->siguiente){
					for(Nodo<Producto> *segundo=inicio;segundo!=final;segundo=segundo->siguiente){
						if(segundo->getDato()->getCantidad()>segundo->siguiente->getDato()->getCantidad()){
							Producto *aux=segundo->siguiente->getDato();
							segundo->siguiente->setDato(segundo->getDato());
							segundo->setDato(aux);
						}
					}
				}
			}else{
				cout<<"\nVacio\n";
			}
		}
		void butbujaID(Nodo<Producto> *&inicio,Nodo<Producto> *final){
			if(!isEmpty()){
				for(Nodo<Producto> *primero=inicio;primero->siguiente!=NULL;primero=primero->siguiente){
					for(Nodo<Producto> *segundo=inicio;segundo!=final;segundo=segundo->siguiente){
						if(segundo->getDato()->getID()>segundo->siguiente->getDato()->getID()){
							Producto *aux=segundo->siguiente->getDato();
							segundo->siguiente->setDato(segundo->getDato());
							segundo->setDato(aux);
						}
					}
				}
			}else{
				cout<<"\nVacio\n";
			}
		}
		void ordenAleatorio(){
			int aleatorio=1+rand()%(3);
			if(aleatorio==1){
				//heapsort  -- precio (Pendiente)
				shellSort();
				show();
				Sleep(5000);
			}else if(aleatorio==2){
				//quicksort  -- cantidades (Pendiente)
				butbujaCantidades(inicio,final);
				show();
				Sleep(5000);
			}else{
				//id
				butbujaID(inicio,final);
				show();
				Sleep(5000);
			}
		}
		
		
};
#endif 
