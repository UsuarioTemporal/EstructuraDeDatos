#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
using namespace std;
class Persona{
	private :
		string nombre;
		int id;
	public :
		Persona(string nombre,int id){
			this->nombre=nombre;
			this->id=id;
		}
		string getNombre(){
			return nombre;
		}
		int getID(){
			return id;
		}
		void setNombre(string nombre){
			this->nombre=nombre;
		}
		void toString(){
			cout<<id<<"\t";
			if(nombre.length()<8){
				cout<<nombre<<"\t\t";
			}else{
				cout<<nombre<<"\t";
			}
		}
};
#endif
