#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
using namespace std;
class Producto{
	private :
		int id;
		int cantidad;
		string nombre;
		double precioU;
	public : 
		Producto(string nombre,double precioU,int cantidad,int id){
			this->nombre=nombre;
			this->precioU=precioU;
			this->cantidad=cantidad;
			this->id=id;
		}
		int getID(){
			return id;
		}
		string getNombre(){
			return nombre;
		}
		double getPrecioU(){
			return precioU;
		}
		int getCantidad(){
			return cantidad;
		}
		
		/*disminu*/
		void setCantidad(int cantidad){
			this->cantidad-=cantidad;
		}
		void setAgregarCantidad(int cantidad){
			this->cantidad+=cantidad;
		}
		
		
		//
		void setCantidadObject(int cantidad){
			this->cantidad=cantidad;
		}
		void toString(){
			cout<<id<<"\t\t"<<nombre;
			if(nombre.length()<10){
				cout<<"\t\t\t\t";
			}
			else if(nombre.length()<=13){
				cout<<"\t\t\t";
			}
			else if(nombre.length()<=23){
				cout<<"\t\t";
			}else{
				cout<<"\t";
			}
			cout<<cantidad<<"\t\t"<<precioU<<" $"<<endl;
		}
};
#endif
