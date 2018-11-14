#ifndef PILA_H
#define PILA_H
#include<iostream>
using namespace std;
class Nodo{
	private :
		int dato;
	public : 
		Nodo *siguiente;
		Nodo(int dato){
			siguiente=NULL;
			this->dato=dato;
		}
		int getDato(){
			return dato;
		}
		void setDato(int dato){
			this->dato=dato;
		}
};
class Pila{
	private :
		Nodo *cima;
	public :
		Pila(){
			cima=NULL;
		}
		bool isEmpty(){
			return cima==NULL;
		}
		void push(int dato){
			Nodo *nuevo=new Nodo(dato);
			nuevo->siguiente=cima;
			cima=nuevo;
		}
		int pop(){
			if(!isEmpty()){
				Nodo *temporal=NULL;
				temporal=cima;
				cima=cima->siguiente;
				int y=temporal->getDato();
				delete temporal;
				temporal=NULL;
				return y;
			}else{
				cout<<"\nVacio"<<endl;
				return -1;
			}
		}
		void show(){
			if(!isEmpty()){
				Nodo *recorrer=cima;
				cout<<endl;
				while(recorrer!=NULL){
					cout<<" | "<<recorrer->getDato()<<" | "<<endl;
					recorrer=recorrer->siguiente;
				}
				cout<<endl;
			}else{
				cout<<"\nVacio"<<endl;
			}
		}
		bool buscar(int dato){
			Nodo *recorrer=cima;
			while(recorrer!=NULL && recorrer->getDato()!=dato){
				recorrer=recorrer->siguiente;
			}
			return recorrer!=NULL;
		}
		int existeNumero(int dato){
			Nodo *recorrer=cima;
			int conteo=0;
			while(recorrer!=NULL){
				if(recorrer->getDato()==dato){
					conteo++;
				}
				recorrer=recorrer->siguiente;
			}
			return conteo;
		}
		int existenPares(){
			Nodo *recorrer=cima;
			int conteo=0;
			while(recorrer!=NULL){
				if(recorrer->getDato()%2==0){
					conteo++;
				}
				recorrer=recorrer->siguiente;
			}
			return conteo;
		}
//		Método para el ejercicio número 1 elimando buscado
		void eliminadoBuscado(Pila *&auxiliar,int dato){
			if(isEmpty()){
				cout<<"\nVacio\n";
			}else{
				int conteoNumero=existeNumero(dato);
				if(conteoNumero>0){
					while(conteoNumero>0){
						if(cima->getDato()==dato){
							this->pop();
							conteoNumero--;
						}else{
							auxiliar->push(this->pop());
						}
					}
				}else{
					cout<<"\nNo existe el numero\n";
				}
				
			}
		}
//		Método para el ejercicio número 2 elimando pares
		void eliminadoPares(Pila *&auxiliar){
			if(isEmpty()){
				cout<<"\nVacio\n";
			}else{
				int conteoDePares=existenPares();
				auxiliar=new Pila();
				if(conteoDePares>0){
					while(conteoDePares>0){
						if(cima->getDato()%2==0){
							this->pop();
							conteoDePares--;
						}else{
							auxiliar->push(this->pop());
						}
					}
				}else{
					cout<<"\nNo existen pares\n";
				}
			}	
		}
// 		Método para el ejercicio número 3 tranferencia de datos
		void tranferencia(Pila *&auxiliar){
			if(isEmpty()){
				cout<<"\nVacio\n";
			}else{
				auxiliar=new Pila();
				while(!isEmpty()){
					auxiliar->push(this->pop());
				}
			}
		}
};
#endif
