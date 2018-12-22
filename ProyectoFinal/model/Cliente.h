#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pila.h"
#include "Persona.h"
class Cliente : public Persona{
	private :
		Pila *productos;
		double gasto;
	public :
		Cliente(string nombre,int id):Persona(nombre,id){
			productos=new Pila();
			gasto=0;
		}
		
		Pila *getPilaProductos(){
			return productos;
		}
		
		double getGasto(){
			return gasto;
		}
		
		void setGasto(double gasto){
			this->gasto+=gasto;
		}
		void toString(){
			cout<<"\n";
			Persona::toString();
			cout<<gasto<<" $\n";
		}
		
		
};
#endif 
