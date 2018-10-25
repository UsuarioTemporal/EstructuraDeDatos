#include<iostream>
#include<vector>
using namespace std;
namespace SimpleList{
	int conteo=0;
	struct Nodo{
		int dato;
		Nodo *siguiente=NULL;	
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
	void insertToTheStart(Nodo *&inicio,Nodo *&final,int dato){
		conteo=conteo+1;
		cout<<conteo;
		Nodo *nuevo1=new Nodo;
		nuevo1->dato=dato;
		if(isEmpty(inicio)){
			inicio=final=nuevo1;
		}else{
			nuevo1->siguiente=inicio;
			inicio=nuevo1;
		}
	}
	void insertToTheEnd(Nodo *&inicio,Nodo *&final,int dato){
		conteo++;
		Nodo *nuevo=new Nodo;
		nuevo->dato=dato;
		if(isEmpty(inicio)){
			inicio=final=nuevo;
		}else{
			final->siguiente=nuevo;
			final=final->siguiente ;
		}
	}
	
	void deleteToTheStart(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
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
	void deleteToTheEnd(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
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
	bool find(Nodo *inicio,int dato){
		Nodo *recorrer=new Nodo;
		recorrer=inicio;
		while(recorrer!=NULL && recorrer->dato!=dato){
			recorrer=recorrer->siguiente;
		}
		return recorrer!=NULL;
	}
	
	void insertarAntesODespues(Nodo *&inicio,Nodo *&final,int dato,int datoSoA,int opcion){
			if(find(inicio,dato)){
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
	void deleteEspecific(Nodo *&inicio,Nodo *&final,int dato){
			if(find(inicio,dato)){
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
	void show(Nodo *inicio){
		if(!isEmpty(inicio)){
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
			recorrer=inicio;
			while(recorrer!=NULL){
				bool primo=true;
				for(int i=2;i<recorrer->dato;i++){
					
					if(recorrer->dato%i==0){
						primo=false;
						break;
					}
				}
				if(primo && recorrer->dato!=0 && recorrer->dato!=1){
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
	//mover cada ... ejm mover cada dos posiciones : 1 - 2 - 3 - 4 , resultado : 3 - 4 - 1 - 2
//	void rotando(Nodo *&inicio,Nodo *&final){
//		if(!isEmpty(inicio)){
//			int dato;cin>>dato;
//			if(dato>conteo){
//				Nodo *nuevoInicio=new Nodo;
//				nuevoInicio=inicio;
//				Nodo *nuevoFinal=new Nodo;
//				nuevoFinal=final;
//				Nodo *recorrer=new Nodo;
//				recorrer=inicio;
//				for(int i=1;i<dato;i++){
//					recorrer=recorrer->siguiente;
//				}
//				
//			}
//		}else{
//			cout<<"\nVacio\n";
//		}
//	}

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
