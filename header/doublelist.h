#include<iostream>
#include<vector>
using namespace std;
namespace DoubleList{
	int conteo=0;
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL,*anterior=NULL;	
	};
	bool isEmpty(Nodo *inicio){
		return inicio==NULL;
	}
	void contar(Nodo *inicio){
		if(!isEmpty(inicio)){
			cout<<"\nCantidad de elementos : "<<conteo<<endl;
		}else{
			cout<<"\nVacio\n";
		}
	}
	void menorYMayor(Nodo *inicio){
		if(isEmpty(inicio)){
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
	bool find(Nodo *inicio,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && dato!=recorrer->dato){
			recorrer=recorrer->siguiente;
		}
		
		return recorrer!=NULL;
	}
	void insertToTheStart(Nodo *&inicio,Nodo *&final,int dato){
			conteo++;
			Nodo *nuevo=new Nodo;
			nuevo->dato=dato;
			if(!isEmpty(inicio)){
				nuevo->siguiente=inicio;
				inicio=nuevo;
				inicio->siguiente->anterior=inicio;
			}else{
				inicio=final=nuevo;	
			}
	}
	
	void insertToTheEnd(Nodo *&inicio,Nodo *&final,int dato){
			conteo++;
			Nodo *nuevo=new Nodo;
			nuevo->dato=dato;
			if(!isEmpty(inicio)){
				nuevo->anterior=final;
				nuevo->anterior->siguiente=nuevo;
				final=nuevo;
			}else{
				inicio=final=nuevo;	
			}
	}
	void buscar(Nodo *inicio,Nodo *final,int dato){
			if(find(inicio,dato)){
				Nodo *recorrer=new Nodo;
				recorrer=inicio;
				int posicion=1;
				while(recorrer->dato!=dato){
					posicion++;
					recorrer=recorrer->siguiente;
				}
				cout<<"\nElemento encontrado "<<recorrer->dato<<" en la posicion : "<<posicion<<endl;
			}else{
				cout<<"\nNo existe\n";
			}
	}
	void deleteTheStart(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			conteo--;
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
	void deleteTheEnd(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			conteo--;
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
	
	
	
	void deleteEspecific(Nodo *&inicio,Nodo *&final,int dato){
		if(!isEmpty(inicio)){
			if(find(inicio,dato)){
				conteo--;
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
	void show(Nodo *inicio){
		if(!isEmpty(inicio)){
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
	
	
	int  numeroDeRepeticiones(Nodo *inicio,int dato){
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
	void eliminarDosprimeros(Nodo *&inicio,Nodo *&final){
		if(conteo<2){
			cout<<"No se puede"<<endl;
		}else{
			if(conteo==2){
				inicio=final=NULL;
				conteo=conteo-2;
			}else{
				for(int i=1;i<=2;i++){
					deleteTheStart(inicio,final);
				}
			}
		}
	}
	void eliminando(vector<int> vect,Nodo *&inicio,Nodo *&final){
		for(int i=0;i<vect.size();i++){
				deleteEspecific(inicio,final,vect[i]);
		}
		vect.clear();
	}
	//eliminar repetidos
	void eliminarRepetidos(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			vector<int> vect;
			Nodo *recorrer=new Nodo;
			int datoTemporal=0;
			recorrer=inicio;
			while(recorrer!=NULL){
				Nodo *nuevo=new Nodo;
				nuevo=recorrer;
				int dato=nuevo->dato;
				int cantidad=numeroDeRepeticiones(recorrer,dato);
				if(cantidad>1){
					vect.push_back(dato);
				}
				recorrer=recorrer->siguiente;
			}
			for(int i=0;i<vect.size();i++){
				deleteEspecific(inicio,final,vect[i]);
			}
			vect.clear();
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	//Eliminar pares
	void eliminarPares(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			vector<int> vect1;
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			while(recorrer!=NULL){
				if(recorrer->dato % 2 == 0){
					vect1.push_back(recorrer->dato);
				}
				recorrer=recorrer->siguiente;
			}
			recorrer=NULL;
			eliminando(vect1,inicio,final);
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	//Eliminar impares
	void eliminarImpares(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			vector<int> vect;
			Nodo *recorrer=new Nodo;
			recorrer=inicio;
			while(recorrer!=NULL){
				if(recorrer->dato%2!=0){
					vect.push_back(recorrer->dato);
				}
				recorrer=recorrer->siguiente;
			}
			recorrer=NULL;
			eliminando(vect,inicio,final); 
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	
	//ordenar
	void ordenarPorBurbuja(Nodo *&inicio,Nodo *final){
		if(!isEmpty(inicio)){
			for(Nodo *primero=inicio;primero->siguiente!=NULL;primero=primero->siguiente){
				for(Nodo *segundo=inicio;segundo!=final;segundo=segundo->siguiente){
					if(segundo->dato>segundo->siguiente->dato){
						int aux=segundo->siguiente->dato;
						segundo->siguiente->dato=segundo->dato;
						segundo->dato=aux;
					}
				}
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	//eliminar numeroPrimos
	void eliminarNumerosPrimos(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			vector<int> vect;
			Nodo *recorrer=new Nodo;
			
			while(recorrer!=NULL){
				bool primo=false;
				for(int i=2;i<recorrer->dato;i++){
					if(recorrer->dato%i==0){
						primo=true;
						break;
					}
				}
				if(primo){
					vect.push_back(recorrer->dato);
				}
				recorrer=recorrer->siguiente;
			}
			eliminando(vect,inicio,final);
		}else{
			cout<<"\nVacio\n";
		}
	}
	//eliminar posiciones pares
	void eliminarPosicionesPares(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			Nodo *recorrer=new Nodo;
			vector<int> vect;
			recorrer=inicio;
			for(int i=1;i<=conteo;i++){
				if(i%2==0){
					vect.push_back(recorrer->dato);
				}
				recorrer=recorrer->siguiente;
			}
			eliminando(vect,inicio,final);
		}else{
			cout<<"\nVacio\n";
		}
	}
	//eliminar posiciones impares
	void eliminarPosicionesImpares(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
				Nodo *recorrer=new Nodo;
				vector<int> vect;
				recorrer=inicio;
				for(int i=1;i<=conteo;i++){
					if(i%2!=0){
						vect.push_back(recorrer->dato);
					}
					recorrer=recorrer->siguiente;
				}
				eliminando(vect,inicio,final);
			}else{
				cout<<"\nVacio\n";
			}
		}
	void insertarAntesODespues(Nodo *&inicio,Nodo *&final,int datoFijo,int dato,int opcion){
			if(find(inicio,datoFijo)){
				Nodo *recorrer=new Nodo;
				Nodo *nuevo=new Nodo;
				if(opcion==1){ // antes
					if(inicio->dato==datoFijo){
						insertToTheStart(inicio,final,dato);
					}else{
						conteo++;
						recorrer=inicio;
						while(recorrer->siguiente->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->dato=dato;
						nuevo->siguiente=recorrer->siguiente;
						nuevo->siguiente->anterior=nuevo;
						recorrer->siguiente=nuevo;
						nuevo->anterior=recorrer;
					}
				}else{//despues
					if(final->dato==datoFijo){
						insertToTheEnd(inicio,final,dato);
					}else{
						conteo++;
						recorrer=inicio;
						while(recorrer->dato!=datoFijo){
							recorrer=recorrer->siguiente;
						}
						nuevo->dato=dato;
						nuevo->siguiente=recorrer->siguiente;
						nuevo->siguiente->anterior=nuevo;
						recorrer->siguiente=nuevo;
						nuevo->anterior=recorrer;
					}
				}
			}else{
				cout<<"\nNo existe\n";
			}
	}

	// Invertir la lista
	void invertir(Nodo *&inicio,Nodo *&final){
	    Nodo *ante = NULL;
	    Nodo *sigu = NULL;
	    Nodo *temp = new Nodo;
	    temp=inicio;
	    while (temp!=NULL) {
	    	
	        sigu = temp->siguiente;
	        temp->siguiente = ante;
	        ante = temp;
	        temp = sigu;
	        if(ante->siguiente==NULL){
	        	final=ante;
			}
	    }
	    sigu = ante;
	    inicio=ante;
	}
}
