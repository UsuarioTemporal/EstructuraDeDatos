#include "ClassGraph.h"
using namespace std;
Grafo *graph=new Grafo();
//Ruta mas corta
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
				graph->insertArtista();
				break;
			case 3:
				graph->recorridoAnchura();
				break;
			case 4:
				graph->recorridoProfundidad();
				break;
			case 5:
				graph->listaAdyacencia();
				break;
			case 6:
				
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				system("cls");
				break;
			default :
				exit(0);
				break;
		}
	}while(true);
}
int main(){
	graph->existeCamino(graph->getVertice('a'),graph->getVertice('c'));
	graph->getGrado(0,graph->getVertice('a'));
	graph->getGrado(1,graph->getVertice('a'));
	graph->getGrado(2,graph->getVertice('a'));
}
