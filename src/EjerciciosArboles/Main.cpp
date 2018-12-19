#include "Tree.h"
#include<locale.h>
Nodo *raiz=NULL;
void menu();
bool opciones(int);
int main(){
	setlocale(LC_ALL,"");
	menu();
	
}

void menu(){
	bool condition=true;
	do{
		cout<<"\n1.Insertar"<<endl;//hecho
		cout<<"2.Mostrar "<<endl;//hecho
		cout<<"3.Buscar con recorrido "<<endl;//hecho
		cout<<"4.Mostrar Preorden "<<endl;//hecho
		cout<<"5.Mostrar Inorden "<<endl;//hecho
		cout<<"6.Mostrar PosOrden "<<endl;//hecho
		cout<<"7.Eliminar elemento "<<endl;//hecho
		cout<<"8.Elemento menor "<<endl;//hecho
		cout<<"9.Elemento mayor "<<endl;//hecho
		cout<<"10.Profundidad o nivel"<<endl;//hecho
		cout<<"11.Altura "<<endl;//hecho
		cout<<"12.Mostrar hojas del arbol"<<endl;//hecho
		cout<<"13.Recorrido por anchura"<<endl;//hecho
		cout<<"14.Cantidad de nodos o tamaño del arbol"<<endl;  //hecho
		cout<<"15.Imprimir solo padres"<<endl;//hecho
		cout<<"16.Limpirar "<<endl;
		cout<<"17.Salir "<<endl;
		int op;
		cout<<"\nOpcion : ";
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			insertar(raiz,dato,NULL);
			system("cls");
			break;
		case 2:
			cout<<"\n";
			show(raiz,0);
			break;
		case 3:
			cin>>dato;
			if(busqueda(raiz,dato)){
				cout<<"\nEncontrado\n";
			}else{
				cout<<"\nNo existe\n";
			}
			break;
		case 4:
			preOrden(raiz);
			break;
		case 5:
			inOrden(raiz);
			break;
		case 6:
			posOrden(raiz);
			break;
		case 7:
			cin>>dato;
			eliminar(raiz,dato);
			break;
		case 8:
			encotrarMenor(raiz);
			break;
		case 9:
			encotrarMayor(raiz);
			break;
		case 10:
			cout<<"\nLa profundidad : "<<profundidad(raiz)<<"\n";
			break;
		case 11:
			cout<<"\nLa Altura : "<<profundidad(raiz)+1<<"\n";
			break;
		case 12:
			mostrarHojas(raiz);
			break;
		case 13:
			imprimirNivel(raiz);
			
			break;
		case 14:
			cantidadDeNodos(raiz);
			break;
		case 15:
			mostrarPadres(raiz);
			break;
		case 16:
			system("cls");
			break;
			
		default :
			return true;
	}
	return false;
}
