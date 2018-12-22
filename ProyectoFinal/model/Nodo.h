#ifndef NODO_H
#define NODO_H
#include<iostream>
using namespace std;
template<class T >class Nodo{
	private :
		T *dato;
	public :
//		enlaces solo para las listas
		Nodo *siguiente;
		Nodo *anterior;
//		fin de elances para las listas

//		Enlaces para el Árbol AVL
		Nodo *padre;
		Nodo *hijoDerecho;
		Nodo *hijoIzquierdo;
//		Fin de enlaces AVL
		Nodo(T *_dato){
			dato=_dato;
			siguiente=NULL;
			anterior=NULL;
			hijoDerecho=hijoIzquierdo=padre=NULL;
		}
		
		T *getDato(){
			return dato;
		}
		void *setDato(T *dato){
			this->dato=dato;
		}
};
#endif
