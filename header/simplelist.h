#include<iostream>
using namespace std;
namespace SimpleList{
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL;	
	};
	bool isEmpty(Nodo *inicio){
		return inicio==NULL;
	}
	void insertToTheStart(Nodo *&inicio,Nodo *&final,int dato){
		Nodo *nuevo1=new Nodo;
		nuevo1->dato=dato;
		if(isEmpty(inicio)){
			inicio=final=nuevo1;
		}else{
			nuevo1->siguiente=inicio;
			inicio=nuevo1;
		}
	}
	void insertToTheEnd(Nodo *&inicio,Nodo *&final,int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		if(isEmpty(inicio)){
			inicio=final=nuevo;
		}else{
			final->siguiente=nuevo;
			final=final->siguiente ;
		}
	}
	
	void deleteToTheStart(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			if(inicio==final){
				delete inicio;
				delete final;
			}else{
				Nodo *temporal=new Nodo;
				temporal=inicio;
				int elemento=temporal->dato;
				inicio=inicio->siguiente;
				delete temporal;
			}
			
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	void deleteToTheEnd(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			if(inicio==final){
				delete inicio;
				delete final;
			}else{
				Nodo *temporal=new Nodo;
				temporal = inicio;
				while(temporal->siguiente!=final){
					temporal=temporal->siguiente;
				}
				final = temporal;
				temporal=temporal->siguiente;
				cout<<"Eliminado "<<temporal->dato;
				final->siguiente=NULL;
				delete temporal;
			}
			
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	bool find(Nodo *inicio,Nodo *final,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && recorrer->dato!=dato){
			recorrer=recorrer->siguiente;
		}
		return recorrer!=NULL;
	}
	void deleteEspecific(Nodo *inicio,Nodo *final,int dato){
		if(!isEmpty(inicio)){
			if(find(inicio,final,dato)){
				Nodo *tem=new Nodo;
				if(inicio==final && inicio->dato==dato){
					delete inicio;
					delete final;
				}else if(inicio->dato==dato){
					tem=inicio;
					inicio=inicio->siguiente;
				}else{
					tem=inicio->siguiente;
					Nodo *anterior=inicio;
					while(tem->dato!=dato){
						tem=tem->siguiente;
						anterior=anterior->siguiente;
					}
					if(tem==final){
						final=anterior;
						final->siguiente =NULL;
					}else{
						anterior->siguiente=tem->siguiente ;
						tem->siguiente=NULL;
					}
					
				}
				delete tem;
			}else{
				cout<<"\nNo existe"<<endl;
			}
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
	void show(Nodo *inicio){
		if(!isEmpty(inicio)){
			Nodo *recorrer=new Nodo;
			recorrer = inicio;
			while(recorrer!=NULL){
				cout<<"["<<recorrer->dato<<"]-->";
				recorrer=recorrer->siguiente;
			}
			cout<<" || "<<endl;
		}else{
			cout<<"\nVacio"<<endl;
		}
	}
}
