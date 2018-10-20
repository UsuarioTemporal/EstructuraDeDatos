#include<iostream>
using namespace std;
template <class T> class Nodo{
	public :
		T dato;
		Nodo *siguiente;
		Nodo(T _dato){
			dato=_dato;
			siguiente=NULL;
		}
		Nodo(){
			dato=NULL;
			siguiente=NULL;
		}
};
template <class T>class Lista{
	public :
		Nodo<T> *inicio,*final;
		Lista(){
			inicio=NULL;
			final=NULL;
		}
		void insert(T dato){
			Nodo<T> *nuevo=new Nodo<T>(dato);
			if(inicio==NULL){
				inicio=final=nuevo;
			}else{
				nuevo->siguiente=inicio;
				inicio=nuevo;
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

int main(){
	Lista<int> lista=Lista<int>();
	lista.insert(5);
//	lista.insertToTheStart(6);
//	lista.insertToTheStart(5);
//	lista.insertToTheStart(7);
//	lista.insertToTheStart(0);
	lista.show();
}
