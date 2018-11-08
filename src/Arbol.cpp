#include<tree.h>
using namespace Tree;
Nodo *raiz=NULL;
void menu();
bool opciones(int);
int main(){
	menu();
}

void menu(){
	bool condition=true;
	do{
		cout<<"\n1.Insertar"<<endl;
		cout<<"2.Mostrar "<<endl;
		cout<<"3.Buscar "<<endl;
		cout<<"4.Mostrar Preorden "<<endl;
		cout<<"5.Mostrar Inorden "<<endl;
		cout<<"6.Mostrar PosOrden "<<endl;
		cout<<"7.Eliminar elemento "<<endl;
		cout<<"8.Elemento menor "<<endl;
		cout<<"9.Elemento mayor "<<endl;
		cout<<"10.Limpirar "<<endl;
		cout<<"11.Salir "<<endl;
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
			system("cls");
			break;
		default :
			return true;
	}
	return false;
}
