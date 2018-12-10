//#include "Grafo.h"
#include "ClassGraph.h"
using namespace std;
int main(){
//	Nodo *graph=NULL;
	Grafo *graph=new Grafo();
	graph->insertarVertice('a');
	graph->insertarVertice('b');
	graph->insertarVertice('c');
	graph->insertarVertice('d');
	graph->insertarVertice('e');
	graph->insertarVertice('f');
	graph->insertArtista();
	graph->listaAdyacencia();
	graph->deleteArista();
	graph->listaAdyacencia();
}
