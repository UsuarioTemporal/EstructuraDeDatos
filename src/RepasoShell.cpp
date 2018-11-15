#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *siguiente=NULL;	
};
int conteo=0;
void insert(Nodo *&inicio,Nodo *&final,int dato){
	Nodo *nuevo=new Nodo;
	nuevo->dato=dato;
	conteo++;
	if(inicio!=NULL){
		final->siguiente=nuevo;
		final=nuevo;
	}else{
		inicio=final=nuevo;
	}
}

void show(Nodo *&inicio){
	Nodo *recorrer=inicio;
	cout<<"\n";
	while(recorrer!=NULL){
		cout<<"["<<recorrer->dato<<"]->";
		recorrer=recorrer->siguiente;
	}
	cout<<"||\n\n";
}
Nodo *getNodo(Nodo *nodo,int saltos){
	for(int i=1;i<=saltos;i++){
		nodo=nodo->siguiente;
	}
	return nodo;
}
void shellSort(Nodo *&inicio){
	for(int saltos=conteo/2;saltos>0;saltos/=2){
		Nodo *primero=inicio;
		Nodo *ultimo=getNodo(inicio,saltos);
		int posUltimo=saltos;
		while(ultimo!=NULL){
			Nodo *supUltimo=ultimo;
			Nodo *supPrimero=primero;
			int supPosUltimo=posUltimo;
			do{
				if(supUltimo->dato<supPrimero->dato){
					int aux=supUltimo->dato;
					supUltimo->dato=supPrimero->dato;
					supPrimero->dato=aux;
				}
				int supPosPrimero=supPosUltimo-saltos;
				if(supPosPrimero>=saltos && supPrimero!=inicio){
					supUltimo=supPrimero;
					supPrimero=getNodo(inicio,supPosPrimero-saltos);
					supPosUltimo-=saltos;
				}else{
					break;
				}
			}while(supUltimo->dato<supPrimero->dato);
			ultimo=ultimo->siguiente;
			primero=primero->siguiente;
			posUltimo++;
		}
		
	}
}
Nodo *inicio=NULL;
Nodo *final=NULL;
int main(){
	srand(time(NULL));
	for(int i=0;i<13;i++){
		insert(inicio,final,2+rand()%(9));
	}
	show(inicio);
	shellSort(inicio);
	show(inicio);
}
