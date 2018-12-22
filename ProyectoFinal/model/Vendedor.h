#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Persona.h"
#include<iostream>
using namespace std;
class Vendedor : public Persona{
	private :
		string password;
		double ganacia;
	public :
		Vendedor(string nombre,int id,string password):Persona(nombre,id){
			this->password=password;
			ganacia=0;
		}
		
		double getGanacia(){
			return ganacia;
		}
		string getPassword(){
			return password;
		}
		void setGanacia(double ganancia){
			this->ganacia=ganancia;
		}
};
#endif
