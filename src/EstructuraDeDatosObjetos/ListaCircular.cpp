#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Nodo{
	public :
	int dato;
	Nodo *siguiente=this;	
};
class ListaCircular{
	public:
		Nodo *ultimo;
		ListaCircular(){
			ultimo=NULL;
		}
	int conteo=0;
	bool isEmpty(){
		return ultimo==NULL;
	}
	void contar(){
		if(isEmpty()){
			cout<<"\nVacio\n";
		}else{
			cout<<"\nNumero de elementos : "<<conteo<<endl;
		}
	}
	/// :| 
	void insertToEnd(int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		conteo++;
		if(ultimo!=NULL){
			nuevo->siguiente=ultimo->siguiente ;
			ultimo->siguiente=nuevo;
		}
		ultimo=nuevo;
	}	
	void insertToStart(int dato){
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		conteo++;
		if(isEmpty()){
			ultimo=nuevo;
		}else{
			Nodo *inicio=new Nodo;
			inicio=ultimo->siguiente;
			ultimo->siguiente=nuevo;
			nuevo->siguiente=inicio;
		}
	}
	void deleteToStart(){
		if(!isEmpty()){
			conteo--;
			if(ultimo==ultimo->siguiente){
				ultimo=NULL;
			}else{
				Nodo *inicio=new Nodo;
				inicio=ultimo->siguiente;
				ultimo->siguiente=inicio->siguiente;
				inicio=NULL;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	void deleteToEnd(){
		if(!isEmpty()){
			conteo--;
			if(ultimo==ultimo->siguiente){
				ultimo=NULL;
			}else{
				Nodo *recorrer=new Nodo;
				Nodo *posterior=new Nodo;
				recorrer=ultimo->siguiente;
				posterior=recorrer->siguiente;
				while(recorrer->siguiente !=ultimo){
					recorrer=recorrer->siguiente;
					posterior=posterior->siguiente;
				}
				recorrer->siguiente =ultimo->siguiente;
				ultimo=recorrer;
				posterior=NULL;
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void insertToEndOrToStartOf(int datoFijo,int opcion,int dato){
		if(!isEmpty()){
			if(find(datoFijo)){
				conteo++;
				Nodo *recorrer=new Nodo;
				Nodo *nuevo=new Nodo;
				if(opcion==1){ //antes
					if(ultimo->siguiente->dato==datoFijo){
						insertToStart(dato);
					}else{
						nuevo->dato=dato;
						recorrer=ultimo->siguiente;
						while(recorrer->siguiente->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->siguiente=recorrer->siguiente;
						recorrer->siguiente =nuevo;
					}
				}else{ //despues
					if(ultimo->dato==datoFijo){
						insertToEnd(dato);
					}else{
						nuevo->dato=dato;
						recorrer=ultimo->siguiente;
						while(recorrer->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->siguiente=recorrer->siguiente;
						recorrer->siguiente=nuevo;
					}
				}
			}else{
				cout<<"\nNo existe el dato fijo\n";
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	
	bool find(int dato){
		Nodo *actual=new Nodo;
		actual=ultimo;
		bool encontrado=false;
		while(actual->siguiente!=ultimo && !encontrado){
			encontrado=(dato==actual->dato);
			if(!encontrado){
				actual=actual->siguiente;
			}
		}
		return actual->dato==dato;
	}
	
	void deleteEspecific(int dato){
		if(!isEmpty()){
			if(find(dato)){
				conteo--;
				Nodo *actual=new Nodo;
				if(ultimo->siguiente==ultimo){
					ultimo=NULL;
				}else{
					Nodo *anterior=new Nodo;
					anterior=ultimo;
					actual=ultimo->siguiente;
					while(actual->dato!=dato){
						actual=actual->siguiente;
						anterior=anterior->siguiente;
					}
					if(actual==ultimo){
						ultimo=anterior;
						ultimo->siguiente=actual->siguiente;				
					}else{
						anterior->siguiente=actual->siguiente;
					}
				}
				actual=NULL;
			}else{
				cout<<"\nNo existe\n";
			}
		}else{
			cout<<"\nVacio\n" ;
		}
	}
	
	void show(){
		Nodo *recorrer=new Nodo;
		recorrer=ultimo->siguiente;
		string cadena="-->";
		do{
			char buffer[10];
			char *str=itoa(recorrer->dato,buffer,10);
			string dato=string(str);
			cadena+="["+dato+"]-->";
			recorrer=recorrer->siguiente;
			
		}while(recorrer!=ultimo->siguiente);
		cout<<"\n"<<cadena<<"\n";
	}	
};
void menu();
bool opciones(int);
ListaCircular listaCircular=ListaCircular();
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar al final"<<endl;
		cout<<"2. Insertar al inicio"<<endl;
		cout<<"3. Eliminar al inicio"<<endl;
		cout<<"4. Eliminar al final"<<endl;
		cout<<"5. Eliminar especifico"<<endl;
		cout<<"6. Mostrar "<<endl;
		cout<<"7. Limpiar "<<endl;
		cout<<"8. Salir "<<endl;
		int op;
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			listaCircular.insertToEnd(dato);
			break;
		case 2:
			cin>>dato;
			listaCircular.insertToStart(dato);
			break;
		case 3:
			listaCircular.deleteToStart();
			break;
		case 4:
			listaCircular.deleteToEnd();
			break;
		case 5:
			cin>>dato;
			listaCircular.deleteEspecific(dato);
			break;
		case 6:
			listaCircular.show();
			break;
		case 7:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
