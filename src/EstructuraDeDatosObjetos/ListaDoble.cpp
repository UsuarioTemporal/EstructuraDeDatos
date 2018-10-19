#include<iostream>
using namespace std;
class Nodo{
	public :
		int dato;
		Nodo *siguiente=NULL,*anterior=NULL;	
};
class ListaDoble{
	public :
		Nodo *inicio,*final;
		ListaDoble(){
			inicio=final=NULL;
		}
		bool isEmpty(){
		return inicio==NULL;
		}
		void insertToTheStart(int dato){
				Nodo *nuevo=new Nodo;
				nuevo->dato=dato;
				if(!isEmpty()){
					nuevo->siguiente=inicio;
					inicio=nuevo;
					inicio->siguiente->anterior=inicio;
				}else{
					inicio=final=nuevo;	
				}
		}
		
		void insertToTheEnd(int dato){
				Nodo *nuevo=new Nodo;
				nuevo->dato=dato;
				if(!isEmpty()){
					nuevo->anterior=final;
					nuevo->anterior->siguiente=nuevo;
					final=nuevo;
				}else{
					inicio=final=nuevo;	
				}
		}
		void deleteTheStart(){
			if(!isEmpty()){
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
		void deleteTheEnd(){
					if(!isEmpty()){
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
		
		bool find(int dato){
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			while(recorrer!=NULL && dato!=recorrer->dato){
				recorrer=recorrer->siguiente;
			}
			
			return recorrer!=NULL;
		}
		
		void deleteEspecific(int dato){
			if(!isEmpty()){
				if(find(dato)){
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
		void show(){
			if(!isEmpty()){
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
	};
void menu();
bool opciones(int);
ListaDoble listaDoble=ListaDoble();
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar al comienzo "<<endl;
		cout<<"2. Insertar al final "<<endl;
		cout<<"3. Eliminar el inicio"<<endl;
		cout<<"4. Eliminar el final"<<endl;
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
			listaDoble.insertToTheStart(dato);
			break;
		case 2:
			cin>>dato;
			listaDoble.insertToTheEnd(dato);
			break;
		case 3:
			listaDoble.deleteTheStart();
			break;
		case 4:
			listaDoble.deleteTheEnd();
			break;
		case 5:
			cin>>dato;
			listaDoble.deleteEspecific(dato);
			break;
		case 6:
			listaDoble.show();
			break;
		case 7:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
