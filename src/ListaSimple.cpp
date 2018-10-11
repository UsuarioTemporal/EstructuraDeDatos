#include<simplelist.h>
#include<stdio.h>
//ordenar
using namespace SimpleList;
Nodo *inicio=NULL;
Nodo *final=NULL;
void menu();
bool opciones(int);
int main(){
	system("color 0B");
	menu();
	inicio=final=NULL;
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar al comienzo "<<endl;
		cout<<"2. Insertar al final "<<endl;
		cout<<"3. Eliminar el inicio"<<endl;
		cout<<"4. Eliminar el final"<<endl;
		cout<<"5. Eliminar especifico"<<endl;
		cout<<"6. Buscar "<<endl;
		cout<<"7. Ingresar dato en :  "<<endl;
		cout<<"8. Mostrar  "<<endl;
		cout<<"9. Cantidad de elementos  "<<endl;
		cout<<"10. Menor y mayor "<<endl;
		cout<<"11. Eliminar Nodos repetidos "<<endl;
		cout<<"12. Limpiar "<<endl;
		cout<<"13. Salir "<<endl;
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
			insertToTheStart(inicio,final,dato);
			break;
		case 2:
			cin>>dato;
			insertToTheEnd(inicio,final,dato);
			break;
		case 3:
			deleteToTheStart(inicio,final);
			break;
		case 4:
			deleteToTheEnd(inicio,final);
			break;
		case 5:
			if(isEmpty(inicio)){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				deleteEspecific(inicio,final,dato);
			}
			break;
		case 6:
			if(isEmpty(inicio)){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				buscar(inicio,final,dato);
			}
			break;
		case 7:
			if(!isEmpty(inicio)){
				int opcion;
				int datoSoA;
				cout<<"El valor que sera fijo : ";
				cin>>dato;
				cout<<"1.Antes"<<endl;
				cout<<"2.Despues"<<endl;
				cin>>opcion;
				cout<<"Ingrese el dato : ";
				cin>>datoSoA;
				insertarAntesODespues(inicio,final,dato,datoSoA,opcion);
			
			}else{
				cout<<"\nvacio\n";
			}
			break;
		case 8:
			show(inicio);
			break;
		case 9:
			contar(inicio);
			break;
		case 10:
			menorYMayor(inicio);
			break;
		case 11:
			eliminarDuplicados(inicio,final);
			break;
		case 12:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
