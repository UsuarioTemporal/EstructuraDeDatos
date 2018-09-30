#include<iostream>
#include<vector>
using namespace std;
class Animal{
	private :
		int edad;
	public :
		Animal(int edad){
			this->edad=edad;
		}
		virtual void comer(){
			
		}
};
class Humano: public Animal{
	private :
		string nombre;
		string sexo;
		string dni;
	public :
		Humano(int edad,string nombre,string sexo,string dni):Animal(edad){
			this->nombre=nombre;
			this->sexo=sexo;
			this->dni=dni;
		}
		void comer(){
		}
};
class Hombre : public Humano{
	private :
		string enfermedadProstata;
	public :
		Hombre(int edad,string nombre,string sexo,string dni,string  enfermedadProstata) : Humano(edad,nombre,sexo,dni){
			this->enfermedadProstata=enfermedadProstata;
			
		}
		void comer(){
		}
};
//
class Mujer: public Humano{
	public :
		Mujer(int edad,string nombre,string sexo,string dni):Humano(edad,nombre,sexo,dni){
			
		}
		void comer(){
			
		}
};
class Perro: public Animal{
	private :
		string raza;
	public :
		Perro(int edad,string raza):Animal(edad){
			this->raza=raza;
		}
		void comer(){
			
		}
};
int main(){
	Animal *mundo[2];
	mundo[0]=new Mujer(12,"Maria","Femenina","12345");
	return 0;
}
