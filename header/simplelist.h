#include<iostream>
using namespace std;
namespace SimpleList{
	int conteo=0;
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL;	
	}; 
	bool isEmpty(Nodo *inicio){
		return inicio==NULL;
	}
	void contar(Nodo *inicio){
		if(!isEmpty(inicio)){
			cout<<"\nCantidad de elementos : "<<conteo<<endl;
		}else{
			cout<<"\nVacio\n";
		}
	}
	void menorYMayor(Nodo *inicio){
		if(isEmpty(inicio)){
			cout<<"\nVacio\n";
		}else{
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			int mayor=recorrer->dato;
			int menor=recorrer->dato;
			while(recorrer!=NULL){
				if(menor>recorrer->dato){
					menor=recorrer->dato;
				}
				if(mayor<recorrer->dato){
					mayor=recorrer->dato;
				}
				recorrer=recorrer->siguiente;
			}
			
			cout<<"\nEl menor de los datos es "<<menor;
			cout<<"\nEl mayor de los datos es "<<mayor;
		}
	}
	void insertToTheStart(Nodo *&inicio,Nodo *&final,int dato){
		conteo++;
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
		conteo++;
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
			conteo--;
			if(inicio==final){
				inicio=final=NULL;
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
			conteo--;
			if(inicio==final){
				inicio=final=NULL;
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
	bool find(Nodo *inicio,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && recorrer->dato!=dato){
			recorrer=recorrer->siguiente;
		}
		return recorrer!=NULL;
	}
	
	void insertarAntesODespues(Nodo *&inicio,Nodo *&final,int dato,int datoSoA,int opcion){
			if(find(inicio,dato)){
				conteo++;
				Nodo *recorrer=new Nodo;
				Nodo *nuevo=new Nodo;
				if(opcion==1){
					if(inicio->dato==dato){
						recorrer->dato=datoSoA;
						recorrer->siguiente=inicio;
						inicio=recorrer;
					}else{
						recorrer=inicio->siguiente;
						Nodo *anterior=new Nodo;
						anterior=inicio;
						while(recorrer->dato!=dato){
							recorrer=recorrer->siguiente;
							anterior=anterior->siguiente;
						}
						nuevo->dato=datoSoA;
						anterior->siguiente=nuevo;
						nuevo->siguiente=recorrer;
					}
				}else{
					if(final->dato==dato){
						recorrer->dato=datoSoA;
						final->siguiente=recorrer;
						final=final->siguiente;
					}else{
						nuevo->dato=datoSoA;
						recorrer=inicio;
						while(recorrer->dato!=dato){
							recorrer=recorrer->siguiente;
						}
						nuevo->siguiente=recorrer->siguiente;
						recorrer->siguiente=nuevo;
					}
				}
			}else{
				cout<<"\nNo existe\n";
			}
	}
	void buscar(Nodo *inicio,Nodo *final,int dato){
			if(find(inicio,dato)){
				Nodo *recorrer=new Nodo;
				recorrer=inicio;
				int posicion=0;
				while(recorrer->dato!=dato){
					posicion++;
					recorrer=recorrer->siguiente;
				}
				cout<<"\nElemento encontrado "<<recorrer->dato<<" en la posicion : "<<posicion<<endl;
			}else{
				cout<<"\nNo existe\n";
			}
	}
	void deleteEspecific(Nodo *&inicio,Nodo *&final,int dato){
			if(find(inicio,dato)){
				conteo--;
				Nodo *tem=new Nodo;
				if(inicio==final && inicio->dato==dato){
					inicio=final=NULL;
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
	void ordenarQuickSort(){
		
	}
	int  numeroDeRepeticiones(Nodo *inicio,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		int cantidad=0;
		while(recorrer!=NULL){
			if(recorrer->dato==dato){
				cantidad++;
			}
			recorrer=recorrer->siguiente ;
		}
		return cantidad;
	}
	void listaAuxliar(Nodo *&inicio,Nodo *&final){
		
	}
	void eliminarDuplicados(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			while(recorrer!=NULL ){
				int dato=recorrer->dato;
				int cantidad=numeroDeRepeticiones(inicio,dato)-1;
				for(int i=1;i<=cantidad && recorrer!=NULL;i++){
					recorrer=recorrer->siguiente;
					deleteEspecific(inicio,final,dato);
				}
				recorrer=recorrer->siguiente;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
}
