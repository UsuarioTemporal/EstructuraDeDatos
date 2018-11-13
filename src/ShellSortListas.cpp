#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Nodo {
	public :
		int dato;
		Nodo *siguiente;
		Nodo(int dato){
			siguiente=NULL;
			this->dato;
		}
};
class Lista{
	private :
		Nodo *inicio,*final;
	public 	:
		int conteo;
		Lista(){
			inicio=final=NULL;
			conteo=0;
		}
		void show(){
			if(inicio!=NULL){
				Nodo *recorrer=inicio;
				cout<<"\n";
				while(recorrer!=NULL){
					cout<<"["<<recorrer->dato<<"]-->";
					recorrer=recorrer->siguiente;
				}
				cout<<"||\n"<<endl;
			}else{
				cout<<"\nVacio"<<endl;
			}
		}
		void insert(int dato){
			Nodo *nuevo=new Nodo(dato);
			nuevo->dato=dato;
			conteo++;
			if(inicio==NULL){
				inicio=final=nuevo;
			}else{
				final->siguiente=nuevo;
				final=nuevo;
			}
		}
		Nodo *retroceder(Nodo *supuestoP,int lugar){
			for(int i=1;i<=lugar;i++){
				supuestoP=supuestoP->siguiente;
			}
			return supuestoP;
		}
		void shellSort(){
			Nodo *q=NULL;
		    int saltos = conteo / 2;
		    while (saltos > 0) {
		        q = inicio;
		        for (int i = 1; i <=saltos; i++) {
		            q = q->siguiente;
		        }
		        Nodo *p= inicio;
		        int posicionQ=saltos;
		        while (q != NULL) {
					Nodo *supuestoQ=q;
					Nodo *supuestoP=p;
					int supuestaPosicionQ=posicionQ;
					do{
						if (supuestoP->dato > supuestoQ->dato) {
				            int aux = supuestoP->dato;
				            supuestoP->dato = supuestoQ->dato;
				            supuestoQ->dato = aux;
			            }
			            int supuestaPosicionP=supuestaPosicionQ-saltos;
			            if(supuestaPosicionP>=saltos && supuestoP!=inicio){
			                supuestoQ=supuestoP;
			                supuestoP=retroceder(inicio,supuestaPosicionP-saltos);
			                supuestaPosicionQ-=saltos;
						}else{
							break;
						}
					}while(supuestoP->dato > supuestoQ->dato);
			        p = p->siguiente;
			        q = q->siguiente;
			        posicionQ++;
		        }
		        saltos/= 2;
			}	        
		}
		
		
};
int main(){
	srand(time(NULL));
	Lista lista=Lista();
//	int array[]={5,-1,5,1,5,1,3,4,3,0,-4,5,47};
//	int array[]={12,24,6,30,17,5};
	int numero=13;
	int array[numero];
	for(int i=0;i<numero;i++){
		array[i] = -20 + rand()%(20+1-(-20));
	}
	cout<<sizeof(array)/sizeof(*array);
	for(int i=0;i<sizeof(array)/sizeof(*array);i++){
		lista.insert(array[i]);
	}
	lista.show();
	lista.shellSort();
	lista.show();
	system("pause");
	return 0;
}
