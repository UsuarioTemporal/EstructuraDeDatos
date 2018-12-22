#ifndef PILA_H
#define PILA_H
#include "Producto.h"
#include "Nodo.h"
#include<iostream>
using namespace std;
class Pila{
	private :
		Nodo<Producto> *cima;
	public : 
		Pila(){
			cima=NULL;
		}
		bool isEmpty(){
			return cima==NULL;
		}
		void push(Producto *producto){
			Nodo<Producto> *nuevo=new Nodo<Producto>(producto);
			nuevo->siguiente=cima;
			cima=nuevo;
		}
		void pop(){
			if(!isEmpty()){
				Nodo<Producto> *recorrer=cima;
				cima=cima->siguiente;
				recorrer=NULL;
			}else{
				cout<<"\nVacio\n";
			}
		}
		void clear(){
			if(!isEmpty()){
				while(!isEmpty()){
					pop();
				}
			}else{
				cout<<"\nVacio\n";
			}
		}
		
		void showPila(){
			if(!isEmpty()){
				Nodo<Producto> *recorrer=cima;
				cout<<"#ID\t\tNOMBRE\t\t\t\tCANTIDAD\tPRECIO UNITARIO\n";
				cout<<"------------------------------------------------------------------------------\n";
				while(recorrer!=NULL){
					recorrer->getDato()->toString();
					recorrer=recorrer->siguiente;
				}
				cout<<endl;
			}else{
				cout<<"\nVacio\n";
			}
		}
};
#endif 
