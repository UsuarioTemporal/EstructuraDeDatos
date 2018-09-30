#include<iostream>
using namespace std;
namespace DoubleList{
	
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL,*anterior=NULL;	
	};
	bool isEmpty(Nodo *inicio){
		return inicio==NULL;
	}
	void insertToTheStart(Nodo *&inicio,Nodo *&final,int dato){
			Nodo *nuevo=new Nodo;
			nuevo->dato=dato;
			if(!isEmpty(inicio)){
				nuevo->siguiente=inicio;
				inicio=nuevo;
				inicio->siguiente->anterior=inicio;
			}else{
				inicio=final=nuevo;	
			}
	}
	
	void insertToTheEnd(Nodo *&inicio,Nodo *&final,int dato){
			Nodo *nuevo=new Nodo;
			nuevo->dato=dato;
			if(!isEmpty(inicio)){
				nuevo->anterior=final;
				nuevo->anterior->siguiente=nuevo;
				final=nuevo;
			}else{
				inicio=final=nuevo;	
			}
	}
	void deleteTheStart(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			if(inicio==final){
				delete inicio;
				delete final;
			}else{
				Nodo *temporal=new Nodo ;
				temporal=inicio;
				inicio=inicio->siguiente;
				temporal->siguiente->anterior=NULL;
//				temporal->siguiente=NULL; //No es necesario
				delete temporal;
			}
		}else{
			cout<<"\nVacio \n";
		}
	}
	void deleteTheEnd(Nodo *&inicio,Nodo *&final){
				if(!isEmpty(inicio)){
			if(inicio==final){
				delete inicio;
				delete final;
			}else{
				Nodo *temporal=new Nodo ;
				temporal=final;
				final=final->anterior;
				final->siguiente=NULL;
				delete temporal;
			}
		}else{
			cout<<"\nVacio \n";
		}
	}
	
	bool find(Nodo *inicio,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && dato!=recorrer->dato){
			recorrer=recorrer->siguiente;
		}
		
		return recorrer!=NULL;
	}
	
	void deleteEspecific(Nodo *&inicio,Nodo *&final,int dato){
		if(!isEmpty(inicio)){
			if(find(inicio,dato)){
				Nodo *temporal=new Nodo;
				
				if(inicio==final){
					delete inicio;
					delete final;
				}else if(inicio->dato==dato){
					temporal=inicio;
					inicio=inicio->siguiente;
					temporal->siguiente->anterior=NULL;
				}else{
					Nodo *anterior=new Nodo;
					temporal=inicio->siguiente;
					anterior=inicio;
					while(temporal->dato!=dato){
						temporal=temporal->siguiente;
						anterior=anterior->siguiente;
					}
					if(temporal==final){
						final=final->anterior;
						final->siguiente=NULL;
					}else{
						anterior->siguiente=temporal->siguiente;
						temporal->siguiente->anterior=anterior;
					}
				}
				delete temporal;
			}else{
				cout<<"\nNo existe \n";
			}
		}else{
			cout<<"\nVacio \n";
		}
	}
	void show(Nodo *inicio){
		if(!isEmpty(inicio)){
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			cout<<"|| <-- ";
			while(recorrer!=NULL){
				cout<<"["<<recorrer->dato<<"]";
				if(recorrer->siguiente!=NULL){
					cout<<"<-->";
				}
				recorrer=recorrer->siguiente;
			}
			cout<<"--> ||";
		}else{
			cout<<"\nVacio "<<endl;
		}
			
	}
}
