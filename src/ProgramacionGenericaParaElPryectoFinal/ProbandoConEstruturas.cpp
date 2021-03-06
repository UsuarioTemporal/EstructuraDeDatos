#include<iostream>
using namespace std;
class Persona{
	private :
		string nombre;
		double sueldo;
	public :
		Persona(string nombre,double sueldo){
			this->nombre=nombre;
			this->sueldo=sueldo;
		}
		string getNombre(){
			return nombre;
		}
		double getSueldo(){
			return sueldo;
		}
};
template <class T> class Nodo{
	public :
		T *dato;
		Nodo *siguiente;
		Nodo(T *_dato){
			dato=_dato;
			siguiente=NULL;
		}
		string imprimirNodo(){
			Persona *p=dato;
			return p->getNombre();
		}
		
};
template <class T>class Lista{
	public :
		Nodo<T> *inicio,*final;
		Lista(){
			inicio=NULL;
			final=NULL;
		}
		void insert(T *dato){
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
		void show2(){
			if(!inicio==NULL){
				Nodo<T> *recorrer=inicio;
				while(recorrer!=NULL){
					cout<<"["<<recorrer->imprimirNodo()<<"]-->";
					recorrer=recorrer->siguiente;
				}
				cout<<" || "<<endl;
			}else{
				cout<<"\nVacio"<<endl;
			}
		}
};

int main(){
//	Lista<int> lista=Lista<int>();
//	lista.insert(5);
//	lista.insert(6);
//	lista.insert(5);
//	lista.insert(7);
//	lista.insert(0);
//	lista.show();
//	
//	
//	Lista<string> listaDeString=Lista<string>();
//	listaDeString.insert("uno");
//	listaDeString.insert("dos");
//	listaDeString.insert("tres");
//	listaDeString.insert("cuatro");
//	listaDeString.show();
	
	
	Lista<Persona> *listaDePersonas=new Lista<Persona>();
	Persona *p1=new Persona("Thom",12.5);
	Persona *p2=new Persona("Thodfsdfm",172.5);
	listaDePersonas->insert(p1);
	listaDePersonas->insert(p2);
	listaDePersonas->show2();
}
