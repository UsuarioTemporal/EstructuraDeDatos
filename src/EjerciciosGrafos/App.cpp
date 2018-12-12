#include "Grafo.h"
Nodo *graph=NULL;
void menu(){
	do{
		int opcion;
		char etiqueta;
		fflush(stdin);
		cout<<"\n1.Insertar Nodo\n";
		cout<<"2.Insertar Arista\n";
		cout<<"3.Recorrido Anchura\n";
		cout<<"4.Recorrido Profundidad\n";
		cout<<"5.Lista de adyacencia\n";
		cout<<"6.Obtener grado general\n";
		cout<<"7.Obtener grado entrada\n";
		cout<<"8.Obtener grado salida\n";
		cout<<"Opcion : ";
		cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout<<"\n1.Insertar etiqueta :";
				cin>>etiqueta;
				insertarNodo(etiqueta,graph);
				break;
			case 2:
				insertarAris(graph);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				listaAdyacencia(graph);
				break;
			case 6:
				
				break;
			case 7:
				break;
			case 8:
				break;
		}
	}while(true);
}

int main(){
	menu();
}



