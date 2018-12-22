#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<string.h>
#include<conio.h>
#include "Vendedor.h"
#include "ListaDoble.h"
#include "Cliente.h"

#include "Tree.h"
#include "Cola.h"
#include "Validaciones.h"
#include <sstream>
#include <windows.h>
#include <string>
using namespace std;

class Menu{
	//Administradot por defecto 
	Vendedor *vendedor=new Vendedor("admin",1,"root");
	//
	Cliente *clientes[4];
	ListaDobleProductos *productosDisponible;
	Tree *arbolClientes;
	Cola *cola=new Cola();
	public :
		Menu(){
			arbolClientes=new Tree();
//			Productos existentes
			productosDisponible=new ListaDobleProductos();
			productosDisponible->insert(new Producto("Confeti colores de 10kg",18,40,1));
			productosDisponible->insert(new Producto("Confeti amarillo de 10kg",12,36,2));
			productosDisponible->insert(new Producto("Serpentina",16,60,3));
			productosDisponible->insert(new Producto("Polvo metálico 1kg",5,200,4));
			productosDisponible->insert(new Producto("Bolillas de tecnopor 1kg",8,300,5));
			productosDisponible->insert(new Producto("Mascaras de año nuevo ",2,400,6));
			
//			Usuarios Por defectos
			clientes[0]=new Cliente("Cristian",1);
			cola->insert(new Producto("Bolillas de tecnopor 1kg",8,10,5));
			cola->insert(new Producto("Mascaras de año nuevo ",2,5,6));
			cola->clear(clientes[0]);
			clientes[1]=new Cliente("Fabrizio",2);
			cola->insert(new Producto("Confeti amarillo de 10kg",12,18,2));
			cola->clear(clientes[1]);
			clientes[2]=new Cliente("Thom",3);
			cola->insert(new Producto("Confeti colores de 10kg",18,13,1));
			cola->clear(clientes[2]);
			clientes[3]=new Cliente("Angel",4);
			cola->insert(new Producto("Confeti amarillo de 10kg",12,8,2));
			cola->clear(clientes[3]);
			for(int i=0;i<4;i++){
				arbolClientes->insert(clientes[i],NULL);
			}
			
			
			
		}
		void initComponents(){
			entrada();
		}
		
