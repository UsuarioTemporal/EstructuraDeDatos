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
		cout<<"\n1. Insertar"<<endl;
		cout<<"2.Mostrar "<<endl;
		cout<<"3.Buscar "<<endl;
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
			insertar(raiz,dato);
			break;
		case 2:
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
	}
	return false;
}
