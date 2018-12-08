#ifndef GRAFO_H
#define GRAFO_H
#include<isotream>
using namespace std;
struct Nodo{
	char etiqueta;
	Nodo *siguiente=NULL;
	Arista *aristaAdyacente;
};
struct Arista{
	Nodo *destino=NULL;
	Arista *siguiente=NULL;
};
#endif GREAFO_H