	private: 
		void entrada(){
			int opcion;
			string opcionString;
			do{
				system("color 0b");
				fflush(stdin);
				system("cls");
				cout<<"\t\t\tRAYMIS COLORS S.A\n";
				cout<<"\t\t\t-----------------\n";
				cout<<"\n\t1.Cliente\n";
				cout<<"\t2.Administrador\n";
				cout<<"\tOpcion : ";
				
				getline(cin, opcionString);
				if(!isNumber(opcionString)){
					system("cls");
					cout<<"\n\tOpcion incorrecta,intentelo denuevo\n\tCargando componentes ,porfavor espere\n";
					Sleep(2000);
				}else{
					
					opcion=atoi(opcionString.c_str());
					if(opcion==1){
						system("cls");
						menuCliente();
					}else if(opcion==2){
						system("cls");
						menuAdministrador();
						
					}else{
						system("cls");
						cout<<"\n\tOpcion incorrecta,intentelo denuevo\n\tCargando componentes ,porfavor espere\n";
						Sleep(2000);
					}
				}
				
			}while(true);
		}
		/*la mejor función que hice en toda mi p$&!%@ vida >:) */
		void errores(Producto *&proOriginal,Producto *listPro){
			Producto s=*listPro;
			proOriginal=new Producto(s.getNombre(),s.getPrecioU(),s.getCantidad(),s.getID());
		}
		/*----------------------------------------------*/
		void catalogo(){
			productosDisponible->show();
		}
		void menuCliente(){
			bool registrado=false;
			Cliente *nuevo;
			
			int idCliente;
			string cadena;
			do{
				system("color 0D");
				fflush(stdin);
				system("cls");
				if(registrado){
					cout<<"\nUsuario actual : "<<nuevo->getNombre()<<"\n\n";
				}
				catalogo();
				cout<<"\nSeleccione Un ID y agrege a su compra : ";
				
				getline(cin, cadena);
				if(!isNumber(cadena)){
					system("cls");
					cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
					Sleep(2000);
				}else{
					int id;
					id=atoi(cadena.c_str());
					if(id==0 || id>productosDisponible->conteo){
						system("cls");
						cout<<"\nEl ID no existe\nCargando componentes ,porfavor espere\n";
						Sleep(2000);
					}else{
						Producto *pro;
//						Producto *pro=productosDisponible->get(id)->getDato(); // aqui esta
						errores(pro,productosDisponible->get(id)->getDato());
						int cantidad;
						do{
							fflush(stdin);
							cout<<"Seleccione la cantidad a comprar de "<<productosDisponible->get(id)->getDato()->getNombre()<<" : ";
							getline(cin, cadena);
							if(!isNumber(cadena)){
								cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
							}else{
								cantidad=atoi(cadena.c_str());
								
								if(pro->getCantidad()<cantidad){
									cout<<"\nCantidad Errorea ... \n";
								}else{
									break;
								}
							}
						}while(true);
						
						/*Curioso*/
						int cantidadSup = pro->getCantidad()-cantidad;
						pro->setCantidadObject(cantidad);
						productosDisponible->get(id)->getDato()->setCantidadObject(cantidadSup);
						/* --- */
						
						if(!registrado){
							string nombre;
							cout<<"\nPara terminar la compra ingrese su nombre: ";
							fflush(stdin);
							cin>>nombre;
							idCliente=arbolClientes->conteo+1;
							nuevo=new Cliente(nombre,idCliente);
						}
						/*Jorge el curioso paso por aqui*/
						cola->insert(pro);
						/*---*/
						fflush(stdin);
						do{
							fflush(stdin);
							system("cls");
							cout<<"\¿Desea continuar con las compras? ...\n1.Si continuar\n2.No ,ceder el paso\n3.Salir de clientes\n";
							cout<<"Opcion : ";
							getline(cin, cadena);
							if(!isNumber(cadena)){
								cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
								Sleep(2000);
							}else{
								
								int opcion=atoi(cadena.c_str());
								if(opcion>3 || opcion<=0){
									cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
									Sleep(2000);
								}else{
									if(opcion==1){
										registrado=true;
									}else if(opcion==2){
										registrado=false;
										cola->clear(nuevo);
										arbolClientes->insert(nuevo,NULL);
									}else{
										cola->clear(nuevo);
										arbolClientes->insert(nuevo,NULL);
										cout<<"saliendo";
										return ;
									}
									break;
								}
								
							}
						
						}while(true);
					}
					
					
					
				}
			
			}while(true);
			
		}
		
		
		void menuAdministrador(){
			int intentos = 0;
			do{
				system("color 0a");
				cout<<"\t\t\tLOGIN ADMINISTRADOR\n";
				cout<<"\t\t\t-------------------\n";
				cout<<"\tUser: ";
				string user;
				cin>>user;
				string pass="";
				cout<<"\tpassword : ";
				char caracter =getch();
				
				while(caracter!=13){
					if(caracter!=8){ //backspace
						pass.push_back(caracter);
						cout<<"*";
					}else{
						if(pass.size()>0){
							cout<<"\b \b";//retroce el cursor y  borra
							pass=pass.substr(0,pass.size()-1);
						}
					}
					
					caracter=getch();
				}
				
				if(vendedor->getNombre()==user && vendedor->getPassword()==pass){
					break;
				}else{
					cout<<"\n";
					cout<<"\n\t-------------------";
					cout<<"\n\tLa cuenta no existe";
					cout<<"\n\t-------------------\n";
					intentos++;
					cout<<"\n\tIntento numero "<<intentos;
					Sleep(2000);
					system("cls");
				}
			}while(true && intentos<3);
			fflush(stdin);
			if(intentos==3) return ;
			do{
				fflush(stdin);
				system("cls");
				cout<<"\t\t\tAdministrar las ventas y producto\n";
				cout<<"\t\t\t---------------------------------\n";
				cout<<"\t1.Listar Ventas \n";
				cout<<"\t2.Agregar Producto\n";
				cout<<"\t3.Salir\n";	
				cout<<"\tOpcion : ";
				int opcion;
				string cadena;
				getline(cin, cadena);
				if(!isNumber(cadena)){
					system("cls");
					cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
					Sleep(2000);
				}else{
					
					opcion=atoi(cadena.c_str());
					if(opcion<1 || opcion>3){
						system("cls");
						cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
						Sleep(2000);
					}else{
						if(opcion==1){
							system("cls");
							listarVentas();
						}else if(opcion==2){
							system("cls");
							agregarProductos();
							
						}else{
							system("cls");
							break;
						}
					}
				}
			}while(true);
		}
		
		
		
