#include<iostream>
#include<vector>
#include<Math.h>
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
			eliminando(vect,inicio,final);
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
	Nodo *retroceder(Nodo *supuestoP,int lugar){
			for(int i=1;i<=lugar;i++){
				supuestoP=supuestoP->siguiente;
			}
			return supuestoP;
	}
	void ordenarSeleccion(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			for(Nodo *primero=inicio;primero!=final;primero=primero->siguiente){
				for(Nodo *segundo=primero->siguiente;segundo!=NULL;segundo=segundo->siguiente){
					if(segundo->dato<primero->dato){
						int aux=segundo->dato;
						segundo->dato=primero->dato;
						primero->dato=aux;
					}
				}
			}
		}else{
			cout<<"\nVacio\n";
		}
	}
	
	
	void ordenarInsercion(Nodo *&inicio,Nodo *&final){
		if(!isEmpty(inicio)){
			int posTem=0;
			for(Nodo *primero=inicio;primero!=NULL;primero=primero->siguiente){
				int supPosTem=posTem;
				Nodo *pos=primero;
				Nodo *ant=retroceder(inicio,posTem-1);
				while(supPosTem>0 && pos->dato<ant->dato){
					int aux=ant->dato;
					ant->dato=pos->dato;
					pos->dato=aux;
					ant=retroceder(inicio,supPosTem-2);
					pos=retroceder(inicio,supPosTem-1);
					supPosTem--;
				}
				posTem++;
			}
		}
	}
	vector< vector<int> > Vec;
	void radix(Nodo *&inicio,Nodo *&final){
		Vec.resize(10);
		int temporal;
		int mayor=inicio->dato;
		for(Nodo *recorrer=inicio;recorrer!=NULL;recorrer=recorrer->siguiente){
			if(recorrer->dato>mayor){
				mayor=recorrer->dato;
			}
		}
		int cifras=0;
		while(mayor!=0){
			mayor/=10;
			cifras++;
		}
		
		for(int i=0;i<cifras;i++){
			int m=0;
			for(int j=0;j<conteo;j++){
				Nodo *sup=retroceder(inicio,j);
				temporal=(int)(sup->dato/pow(10,i))%10;
				Vec[temporal].push_back(sup->dato);
			}
			for(int k=0;k<10;k++){
				for(int l=0;l<Vec[k].size();l++){
					retroceder(inicio,m)->dato=Vec[k][l];
					m++;
				}
				Vec[k].clear();
			}
		}
	}
	int getLength(Nodo *partida){
		Nodo* recorrer = partida;
		int i=0;
		for(;recorrer!=NULL;recorrer=recorrer->siguiente){
			i++;
		}
		return i;
	}
	Nodo* merge(Nodo *&inicio1,Nodo *&inicio2){
		Nodo* nuevoInicio;
		if(inicio1==NULL) return inicio2;
		else if(inicio2 ==NULL) return inicio1;
		
		if(inicio1->dato < inicio2->dato){
			nuevoInicio = inicio1;
			nuevoInicio->siguiente = merge(inicio1->siguiente,inicio2);
		}
		else{
			nuevoInicio = inicio2;
			nuevoInicio->siguiente = merge(inicio1,inicio2->siguiente);
		}
		
		return nuevoInicio;
	}	
	void mergeSort(Nodo *&inicio){
		if(inicio->siguiente!=NULL){
			Nodo* inicio1;
			Nodo* inicio2 = inicio;
			int len = getLength(inicio);
			for(int i=0; i<len/2;i++){   
				inicio1 = inicio2; 
				inicio2 = inicio2->siguiente;
			}
			inicio1->siguiente = NULL;	
			inicio1 = inicio;
			mergeSort(inicio1);
			mergeSort(inicio2);
			inicio = merge(inicio1,inicio2);
		}
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
