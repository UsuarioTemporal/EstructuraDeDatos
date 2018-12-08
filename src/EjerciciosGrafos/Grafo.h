#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
using namespace std;
struct Nodo{
	char etiqueta;
	struct Nodo *siguiente=NULL;
	struct Arista *aristaAdyacente;
};
struct Arista{
	struct Nodo *destino=NULL;
	struct Arista *siguiente=NULL;
};
#endif 
