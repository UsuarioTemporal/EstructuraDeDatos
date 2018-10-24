#include<iostream>
using namespace std;
class Persona{
	private :
		string nombre;
		int edad;
	public  :
		Persona(string nombre,int edad){
			this->nombre=nombre;
			this->edad=edad;
		}
		int getEdad(){
			return edad;	
		}
		string getNombre(){
			return nombre;
		}
		void toString(){
				cout<<"[N : "<<nombre<<" E : "<<edad<<"]";
		}
};
template <class T> class Nodo{
	public :
		T *dato;
		Nodo *siguiente=NULL;
		Nodo *anterior=NULL;
		Nodo(T *dato){
			this->dato=dato;
		}
		
};
template <class T>class ListaDoble{
	public :
		Nodo<T> *inicio,*final;
		ListaDoble(){
			inicio=final=NULL;
		}
		bool isEmpty(){
			return inicio==NULL;
		}
		void insert(T *dato){
				Nodo<T> *nuevo=new Nodo<T>(dato);
				if(!isEmpty()){
					final->siguiente=nuevo;
					nuevo->anterior=final;
					final=nuevo;
				}else{
					inicio=final=nuevo;
	
				}
			}
			Nodo<T> *get(int indice){
					Nodo<T> *recorrer;
					recorrer=inicio;
					for(int i=1;i<indice;i++){
						recorrer=recorrer->siguiente;
					}
					return recorrer;
			}
			void show(){
				if(!isEmpty()){
					Nodo<T> *recorrer;
					recorrer=inicio;
					cout<<"|| <-- ";
					while(recorrer!=NULL){
						recorrer->dato->toString();
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
};
ListaDoble<Persona> *listaPersonas=new ListaDoble<Persona>();
int main(){
	listaPersonas->insert(new Persona("Thom",12));
	listaPersonas->insert(new Persona("Maurick",13));
	listaPersonas->insert(new Persona("Roman",14));
	listaPersonas->insert(new Persona("Aguilar",15));
	listaPersonas->show();
	
}
