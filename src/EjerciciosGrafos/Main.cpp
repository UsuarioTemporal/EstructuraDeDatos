#include "ClassGraph.h"
using namespace std;
Grafo *graph=new Grafo();
//dirigido y no dirigido
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
				graph->getGrado(0,vertice);
				break;
			case 7:
				graph->getGrado(1,vertice);
				break;
			case 8:
				graph->getGrado(2,vertice);
				break;
			case 9:
				graph->deleteVertice();
				break;
			case 10:
				graph->deleteArista();
				break;
			case 11:
				//camino
				graph->existeCamino();
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
}