		void listarPilaProductosCliente(){
			do{
				fflush(stdin);
				cout<<"\n1.Pila productos de cliente ";
				cout<<"\n2.Salir\n";
				cout<<"Opcion : ";
				int opcion;
				string cadena;
				getline(cin, cadena);
				if(!isNumber(cadena)){
					system("cls");
					cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
					Sleep(2000);
				}else{
					opcion=atoi(cadena.c_str());
					if(opcion<1 || opcion>2){
						system("cls");
						cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
						Sleep(2000);
					}else{
						if(opcion==1){
							int id;
							
							cout<<"\nIngrese el id del cliente para ver los productos : ";
							cin>>id;
							arbolClientes->obtenerPilaProductos(id);
							Sleep(5000);
						}else{
							system("cls");
							break;
						}
					}
				}
				
			}while(true);
		}
		void listarVentas(){
			arbolClientes->inOrden();
			arbolClientes->ganancia(vendedor);
			cout<<"\nLa ganancia total es : "<<vendedor->getGanacia()<<" $\n";
			listarPilaProductosCliente();
		}
		void agregarProductos(){
			do{
				fflush(stdin);
				system("cls");
				cout<<"1.Agregar producto ya existente\n";
				cout<<"2.Agregar nuevo producto\n";
				cout<<"3.Cambiar el orden del catalogo\n";
				cout<<"4.Salir\n";
				cout<<"Opcion : ";
				int opcion;
				string cadena;
				getline(cin, cadena);
				if(!isNumber(cadena)){
					system("cls");
					cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
					Sleep(2000);
				}else{
					opcion=atoi(cadena.c_str());
					if(opcion<1 || opcion>4){
						system("cls");
						cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
						Sleep(2000);
					}else{
						
						if(opcion==1){
							int id;
							do{
							
								fflush(stdin);
								catalogo();
								system("cls");
								cout<<"\nIngrese el ID a buscar : ";
								getline(cin,cadena);
								if(isNumber(cadena)) {
									fflush(stdin);
									id=atoi(cadena.c_str());
									if(id==0 || id>productosDisponible->conteo){
										system("cls");
										cout<<"\nEl ID no existe\nCargando componentes ,porfavor espere\n";
										Sleep(2000);
									}else{
										break;
									}
								}else{
									system("cls");
									cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
									Sleep(2000);
								}
							}while(true);
							
							do{
								fflush(stdin);
								cout<<"Ingrese la cantidad a aumentar : ";
								getline(cin,cadena);
								if(isNumber(cadena)){
									fflush(stdin);
									int cantidad=atoi(cadena.c_str());
									if(cantidad<=0){
										system("cls");
										cout<<"\nCantidad incorrecta\nCargando componentes ,porfavor espere\n";
										Sleep(2000);
									}else{
										productosDisponible->get(id)->getDato()->setAgregarCantidad(opcion);
										catalogo();
										Sleep(5000);
										break;
									}
								}
								
							}while(true);
						}else if(opcion==2){
							system("cls");
							string nombre;
							double precioUnitario;
							int cantidad;
							do{
								fflush(stdin);
								system("cls");
								cout<<"\nIngrese el nombre del producto : ";
								getline(cin,nombre);
								if(isExist(productosDisponible,nombre)){
									system("cls");
									cout<<"El producto ya existe en el catalogo\nCargando componentes ,porfavor espere\n";
									Sleep(2000);	
								}else{
									break;
								}
							}while(true);
							do{
								fflush(stdin);
								cout<<"\nIngrese el precio Unitario : ";
								getline(cin,cadena);
								if(isFloat(cadena)){
									precioUnitario=atof(cadena.c_str());
									if(precioUnitario==0){
										cout<<"\Precio invalido\nCargando componentes ,porfavor espere\n";
										Sleep(2000);
									}else{
										fflush(stdin);
										break;
									}
								}else{
									cout<<"\Precio invalido\nCargando componentes ,porfavor espere\n";
									Sleep(2000);
								}
							}while(true);
							do{
								fflush(stdin);
								cout<<"\nIngrese la cantidad : ";
								getline(cin, cadena);
								if(!isNumber(cadena)){
									cout<<"\nOpcion incorrecta,intentelo denuevo\nCargando componentes ,porfavor espere\n";
								}else{
									cantidad=atoi(cadena.c_str());
									
									if(cantidad==0){
										cout<<"\nCantidad Errorea ... \n";
									}else{
										fflush(stdin);
										break;
									}
								}
							}while(true);
							productosDisponible->insert(new Producto(nombre,precioUnitario,cantidad,productosDisponible->conteo+1));
							catalogo();
							Sleep(5000);
						}else if(opcion==3){
							productosDisponible->ordenAleatorio();
							system("cls");
						}else{
							system("cls");
							break;
						}
					}
				}
				
			}while(true);
		}
		
};
#endif
