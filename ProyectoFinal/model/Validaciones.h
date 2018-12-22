#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include<iostream>

#include <string> // string, stoi
#include <cctype> // isdigit
#include <cstdlib> // atoi
 
using namespace std;

bool isNumber(string linea){
   	int longitud = linea.size();
 
   	if (longitud == 0) { // Cuando el usuario pulsa ENTER
      	return false;
   	}else {
      	int item= 0;
      	while (item < longitud) {
         	if (!isdigit(linea[item])) {
            	return false;
         	}
         	item++;
      	}
   	}
 
   	return true;
}

bool isFloat(string linea){
	int longitud = linea.size();
	int item=-1;
	if(longitud==0){
		return false;
	}else{
		int conteo=0;
		for(int i=0;i<longitud;i++){
			if(conteo>1){
				return false;
			}else{
				if(linea[i]=='.'){
					item=i;
					conteo++;
				}
			}
		}
		for(int i=0;i<longitud;i++){
			if(i!=item){
				if (!isdigit(linea[i])) {
            		return false;
         		}
			}
		}
		return true;
	}
}


bool isExist(ListaDobleProductos *&productos,string cadena){
	
	for(int i=0;i<cadena.size();i++){
		cadena[i]=toupper(cadena[i]);
	}
	for(int i=1;i<=productos->conteo;i++){
		string producto=productos->get(i)->getDato()->getNombre();
		for(int j=0;j<producto.size();j++){
			producto[j]=toupper(producto[j]);
		}
		if(cadena==producto){
			return true;
		}
	}
	return false;
}
#endif
