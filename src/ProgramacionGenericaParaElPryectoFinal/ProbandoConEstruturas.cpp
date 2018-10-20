#include<iostream>
using namespace std;
template <class T>class Nodo{
	public :
		T dato;
		Nodo *siguiente;
		Nodo(T dato,Nodo *siguiente){
			this->dato=dato;
			this->siguiente=siguiente;
		}
};
template <class T>class Lista{
	public :
		Nodo<T> *inicio,*final;
		Lista(){
			inicio=final=NULL;
		}
		void insertToTheStart(T dato){
			Nodo<T> *nuevo1;
			nuevo1->dato=dato;
			if(inicio==NULL){
				inicio=final=nuevo1;
			}else{
				nuevo1->siguiente=inicio;
				inicio=nuevo1;
			}
		}
		void show(){
			if(!inicio==NULL){
				Nodo<T> *recorrer=inicio;
				while(recorrer!=NULL){
					cout<<"["<<recorrer->dato<<"]-->";
					recorrer=recorrer->siguiente;
				}
				cout<<" || "<<endl;
			}else{
				cout<<"\nVacio"<<endl;
			}
		}
};
//Lista<int> lista();
int main(){
//	lista.insertToTheStart(8);
//	lista.insertToTheStart(6);
//	lista.insertToTheStart(5);
//	lista.insertToTheStart(7);
//	lista.insertToTheStart(0);
//	lista.show();
}
