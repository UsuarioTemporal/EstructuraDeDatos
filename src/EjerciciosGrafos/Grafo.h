#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
using namespace std;
struct Arista{
	struct Nodo *destino=NULL;
	struct Arista *siguiente=NULL;
	int peso;
};
struct Nodo{
	char etiqueta;
	struct Nodo *siguiente=NULL;
	struct Arista *aristaAdyacente=NULL;
	
};
int conteo=0;



#endif 
