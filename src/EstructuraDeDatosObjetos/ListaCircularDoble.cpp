#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Nodo{
	public :
		int dato;
		Nodo *anterior=this;
		Nodo *siguiente=this;	
};
class CircleDoubleList{
	public :
		Nodo *ultimo;
		CircleDoubleList(){
			ultimo=NULL;
		}
		bool isEmpty(){
		return ultimo==NULL;
		}
		
		void insert(int dato){
			Nodo *nuevo=new Nodo;
			nuevo->dato=dato;
			if(ultimo!=NULL){
				nuevo->siguiente=ultimo->siguiente ;
				ultimo->siguiente=nuevo;
				nuevo->siguiente->anterior=nuevo;
				nuevo->anterior=ultimo;
			}
			ultimo=nuevo;
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
					Nodo *actual=new Nodo;
					if(ultimo->siguiente==ultimo){
						delete ultimo;
					}else{
						Nodo *anterior=ultimo;
						actual=ultimo->siguiente;
						while(actual->dato!=dato){
							actual=actual->siguiente;
							anterior=anterior->siguiente;
						}
						if(actual==ultimo){
							ultimo=anterior;
							ultimo->siguiente=actual->siguiente;
							ultimo->siguiente->anterior=ultimo;
						}else{
							anterior->siguiente=actual->siguiente;
							anterior->siguiente->anterior=anterior;
						}
					}
					delete actual;
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
			string cadena="<-->";
			do{
				char buffer[10];
				char *str=itoa(recorrer->dato,buffer,10);
				string dato=string(str);
				cadena+="["+dato+"]<-->";
				recorrer=recorrer->siguiente;
				
			}while(recorrer!=ultimo->siguiente);
			cout<<"\n"<<cadena<<"\n";
		}
};
CircleDoubleList listaCircularDoble=CircleDoubleList();
void menu();
bool opciones(int);
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar"<<endl;
		cout<<"2. Eliminar especifico"<<endl;
		cout<<"3. Mostrar "<<endl;
		cout<<"4. Limpiar "<<endl;
		cout<<"5. Salir "<<endl;
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
			listaCircularDoble.insert(dato);
			break;
		case 2:
			cin>>dato;
			listaCircularDoble.deleteEspecific(dato);
			break;
		case 3:
			listaCircularDoble.show();
			break;
		case 4:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
