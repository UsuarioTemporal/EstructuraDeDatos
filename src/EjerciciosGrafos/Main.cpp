#include "ClassGraph.h"
using namespace std;
Grafo *graph=new Grafo();
//conexo o no
//matriz de adyacencia
//dirigido y no dirigido
//kruskal
//ruta mas corta
//prim
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
		cout<<"9.Eliminar Vertice\n";
		cout<<"10.Eliminar Arista\n";
		cout<<"11.Exite camino\n";
		cout<<"12.Ruta mas corta\n";
		cout<<"13.Limpiar\n";
		cout<<"14.Salir\n";
		cout<<"Opcion : ";
		cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout<<"\n1.Insertar etiqueta :";
				cin>>etiqueta;
				graph->insertarVertice(etiqueta);
				break;
			case 2:
				if(!graph->isEmpty()){
					graph->insertArtista();
				}else{
					cout<<"\nel grafo esta vacio\n";
				}
				break;
			case 3:
				if(!graph->isEmpty()){
					cout<<"\n1.Insertar etiqueta :";
					cin>>etiqueta;
					Vertice *origen=graph->getVertice(etiqueta);
					if(origen==NULL){
						cout<<"\nVertice no existe\n";
					}else{
						graph->recorridoAnchura(origen);
						
					}
				}else{
					cout<<"\nel grafo esta vacio\n";
				}
				
				break;
			case 4:
				if(!graph->isEmpty()){
					cout<<"\n1.Insertar etiqueta :";
					cin>>etiqueta;
					Vertice *origen=graph->getVertice(etiqueta);
					if(origen==NULL){
						cout<<"\nVertice no existe\n";
					}else{
						graph->recorridoProfundidad(origen);
						
					}
				}else{
					cout<<"\nel grafo esta vacio\n";
				}
				break;
			case 5:
				if(!graph->isEmpty()){
					graph->listaAdyacencia();
				}else{
					cout<<"\nel grafo esta vacio\n";
				}
				break;
			case 6:
				cout<<"\n1.Insertar etiqueta :";
				cin>>etiqueta;
				if(!graph->isEmpty()){
					graph->getGrado(0,etiqueta);
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				break;
			case 7:
				cout<<"\n1.Insertar etiqueta :";
				cin>>etiqueta;
				if(!graph->isEmpty()){
					graph->getGrado(1,etiqueta);
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				break;
			case 8:
				cout<<"\n1.Insertar etiqueta :";
				cin>>etiqueta;
				if(!graph->isEmpty()){
					graph->getGrado(2,etiqueta);
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				break;
			case 9:
				if(!graph->isEmpty()){
					graph->deleteVertice();
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				
				break;
			case 10:
				if(!graph->isEmpty()){
					graph->deleteArista();
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				
				break;
			case 11:
				if(!graph->isEmpty()){
					char inicio;
					char final;
					cout<<"\nIngrese la etiqueta origen : ";
					cin>>inicio;
					cout<<"\nIngrese la etiqueta destino : ";
					cin>>final;
					graph->caminoEntre(inicio,final);
				}else{
					cout<<"\nEl grafo esta vacio\n";
				}
				break;
			case 12:
				//ruta mas corta
				break;
			case 13:
				system("cls");
				break;
			default :
				exit(0);
		}
	}while(true);
}
int main(){
	menu();
	return 0;
}
