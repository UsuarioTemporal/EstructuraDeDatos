#include<iostream>
using namespace std;
class Nodo{
	public :
		int dato;
		Nodo *siguiente=NULL;
};
class ListaSimple{
	int conteo=0;
	public :
		Nodo *inicio,*final;
		bool isEmpty(){
			return inicio==NULL;
		}
		ListaSimple(){
			inicio=final=NULL;
		}
		void contar(){
		if(!isEmpty()){
			cout<<"\nCantidad de elementos : "<<conteo<<endl;
		}else{
			cout<<"\nVacio\n";
		}
	}
	void menorYMayor(){
		if(isEmpty()){
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
	void insertToTheStart(int dato){
		conteo++;
		Nodo *nuevo1=new Nodo;
		nuevo1->dato=dato;
		if(isEmpty()){
			inicio=final=nuevo1;
		}else{
			nuevo1->siguiente=inicio;
			inicio=nuevo1;
		}
	}
	void insertToTheEnd(int dato){
		conteo++;
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		if(isEmpty()){
			inicio=final=nuevo;
		}else{
			final->siguiente=nuevo;
			final=final->siguiente ;
		}
	}
	
	void deleteToTheStart(){
		if(!isEmpty()){
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
	void deleteToTheEnd(){
		if(!isEmpty()){
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
	bool find(int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && recorrer->dato!=dato){
			recorrer=recorrer->siguiente;
		}
		return recorrer!=NULL;
	}
	
	void insertarAntesODespues(int dato,int datoSoA,int opcion){
			if(find(dato)){
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
	void buscar(int dato){
			if(find(dato)){
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
	void deleteEspecific(int dato){
			if(find(dato)){
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
				tem=NULL;
			}else{
				cout<<"\nNo existe"<<endl;
			}
	}
	void show(){
		if(!isEmpty()){
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
	
	int  numeroDeRepeticiones(int dato){
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
	void eliminarDosprimeros(){
		if(conteo<2){
			cout<<"No se puede"<<endl;
		}else{
			conteo=conteo-2;
			if(conteo==2){
				inicio=final=NULL;
			}else{
				Nodo *primero=new Nodo;
				Nodo *segundo=new Nodo;
				primero=inicio;
				segundo=inicio->siguiente;
				inicio=segundo->siguiente;
				primero=NULL;
				segundo=NULL;
			}
		}
	}
	void eliminarDuplicados(){
		if(!isEmpty()){
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			while(recorrer!=NULL ){
				Nodo *nuevo=new Nodo;
				nuevo=recorrer;
				int dato=nuevo->dato;
				int cantidad=numeroDeRepeticiones(dato)-1;
				for(int i=1;i<=cantidad ;i++){
					deleteEspecific(dato);
				}
				if(recorrer==NULL){
					break;
				}else{
					recorrer=recorrer->siguiente ;
				}
				
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
};
void menu();
bool opciones(int);
ListaSimple lista=ListaSimple();
int main(){
	
	system("color 0B");
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
		cout<<"6. Buscar "<<endl;
		cout<<"7. Ingresar dato en :  "<<endl;
		cout<<"8. Mostrar  "<<endl;
		cout<<"9. Cantidad de elementos  "<<endl;
		cout<<"10. Menor y mayor "<<endl;
		cout<<"11. Eliminar Nodos repetidos "<<endl;
		cout<<"12. ELIMINAR DOS PRIMEROS "<<endl;
		cout<<"13. Limpiar "<<endl;
		cout<<"14. Salir "<<endl;
		int op;
		cout<<"\nOpcion : ";
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			lista.insertToTheStart(dato);
			break;
		case 2:
			cin>>dato;
			lista.insertToTheEnd(dato);
			break;
		case 3:
			lista.deleteToTheStart();
			break;
		case 4:
			lista.deleteToTheEnd();
			break;
		case 5:
			if(lista.isEmpty()){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				lista.deleteEspecific(dato);
			}
			break;
		case 6:
			if(lista.isEmpty()){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				lista.buscar(dato);
			}
			break;
		case 7:
			if(!lista.isEmpty()){
				int opcion;
				int datoSoA;
				cout<<"El valor que sera fijo : ";
				cin>>dato;
				cout<<"1.Antes"<<endl;
				cout<<"2.Despues"<<endl;
				cin>>opcion;
				cout<<"Ingrese el dato : ";
				cin>>datoSoA;
				lista.insertarAntesODespues(dato,datoSoA,opcion);
			
			}else{
				cout<<"\nvacio\n";
			}
			break;
		case 8:
			lista.show();
			break;
		case 9:
			lista.contar();
			break;
		case 10:
			lista.menorYMayor();
			break;
		case 11:
			lista.eliminarDuplicados();
			break;
		case 12:
			lista.eliminarDosprimeros();
			break;
		case 13:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
