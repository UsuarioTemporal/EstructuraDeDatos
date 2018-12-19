#include "ClassGraph.h"
using namespace std;
Grafo *graph=new Grafo();
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
				graph->insertarVertice(etiqueta);
				break;
			case 2:
				graph->insertArtista();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
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
	graph->listaAdyacencia();
//	graph->deleteArista();
//	graph->listaAdyacencia();
//	graph->deleteVertice();
//	graph->listaAdyacencia();
	cout<<"\n";
//	graph->recorridoProfundidad(graph->getVertice('a'));
	graph->existeCamino(graph->getVertice('a'),graph->getVertice('c'));
	graph->getGrado(0,graph->getVertice('a'));
	graph->getGrado(1,graph->getVertice('a'));
	graph->getGrado(2,graph->getVertice('a'));
}
